#include "Core/Color.h"
#include "Core/Errors.h"
#include "Utils/Constants.h"

namespace Axle::Core {

Color::Color( const unsigned char red,
              const unsigned char green,
              const unsigned char bblue,
              const unsigned char alpha )
    : r( red ), g( green ), b( bblue ), a( alpha )
{
}

Color::Color( const unsigned char red,
              const unsigned char green,
              const unsigned char blue )
    : r( red ), g( green ), b( blue )
{
}

Color::Color( int hexcode )
{ // Check if the color is in the right range
  if ( hexcode < 0 || hexcode > Utils::MAX_COLOR_HEX_VALUE ) {
    throw InvalidParameterRangeError(
        "hexcode", 0, Utils::MAX_COLOR_HEX_VALUE );
  }
  r = ( hexcode >> 16 ) & 0xFF;
  g = ( hexcode >> 8 ) & 0xFF;
  b = hexcode & 0xFF;
  a = 255;
}

Color::operator std::string() const
{
  return "Color(" + std::to_string( r ) + ", " + std::to_string( g ) + ", " +
         std::to_string( b ) + ", " + std::to_string( a ) + ")";
}

} // namespace Axle::Core
