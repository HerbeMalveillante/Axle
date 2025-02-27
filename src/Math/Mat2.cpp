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
  if ( det == 0.0F ) {
    throw Core::MatrixNonInvertibleError();
  }
}

} // namespace Axle::Math
