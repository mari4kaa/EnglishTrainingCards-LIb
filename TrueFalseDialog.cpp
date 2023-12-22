#include "TrueFalseDialog.h"

TrueFalseDialog::TrueFalseDialog() {};
TrueFalseDialog::~TrueFalseDialog() {};

wstring TrueFalseDialog::word = L"";
wstring TrueFalseDialog::definition = L"";
wstring TrueFalseDialog::answer = L"";
HWND TrueFalseDialog::hDefinitionLabel = NULL;
HWND TrueFalseDialog::hWordLabel = NULL;

INT_PTR CALLBACK DlgTrueFalse(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        TrueFalseDialog::OnInitDialog(hDlg);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BUTTON_TRUE)
        {
            wstring answ = L"true";
            TrueFalseDialog::OnSubmit(answ);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }

        if (LOWORD(wParam) == IDC_BUTTON_FALSE)
        {
            wstring answ = L"false";
            TrueFalseDialog::OnSubmit(answ);
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

void TrueFalseDialog::Show(HWND parent, HINSTANCE parentInst, list<wstring> data)
{
    if (data.size() == 3)
    {
        auto iter = data.begin();
        word = *iter;
        definition = *(++iter);
        answer = data.back();
        DialogBox(parentInst, MAKEINTRESOURCE(IDD_DIALOG2), parent, DlgTrueFalse);
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
};

void TrueFalseDialog::OnInitDialog(HWND hDlg)
{
    hDefinitionLabel = GetDlgItem(hDlg, IDC_DEFINITION_LABEL);
    hWordLabel = GetDlgItem(hDlg, IDC_STATIC_WORD);

    SetWindowText(hDefinitionLabel, definition.c_str());
    SetWindowText(hWordLabel, word.c_str());
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
};
