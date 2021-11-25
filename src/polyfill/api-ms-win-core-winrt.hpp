

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    4,
    HRESULT,
    WINAPI,
    RoInitialize,
    _In_ RO_INIT_TYPE initType)
{
    if (auto const pRoInitialize = wp_get_RoInitialize())
    {
        return pRoInitialize(initType);
    }

    if ((unsigned)initType > (unsigned)RO_INIT_MULTITHREADED)
    {
        return E_INVALIDARG;
    }

    return CoInitializeEx(
        nullptr,
        initType ? COINIT_MULTITHREADED : COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(api_ms_win_core_winrt_l1_1_0, 0, void, WINAPI, RoUninitialize, VOID)
{
    if (auto const pRoUninitialize = wp_get_RoUninitialize())
    {
        return pRoUninitialize();
    }

    CoUninitialize();
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    8,
    HRESULT,
    WINAPI,
    RoActivateInstance,
    _In_ HSTRING activatableClassId,
    _COM_Outptr_ IInspectable **instance)
{
    if (auto const pRoActivateInstance = wp_get_RoActivateInstance())
    {
        return pRoActivateInstance(activatableClassId, instance);
    }

    if (instance)
        *instance = nullptr;

    return E_NOTIMPL;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    16,
    HRESULT,
    WINAPI,
    RoRegisterActivationFactories,
    _In_reads_(count) HSTRING *activatableClassIds,
    _In_reads_(count) PFNGETACTIVATIONFACTORY *activationFactoryCallbacks,
    _In_ UINT32 count,
    _Out_ RO_REGISTRATION_COOKIE *cookie)
{
    if (auto const pRoRegisterActivationFactories = wp_get_RoRegisterActivationFactories())
    {
        return pRoRegisterActivationFactories(
            activatableClassIds, activationFactoryCallbacks, count, cookie);
    }

    if (cookie)
        *cookie = nullptr;

    return E_NOTIMPL;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    4,
    void,
    WINAPI,
    RoRevokeActivationFactories,
    _In_ RO_REGISTRATION_COOKIE cookie)
{
    if (auto const pRoRevokeActivationFactories = wp_get_RoRevokeActivationFactories())
    {
        return pRoRevokeActivationFactories(cookie);
    }
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    12,
    HRESULT,
    WINAPI,
    RoGetActivationFactory,
    _In_ HSTRING activatableClassId,
    _In_ REFIID iid,
    _COM_Outptr_ void **factory)
{
    if (auto const pRoGetActivationFactory = wp_get_RoGetActivationFactory())
    {
        return pRoGetActivationFactory(activatableClassId, iid, factory);
    }

    if (factory)
        *factory = nullptr;

    return E_NOTIMPL;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    12,
    HRESULT,
    WINAPI,
    RoRegisterForApartmentShutdown,
    _In_ IApartmentShutdown *callbackObject,
    _Out_ UINT64 *apartmentIdentifier,
    _Out_ APARTMENT_SHUTDOWN_REGISTRATION_COOKIE *regCookie)
{
    if (auto const pRoRegisterForApartmentShutdown = wp_get_RoRegisterForApartmentShutdown())
    {
        return pRoRegisterForApartmentShutdown(callbackObject, apartmentIdentifier, regCookie);
    }

    if (regCookie)
        *regCookie = nullptr;

    return E_NOTIMPL;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    4,
    HRESULT,
    WINAPI,
    RoUnregisterForApartmentShutdown,
    _In_ APARTMENT_SHUTDOWN_REGISTRATION_COOKIE regCookie)
{
    if (auto const pRoUnregisterForApartmentShutdown = wp_get_RoUnregisterForApartmentShutdown())
    {
        return pRoUnregisterForApartmentShutdown(regCookie);
    }

    return E_NOTIMPL;
}
#endif

#if (WP_SUPPORT_VERSION < NTDDI_WIN8)

// Windows 8 [desktop apps | UWP apps]
// Windows Server 2012 [desktop apps | UWP apps]
__DEFINE_THUNK(
    api_ms_win_core_winrt_l1_1_0,
    4,
    HRESULT,
    WINAPI,
    RoGetApartmentIdentifier,
    _Out_ UINT64 *apartmentIdentifier)
{
    if (auto const pRoGetApartmentIdentifier = wp_get_RoGetApartmentIdentifier())
    {
        return pRoGetApartmentIdentifier(apartmentIdentifier);
    }

    return E_NOTIMPL;
}
#endif
