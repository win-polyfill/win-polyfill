/* This should be keep stable version to version */
enum win_polyfill_identifier
{
    wp_id_SystemParametersInfoForDpi = 0,

    wp_idMaximal, /* Without leading _ for make sure all win32 API identifier can be exposed */
};

/* 0 means success, other are NTSTATUS error code */
typedef void *(*wp_load_identifier_function)(enum win_polyfill_identifier id);
void *wp_load_identifier(enum win_polyfill_identifier id);
