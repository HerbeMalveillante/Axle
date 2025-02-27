
#include "Math/Vec2.hpp"
#include "Core/Errors.hpp"
#include <cmath>
#include <string>

namespace Axle::Math {

// ╔══════════════════════════════════╗
// ║ -> Constructors
// ╚══════════════════════════════════╝

Vec2::Vec2() : x( 0.0F ), y( 0.0F ) {}

Vec2::Vec2( float x, float y ) : x( x ), y( y ) {}

Vec2::Vec2( float value ) : x( value ), y( value ) {}

// ╔══════════════════════════════════╗
// ║ -> Utils
// ╚══════════════════════════════════╝

std::string Vec2::toString() const
{
  return "Vec2(" + std::to_string( x ) + ", " + std::to_string( y ) + ")";
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

float Vec2::length() const { return sqrt( x * x + y * y ); }

void Vec2::normalize()
{
  const float len = length();

  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }

  x /= len;
  y /= len;
}

Vec2 Vec2::normalized() const
{
  const float len = length();
  // Check if the length is zero
  if ( len == 0 ) {
    throw Core::DivisionByZeroError( "Cannot normalize a null vector." );
  }

  return { x / len, y / len };
}

Vec2 Vec2::dot( const Vec2& other ) const
{
  return { x * other.x, y * other.y };
}

// ╔══════════════════════════════════╗
// ║ -> Operators
// ╚══════════════════════════════════╝

float& Vec2::operator[]( unsigned int index )
{
  switch ( index ) {
    case 0:
      return x;
    case 1:
      return y;
    default:
      throw Core::IndexOutOfBoundsError( 0, 1 );
  }
}

Vec2 Vec2::operator+( float scalar ) const
{
  return { x + scalar, y + scalar };
}

Vec2 Vec2::operator-( float scalar ) const
{
  return { x - scalar, y - scalar };
}

Vec2 Vec2::operator*( float scalar ) const
{
  return { x * scalar, y * scalar };
}

Vec2 Vec2::operator/( float scalar ) const
{
  if ( scalar == 0 ) {
    throw Core::DivisionByZeroError();
  }
  return { x / scalar, y / scalar };
}

Vec2 Vec2::operator-() const { return { -x, -y }; }

Vec2 Vec2::operator+( const Vec2& other ) const
{
  return { x + other.x, y + other.y };
}

Vec2 Vec2::operator-( const Vec2& other ) const
{
  return { x - other.x, y - other.y };
}

} // namespace Axle::Math
