#ifndef AXLE_VECTOR_H
#define AXLE_VECTOR_H

namespace Axle::Math {

// Vector is the base class for all vector types.
// It enables reuse of common vector operations.
class Vector {
private:
  float data[4];
  unsigned int components;
};

} // namespace Axle::Math

#endif // AXLE_VECTOR_H
