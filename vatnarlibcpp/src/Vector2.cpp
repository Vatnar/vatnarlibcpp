#include "Vector2.h"
#include <cmath>
#include <iostream>
using namespace Vatnar;
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

Vector2 & Vector2::operator+=(const Vector2 &other) {
    setX(this->X + other.X);
    setY(this->Y + other.Y);
    return *this;
}

Vector2 & Vector2::operator-=(const Vector2 &other) {
    setX(this->X + other.X);
    setY(this->Y + other.Y);
    return *this;
}

Vector2 Vector2::operator*(const double scalar) const {
    return {this->X * scalar, this->Y * scalar};
}

Vector2 Vector2::operator/(const double scalar) const {
    return {this->X / scalar, this->Y / scalar};
}

Vector2 Vector2::dot(const Vector2 &other) const {
    return {this->X * other.X, this->Y * other.Y};
}

Vector2 Vector2::operator*(const Vector2 &other) const {
    return this->dot(other);
}

bool Vector2::operator==(const Vector2 &other) const {
    if (this->X == other.X && this->Y == other.Y) { return true; }
    return false;
}

bool Vector2::operator!=(const Vector2 &other) const {
    if (this->X != other.X || this->Y != other.Y) { return true; }
    return false;
}

bool Vector2::operator<(const Vector2 &other) const {
    if (this->magnitude() < other.magnitude()) { return true; }
    return false;
}
bool Vector2::operator>(const Vector2 &other) const {
    if (this->magnitude() > other.magnitude()) { return true; }
    return false;
}

Vector2::operator bool() const {
    return magnitude() != 0.0;
}


double Vector2::magnitude() const {
    return std::sqrt(this->getX() * this->getX() + this->getY() * this->getY());
}

Vector2 &Vector2::normalize() { // Not correct
    double len = magnitude();
    if (len == 0.0) {
        std::cout << "Cant normalize, length is 0";
        return *this;
    }
    setY(getY()/len);
    setX(getX()/len);
    return *this;
}
Vector2 Vector2::normalized() const {
    Vector2 temp = *this;
    temp.normalize();
    return temp;
}

std::string Vector2::toString() const {
    std::string result = "Vector2(" + std::to_string(X) + ", " + std::to_string(
                             Y) + ")";
    return result;
}
