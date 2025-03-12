#include <iostream>
#include <cmath>
#include "some.h"
using namespace std;

double Length(Point p1, Point p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

double Triangle::Area(){
    double a = Length(A, B);
    double b = Length(B, C);
    double c = Length(A, C);

    double piv = (a + b + c) / 2;
    return sqrt(piv * (piv - a) * (piv - b) * (piv - c));
}

bool Triangle::IsSingular() {
    if (Area() == 0) 
        return true;
    else  return false; } 


double VectorDob (Point A, Point B, Point P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}    

bool Triangle::IsContains(Point P) {
    double v_a = VectorDob(A, B, P);
    double v_b = VectorDob(B, C, P);
    double v_c = VectorDob(C, A, P);

    if ((v_a >= 0 && v_b >= 0 && v_c >= 0) || (v_a < 0 && v_b < 0 && v_c < 0)) {
        return true;
    }

    else { return false; }
}