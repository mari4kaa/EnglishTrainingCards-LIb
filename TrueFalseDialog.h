#pragma once
#include "MyDialog.h"

class TrueFalseDialog : public virtual MyDialog
{
private:
    static wstring word;
    static wstring definition;
    static wstring answer;

    static HWND hDefinitionLabel;
    static HWND hWordLabel;
public:
    TrueFalseDialog();
    ~TrueFalseDialog();
    static void OnInitDialog(HWND hDlg);
    void Show(HWND parent, HINSTANCE parentInst, list<wstring> data);
    static void OnSubmit(wstring buttonAnsw);
};
