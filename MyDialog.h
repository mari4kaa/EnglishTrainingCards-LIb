#pragma once
#include "resource1.h"
#include <Windows.h>
#include <list>
#include <string>
using namespace std;

class MyDialog {
public:
    virtual ~MyDialog() {};
    virtual void Show(HWND parent, HINSTANCE parentInst, list<wstring> data) = 0;
};
