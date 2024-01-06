#include "OneAnswerDialog.h"

OneAnswerDialog::OneAnswerDialog() {};
OneAnswerDialog::~OneAnswerDialog() {};

INT_PTR CALLBACK OneAnswerDialog::DlgOneAnswerSimple(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    OneAnswerDialog* dialog = reinterpret_cast<OneAnswerDialog*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<OneAnswerDialog*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);
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

int OneAnswerDialog::Show(HWND parent, list<wstring> data)
{
    if (data.size() == 5) {
        auto iter = data.begin();
        option1 = *iter;
        option2 = *(++iter);
        option3 = *(++iter);
        definition = *(++iter);
        rightAnswer = *(++iter);
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG7), parent, DlgOneAnswerSimple, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};

void OneAnswerDialog::OnInitDialog(HWND hDlg)
{
    SetDlgItemText(hDlg, IDC_RADIO1, option1.c_str());
    SetDlgItemText(hDlg, IDC_RADIO2, option2.c_str());
    SetDlgItemText(hDlg, IDC_RADIO3, option3.c_str());

    SetDlgItemText(hDlg, IDC_DEFINITION_LABEL, definition.c_str());
};

void OneAnswerDialog::OnSubmit(wstring buttonAnsw)
{
    HWND hDlg = GetActiveWindow();
    int selectedRadioButton = GetCheckedRadioButton(hDlg);

    wstring selectedOption;
    switch (selectedRadioButton)
    {
    case IDC_RADIO1:
        selectedOption = option1;
        break;
    case IDC_RADIO2:
        selectedOption = option2;
        break;
    case IDC_RADIO3:
        selectedOption = option3;
        break;
    default:
        break;
    }

    bool isCorrect = (rightAnswer.compare(selectedOption) == 0);

    MessageBox(
        NULL,
        isCorrect ? L"Correct! You got it right!" : L"Wrong answer.",
        L"Result",
        MB_OK | (isCorrect ? MB_ICONINFORMATION : MB_ICONERROR)
    );
    result = (int)isCorrect - 1;
};

int OneAnswerDialog::GetCheckedRadioButton(HWND hDlg)
{
    int selectedRadioButton = 0;
    if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED) {
        selectedRadioButton = IDC_RADIO1;
    }
    else if (IsDlgButtonChecked(hDlg, IDC_RADIO2) == BST_CHECKED) {
        selectedRadioButton = IDC_RADIO2;
    }
    else if (IsDlgButtonChecked(hDlg, IDC_RADIO3) == BST_CHECKED) {
        selectedRadioButton = IDC_RADIO3;
    }
    return selectedRadioButton;
};
