#include <iostream>

#include "Vector2.h"

template<typename T, typename... Args>
T sumObject(T first, Args... rest) { return first + (rest + ...); }

int main() {
    Vatnar::Vector2 Velocity = {5, 3};
    Vatnar::Vector2 u        = {1, 2};
    Velocity += u;
    if (Velocity) std::cout << Velocity.normalize().magnitude();


    return 0;
}
