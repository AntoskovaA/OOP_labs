#ifndef LAB_2_H
#define LAB_2_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    double Area();
    bool IsSingular();
    bool IsContains(Point P);
};

double Length(Point p1, Point p2);

double VectorDob (Point A, Point B, Point P);

#endif