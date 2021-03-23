#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////////
// 
// FUNCTION: LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)
//
// PARAMETERS: [in]  hWind     - window handle;
//             [in]  uMsg      - message for window;
//             [in]  wParam    - additional information for message;
//             [in]  lParam    - additional information for message.
//
// RETURN VALUE: 0  - in all cases.
//
// PURPOSE: message processing function.
//
// COMMENTS: no.
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT ps;

    static HFONT m_PixelFont;

    switch (uMsg) {
    case WM_CREATE:
        if (::AddFontResourceEx(TEXT("Pixel.ttf"), FR_NOT_ENUM, nullptr)) { 
            ::SendNotifyMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
        }

        m_PixelFont = ::CreateFont(14, 14, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Pixel"));
        return 0;

    case WM_PAINT:
    {
        hDC = ::BeginPaint(hWnd, &ps);
    
        ::EndPaint(hWnd, &ps);
        return 0;
    }

    case WM_DESTROY:
        ::RemoveFontResourceEx(TEXT("Pixel.ttf"), FR_NOT_ENUM, nullptr);
        ::PostQuitMessage(NULL);
        return 0;

    default:
        return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}