#include <iostream>

#include "Circle2D.h"
#include "Point2D.h"

template<typename T, typename... Args>
T sumObject(T first, Args... rest) {
    return first + (rest + ...);
}

int main() {



    return 0;

}
