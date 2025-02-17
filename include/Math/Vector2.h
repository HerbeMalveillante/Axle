

#ifndef VECTOR2_H
#define VECTOR2_H


namespace Axle::Math{

    /// @brief Represents a 2D float vector
    class Vector2{
        float x;
        float y;

        public:
            Vector2(float x, float y);
            Vector2();
            [[nodiscard]] float getX() const;
            [[nodiscard]] float getY() const;
            void setX(float x);
            void setY(float y);
    };
}


#endif //VECTOR2_H
