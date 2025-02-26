#include "Core/Errors.h"

namespace Axle::Core {

AxleError::AxleError() { message = "An unknown error occurred"; }
const char *AxleError::what() const noexcept { return message.c_str(); }

AppNotInitializedError::AppNotInitializedError() {
  message = "This function requires the App to be initialized";
}

} // namespace Axle::Core
