#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"
#include <cstring>
using namespace std;
namespace seneca {
    //Defalt constructor 
    Rectangle::Rectangle() : m_width(0), m_height(0) {}
    //constructor with 3 arguments 
    Rectangle::Rectangle(const char* label, int width, int height)
        : LblShape(label), m_width(width), m_height(height) {
        if (m_height < 3) m_height = 3;
        if (m_width < static_cast<int>(strlen(label)) + 2) m_width = static_cast<int>(strlen(label)) + 2;
    }
// overide Getspaces function 
    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }
//over ride draw 
    void Rectangle::draw(ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << '+' << string(m_width - 2, '-') << '+' << endl;
            os << '|';
            os << label();
            os << string(m_width - 2 - strlen(label()), ' ');
            os << '|' << endl;
            for (int i = 0; i < static_cast<int>(m_height) - 3; ++i) {
                os << '|';
                os << string(m_width - 2, ' ');
                os << '|' << endl;
            }
            os << '+' << string(m_width - 2, '-') << '+';
        }
    }
}