#ifndef AXLE_MAT2_HPP
#define AXLE_MAT2_HPP

#include "Core/Errors.hpp"
#include <array>
#include <string>

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
  Mat2( const Mat2& other ) = default;
  ~Mat2() = default;

  // ╔══════════════════════════════════╗
  // ║ -> Getters and Setters
  // ╚══════════════════════════════════╝

  float& at( unsigned int row, unsigned int col );
  [[nodiscard]] float at( unsigned int row, unsigned int col ) const;

  // ╔══════════════════════════════════╗
  // ║ -> Utils
  // ╚══════════════════════════════════╝

  [[nodiscard]] std::string toString() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operations
  // ╚══════════════════════════════════╝

  [[nodiscard]] float det() const;
  void setIdentity();
  void transpose();
  void invert();
  [[nodiscard]] Mat2 transposed() const;
  [[nodiscard]] Mat2 inverted() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operators
  // ╚══════════════════════════════════╝

  // scalar multiplication
  Mat2 operator*( float scalar ) const;
  Mat2& operator*=( float scalar );
};

} // namespace Axle::Math

#endif // AXLE_MAT2_HPP
