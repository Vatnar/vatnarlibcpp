#ifndef POINT_2D_H
#define POINT_2D_H
#include <string>

class Point2D {
public:
    static Point2D Zero();
    Point2D(double x, double y);
    Point2D operator + (const Point2D &other) const;
    bool operator == (const Point2D &other) const;
    double distance(const Point2D &other) const;

    [[nodiscard]] std::string toString() const;

public:
    double x;
    double y;
};



#endif //POINT_2D_H
