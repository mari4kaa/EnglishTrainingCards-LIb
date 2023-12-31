#include "TrueFalseDialog.h"

TrueFalseDialog::TrueFalseDialog() {};
TrueFalseDialog::~TrueFalseDialog() {};

INT_PTR CALLBACK TrueFalseDialog::DlgTrueFalse(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    TrueFalseDialog* dialog = reinterpret_cast<TrueFalseDialog*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<TrueFalseDialog*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);
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

int TrueFalseDialog::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 3)
    {
        auto iter = data.begin();
        word = *iter;
        definition = *(++iter);
        answer = data.back();
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG2), parent, DlgTrueFalse, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};

void TrueFalseDialog::OnInitDialog(HWND hDlg)
{
    SetDlgItemText(hDlg, IDC_DEFINITION_LABEL, definition.c_str());
    SetDlgItemText(hDlg, IDC_STATIC_WORD, word.c_str());
};

void TrueFalseDialog::OnSubmit(wstring buttonAnsw)
{
    bool isSame = (answer.compare(buttonAnsw) == 0);
    MessageBox(
        NULL,
        isSame ? L"Correct! You got it right!" : L"Wrong answer.",
        L"Result",
        MB_OK | (isSame ? MB_ICONINFORMATION : MB_ICONERROR)
    );
    result = (int)isSame - 1;
};
