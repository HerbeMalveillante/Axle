#include "Math/Vec4.hpp"
#include "Core/Errors.hpp"
#include <cmath>
#include <string>

namespace Axle::Math {

// ╔══════════════════════════════════╗
// ║ -> Constructors
// ╚══════════════════════════════════╝

Vec4::Vec4() : x( 0.0F ), y( 0.0F ), z( 0.0F ), w( 0.0F ) {}

Vec4::Vec4( float x, float y, float z, float w )
    : x( x ), y( y ), z( z ), w( w )
{
}

Vec4::Vec4( float value ) : x( value ), y( value ), z( value ), w( value ) {}

// ╔══════════════════════════════════╗
// ║ -> Utils
// ╚══════════════════════════════════╝

std::string Vec4::toString() const
{
  return "Vec4(" + std::to_string( x ) + ", " + std::to_string( y ) + ", " +
         std::to_string( z ) + ", " + std::to_string( w ) + ")";
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

float Vec4::length() const { return sqrt( x * x + y * y + z * z + w * w ); }

void Vec4::normalize()
{
  const float len = length();
  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }
  x /= len;
  y /= len;
  z /= len;
  w /= len;
}

Vec4 Vec4::normalized() const
{
  const float len = length();
  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }
  return { x / len, y / len, z / len, w / len };
}

Vec4 Vec4::dot( const Vec4& other ) const
{
  return { x * other.x, y * other.y, z * other.z, w * other.w };
}

// ╔══════════════════════════════════╗
// ║ -> Operators
// ╚══════════════════════════════════╝

float& Vec4::operator[]( unsigned int index )
{
  switch ( index ) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    case 3:
      return w;
    default:
      throw Core::IndexOutOfBoundsError( 0, 3 );
  }
}

Vec4 Vec4::operator+( float scalar ) const
{
  return { x + scalar, y + scalar, z + scalar, w + scalar };
}

Vec4 Vec4::operator-( float scalar ) const
{
  return { x - scalar, y - scalar, z - scalar, w - scalar };
}

Vec4 Vec4::operator*( float scalar ) const
{
  return { x * scalar, y * scalar, z * scalar, w * scalar };
}

Vec4 Vec4::operator/( float scalar ) const
{
  if ( scalar == 0 ) {
    throw Core::DivisionByZeroError();
  }
  return { x / scalar, y / scalar, z / scalar, w / scalar };
}

Vec4 Vec4::operator-() const { return { -x, -y, -z, -w }; }

Vec4 Vec4::operator+( const Vec4& other ) const
{
  return { x + other.x, y + other.y, z + other.z, w + other.w };
}

Vec4 Vec4::operator-( const Vec4& other ) const
{
  return { x - other.x, y - other.y, z - other.z, w - other.w };
}

} // namespace Axle::Math
