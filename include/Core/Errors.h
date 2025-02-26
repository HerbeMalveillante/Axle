#ifndef AXLE_ERRORS_H
#define AXLE_ERRORS_H

#include <exception>
#include <string>

namespace Axle::Core {

class AxleError : public std::exception {
protected:
  std::string message;

public:
  explicit AxleError();
  const char *what() const noexcept override;
};

class AppNotInitializedError : public AxleError {
public:
  explicit AppNotInitializedError();
};

} // namespace Axle::Core
#endif // AXLE_ERRORS_H
