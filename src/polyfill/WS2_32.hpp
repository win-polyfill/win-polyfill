

/* Extract begin open */
#if !defined(WIN_POLYFILL_DISABLE_SOCKET)
/* Extract begin close */

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows 8.1, Windows Vista [desktop apps | UWP apps]
// Windows Server 2008 [desktop apps | UWP apps]
__DEFINE_THUNK(
    ws2_32,
    12,
    INT,
    WINAPI,
    inet_pton,
    _In_ INT Family,
    _In_ PCSTR pszAddrString,
    _When_(Family == AF_INET, _Out_writes_bytes_(sizeof(IN_ADDR)))
        _When_(Family == AF_INET6, _Out_writes_bytes_(sizeof(IN6_ADDR))) PVOID pAddrBuf)
{
    if (auto pinet_pton = wp_get_inet_pton())
    {
        return pinet_pton(Family, pszAddrString, pAddrBuf);
    }

    typedef char Char;

    if (nullptr == pszAddrString || nullptr == pAddrBuf)
    {
        WSASetLastError(WSAEFAULT);
        return -1;
    }

    if (AF_INET == Family)
    {
        // IPv4
        UCHAR IPAddress[4] = {};

        unsigned i = 0;
        for (; i != _countof(IPAddress);)
        {
            auto &IPNum = IPAddress[i++];

            auto Start = pszAddrString;
            for (; *Start && *Start != Char('.'); ++Start)
            {
                auto &Ch = *Start;

                // 必须是0~9数字
                if (Ch >= Char('0') && Ch <= Char('9'))
                {
                    auto NewNum = IPNum * 10ul + (Ch & 0x0Ful);
                    if (NewNum > 0xFF)
                    {
                        // 不能大于255
                        return 0;
                    }

                    IPNum = (UCHAR)NewNum;
                }
                else
                {
                    return 0;
                }
            }

            //
            if (Start == pszAddrString)
                return 0;

            pszAddrString = Start;

            if (*pszAddrString == Char('\0'))
                break;
            else
                ++pszAddrString;
        }

        // 未正常截断
        if (i != _countof(IPAddress) || *pszAddrString != Char('\0'))
            return 0;

        ((IN_ADDR *)pAddrBuf)->S_un.S_addr = *(ULONG *)IPAddress;

        return 1;
    }
    else if (AF_INET6 == Family)
    {
        // IPv6

        IN6_ADDR IPAddress;

        int i = 0;
        int InsertIndex = -1;

        for (; i != _countof(IPAddress.u.Word) && *pszAddrString;)
        {
            if (pszAddrString[0] == Char(':') && pszAddrString[1] == Char(':'))
            {
                // 缩进只能有一次
                if (InsertIndex != -1)
                    return 0;

                InsertIndex = i;

                pszAddrString += 2;
                continue;
            }

            auto &IPNum = IPAddress.u.Word[i++];
            IPNum = 0;

            auto Start = pszAddrString;
            for (; *Start && *Start != Char(':'); ++Start)
            {
                auto &Ch = *Start;

                unsigned int NewNum;

                // 0~9数字
                if (Ch >= Char('0') && Ch <= Char('9'))
                {
                    NewNum = Ch & 0x0Ful;
                }
                else if (Ch >= Char('a') && Ch <= Char('f'))
                {
                    NewNum = Ch - Char('a') + 10;
                }
                else if (Ch >= Char('A') && Ch <= Char('F'))
                {
                    NewNum = Ch - Char('A') + 10;
                }
                else
                {
                    // 无法识别
                    return 0;
                }

                NewNum = ((unsigned int)IPNum << 4) | NewNum;

                if (NewNum > 0xFFFF)
                {
                    // 不能大于255
                    return 0;
                }

                IPNum = NewNum;
            }

            // 截断错误
            if (Start == pszAddrString)
            {
                return 0;
            }

            IPNum = _byteswap_ushort(IPNum);

            pszAddrString = Start;

            if (*pszAddrString == Char('\0'))
            {
                break;
            }
            else if (pszAddrString[1] == Char(':'))
            {
            }
            else
            {
                ++pszAddrString;
            }
        }

        // 未正常截断
        if (*pszAddrString != Char('\0'))
        {
            return 0;
        }
        else if (i != _countof(IPAddress.u.Word) && InsertIndex == -1)
        {
            return 0;
        }
        else
        {
            if (InsertIndex == -1)
            {
                *(IN6_ADDR *)pAddrBuf = IPAddress;
            }
            else
            {
                // 先复制头

                auto j = 0u;
                for (; j != InsertIndex; ++j)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = IPAddress.u.Word[j];
                }

                // 补充中间 0
                for (const auto Count = _countof(IPAddress.u.Word) - i + j; j != Count; ++j)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = 0;
                }

                // 复制小尾巴
                for (; j != _countof(IPAddress.u.Word); ++j, ++InsertIndex)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = IPAddress.u.Word[InsertIndex];
                }
            }
            return 1;
        }
    }
    else
    {
        WSASetLastError(WSAEAFNOSUPPORT);
        return -1;
    }
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows 8.1, Windows Vista [desktop apps | UWP apps]
// Windows Server 2008 [desktop apps | UWP apps]
__DEFINE_THUNK(
    ws2_32,
    12,
    INT,
    WINAPI,
    InetPtonW,
    _In_ INT Family,
    _In_ PCWSTR pszAddrString,
    _When_(Family == AF_INET, _Out_writes_bytes_(sizeof(IN_ADDR)))
        _When_(Family == AF_INET6, _Out_writes_bytes_(sizeof(IN6_ADDR))) PVOID pAddrBuf)
{
    if (auto pInetPtonW = wp_get_InetPtonW())
    {
        return pInetPtonW(Family, pszAddrString, pAddrBuf);
    }

    typedef wchar_t Char;

    if (nullptr == pszAddrString || nullptr == pAddrBuf)
    {
        WSASetLastError(WSAEFAULT);
        return -1;
    }

    if (AF_INET == Family)
    {
        // IPv4
        UCHAR IPAddress[4] = {};

        unsigned i = 0;
        for (; i != _countof(IPAddress);)
        {
            auto &IPNum = IPAddress[i++];

            auto Start = pszAddrString;
            for (; *Start && *Start != Char('.'); ++Start)
            {
                auto &Ch = *Start;

                // 必须是0~9数字
                if (Ch >= Char('0') && Ch <= Char('9'))
                {
                    auto NewNum = IPNum * 10ul + (Ch & 0x0Ful);
                    if (NewNum > 0xFF)
                    {
                        // 不能大于255
                        return 0;
                    }

                    IPNum = (UCHAR)NewNum;
                }
                else
                {
                    return 0;
                }
            }

            //
            if (Start == pszAddrString)
                return 0;

            pszAddrString = Start;

            if (*pszAddrString == Char('\0'))
                break;
            else
                ++pszAddrString;
        }

        // 未正常截断
        if (i != _countof(IPAddress) || *pszAddrString != Char('\0'))
            return 0;

        ((IN_ADDR *)pAddrBuf)->S_un.S_addr = *(ULONG *)IPAddress;

        return 1;
    }
    else if (AF_INET6 == Family)
    {
        // IPv6

        IN6_ADDR IPAddress;

        int i = 0;
        int InsertIndex = -1;

        for (; i != _countof(IPAddress.u.Word) && *pszAddrString;)
        {
            if (pszAddrString[0] == Char(':') && pszAddrString[1] == Char(':'))
            {
                // 缩进只能有一次
                if (InsertIndex != -1)
                    return 0;

                InsertIndex = i;

                pszAddrString += 2;
                continue;
            }

            auto &IPNum = IPAddress.u.Word[i++];
            IPNum = 0;

            auto Start = pszAddrString;
            for (; *Start && *Start != Char(':'); ++Start)
            {
                auto &Ch = *Start;

                unsigned int NewNum;

                // 0~9数字
                if (Ch >= Char('0') && Ch <= Char('9'))
                {
                    NewNum = Ch & 0x0Ful;
                }
                else if (Ch >= Char('a') && Ch <= Char('f'))
                {
                    NewNum = Ch - Char('a') + 10;
                }
                else if (Ch >= Char('A') && Ch <= Char('F'))
                {
                    NewNum = Ch - Char('A') + 10;
                }
                else
                {
                    // 无法识别
                    return 0;
                }

                NewNum = ((unsigned int)IPNum << 4) | NewNum;

                if (NewNum > 0xFFFF)
                {
                    // 不能大于255
                    return 0;
                }

                IPNum = NewNum;
            }

            // 截断错误
            if (Start == pszAddrString)
            {
                return 0;
            }

            IPNum = _byteswap_ushort(IPNum);

            pszAddrString = Start;

            if (*pszAddrString == Char('\0'))
            {
                break;
            }
            else if (pszAddrString[1] == Char(':'))
            {
            }
            else
            {
                ++pszAddrString;
            }
        }

        // 未正常截断
        if (*pszAddrString != Char('\0'))
        {
            return 0;
        }
        else if (i != _countof(IPAddress.u.Word) && InsertIndex == -1)
        {
            return 0;
        }
        else
        {
            if (InsertIndex == -1)
            {
                *(IN6_ADDR *)pAddrBuf = IPAddress;
            }
            else
            {
                // 先复制头

                auto j = 0u;
                for (; j != InsertIndex; ++j)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = IPAddress.u.Word[j];
                }

                // 补充中间 0
                for (const auto Count = _countof(IPAddress.u.Word) - i + j; j != Count; ++j)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = 0;
                }

                // 复制小尾巴
                for (; j != _countof(IPAddress.u.Word); ++j, ++InsertIndex)
                {
                    ((IN6_ADDR *)pAddrBuf)->u.Word[j] = IPAddress.u.Word[InsertIndex];
                }
            }
            return 1;
        }
    }
    else
    {
        WSASetLastError(WSAEAFNOSUPPORT);
        return -1;
    }
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows 8.1, Windows Vista [desktop apps | UWP apps]
// Windows Server 2008 [desktop apps | UWP apps]
__DEFINE_THUNK(
    ws2_32,
    16,
    PCSTR,
    WINAPI,
    inet_ntop,
    _In_ INT Family,
    _In_ const VOID *pAddr,
    _Out_writes_(StringBufSize) PSTR pStringBuf,
    _In_ size_t StringBufSize)
{
    if (auto pinet_ntop = wp_get_inet_ntop())
    {
        return pinet_ntop(Family, pAddr, pStringBuf, StringBufSize);
    }

    NTSTATUS WSAError = ERROR_SUCCESS;

    if (pAddr == nullptr || pStringBuf == nullptr)
    {
        WSAError = ERROR_INVALID_PARAMETER;
    }
    else
    {
        char BufferTemp[64];
        auto szString = pStringBuf;
        size_t cchString = 0;

        constexpr const char Hex[] = "0123456789abcdef";

        if (AF_INET == Family)
        {
            // IPv4
            if (StringBufSize < 16)
            {
                szString = BufferTemp;
            }

            auto &IPv4 = *((unsigned char(*)[4])pAddr);

            for (int i = 0; i != _countof(IPv4); ++i)
            {
                auto Num = IPv4[i];
                if (Num < 10)
                {
                    // 1 位
                    szString[cchString++] = Hex[Num];
                }
                else if (Num < 100)
                {
                    // 2 位
                    szString[cchString++] = Hex[Num / 10];
                    szString[cchString++] = Hex[Num % 10];
                }
                else
                {
                    // 3 位
                    szString[cchString++] = Hex[Num / 100];
                    szString[cchString++] = Hex[(Num / 10) % 10];
                    szString[cchString++] = Hex[Num % 10];
                }

                szString[cchString++] = '.';
            }

            --cchString;
        }
        else if (AF_INET6 == Family)
        {
            // IPv6
            if (StringBufSize < 46)
            {
                szString = BufferTemp;
            }

            auto &IPv6 = ((const IN6_ADDR *)pAddr)->u.Word;

            int ZeroIndex = -1;
            int ZeroCount = 1;

            // 统计 连续 0个数最多的情况
            for (int i = 0; i != _countof(IPv6);)
            {
                auto j = i;

                for (; j != _countof(IPv6) && IPv6[j] == 0; ++j)
                    ;

                auto Count = j - i;

                if (Count)
                {
                    if (Count > ZeroCount)
                    {
                        ZeroCount = Count;
                        ZeroIndex = i;
                    }

                    i = j;
                }
                else
                {
                    ++i;
                }
            }

            for (int i = 0; i != _countof(IPv6);)
            {
                if (ZeroIndex == i)
                {
                    if (i == 0)
                    {
                        szString[cchString++] = ':';
                    }

                    szString[cchString++] = ':';
                    i += ZeroCount;
                }
                else
                {
                    auto Num = _byteswap_ushort(IPv6[i++]);

                    if (Num <= 0xF)
                    {
                        // 1 位
                        szString[cchString++] = Hex[Num];
                    }
                    else if (Num <= 0xFF)
                    {
                        // 2 位
                        szString[cchString++] = Hex[Num >> 4];
                        szString[cchString++] = Hex[Num & 0x0F];
                    }
                    else if (Num <= 0xFFF)
                    {
                        // 3 位
                        szString[cchString++] = Hex[(Num >> 8)];

                        szString[cchString++] = Hex[(Num >> 4) & 0x0F];
                        szString[cchString++] = Hex[(Num >> 0) & 0x0F];
                    }
                    else
                    {
                        // 4位
                        szString[cchString++] = Hex[(Num >> 12)];
                        szString[cchString++] = Hex[(Num >> 8) & 0x0F];

                        szString[cchString++] = Hex[(Num >> 4) & 0x0F];
                        szString[cchString++] = Hex[(Num >> 0) & 0x0F];
                    }

                    if (i != _countof(IPv6))
                        szString[cchString++] = ':';
                }
            }
        }
        else
        {
            WSAError = WSAEAFNOSUPPORT;
        }

        if (WSAError == ERROR_SUCCESS)
        {
            if (cchString >= StringBufSize)
            {
                WSAError = ERROR_INVALID_PARAMETER;
            }
            else
            {
                if (szString != BufferTemp)
                {
                    // 缓冲区不足

                    memcpy(pStringBuf, szString, sizeof(szString[0]) * cchString);
                }

                pStringBuf[cchString] = '\0';

                return pStringBuf;
            }
        }
    }

    WSASetLastError(WSAError);
    return nullptr;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

// Windows 8.1, Windows Vista [desktop apps | UWP apps]
// Windows Server 2008 [desktop apps | UWP apps]
__DEFINE_THUNK(
    ws2_32,
    16,
    PCWSTR,
    WINAPI,
    InetNtopW,
    _In_ INT Family,
    _In_ const VOID *pAddr,
    _Out_writes_(StringBufSize) PWSTR pStringBuf,
    _In_ size_t StringBufSize)
{
    if (auto pInetNtopW = wp_get_InetNtopW())
    {
        return pInetNtopW(Family, pAddr, pStringBuf, StringBufSize);
    }

    NTSTATUS WSAError = ERROR_SUCCESS;

    if (pAddr == nullptr || pStringBuf == nullptr)
    {
        WSAError = ERROR_INVALID_PARAMETER;
    }
    else
    {
        wchar_t BufferTemp[64];
        auto szString = pStringBuf;
        size_t cchString = 0;

        constexpr const char Hex[] = "0123456789abcdef";

        if (AF_INET == Family)
        {
            // IPv4
            if (StringBufSize < 16)
            {
                szString = BufferTemp;
            }

            auto &IPv4 = *((unsigned char(*)[4])pAddr);

            for (int i = 0; i != _countof(IPv4); ++i)
            {
                auto Num = IPv4[i];
                if (Num < 10)
                {
                    // 1 位
                    szString[cchString++] = Hex[Num];
                }
                else if (Num < 100)
                {
                    // 2 位
                    szString[cchString++] = Hex[Num / 10];
                    szString[cchString++] = Hex[Num % 10];
                }
                else
                {
                    // 3 位
                    szString[cchString++] = Hex[Num / 100];
                    szString[cchString++] = Hex[(Num / 10) % 10];
                    szString[cchString++] = Hex[Num % 10];
                }

                szString[cchString++] = '.';
            }

            --cchString;
        }
        else if (AF_INET6 == Family)
        {
            // IPv6
            if (StringBufSize < 46)
            {
                szString = BufferTemp;
            }

            auto &IPv6 = ((const IN6_ADDR *)pAddr)->u.Word;

            int ZeroIndex = -1;
            int ZeroCount = 1;

            // 统计 连续 0个数最多的情况
            for (int i = 0; i != _countof(IPv6);)
            {
                auto j = i;

                for (; j != _countof(IPv6) && IPv6[j] == 0; ++j)
                    ;

                auto Count = j - i;

                if (Count)
                {
                    if (Count > ZeroCount)
                    {
                        ZeroCount = Count;
                        ZeroIndex = i;
                    }

                    i = j;
                }
                else
                {
                    ++i;
                }
            }

            for (int i = 0; i != _countof(IPv6);)
            {
                if (ZeroIndex == i)
                {
                    if (i == 0)
                    {
                        szString[cchString++] = ':';
                    }

                    szString[cchString++] = ':';
                    i += ZeroCount;
                }
                else
                {
                    auto Num = _byteswap_ushort(IPv6[i++]);

                    if (Num <= 0xF)
                    {
                        // 1 位
                        szString[cchString++] = Hex[Num];
                    }
                    else if (Num <= 0xFF)
                    {
                        // 2 位
                        szString[cchString++] = Hex[Num >> 4];
                        szString[cchString++] = Hex[Num & 0x0F];
                    }
                    else if (Num <= 0xFFF)
                    {
                        // 3 位
                        szString[cchString++] = Hex[(Num >> 8)];

                        szString[cchString++] = Hex[(Num >> 4) & 0x0F];
                        szString[cchString++] = Hex[(Num >> 0) & 0x0F];
                    }
                    else
                    {
                        // 4位
                        szString[cchString++] = Hex[(Num >> 12)];
                        szString[cchString++] = Hex[(Num >> 8) & 0x0F];

                        szString[cchString++] = Hex[(Num >> 4) & 0x0F];
                        szString[cchString++] = Hex[(Num >> 0) & 0x0F];
                    }

                    if (i != _countof(IPv6))
                        szString[cchString++] = ':';
                }
            }
        }
        else
        {
            WSAError = WSAEAFNOSUPPORT;
        }

        if (WSAError == ERROR_SUCCESS)
        {
            if (cchString >= StringBufSize)
            {
                WSAError = ERROR_INVALID_PARAMETER;
            }
            else
            {
                if (szString != BufferTemp)
                {
                    // 缓冲区不足

                    memcpy(pStringBuf, szString, sizeof(szString[0]) * cchString);
                }

                pStringBuf[cchString] = '\0';

                return pStringBuf;
            }
        }
    }

    WSASetLastError(WSAError);
    return nullptr;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)

static int poll_win32_select(LPWSAPOLLFD fdArray, ULONG fds, INT timeout)
{
    uintptr_t *fd_set_memory = NULL;
    ULONG i = 0;
    int count = 0;
    fd_set *readfds = NULL;
    fd_set *writefds = NULL;
    fd_set *exceptfds = NULL;
    struct timeval *__ptimeout = NULL;
    struct timeval time_out;
    int result = -1;

    for (count = 0; count < 2; ++count)
    {
        int read_count = 0;
        int write_count = 0;
        int except_count = 0;
        for (i = 0; i < fds; i++)
        {
            struct pollfd *fd = fdArray + i;
            if (fd->fd == INVALID_SOCKET)
            {
                continue;
            }

            // Read (in) socket
            if (fd->events & (POLLRDNORM | POLLRDBAND | POLLPRI))
            {
                if (readfds != NULL)
                {
                    readfds->fd_array[read_count] = fd->fd;
                }
                ++read_count;
            }

            // Write (out) socket
            if (fd->events & (POLLWRNORM | POLLWRBAND))
            {
                if (writefds != NULL)
                {
                    writefds->fd_array[write_count] = fd->fd;
                }
                ++write_count;
            }

            // Exception
            if (fd->events & (POLLERR | POLLHUP | POLLNVAL))
            {
                if (exceptfds != NULL)
                {
                    exceptfds->fd_array[except_count] = fd->fd;
                }
                ++except_count;
            }
        }

        if (fd_set_memory == NULL)
        {
            size_t mem_size = 0;
            read_count = max(64, read_count);
            write_count = max(64, write_count);
            except_count = max(64, except_count);
            mem_size = ((read_count + write_count + except_count) + 3) * sizeof(uintptr_t);
            fd_set_memory = (uintptr_t *)HeapAlloc(GetProcessHeap(), 0, mem_size);
        }
        else
        {
            readfds->fd_count = read_count;
            writefds->fd_count = write_count;
            exceptfds->fd_count = except_count;
            break;
        }
        if (fd_set_memory == NULL)
        {
            return -1;
        }
        readfds = (fd_set *)fd_set_memory;
        writefds = (fd_set *)(fd_set_memory + (read_count + 1));
        exceptfds = (fd_set *)(fd_set_memory + (read_count + 1) + (write_count + 1));
    }

    /*
    timeout  < 0 , infinite
    timeout == 0 , nonblock
    timeout  > 0 , the time to wait
    */
    if (timeout >= 0)
    {
        time_out.tv_sec = timeout / 1000;
        time_out.tv_usec = (timeout % 1000) * 1000;
        __ptimeout = &time_out;
    }

    result = select(1, readfds, writefds, exceptfds, __ptimeout);

    if (result > 0)
    {
        for (i = 0; i < fds; i++)
        {
            struct pollfd *fd = fdArray + i;
            fd->revents = 0;
            if (fd->fd == INVALID_SOCKET)
            {
                continue;
            }
            if (FD_ISSET(fd->fd, readfds))
            {
                fd->revents |= fd->events & // NOLINT
                               (POLLRDNORM | POLLRDBAND | POLLPRI);
            }

            if (FD_ISSET(fd->fd, writefds))
            {
                fd->revents |= fd->events & // NOLINT
                               (POLLWRNORM | POLLWRBAND);
            }

            if (FD_ISSET(fd->fd, exceptfds))
            {
                fd->revents |= fd->events & // NOLINT
                               (POLLERR | POLLHUP | POLLNVAL);
            }
        }
    }

    HeapFree(GetProcessHeap(), 0, fd_set_memory);
    return result;
}

// Windows 8.1, Windows Vista [desktop apps | UWP apps]
// Windows Server 2008 [desktop apps | UWP apps]
// 参考 https://blog.csdn.net/liangzhao_jay/article/details/53261684 实现
__DEFINE_THUNK(
    ws2_32,
    12,
    int,
    WSAAPI,
    WSAPoll,
    _Inout_ LPWSAPOLLFD fdArray,
    _In_ ULONG fds,
    _In_ INT timeout)
{
    if (auto const pWSAPoll = wp_get_WSAPoll())
    {
        return pWSAPoll(fdArray, fds, timeout);
    }

    return poll_win32_select(fdArray, fds, timeout);
}
#endif

/* Extract end open */
#endif /* !defined(WIN_POLYFILL_DISABLE_SOCKET) */
/* Extract end close */
