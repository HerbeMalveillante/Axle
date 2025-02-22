#ifndef MAT4_H
#define MAT4_H

#include <iostream>

namespace Axle::Math {

class Mat4 {
private:
  // Column-major order
  float data[4 * 4];

public:
  Mat4();
  Mat4(float diagonal);
  Mat4(float *elements);

  void set(int x, int y, float value) { data[x + y * 4] = value; }
  float get(int x, int y) { return data[x + y * 4]; }

  float *getElements() { return data; }
};

} // namespace Axle::Math

#endif // MAT4_H
