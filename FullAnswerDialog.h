#pragma once
#include "MyDialog.h"

class FullAnswerDialog : public virtual MyDialog
{
private:
    static wstring word;
    static wstring definition;

    static HWND hDefinitionLabel;
    static HWND hWordTextBox;

public:
    FullAnswerDialog();
    ~FullAnswerDialog();
    static void OnInitDialog(HWND hDlg);
    void Show(HWND parent, HINSTANCE parentInst, list<wstring> data);
    static void OnSubmit();
};