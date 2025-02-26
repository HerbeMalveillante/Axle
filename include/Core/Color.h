#ifndef AXLE_COLOR_H
#define AXLE_COLOR_H

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
  Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  Color(unsigned char r, unsigned char g, unsigned char b);
  Color(int hexcode);
  Color(ColorPreset preset);

  unsigned char getRi() const { return r; }
  unsigned char getGi() const { return g; }
  unsigned char getBi() const { return b; }
  unsigned char getAi() const { return a; }

  float getRf() const { return r / 255.0f; }
  float getGf() const { return g / 255.0f; }
  float getBf() const { return b / 255.0f; }
  float getAf() const { return a / 255.0f; }

  operator std::string() const;
};

} // namespace Axle::Core
#endif // AXLE_COLOR_H
