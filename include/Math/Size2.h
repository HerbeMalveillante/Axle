

#ifndef SIZE_H
#define SIZE_H


namespace Axle::Math{

    /// @brief Represents a 2D unsigned integer size
    class Size2 {
        private:
            unsigned int width;
            unsigned int height;

        public:
            Size2(unsigned int width, unsigned int height);
            Size2();
            [[nodiscard]] unsigned int getWidth() const;
            [[nodiscard]] unsigned int getHeight() const;
            void setWidth(unsigned int width);
            void setHeight(unsigned int height);
    };
}


#endif //SIZE_H
