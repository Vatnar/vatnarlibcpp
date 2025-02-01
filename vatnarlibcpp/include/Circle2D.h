#ifndef CIRCLE2D_H
#define CIRCLE2D_H
#include <string>

#include "Point2D.h"


class Circle2D {
public:
    Circle2D(const Vector2 &center, double radius);
    // Is currently non-responsive to change of perimeter.
    Circle2D(const Vector2 &center, const Vector2 &perimeter);
    [[nodiscard]] std::string toString() const;
    const Vector2 &center;
    double radius;
};



#endif //CIRCLE2D_H
