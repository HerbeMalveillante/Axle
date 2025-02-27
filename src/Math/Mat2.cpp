#include "Math/Mat2.hpp"
#include "Core/Errors.hpp"
#include <array>
#include <string>

namespace Axle::Math {

// ╔══════════════════════════════════╗
// ║ -> Constructors
// ╚══════════════════════════════════╝

Mat2::Mat2() : data { 1.0F, 0.0F, 0.0F, 1.0F } {}

Mat2::Mat2( float diagonal ) : data { diagonal, 0.0F, 0.0F, diagonal } {}

// ╔══════════════════════════════════╗
// ║ -> Getters and setters
// ╚══════════════════════════════════╝

float& Mat2::at( unsigned int row, unsigned int col )
{
  if ( row > 1 || col > 1 ) {
    throw Core::IndexOutOfBoundsError( 0, 1 );
  }
  return data.at( row * 2 + col );
}

[[nodiscard]] float Mat2::at( unsigned int row, unsigned int col ) const
{
  if ( row > 1 || col > 1 ) {
    throw Core::IndexOutOfBoundsError( 0, 1 );
  }
  return data.at( row * 2 + col );
}

// ╔══════════════════════════════════╗
// ║ -> Utils
// ╚══════════════════════════════════╝

std::string Mat2::toString() const
{
  std::string result = "Matrix 2x2:\n";

  result += std::to_string( data.at( 0 ) ) + " " +
            std::to_string( data.at( 1 ) ) + "\n";
  result +=
      std::to_string( data.at( 2 ) ) + " " + std::to_string( data.at( 3 ) );
  return result;
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

float Mat2::det() const
{
  return data.at( 0 ) * data.at( 3 ) - data.at( 1 ) * data.at( 2 );
}

void Mat2::setIdentity() { data = { 1.0F, 0.0F, 0.0F, 1.0F }; }

void Mat2::transpose() { std::swap( data.at( 1 ), data.at( 2 ) ); }

void Mat2::invert()
{
  float det = this->det();
  if ( det == 0 ) {
    throw Core::MatrixNonInvertibleError();
  }
  float invDet = 1.0F / det;

  std::swap( data.at( 0 ), data.at( 3 ) );
  data.at( 1 ) = -data.at( 1 );
  data.at( 2 ) = -data.at( 2 );

  *this *= invDet;
}

Mat2 Mat2::transposed() const
{
  Mat2 result( *this );
  result.transpose();
  return result;
}

Mat2 Mat2::inverted() const
{
  Mat2 result( *this );
  result.invert();
  return result;
}

// ╔══════════════════════════════════╗
// ║ -> Operators
// ╚══════════════════════════════════╝

Mat2 Mat2::operator*( float scalar ) const
{
  Mat2 result;
  for ( unsigned int i = 0; i < 4; i++ ) {
    result.data.at( i ) = data.at( i ) * scalar;
  }
  return result;
}

Mat2 Mat2::operator/( float scalar ) const
{
  if ( scalar == 0.0F ) {
    throw Core::DivisionByZeroError();
  }
  Mat2 result;
  for ( unsigned int i = 0; i < 4; i++ ) {
    result.data.at( i ) = data.at( i ) / scalar;
  }
  return result;
}

Mat2 Mat2::operator-() const
{
  Mat2 result;
  for ( unsigned int i = 0; i < 4; i++ ) {
    result.data.at( i ) = -data.at( i );
  }
  return result;
}

Mat2& Mat2::operator*=( float scalar )
{
  for ( unsigned int i = 0; i < 4; i++ ) {
    data.at( i ) *= scalar;
  }
  return *this;
}

Mat2& Mat2::operator/=( float scalar )
{
  if ( scalar == 0.0F ) {
    throw Core::DivisionByZeroError();
  }
  for ( unsigned int i = 0; i < 4; i++ ) {
    data.at( i ) /= scalar;
  }
  return *this;
}

Mat2 operator*( float scalar, const Mat2& mat ) { return mat * scalar; }

Mat2 Mat2::operator+( const Mat2& other ) const
{
  Mat2 result;
  for ( unsigned int i = 0; i < 4; i++ ) {
    result.data.at( i ) = data.at( i ) + other.data.at( i );
  }
  return result;
}

Mat2 Mat2::operator-( const Mat2& other ) const
{
  Mat2 result;
  for ( unsigned int i = 0; i < 4; i++ ) {
    result.data.at( i ) = data.at( i ) - other.data.at( i );
  }
  return result;
}

Mat2 Mat2::operator*( const Mat2& other ) const
{
  Mat2 result;
  result.data.at( 0 ) =
      data.at( 0 ) * other.data.at( 0 ) + data.at( 1 ) * other.data.at( 2 );
  result.data.at( 1 ) =
      data.at( 0 ) * other.data.at( 1 ) + data.at( 1 ) * other.data.at( 3 );
  result.data.at( 2 ) =
      data.at( 2 ) * other.data.at( 0 ) + data.at( 3 ) * other.data.at( 2 );
  result.data.at( 3 ) =
      data.at( 2 ) * other.data.at( 1 ) + data.at( 3 ) * other.data.at( 3 );
  return result;
}

Mat2& Mat2::operator+=( const Mat2& other )
{
  for ( unsigned int i = 0; i < 4; i++ ) {
    data.at( i ) += other.data.at( i );
  }
  return *this;
}

Mat2& Mat2::operator-=( const Mat2& other )
{
  for ( unsigned int i = 0; i < 4; i++ ) {
    data.at( i ) -= other.data.at( i );
  }
  return *this;
}

Mat2& Mat2::operator*=( const Mat2& other )
{
  Mat2 result;
  result.data.at( 0 ) =
      data.at( 0 ) * other.data.at( 0 ) + data.at( 1 ) * other.data.at( 2 );
  result.data.at( 1 ) =
      data.at( 0 ) * other.data.at( 1 ) + data.at( 1 ) * other.data.at( 3 );
  result.data.at( 2 ) =
      data.at( 2 ) * other.data.at( 0 ) + data.at( 3 ) * other.data.at( 2 );
  result.data.at( 3 ) =
      data.at( 2 ) * other.data.at( 1 ) + data.at( 3 ) * other.data.at( 3 );
  *this = result;
  return *this;
}

} // namespace Axle::Math
