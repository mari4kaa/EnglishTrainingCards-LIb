#include "QuizStar.h"

QuizStar::QuizStar() {};
QuizStar::~QuizStar() {};

INT_PTR CALLBACK QuizStar::DlgQuizStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
    QuizStar* dialog = reinterpret_cast<QuizStar*>(GetWindowLongPtr(hDlg, GWLP_USERDATA));
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        dialog = reinterpret_cast<QuizStar*>(lParam);
        SetWindowLongPtr(hDlg, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(dialog));
        dialog->OnInitDialog(hDlg);

        dialog->starManage.SetStarRegion(hDlg, 18);
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

int QuizStar::Show(HWND parent, list<wstring> data) {
    if (data.size() == 5) {
        auto iter = data.begin();
        option1 = *iter;
        option2 = *(++iter);
        option3 = *(++iter);
        definition = *(++iter);
        rightAnswers = *(++iter);
        DialogBoxParam(NULL, MAKEINTRESOURCE(IDD_DIALOG6), parent, DlgQuizStar, reinterpret_cast<LPARAM>(this));
    }
    else {
        MessageBox(NULL, L"Wrong data format in dictionary.", L"Result", MB_OK | MB_ICONERROR);
    }
    return result;
};

