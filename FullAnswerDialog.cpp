#include "FullAnswerDialog.h"

FullAnswerDialog::FullAnswerDialog() {};
FullAnswerDialog::~FullAnswerDialog() {};

INT_PTR CALLBACK FullAnswerDialog::DlgFullSimple(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    FullAnswerDialog* dialog = reinterpret_cast<FullAnswerDialog*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            dialog = reinterpret_cast<FullAnswerDialog*>(lParam);
            SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
            dialog->OnInitDialog(hDlg);
            return (INT_PTR)TRUE;
        }

        case WM_COMMAND:
            if(LOWORD(wParam) == ID_SUBMIT_BUTTON)
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
}

int FullAnswerDialog::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 2)
    {
        word = data.front();
        definition = data.back();
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG1), parent, DlgFullSimple, reinterpret_cast<LPARAM>(this));
    } else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
}

void FullAnswerDialog::OnInitDialog(HWND hDlg)
{
    hWordTextBox = GetDlgItem(hDlg, IDC_WORD_TEXTBOX);

    SetDlgItemText(hDlg, IDC_DEFINITION_LABEL, definition.c_str());
}

void FullAnswerDialog::OnSubmit(wstring buttonAnsw)
{
    WCHAR buffer[256];
    GetWindowText(hWordTextBox, buffer, ARRAYSIZE(buffer));

    wstring enteredWord = buffer;
    bool found = (enteredWord.compare(word) == 0);
    MessageBox(
        NULL,
        found ? L"Correct! You got it right!" : L"Wrong answer.",
        L"Result",
        MB_OK | (found ? MB_ICONINFORMATION : MB_ICONERROR)
    );
    result = (int)found - 1;
};
