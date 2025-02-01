#ifndef POINT_2D_H
#define POINT_2D_H
#include <string>
namespace Vatnar {
    class Vector2 {
    public:
        static Vector2 Zero();

        Vector2(double X, double Y);

        Vector2 get() const;
        void set(double X, double Y);

        double getX() const;
        double getY() const;
        void setX(double X);
        void setY(double Y);


        double magnitude() const;

        Vector2 &normalize();
        Vector2 normalized() const;

        // Add or subtract vectors
        Vector2 operator +(const Vector2 &other) const;
        Vector2 operator -(const Vector2 &other) const;
        Vector2 &operator+=(const Vector2 & other);
        Vector2 &operator-=(const Vector2 & other);

        // Scalar operations
        Vector2 operator *(double scalar) const;
        Vector2 operator /(double scalar) const;

        // Dot product
        Vector2 dot(const Vector2 &other) const;
        Vector2 operator *(const Vector2 &other) const;

        // Compare vectors
        bool operator ==(const Vector2 &other) const;
        bool operator !=(const Vector2 &other) const;

        // Returns true if vectors have the same magnitude
        bool operator<(const Vector2 &other) const;
        bool operator>(const Vector2 &other) const;
        explicit operator bool() const;


        [[nodiscard]] std::string toString() const;


    private:
        double X;
        double Y;
    };
}

#endif //POINT_2D_H
