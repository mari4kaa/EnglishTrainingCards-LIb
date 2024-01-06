#ifndef ONEANSWERSTAR_H
#define ONEANSWERSTAR_H

#pragma once
#include "OneAnswerDialog.h"
#include "StarShape.h"

class MYLIB_API OneAnswerStar : public OneAnswerDialog
{
private:
    StarShape starManage;
public:
    OneAnswerStar();
    ~OneAnswerStar();
    int Show(HWND parent, list<wstring> data);
    static INT_PTR CALLBACK DlgOneAnswerStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif