#ifndef TRUEFALSEDIALOG_H
#define TRUEFALSEDIALOG_H

#pragma once
#include "MyDialog.h"

class MYLIB_API TrueFalseDialog : public virtual MyDialog
{
protected:
    wstring word, definition, answer;
public:
    TrueFalseDialog();
    virtual ~TrueFalseDialog();
    void OnInitDialog(HWND hDlg);
    virtual int Show(HWND parent, list<wstring> data);
    void OnSubmit(wstring buttonAnsw = L"");
    static INT_PTR CALLBACK DlgTrueFalse(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif
