#ifndef AXLE_ERRORS_H
#define AXLE_ERRORS_H

#include <exception>
#include <string>

namespace Axle::Core {

class AxleError : public std::exception {

private:
  std::string message = "An unknown error occurred";

protected:
  void setMessage( const std::string& message );

public:
  explicit AxleError();
  [[nodiscard]] const char* what() const noexcept override;
};

class AppNotInitializedError : public AxleError {
public:
  explicit AppNotInitializedError();
};

class InvalidParameterRangeError : public AxleError {
public:
  InvalidParameterRangeError( const char* parameter,
                              float rangeMin,
                              float rangeMax );
};

} // namespace Axle::Core
#endif // AXLE_ERRORS_H
