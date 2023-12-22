#include "FullAnswerDialog.h"

FullAnswerDialog::FullAnswerDialog() {};
FullAnswerDialog::~FullAnswerDialog() {};

wstring FullAnswerDialog::word = L"";
wstring FullAnswerDialog::definition = L"";
HWND FullAnswerDialog::hDefinitionLabel = NULL;
HWND FullAnswerDialog::hWordTextBox = NULL;

INT_PTR CALLBACK DlgVocabulary(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            FullAnswerDialog::OnInitDialog(hDlg);
            return (INT_PTR)TRUE;
        }

        case WM_COMMAND:
            if(LOWORD(wParam) == ID_SUBMIT_BUTTON)
            {
                FullAnswerDialog::OnSubmit();
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

void FullAnswerDialog::Show(HWND parent, HINSTANCE parentInst, list<wstring> data)
{
    if (data.size() == 2)
    {
        word = data.front();
        definition = data.back();
        DialogBox(parentInst, MAKEINTRESOURCE(IDD_DIALOG1), parent, DlgVocabulary);
    } else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
}

void FullAnswerDialog::OnInitDialog(HWND hDlg)
{
    hDefinitionLabel = GetDlgItem(hDlg, IDC_DEFINITION_LABEL);
    hWordTextBox = GetDlgItem(hDlg, IDC_WORD_TEXTBOX);

    SetWindowText(hDefinitionLabel, definition.c_str());
}

void FullAnswerDialog::OnSubmit()
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
};
