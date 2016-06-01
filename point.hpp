
#ifndef point_hpp
#define point_hpp

#include <stdio.h>


class Point {
protected:
    int x;
    int y;
public:
    Point(): x(1), y(1) {};
    Point(int aX, int aY): x(aX), y(aY) {};
    
    ~Point() {};
    
    friend const Point operator+ (const Point& aLeft, const Point& aRight);
    friend bool        operator==(const Point& aLeft, const Point& aRight);
    friend bool        operator!=(const Point& aLeft, const Point& aRight);
    
    Point& operator=(const Point& aRight) {
        this->x = aRight.x;
        this->y = aRight.y;
        return *this;
    }
    
    int  X();
    void X(int aX);
    int  Y();
    void Y(int aY);
};


#endif 