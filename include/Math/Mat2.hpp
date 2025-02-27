#ifndef AXLE_MAT2_HPP
#define AXLE_MAT2_HPP

#include <array>

namespace Axle::Math {

class Mat2 {
private:
  // Column-major ordering
  std::array<float, 4> data;

public:
  Mat2();
  Mat2( float diagonal );
};

} // namespace Axle::Math

#endif // AXLE_MAT2_HPP
