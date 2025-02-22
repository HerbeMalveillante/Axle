#include "Math/Mat4.h"

namespace Axle::Math {

Mat4::Mat4() {
  for (int i = 0; i < 4 * 4; i++) {
    data[i] = 0.0f;
  }
}

Mat4::Mat4(float diagonal) {
  for (int i = 0; i < 4 * 4; i++) {
    data[i] = 0.0f;
  }
  data[0 + 0 * 4] = diagonal;
  data[1 + 1 * 4] = diagonal;
  data[2 + 2 * 4] = diagonal;
  data[3 + 3 * 4] = diagonal;
}

Mat4::Mat4(float *elements) {
  for (int i = 0; i < 4 * 4; i++) {
    data[i] = elements[i];
  }
}

} // namespace Axle::Math
