#ifndef AXLE_VEC2_HPP
#define AXLE_VEC2_HPP

#include <string>

namespace Axle::Math {

class Vec2 {

public:
  float x, y;

  // ╔══════════════════════════════════╗
  // ║ -> Constructors
  // ╚══════════════════════════════════╝

  Vec2();
  Vec2( float x, float y );
  Vec2( float value );
  Vec2( const Vec2& other ) = default;
  ~Vec2() = default;

  // ╔══════════════════════════════════╗
  // ║ -> Utils
  // ╚══════════════════════════════════╝

  [[nodiscard]] std::string toString() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operations
  // ╚══════════════════════════════════╝

  void normalize();
  [[nodiscard]] Vec2 normalized() const;
  [[nodiscard]] float length() const;
  [[nodiscard]] Vec2 dot( const Vec2& other ) const;

  // ╔══════════════════════════════════╗
  // ║ -> Operators
  // ╚══════════════════════════════════╝

  // copy assignment operator
  Vec2& operator=( const Vec2& other ) = default;

  // Scalar operations
  Vec2 operator*( float scalar ) const;
  Vec2 operator/( float scalar ) const;
  Vec2 operator-() const;

  // Scalar assignment operations
  Vec2& operator*=( float scalar );
  Vec2& operator/=( float scalar );

  // Left scalar operations
  friend Vec2 operator*( float scalar, const Vec2& vec );

  // Vec2 operations
  Vec2 operator+( const Vec2& other ) const;
  Vec2 operator-( const Vec2& other ) const;
};

} // namespace Axle::Math

#endif // AXLE_VEC2_HPP
