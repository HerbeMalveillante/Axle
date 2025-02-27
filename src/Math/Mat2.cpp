#include "Math/Mat2.hpp"
#include <array>

namespace Axle::Math {

Mat2::Mat2() : data { 1.0F, 0.0F, 0.0F, 1.0F } {}

Mat2::Mat2( float diagonal ) : data { diagonal, 0.0F, 0.0F, diagonal } {}

} // namespace Axle::Math
