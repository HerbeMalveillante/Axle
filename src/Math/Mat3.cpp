#include "Math/Mat3.hpp"
#include "Core/Errors.hpp"
#include <array>
#include <string>

namespace Axle::Math {

// ╔══════════════════════════════════╗
// ║ -> Constructors
// ╚══════════════════════════════════╝

Mat3::Mat3() : data { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F } {}
Mat3::Mat3( float diagonal )
    : data { diagonal, 0.0F, 0.0F, 0.0F, diagonal, 0.0F, 0.0F, 0.0F, diagonal }
{
}

// ╔══════════════════════════════════╗
// ║ -> Getters and setters
// ╚══════════════════════════════════╝

float& Mat3::at( unsigned int row, unsigned int col )
{
  if ( row > 2 || col > 2 ) {
    throw Core::IndexOutOfBoundsError( 0, 2 );
  }
  return data.at( row * 3 + col );
}

[[nodiscard]] float Mat3::at( unsigned int row, unsigned int col ) const
{
  if ( row > 2 || col > 2 ) {
    throw Core::IndexOutOfBoundsError( 0, 2 );
  }
  return data.at( row * 3 + col );
}

// ╔══════════════════════════════════╗
// ║ -> Utils
// ╚══════════════════════════════════╝

std::string Mat3::toString() const
{
  std::string result = "Matrix 3x3:\n";

  result += std::to_string( data.at( 0 ) ) + " " +
            std::to_string( data.at( 1 ) ) + " " +
            std::to_string( data.at( 2 ) ) + "\n";
  result += std::to_string( data.at( 3 ) ) + " " +
            std::to_string( data.at( 4 ) ) + " " +
            std::to_string( data.at( 5 ) ) + "\n";
  result += std::to_string( data.at( 6 ) ) + " " +
            std::to_string( data.at( 7 ) ) + " " +
            std::to_string( data.at( 8 ) );
  return result;
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

float Mat3::det() const
{
  return data.at( 0 ) *
             ( data.at( 4 ) * data.at( 8 ) - data.at( 5 ) * data.at( 7 ) ) -
         data.at( 1 ) *
             ( data.at( 3 ) * data.at( 8 ) - data.at( 5 ) * data.at( 6 ) ) +
         data.at( 2 ) *
             ( data.at( 3 ) * data.at( 7 ) - data.at( 4 ) * data.at( 6 ) );
}

void Mat3::setIdentity()
{
  data = { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F };
}

void Mat3::transpose()
{
  std::swap( data.at( 1 ), data.at( 3 ) );
  std::swap( data.at( 2 ), data.at( 6 ) );
  std::swap( data.at( 5 ), data.at( 7 ) );
}

void Mat3::invert() {}

} // namespace Axle::Math
