

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "Math/Vector2.h"
#include "Math/Point2.h"
#include "Math/Size2.h"
#include "Math/Matrix4.h"
#include "Input/Keyboard.h"

namespace Axle::Core{

    class App{

    private:
        std::string title;
        Math::Size2 screenSize;
        Input::Keyboard keyboard;


        bool eventWaiting;
        Math::Matrix4 screenScale;

    public:
        App(Math::Size2 size, const std::string &title);









        public:
    };
}


#endif //WINDOW_H
