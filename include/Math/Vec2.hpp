#ifndef AXLE_VEC2_H
#define AXLE_VEC2_H

#include "Math/Vector.hpp"

namespace Axle::Math {
class Vec2 : public Vector {
public:
  Vec2();
  Vec2( float x, float y );
  Vec2( float value );

  void setX( float x );
  void setY( float y );

  [[nodiscard]] float getX() const;
  [[nodiscard]] float getY() const;
};
} // namespace Axle::Math

#endif // AXLE_VEC2_H
