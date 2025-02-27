#include "Math/Vector.hpp"
#include <cmath>
#include <string>

namespace Axle::Math {

void Vector::setComponentsCount( const unsigned int componentsCount )
{
  this->componentsCount = componentsCount;
}

[[nodiscard]] unsigned int Vector::getComponentsCount() const
{
  return this->componentsCount;
}

void Vector::setComponent( const unsigned int componentIndex,
                           const float value )
{
  this->data.at( componentIndex ) = value;
}

[[nodiscard]] float
Vector::getComponent( const unsigned int componentIndex ) const
{
  return this->data.at( componentIndex );
}

float Vector::length() const
{
  float sum = 0.0F;
  for ( unsigned int i = 0; i < this->componentsCount; i++ ) {
    sum += this->data.at( i ) * this->data.at( i );
  }
  return std::sqrt( sum );
}

std::string Vector::toString() const
{
  std::string result;
  for ( unsigned int i = 0; i < this->componentsCount; i++ ) {
    result += std::to_string( this->data.at( i ) );
    if ( i < this->componentsCount - 1 ) {
      result += ", ";
    }
  }
  return result;
}

} // namespace Axle::Math
