#include "Math/Vec3.hpp"
#include "Core/Errors.hpp"
#include <cmath>
#include <string>

namespace Axle::Math {

// ╔══════════════════════════════════╗
// ║ -> Constructors
// ╚══════════════════════════════════╝

Vec3::Vec3() : x( 0.0F ), y( 0.0F ), z( 0.0F ) {}

Vec3::Vec3( float x, float y, float z ) : x( x ), y( y ), z( z ) {}

Vec3::Vec3( float value ) : x( value ), y( value ), z( value ) {}

// ╔══════════════════════════════════╗
// ║ -> Utils
// ╚══════════════════════════════════╝

std::string Vec3::toString() const
{
  return "Vec3(" + std::to_string( x ) + ", " + std::to_string( y ) + ", " +
         std::to_string( z ) + ")";
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

float Vec3::length() const { return sqrt( x * x + y * y + z * z ); }

void Vec3::normalize()
{
  const float len = length();

  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }
  x /= len;
  y /= len;
  z /= len;
}

Vec3 Vec3::normalized() const
{
  const float len = length();
  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }
  return { x / len, y / len, z / len };
}

Vec3 Vec3::dot( const Vec3& other ) const
{
  return { x * other.x, y * other.y, z * other.z };
}

Vec3 Vec3::cross( const Vec3& other ) const
{
  return { y * other.z - z * other.y,
           z * other.x - x * other.z,
           x * other.y - y * other.x };
}

// ╔══════════════════════════════════╗
// ║ -> Operators
// ╚══════════════════════════════════╝

float& Vec3::operator[]( unsigned int index )
{
  switch ( index ) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      throw Core::IndexOutOfBoundsError( 0, 2 );
  }
}

Vec3 Vec3::operator+( float scalar ) const
{
  return { x + scalar, y + scalar, z + scalar };
}

Vec3 Vec3::operator-( float scalar ) const
{
  return { x - scalar, y - scalar, z - scalar };
}

Vec3 Vec3::operator*( float scalar ) const
{
  return { x * scalar, y * scalar, z * scalar };
}

Vec3 Vec3::operator/( float scalar ) const
{
  if ( scalar == 0 ) {
    throw Core::DivisionByZeroError();
  }
  return { x / scalar, y / scalar, z / scalar };
}

Vec3 Vec3::operator-() const { return { -x, -y, -z }; }

Vec3 Vec3::operator+( const Vec3& other ) const
{
  return { x + other.x, y + other.y, z + other.z };
}

Vec3 Vec3::operator-( const Vec3& other ) const
{
  return { x - other.x, y - other.y, z - other.z };
}

} // namespace Axle::Math
