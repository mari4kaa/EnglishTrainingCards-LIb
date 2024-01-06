#ifndef QUIZDIALOG_H
#define QUIZDIALOG_H

#pragma once
#include "MyDialog.h"

class MYLIB_API QuizDialog : public virtual MyDialog
{
protected:
    wstring option1, option2, option3;
    wstring definition, rightAnswers;
public:
    QuizDialog();
    virtual ~QuizDialog();
    void OnInitDialog(HWND hDlg);
    virtual int Show(HWND parent, list<wstring> data);
    void OnSubmit(wstring buttonAnsw = L"");
    static INT_PTR CALLBACK DlgQuiz(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif
