#include "TrueFalseStar.h"

TrueFalseStar::TrueFalseStar() {};
TrueFalseStar::~TrueFalseStar() {};

INT_PTR CALLBACK TrueFalseStar::DlgTrueFalseStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    TrueFalseStar* dialog = reinterpret_cast<TrueFalseStar*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<TrueFalseStar*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);
        dialog->starManage.SetStarRegion(hDlg, 15);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BUTTON_TRUE)
        {
            wstring answ = L"true";
            dialog->OnSubmit(answ);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDC_BUTTON_FALSE)
        {
            wstring answ = L"false";
            dialog->OnSubmit(answ);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
    }
    return (INT_PTR)FALSE;
};

int TrueFalseStar::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 3)
    {
        auto iter = data.begin();
        word = *iter;
        definition = *(++iter);
        answer = data.back();
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG5), parent, DlgTrueFalseStar, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};