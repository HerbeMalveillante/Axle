
#include "Core/App.h"

namespace Axle::Core {

App::App(const Math::Size2 size, const std::string &title) {
  this->screenSize = size;
  this->title = title;

  this->eventWaiting = false;
  this->screenScale = Math::Matrix4();
}

} // namespace Axle::Core
