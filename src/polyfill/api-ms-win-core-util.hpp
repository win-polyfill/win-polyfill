

#if (WP_SUPPORT_VERSION < NTDDI_WS03SP1)

// Windows XP with SP2, Windows Server 2003 with SP1
__DEFINE_THUNK(kernel32, 4, PVOID, WINAPI, DecodePointer, _In_opt_ PVOID Ptr)
{
    if (auto const pDecodePointer = wp_get_DecodePointer())
    {
        return pDecodePointer(Ptr);
    }
    else
    {
        return Ptr;
    }
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WS03SP1)

// Windows XP with SP2, Windows Server 2003 with SP1
__DEFINE_THUNK(kernel32, 4, PVOID, WINAPI, EncodePointer, _In_opt_ PVOID Ptr)
{
    if (auto const pEncodePointer = wp_get_EncodePointer())
    {
        return pEncodePointer(Ptr);
    }
    else
    {
        return Ptr;
    }
}
#endif
