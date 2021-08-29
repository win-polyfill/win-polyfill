

/* Extract begin open */
#ifdef __cplusplus
/* Extract begin close */

#if (WP_SUPPORT_VERSION < NTDDI_WIN6)
// Windows Vista [desktop apps only]
// Windows Server 2008 [desktop apps only]

__DEFINE_THUNK(
    dwrite,
    -1,
    HRESULT,
    WINAPI,
    DWriteCreateFactory,
    _In_ DWRITE_FACTORY_TYPE factoryType,
    _In_ REFIID iid,
    _COM_Outptr_ IUnknown **factory)
{
    if (auto const pDWriteCreateFactory = wp_get_DWriteCreateFactory())
    {
        return pDWriteCreateFactory(factoryType, iid, factory);
    }

    return __HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
}

#endif // (WP_SUPPORT_VERSION < NTDDI_WIN6)

/* Extract end open */
#endif /* __cplusplus */
/* Extract end close */
