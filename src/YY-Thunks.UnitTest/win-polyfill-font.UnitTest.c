#include <win-polyfill-export-clean.h>

#include <stdbool.h>
#include <stdio.h>
// ### fixme Qt 6 (QTBUG-58610): See comment at QWindowsFontDatabase::systemDefaultFont()
HFONT systemFont() { return (HFONT)GetStockObject(DEFAULT_GUI_FONT); }

bool systemParametersInfo(unsigned action, unsigned param, void *out, unsigned dpi)
{
    const BOOL result = wp_SystemParametersInfoForDpi(action, param, out, 0, dpi);
    return result == TRUE;
}

static bool nonClientMetrics(NONCLIENTMETRICSW *ncm, unsigned dpi)
{
    memset(ncm, 0, sizeof(NONCLIENTMETRICSW));
    ncm->cbSize = sizeof(NONCLIENTMETRICSW);
    return systemParametersInfo(SPI_GETNONCLIENTMETRICS, ncm->cbSize, ncm, dpi);
}
int main(int argc, char **argv)
{
    LOGFONT lf;
    GetObjectW(systemFont(), sizeof(lf), &lf);
    printf("lfHeight:%d\n", lf.lfHeight);

    {
        NONCLIENTMETRICSW ncm;
        bool nonClient = nonClientMetrics(&ncm, 0);
        printf("%d lfMenuFont.lfHeight:%d\n", nonClient, ncm.lfMenuFont.lfHeight);
        printf("%d lfMessageFont.lfHeight:%d\n", nonClient, ncm.lfMessageFont.lfHeight);
        printf("%d lfStatusFont.lfHeight:%d\n", nonClient, ncm.lfStatusFont.lfHeight);
        printf("%d lfCaptionFont.lfHeight:%d\n", nonClient, ncm.lfCaptionFont.lfHeight);
    }

    return 0;
}
