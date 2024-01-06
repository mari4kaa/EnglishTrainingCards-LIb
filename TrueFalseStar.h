#ifndef TRUEFALSESTAR_H
#define TRUEFALSESTAR_H

#pragma once
#include "TrueFalseDialog.h"
#include "StarShape.h"

class MYLIB_API TrueFalseStar : public TrueFalseDialog
{
private:
    StarShape starManage;
public:
    TrueFalseStar();
    ~TrueFalseStar();
    int Show(HWND parent, list<wstring> data);
    static INT_PTR CALLBACK DlgTrueFalseStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif