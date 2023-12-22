#pragma once
#include "MyDialog.h"

class QuizDialog : public virtual MyDialog
{
private:
    static wstring option1, option2, option3, definition, rightAnswers;
public:
    QuizDialog();
    ~QuizDialog();
    static void OnInitDialog(HWND hDlg);
    void Show(HWND parent, HINSTANCE parentInst, list<wstring> data);
    static void OnSubmit(HWND hDlg);
};
