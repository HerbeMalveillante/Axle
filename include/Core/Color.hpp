#ifndef AXLE_COLOR_H
#define AXLE_COLOR_H

#include <string>

namespace Axle::Core {

const int COLOR_WHITE_PURE = 0xFFFFFF;
const int COLOR_BLACK_PURE = 0x000000;
const int COLOR_RED_PURE = 0xFF0000;
const int COLOR_GREEN_PURE = 0x00FF00;
const int COLOR_BLUE_PURE = 0x0000FF;

const int COLOR_DARK = 0x333344;
const int COLOR_LIGHT = 0xeeddcc;

const int COLOR_GRUE_DARK = 0x445566;
const int COLOR_GRUE = 0x667788;
const int COLOR_GRUE_LIGHT = 0x99aabb;

const int COLOR_CYAN_DARK = 0x448888;
const int COLOR_CYAN = 0x66aa99;
const int COLOR_CYAN_LIGHT = 0x88bbbb;

const int COLOR_YELLOW = 0xeebb77;
const int COLOR_ORANGE = 0xdd8855;
const int COLOR_BROWN = 0x774444;
const int COLOR_RED = 0xbb5555;
const int COLOR_PINK = 0xee99aa;
const int COLOR_GREEN = 0x77aa66;
const int COLOR_PURPLE = 0x996699;

class Color {
private:
  unsigned char r = 0;
  unsigned char g = 0;
  unsigned char b = 0;
  unsigned char a = 255;

public:
  Color() = default;
  Color( unsigned char red,
         unsigned char green,
         unsigned char blue,
         unsigned char alpha );
  Color( unsigned char red, unsigned char green, unsigned char blue );
  Color( int hexcode );

  [[nodiscard]] unsigned char getRi() const { return r; }
  [[nodiscard]] unsigned char getGi() const { return g; }
  [[nodiscard]] unsigned char getBi() const { return b; }
  [[nodiscard]] unsigned char getAi() const { return a; }

  [[nodiscard]] float getRf() const { return (float)r / (float)255; }
  [[nodiscard]] float getGf() const { return (float)g / (float)255; }
  [[nodiscard]] float getBf() const { return (float)b / (float)255; }
  [[nodiscard]] float getAf() const { return (float)a / (float)255; }

  operator std::string() const;
};

} // namespace Axle::Core
#endif // AXLE_COLOR_H
