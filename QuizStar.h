#ifndef QUIZSTAR_H
#define QUIZSTAR_H

#pragma once
#include "QuizDialog.h"
#include "StarShape.h"

class MYLIB_API QuizStar : public QuizDialog
{
private:
    StarShape starManage;
public:
    QuizStar();
    ~QuizStar();
    int Show(HWND parent, list<wstring> data);
    static INT_PTR CALLBACK DlgQuizStar(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif