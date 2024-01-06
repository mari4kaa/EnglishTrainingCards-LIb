#ifndef STARSHAPE_H
#define STARSHAPE_H

#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define MYLIB_API __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif

#pragma once
#include "framework.h"
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

class MYLIB_API StarShape
{
private:
    HRGN CreateStarRegion(int cx, int cy, int outerRadius, int innerRadius, int numPoints);
public:
    StarShape();
    ~StarShape();
    void SetStarRegion(HWND hWnd, int numPoints);
};

#endif