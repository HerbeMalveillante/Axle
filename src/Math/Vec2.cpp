#include "Math/Vec2.hpp"

namespace Axle::Math {

Vec2::Vec2()
{
  this->setComponentsCount( 2 );
  this->setX( 0.0F );
  this->setY( 0.0F );
}

Vec2::Vec2( const float x, const float y )
{
  this->setComponentsCount( 2 );
  this->setX( x );
  this->setY( y );
}

Vec2::Vec2( const float value )
{
  this->setComponentsCount( 2 );
  this->setX( value );
  this->setY( value );
}

void Vec2::setX( const float x ) { this->setComponent( 0, x ); }
void Vec2::setY( const float y ) { this->setComponent( 1, y ); }

[[nodiscard]] float Vec2::getX() const { return this->getComponent( 0 ); }
[[nodiscard]] float Vec2::getY() const { return this->getComponent( 1 ); }
} // namespace Axle::Math
