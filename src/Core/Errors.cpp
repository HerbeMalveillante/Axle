#include "Core/Errors.h"

namespace Axle::Core {

const char* AxleError::what() const noexcept { return message.c_str(); }
void AxleError::setMessage( const std::string& message )
{
  this->message = message;
}

AppNotInitializedError::AppNotInitializedError()
{
  setMessage( "This function requires the App to be initialized" );
}

InvalidParameterRangeError::InvalidParameterRangeError( const char* parameter,
                                                        const float rangeMin,
                                                        const float rangeMax )
{
  setMessage( "The parameter " + std::string( parameter ) +
              " must be in the range [" + std::to_string( rangeMin ) + ", " +
              std::to_string( rangeMax ) + "]" );
}

} // namespace Axle::Core
