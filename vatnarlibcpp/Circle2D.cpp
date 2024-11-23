//
// Created by Peter on 23/11/2024.
//

#include "Circle2D.h"

Circle2D::Circle2D( const Point2D &center,  const double radius): center(center), radius(radius){}

Circle2D::Circle2D( const Point2D &center, const Point2D &perimeter): center(center), radius(center.distance(perimeter)){}


std::string Circle2D::toString() const {
    std::string result = "Circle2D(Center: " + center.toString() + ", Radius: double(" + std::to_string(this->radius) + "))"; ;
    return result;
}
