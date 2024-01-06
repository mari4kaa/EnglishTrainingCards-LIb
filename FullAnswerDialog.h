#ifndef FULLANSWERDIALOG_H
#define FULLANSWERDIALOG_H

#pragma once
#include "MyDialog.h"

class MYLIB_API FullAnswerDialog : public MyDialog
{
protected:
    wstring word;
    wstring definition;

    HWND hWordTextBox;

public:
    FullAnswerDialog();
    virtual ~FullAnswerDialog();
    void OnInitDialog(HWND hDlg);
    virtual int Show(HWND parent, list<wstring> data);
    void OnSubmit(wstring buttonAnsw = L"");
    static INT_PTR CALLBACK DlgFullSimple(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif
