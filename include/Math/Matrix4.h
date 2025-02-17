

#ifndef MATRIX4_H
#define MATRIX4_H

namespace Axle::Math {

    class Matrix4 {

    private:
        float m0, m4, m8, m12; // First row
        float m1, m5, m9, m13; // Second row
        float m2, m6, m10, m14; // Third row
        float m3, m7, m11, m15; // Fourth row
    public:
        // Constructor : Identity matrix
        Matrix4();
    };
}


#endif //MATRIX4_H
