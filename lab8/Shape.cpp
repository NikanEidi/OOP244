#include "Shape.h"
namespace seneca {
// Operator overload to handle output stream, relies on draw function
   std::ostream& operator<<(std::ostream& os, const Shape& S) {
      S.draw(os);  // Call the pure virtual draw function
      return os;   // Return the ostream object 
   }
// Operator overload to handle input stream, relies on getSpecs function
    std::istream& operator>>(std::istream& is, Shape& S) {
      S.getSpecs(is);  // Call the pure virtual getSpecs function
      return is;       // Return the istream 
   }
}