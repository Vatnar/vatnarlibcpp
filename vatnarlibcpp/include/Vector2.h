#ifndef POINT_2D_H
#define POINT_2D_H
#include <string>

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

    double distance(const Vector2 &other) const;
    double magnitude() {
        return {}
    }
    // Add or subtract points
    Vector2 operator +(const Vector2 &other) const;
    Vector2 operator -(const Vector2 &other) const;

    // Compare points
    bool operator ==(const Vector2 &other) const;
    bool operator !=(const Vector2 &other) const;



    [[nodiscard]] std::string toString() const;

private:
    double X;
    double Y;
};


#endif //POINT_2D_H
