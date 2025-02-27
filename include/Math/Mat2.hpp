#ifndef AXLE_MAT2_HPP
#define AXLE_MAT2_HPP

#include "Core/Errors.hpp"
#include <array>

namespace Axle::Math {

class Mat2 {
private:
  // Column-major ordering
  std::array<float, 4> data;

public:
  // ╔══════════════════════════════════╗
  // ║ -> Constructors
  // ╚══════════════════════════════════╝

  Mat2();
  Mat2( float diagonal );

  // ╔══════════════════════════════════╗
  // ║ -> Getters and Setters
  // ╚══════════════════════════════════╝

  float operator()( unsigned int row, unsigned int col );
};

} // namespace Axle::Math

#endif // AXLE_MAT2_HPP
