#include "Point2.h"
#include "Vector2.h"
#include <sstream>
namespace Vatnar{
Point2 Point2::get() const { return {X, Y}; }
Point2::Point2(double x, double y) : X(x), Y(y) {}

void Point2::set(const double X, const double Y) {
    this->X = X;
    this->Y = Y;
}

double Point2::getX() const { return X; }
double Point2::getY() const { return Y; }

void Point2::setX(const double X) { this->X = X; }
void Point2::setY(const double Y) { this->Y = Y; }



Point2 Point2::operator+(const Vector2 &other) const {
    return {this->X + other.getX(), this->Y + other.getX()};
}

Point2 Point2::operator-(const Vector2 &other) const {
    return {this->X - other.getX(), this->Y - other.getY()};
}

Point2 & Point2::operator+=(const Vector2 &other) {
    setX(this->X + other.getX());
    setY(this->Y + other.getY());
    return *this;
}

Point2 & Point2::operator-=(const Vector2 &other) {

    setX(getX() + other.getX());
    setY(getY() + other.getY());
    return *this;
}

std::string Point2::toString() const {

        std::ostringstream oss;
        oss << "Point2(" << getX() << ", " << getY() << ")";
        return oss.str();
}
std::ostream& operator<<(std::ostream& os, const Point2& p) {
    return os << p.toString();
}
}
