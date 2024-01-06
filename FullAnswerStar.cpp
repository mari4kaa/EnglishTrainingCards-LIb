#include "FullAnswerStar.h"

FullAnswerStar::FullAnswerStar() {};
FullAnswerStar::~FullAnswerStar() {};

INT_PTR CALLBACK FullAnswerStar::DlgFullStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    FullAnswerStar* dialog = reinterpret_cast<FullAnswerStar*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<FullAnswerStar*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);

        dialog->starManage.SetStarRegion(hDlg, 12);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_SUBMIT_BUTTON)
        {
            dialog->OnSubmit();
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

int FullAnswerStar::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 2)
    {
        word = data.front();
        definition = data.back();
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG4), parent, DlgFullStar, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};
