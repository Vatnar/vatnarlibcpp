#include <cmath>
#include "Point2D.h"

Point2D Point2D::Zero() {return {0, 0};}

Point2D::Point2D(const double x, const double y): x(x), y(y) {}

Point2D Point2D::operator+(const Point2D &other) const {
	return {this->x + other.x, this->y + other.y};
}

bool Point2D::operator==(const Point2D &other) const {
	if (this->x == other.x && this->y == other.y) {
		return true;
	}
	return false;
}

double Point2D::distance(const Point2D &other) const {
	return sqrt(this->x * this->x + this->y * this->y);
}

std::string Point2D::toString() const {
	std::string result = "Point2D(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	return result;
}
