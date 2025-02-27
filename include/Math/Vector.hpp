#ifndef AXLE_VECTOR_H
#define AXLE_VECTOR_H

#include <array>
#include <string>

namespace Axle::Math {

// Vector is the base class for all vector types.
// It enables reuse of common vector operations.
class Vector {

private:
  std::array<float, 4> data = { 0.0F, 0.0F, 0.0F, 0.0F };
  unsigned int componentsCount = 0;

protected:
  Vector() = default;

  void setComponentsCount( unsigned int componentsCount );
  [[nodiscard]] unsigned int getComponentsCount() const;
  void setComponent( unsigned int componentIndex, float value );
  [[nodiscard]] float getComponent( unsigned int componentIndex ) const;

public:
  [[nodiscard]] float length() const;
  [[nodiscard]] std::string toString() const;
};

} // namespace Axle::Math

#endif // AXLE_VECTOR_H
