#ifndef AXLE_VEC3_HPP
#define AXLE_VEC3_HPP

#include <string>

namespace Axle::Math {

class Vec3 {

public:
  float x, y, z;

  // ╔══════════════════════════════════╗
  // ║ -> Constructors
  // ╚══════════════════════════════════╝

  Vec3();
  Vec3( float x, float y, float z );
  Vec3( float value );
  Vec3( const Vec3& other ) = default;
  ~Vec3() = default;

  // ╔══════════════════════════════════╗
  // ║ -> Utils
  // ╚══════════════════════════════════╝

  [[nodiscard]] std::string toString() const;

  // ╔══════════════════════════════════╗
  // ║ -> Operations
  // ╚══════════════════════════════════╝

  void normalize();
  [[nodiscard]] Vec3 normalized() const;
  [[nodiscard]] float length() const;
  [[nodiscard]] Vec3 dot( const Vec3& other ) const;
  [[nodiscard]] Vec3 cross( const Vec3& other ) const;

  // ╔══════════════════════════════════╗
  // ║ -> Operators
  // ╚══════════════════════════════════╝

  // subscript operator
  float& operator[]( unsigned int index );

  // copy assignment operator
  Vec3& operator=( const Vec3& other ) = default;

  // Scalar operations
  Vec3 operator+( float scalar ) const;
  Vec3 operator-( float scalar ) const;
  Vec3 operator*( float scalar ) const;
  Vec3 operator/( float scalar ) const;
  Vec3 operator-() const;

  // Vec3 operations
  Vec3 operator+( const Vec3& other ) const;
  Vec3 operator-( const Vec3& other ) const;
};
} // namespace Axle::Math

#endif
