

#ifndef POINT_H
#define POINT_H


namespace Axle::Math{

    /// @brief Represents a 2D integer position
    class Point2 {
        private:
            int x;
            int y;

        public:
            Point2(int x, int y);
            Point2();
            [[nodiscard]] int getX() const;
            [[nodiscard]] int getY() const;
            void setX(int x);
            void setY(int y);
    };
}

#endif //POINT_H
