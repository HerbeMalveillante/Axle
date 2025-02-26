#ifndef AXLE_COLOR_H
#define AXLE_COLOR_H

#include "Utils/Constants.h"
#include <string>

namespace Axle::Core {

enum class ColorPreset {
  COLOR_WHITE_PURE,
  COLOR_BLACK_PURE,
  COLOR_RED_PURE,
  COLOR_GREEN_PURE,
  COLOR_BLUE_PURE,

  COLOR_DARK,  // #333344
  COLOR_LIGHT, // #eeddcc

  COLOR_GRUE_DARK,  // #445566
  COLOR_GRUE,       // #667788
  COLOR_GRUE_LIGHT, // #99aabb

  COLOR_CYAN_DARK,  // #448888
  COLOR_CYAN,       // #66aa99
  COLOR_CYAN_LIGHT, // #88bbbb

  COLOR_YELLOW, // #eebb77
  COLOR_ORANGE, // #dd8855
  COLOR_BROWN,  // #774444
  COLOR_RED,    // #bb5555
  COLOR_PINK,   // #ee99aa
  COLOR_GREEN,  // #77aa66
  COLOR_PURPLE, // #996699

};

class Color {
private:
  unsigned char r, g, b, a;

public:
  Color();
  Color( unsigned char red,
         unsigned char green,
         unsigned char blue,
         unsigned char alpha );
  Color( unsigned char red, unsigned char green, unsigned char blue );
  Color( int hexcode );
  Color( ColorPreset preset );

  [[nodiscard]] unsigned char getRi() const { return r; }
  [[nodiscard]] unsigned char getGi() const { return g; }
  [[nodiscard]] unsigned char getBi() const { return b; }
  [[nodiscard]] unsigned char getAi() const { return a; }

  [[nodiscard]] float getRf() const
  {
    return (float)r / Utils::MAX_COLOR_VALUE;
  }
  [[nodiscard]] float getGf() const
  {
    return (float)g / Utils::MAX_COLOR_VALUE;
  }
  [[nodiscard]] float getBf() const
  {
    return (float)b / Utils::MAX_COLOR_VALUE;
  }
  [[nodiscard]] float getAf() const
  {
    return (float)a / Utils::MAX_COLOR_VALUE;
  }

  operator std::string() const;
};

} // namespace Axle::Core
#endif // AXLE_COLOR_H
