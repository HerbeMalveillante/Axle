#ifndef AXLE_VEC4_HPP
#define AXLE_VEC4_HPP

#include <string>

namespace Axle::Math {

class Vec4 {
public:
  float x, y, z, w;

  // ╔══════════════════════════════════╗
  // ║ -> Constructors
  // ╚══════════════════════════════════╝

  Vec4();
  Vec4( float x, float y, float z, float w );
  Vec4( float value );
  Vec4( const Vec4& other ) = default;
  ~Vec4() = default;

  // ╔══════════════════════════════════╗
  // ║ -> Utils
  // ╚══════════════════════════════════╝

  [[nodiscard]] std::string toString() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operations
  // ╚══════════════════════════════════╝

  void normalize();
  [[nodiscard]] Vec4 normalized() const;
  [[nodiscard]] float length() const;
  [[nodiscard]] Vec4 dot( const Vec4& other ) const;

  // ╔══════════════════════════════════╗
  // ║ -> Operators
  // ╚══════════════════════════════════╝

  // copy assignment operator
  Vec4& operator=( const Vec4& other ) = default;

  // Scalar operations
  Vec4 operator*( float scalar ) const;
  Vec4 operator/( float scalar ) const;
  Vec4 operator-() const;

  // Scalar assignment operations
  Vec4& operator*=( float scalar );
  Vec4& operator/=( float scalar );

  // Left scalar operations
  friend Vec4 operator*( float scalar, const Vec4& vec );

  // Vec4 operations
  Vec4 operator+( const Vec4& other ) const;
  Vec4 operator-( const Vec4& other ) const;
};

} // namespace Axle::Math

#endif // AXLE_VEC4_HPP
