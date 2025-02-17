#include "Math/Size2.h"

namespace Axle::Math {


    Size2::Size2( const unsigned int width, const unsigned int height) {
        this->width = width;
        this->height = height;
    }

    Size2::Size2() {
        this->width = 0;
        this->height = 0;
    }

    unsigned int Size2::getHeight() const {
        return height;
    }

    unsigned int Size2::getWidth() const {
        return width;
    }

    void Size2::setHeight( const unsigned int height ) {
        this->height = height;
    }

    void Size2::setWidth( const unsigned int width ) {
        this->width = width;
    }








}
