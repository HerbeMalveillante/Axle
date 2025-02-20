#include "Core/Color.h"
#include <assert.h>
#include <cmath>

namespace Axle::Core {

Color::Color() {
  r = 0;
  g = 0;
  b = 0;
  a = 255;
}

Color::Color(const unsigned char r, const unsigned char g,
             const unsigned char b, const unsigned char a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

Color::Color(const unsigned char r, const unsigned char g,
             const unsigned char b) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = 255;
}

Color::Color(int hexcode) { // Check if the color is in the right range
  assert(hexcode >= 0 && hexcode < std::pow(16, 6));
  r = (hexcode >> 16) & 0xFF;
  g = (hexcode >> 8) & 0xFF;
  b = hexcode & 0xFF;
  a = 255;
}

Color::Color(ColorPreset preset) {
  int hexcode;

  switch (preset) {
  case ColorPreset::COLOR_WHITE_PURE:
    hexcode = 0xFFFFFF;
    break;
  case ColorPreset::COLOR_BLACK_PURE:
    hexcode = 0x000000;
    break;
  case ColorPreset::COLOR_RED_PURE:
    hexcode = 0xFF0000;
    break;
  case ColorPreset::COLOR_GREEN_PURE:
    hexcode = 0x00FF00;
    break;
  case ColorPreset::COLOR_BLUE_PURE:
    hexcode = 0x0000FF;
    break;
  case ColorPreset::COLOR_DARK:
    hexcode = 0x333344;
    break;
  case ColorPreset::COLOR_LIGHT:
    hexcode = 0xeeddcc;
    break;
  case ColorPreset::COLOR_GRUE_DARK:
    hexcode = 0x445566;
    break;
  case ColorPreset::COLOR_GRUE:
    hexcode = 0x667788;
    break;
  case ColorPreset::COLOR_GRUE_LIGHT:
    hexcode = 0x99aabb;
    break;
  case ColorPreset::COLOR_CYAN_DARK:
    hexcode = 0x448888;
    break;
  case ColorPreset::COLOR_CYAN:
    hexcode = 0x66aa99;
    break;
  case ColorPreset::COLOR_CYAN_LIGHT:
    hexcode = 0x88bbbb;
    break;
  case ColorPreset::COLOR_YELLOW:
    hexcode = 0xeebb77;
    break;
  case ColorPreset::COLOR_ORANGE:
    hexcode = 0xdd8855;
    break;
  case ColorPreset::COLOR_BROWN:
    hexcode = 0x774444;
    break;
  case ColorPreset::COLOR_RED:
    hexcode = 0xbb5555;
    break;
  case ColorPreset::COLOR_PINK:
    hexcode = 0xee99aa;
    break;
  case ColorPreset::COLOR_GREEN:
    hexcode = 0x77aa66;
    break;
  case ColorPreset::COLOR_PURPLE:
    hexcode = 0x996699;
    break;
  }

  r = (hexcode >> 16) & 0xFF;
  g = (hexcode >> 8) & 0xFF;
  b = hexcode & 0xFF;
  a = 255;
}

Color::operator std::string() const {
  return "Color(" + std::to_string(r) + ", " + std::to_string(g) + ", " +
         std::to_string(b) + ", " + std::to_string(a) + ")";
}

} // namespace Axle::Core
