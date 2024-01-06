#ifndef ONEANSWERDIALOG_H
#define ONEANSWERDIALOG_H

#pragma once
#include "MyDialog.h"

class MYLIB_API OneAnswerDialog : public virtual MyDialog
{
protected:
    wstring option1, option2, option3;
    wstring definition, rightAnswer;
    int GetCheckedRadioButton(HWND hDlg);
public:
    OneAnswerDialog();
    virtual ~OneAnswerDialog();
    void OnInitDialog(HWND hDlg);
    virtual int Show(HWND parent, list<wstring> data);
    void OnSubmit(wstring buttonAnsw = L"");
    static INT_PTR CALLBACK DlgOneAnswerSimple(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif