#include "Core/Errors.hpp"

namespace Axle::Core {

// ╔══════════════════════════════════╗
// ║ -> Base class
// ╚══════════════════════════════════╝

const char* AxleError::what() const noexcept { return message.c_str(); }
void AxleError::setMessage( const std::string& message )
{
  this->message = message;
}

// ╔══════════════════════════════════╗
// ║ -> General / Math
// ╚══════════════════════════════════╝

InvalidParameterRangeError::InvalidParameterRangeError( const char* parameter,
                                                        const float rangeMin,
                                                        const float rangeMax )
{
  setMessage( "The parameter " + std::string( parameter ) +
              " must be in the range [" + std::to_string( rangeMin ) + ", " +
              std::to_string( rangeMax ) + "]" );
}

DivisionByZeroError::DivisionByZeroError()
{
  setMessage( "Division by zero is not allowed" );
}

DivisionByZeroError::DivisionByZeroError( const char* message )
{
  setMessage( message );
}

// ╔══════════════════════════════════╗
// ║ -> App
// ╚══════════════════════════════════╝

AppNotInitializedError::AppNotInitializedError()
{
  setMessage( "This function requires the App to be initialized" );
}

// ╔══════════════════════════════════╗
// ║ -> Shaders
// ╚══════════════════════════════════╝

ShaderCompilationError::ShaderCompilationError( const char* shaderType,
                                                const char* infoLog )
{
  setMessage( "Shader compilation failed for " + std::string( shaderType ) +
              " shader: " + std::string( infoLog ) );
}

ShaderLinkingError::ShaderLinkingError( const char* infoLog )
{
  setMessage( "Shader program linking failed: " + std::string( infoLog ) );
}

ShaderNotCompiledError::ShaderNotCompiledError()
{
  setMessage( "The shader program has not been compiled" );
}

} // namespace Axle::Core
