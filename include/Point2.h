#pragma once
#include <Vector2.h>
namespace Vatnar {
    class Point2 {
    public:
        Point2(double x, double y);
        Point2 get() const;
        void set(double X, double Y);
        double getX() const;
        double getY() const;
        void setX(double X);
        void setY(double Y);

        Point2 operator +(const Vector2 &other) const;
        Point2 operator -(const Vector2 &other) const;
        Point2 &operator+=(const Vector2 & other);
        Point2 &operator-=(const Vector2 & other);

        [[nodiscard]] std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Point2& p);
    private:
        double X = 0;
        double Y = 0;
    };
}
