#ifndef AXLE_ERRORS_HPP
#define AXLE_ERRORS_HPP

#include <exception>
#include <string>

namespace Axle::Core {

// ╔══════════════════════════════════╗
// ║ -> Base class
// ╚══════════════════════════════════╝

class AxleError : public std::exception {

private:
  std::string message = "An unknown error occurred";

protected:
  void setMessage( const std::string& message );

public:
  explicit AxleError() = default;
  [[nodiscard]] const char* what() const noexcept override;
};

// ╔══════════════════════════════════╗
// ║ -> General / Math
// ╚══════════════════════════════════╝

class InvalidParameterRangeError : public AxleError {
public:
  InvalidParameterRangeError( const char* parameter,
                              float rangeMin,
                              float rangeMax );
};

class DivisionByZeroError : public AxleError {
public:
  DivisionByZeroError();
  DivisionByZeroError( const char* message );
};

class IndexOutOfBoundsError : public AxleError {
public:
  IndexOutOfBoundsError();
  IndexOutOfBoundsError( int indexMin, int indexMax );
};

// ╔══════════════════════════════════╗
// ║ -> App
// ╚══════════════════════════════════╝

class AppNotInitializedError : public AxleError {
public:
  explicit AppNotInitializedError();
};

// ╔══════════════════════════════════╗
// ║ -> Shaders
// ╚══════════════════════════════════╝

class ShaderCompilationError : public AxleError {
public:
  ShaderCompilationError( const char* shaderType, const char* infoLog );
};

class ShaderLinkingError : public AxleError {
public:
  ShaderLinkingError( const char* infoLog );
};

class ShaderNotCompiledError : public AxleError {
public:
  ShaderNotCompiledError();
};
} // namespace Axle::Core
#endif // AXLE_ERRORS_HPP
