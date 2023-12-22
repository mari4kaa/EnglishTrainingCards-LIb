#include "QuizDialog.h"

QuizDialog::QuizDialog() {};
QuizDialog::~QuizDialog() {};

wstring QuizDialog::option1 = L"";
wstring QuizDialog::option2 = L"";
wstring QuizDialog::option3 = L"";
wstring QuizDialog::definition = L"";
wstring QuizDialog::rightAnswers = L"";

INT_PTR CALLBACK DlgQuiz(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        QuizDialog::OnInitDialog(hDlg);
        return (INT_PTR)TRUE;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_SUBMIT_BUTTON)
        {
            QuizDialog::OnSubmit(hDlg);
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

void QuizDialog::Show(HWND parent, HINSTANCE parentInst, list<wstring> data)
{
    if (data.size() == 5) {
        auto iter = data.begin();
        option1 = *iter;
        option2 = *(++iter);
        option3 = *(++iter);
        definition = *(++iter);
        rightAnswers = *(++iter);
        DialogBox(parentInst, MAKEINTRESOURCE(IDD_DIALOG3), parent, DlgQuiz);
    } else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
};

void QuizDialog::OnInitDialog(HWND hDlg)
{
    SetDlgItemText(hDlg, IDC_CHECK1, option1.c_str());
    SetDlgItemText(hDlg, IDC_CHECK2, option2.c_str());
    SetDlgItemText(hDlg, IDC_CHECK3, option3.c_str());

    SetDlgItemText(hDlg, IDC_DEFINITION_LABEL, definition.c_str());
};

void QuizDialog::OnSubmit(HWND hDlg)
{
    bool status1 = (IsDlgButtonChecked(hDlg, IDC_CHECK1) == BST_CHECKED)? true: false;
    bool status2 = (IsDlgButtonChecked(hDlg, IDC_CHECK2) == BST_CHECKED) ? true : false;
    bool status3 = (IsDlgButtonChecked(hDlg, IDC_CHECK3) == BST_CHECKED) ? true : false;
    
    bool rightStatus1 = (rightAnswers.find(option1) != wstring::npos);
    bool rightStatus2 = (rightAnswers.find(option2) != wstring::npos);
    bool rightStatus3 = (rightAnswers.find(option3) != wstring::npos);

    bool isCorrect = (status1 == rightStatus1 && status2 == rightStatus2 && status3 == rightStatus3);

    MessageBox(
        NULL,
        isCorrect ? L"Correct! You got it right!" : L"Wrong answer.",
        L"Result",
        MB_OK | (isCorrect ? MB_ICONINFORMATION : MB_ICONERROR)
    );
};