#ifndef MYDIALOG_H
#define MYDIALOG_H

#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define MYLIB_API __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif

#pragma once
#include "framework.h"
#include "resource1.h"
#include <Windows.h>
#include <list>
#include <string>
using namespace std;
EXPIMP_TEMPLATE template class MYLIB_API std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;

class MYLIB_API MyDialog {
public:
    int result;
    virtual ~MyDialog() {};
    virtual void OnInitDialog(HWND hDlg) = 0;
    virtual int Show(HWND parent, list<wstring> data) = 0;
    virtual void OnSubmit(wstring buttonAnsw = L"") = 0;
};

#endif