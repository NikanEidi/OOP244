#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      // Height of the rectangle
      private:
       int m_width;  // Width of the rectangle
       int m_height; //height

   public:
      // Default constructor
      Rectangle();

      // Constructor that initializes label, width, and height
      Rectangle(const char* label, int width, int height);

      // Draws the rectangle using the label, width, and height
      void getSpecs(std::istream& is) override;

      // Gets specifications of the rectangle (label, width, height) from input
      void draw(std::ostream& os) const override;
   };

}

#endif // !SENECA_RECTANGLE_H
