#ifndef AXLE_MAT3_HPP
#define AXLE_MAT3_HPP

#include <array>
#include <string>

namespace Axle::Math {
class Mat3 {
private:
  // Column-major ordering
  std::array<float, 9> data;

public:
  // ╔══════════════════════════════════╗
  // ║ -> Constructors
  // ╚══════════════════════════════════╝

  Mat3();
  Mat3( float diagonal );
  Mat3( const Mat3& other ) = default;
  ~Mat3() = default;

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
  [[nodiscard]] Mat3 transposed() const;
  [[nodiscard]] Mat3 inverted() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operators
  // ╚══════════════════════════════════╝

  // copy assignment operator
  Mat3& operator=( const Mat3& other ) = default;

  // Scalar operators
  Mat3 operator*( float scalar ) const;
  Mat3 operator/( float scalar ) const;
  Mat3 operator-() const;

  // Scalar assignment operators
  Mat3& operator*=( float scalar );
  Mat3& operator/=( float scalar );

  // Left scalar operators
  friend Mat3 operator*( float scalar, const Mat3& mat );

  // Matrix operators
  Mat3 operator+( const Mat3& other ) const;
  Mat3 operator-( const Mat3& other ) const;
  Mat3 operator*( const Mat3& other ) const;

  // Matrix assignment operators
  Mat3& operator+=( const Mat3& other );
  Mat3& operator-=( const Mat3& other );
  Mat3& operator*=( const Mat3& other );
};

} // namespace Axle::Math

#endif // AXLE_MAT3_HPP
