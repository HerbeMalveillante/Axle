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
  std::string result = "\nMatrix 2x2:\n";

  result += std::to_string( data.at( 0 ) ) + " " +
            std::to_string( data.at( 1 ) ) + "\n";
  result += std::to_string( data.at( 2 ) ) + " " +
            std::to_string( data.at( 3 ) ) + "\n";
  return result;
}

// ╔══════════════════════════════════╗
// ║ -> Operations
// ╚══════════════════════════════════╝

} // namespace Axle::Math
