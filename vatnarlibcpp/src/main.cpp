#include <iostream>

#include "Circle2D.h"
#include "Point2D.h"
// Fix memory ownership of circle.
int main() {
    // Point2D point(4.2414125, 22.4215134);
    auto p = Point2D(3, 4);
    auto q = Point2D(3, 4);
    auto c = Circle2D(p, q);

    std::cout << c.toString() << std::endl;

    p = Point2D::Zero();
    std::cout << c.toString() << std::endl;

    return 0;

}
