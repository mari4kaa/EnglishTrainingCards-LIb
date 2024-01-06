#include "StarShape.h"

StarShape::StarShape() {};
StarShape::~StarShape() {};

HRGN StarShape::CreateStarRegion(int cx, int cy, int outerRadius, int innerRadius, int numPoints)
{
    double angleDelta = 2 * M_PI / numPoints;
    std::vector<POINT> rgnPoints;

    for (int i = 0; i < numPoints; ++i)
    {
        double outerX = cx + outerRadius * cos(i * angleDelta);
        double outerY = cy + outerRadius * sin(i * angleDelta);
        POINT outerPoint = { (int)outerX, (int)outerY };

        double innerX = cx + innerRadius * cos((i + 0.5) * angleDelta);
        double innerY = cy + innerRadius * sin((i + 0.5) * angleDelta);
        POINT innerPoint = { (int)innerX, (int)innerY };

        rgnPoints.push_back(outerPoint);
        rgnPoints.push_back(innerPoint);
    }
    HRGN hRgn = CreatePolygonRgn(&rgnPoints[0], rgnPoints.size(), WINDING);
    return hRgn;
}

void StarShape::SetStarRegion(HWND hWnd, int numPoints)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    int cx = (clientRect.left + clientRect.right) / 2;
    int cy = (clientRect.top + clientRect.bottom) / 2;
    int height = (clientRect.bottom - clientRect.top) / 2;
    int width = (clientRect.right - clientRect.left) / 2;

    HRGN hRgn = CreateStarRegion(cx, cy, min(height, width), min(height, width) * 0.7, numPoints);
    int result = SetWindowRgn(hWnd, hRgn, TRUE);
    DeleteObject(hRgn);
}
