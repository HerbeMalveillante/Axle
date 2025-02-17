
#include "Math/Vector2.h"

namespace Axle::Math {

    Vector2::Vector2( const float x, const float y) {
        this->x = x;
        this->y = y;
    }

    Vector2::Vector2() {
        this->x = 0.0f;
        this->y = 0.0f;
    }


    float Vector2::getX() const {
        return x;
    }

    float Vector2::getY() const {
        return y;
    }

    void Vector2::setX( const float x) {
        this->x = x;
    }

    void Vector2::setY( const float y) {
        this->y = y;
    }

}
