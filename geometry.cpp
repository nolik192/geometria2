#include <cmath>
#include "geometry.h"
using namespace std;

double distance(point A, point B)
{
  return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}


bool is_triangle(point A, point B, point C)
{
  double a = distance(B, C);
  double b = distance(A, C);
  double c = distance(A, B);
  return a + b > c && a + c > b && b + c > a;
}

double area_triangle(point A, point B, point C)
{
    return abs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2.0);
}

double area_polygon(point P[], int n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (P[i].x * P[j].y - P[j].x * P[i].y);
    }
    return abs(area) / 2.0;
}

bool is_inside(point A, point B, point C, point D) 
{
    double total_area = area_triangle(A, B, C);
    double area1 = area_triangle(D, A, B);
    double area2 = area_triangle(D, B, C);
    double area3 = area_triangle(D, C, A);
    return std::abs((area1 + area2 + area3) - total_area) < 1e-9;
}
