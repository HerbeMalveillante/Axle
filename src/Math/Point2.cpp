
#include "Math/Point2.h"


namespace Axle::Math {

    Point2::Point2( const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    Point2::Point2() {
        this->x = 0;
        this->y = 0;
    }

    int Point2::getX() const {
        return x;
    }

    int Point2::getY() const {
        return y;
    }

    void Point2::setX( const int x ) {
        this->x = x;
    }

    void Point2::setY( const int y) {
        this->y = y;
    }








}
