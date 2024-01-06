#ifndef FULLANSWERSTAR_H
#define FULLANSWERSTAR_H

#pragma once
#include "FullAnswerDialog.h"
#include "StarShape.h"

class MYLIB_API FullAnswerStar : public FullAnswerDialog
{
private:
    StarShape starManage;
public:
    FullAnswerStar();
    ~FullAnswerStar();
    int Show(HWND parent, list<wstring> data);
    static INT_PTR CALLBACK DlgFullStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif