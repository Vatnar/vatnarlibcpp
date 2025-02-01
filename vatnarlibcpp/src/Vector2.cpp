#include "Point2D.h"
#include <cmath>

Vector2 Vector2::Zero() { return {0, 0}; }

Vector2::Vector2(const double X = 0, const double Y = 0)
    : X(X), Y(Y) {}

Vector2 Vector2::get() const { return {X, Y}; }

void Vector2::set(const double X, const double Y) {
    this->X = X;
    this->Y = Y;
}

double Vector2::getX() const { return X; }

double Vector2::getY() const { return Y; }

void Vector2::setX(const double X) { this->X = X; }

void Vector2::setY(const double Y) { this->Y = Y; }

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {this->X + other.X, this->Y + other.Y};
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {this->X - other.X, this->Y - other.Y};
}

bool Vector2::operator==(const Vector2 &other) const {
    if (this->X == other.X && this->Y == other.Y) { return true; }
    return false;
}

bool Vector2::operator!=(const Vector2 &other) const {
    if (this->X != other.X || this->Y != other.Y) { return true; }
    return false;
}

double Vector2::distance(const Vector2 &other) const {
    return std::sqrt(
        std::pow(this->X - other.X, 2) + std::pow(this->Y - other.Y, 2));
}

std::string Vector2::toString() const {
    std::string result = "Vector2(" + std::to_string(X) + ", " + std::to_string(
                             Y) + ")";
    return result;
}
