#include "Line.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace seneca {

    // Default constructor
   Line::Line() : m_length(0) {}
//constructor with 2 arguments 
    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {
        if (m_length < static_cast<int>(strlen(label))) {
            m_length = static_cast<int>(strlen(label));
        }
    }
//over ride get space and draw 
    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && label()) {
            os << label() << endl;
            os.fill('=');
            os.width(m_length);
            os << "=";
        }
    }

}