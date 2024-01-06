#include "OneAnswerStar.h"

OneAnswerStar::OneAnswerStar() {};
OneAnswerStar::~OneAnswerStar() {};

INT_PTR CALLBACK OneAnswerStar::DlgOneAnswerStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    OneAnswerStar* dialog = reinterpret_cast<OneAnswerStar*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<OneAnswerStar*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);
        dialog->starManage.SetStarRegion(hDlg, 17);
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

int OneAnswerStar::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 5) {
        auto iter = data.begin();
        option1 = *iter;
        option2 = *(++iter);
        option3 = *(++iter);
        definition = *(++iter);
        rightAnswer = *(++iter);
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG8), parent, DlgOneAnswerStar, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};