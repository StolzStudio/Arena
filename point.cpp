
#include "point.hpp"


int Point::X() {
    return this->x;
}

void Point::X(int aX) {
    this->x = aX;
}

int Point::Y() {
    return this->y;
}

void Point::Y(int aY) {
    this->y = aY;
}

const Point operator+(const Point& aLeft, const Point& aRight) {
    return Point(aLeft.x + aRight.x, aLeft.y + aRight.y);
}

bool operator==(const Point& aLeft, const Point& aRight) {
    return ((aLeft.x == aRight.x)&&(aLeft.y == aRight.y));
}

bool operator!=(const Point& aLeft, const Point& aRight) {
    return !((aLeft.x == aRight.x)&&(aLeft.y == aRight.y));
}
