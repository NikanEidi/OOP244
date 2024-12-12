#include "LblShape.h"
#include "Utils.h" 
#include <cstring>
#include <iostream>
namespace seneca {

    // Default constructor
    LblShape::LblShape() : m_label(nullptr) {}

    // Constructor with label initialization
    LblShape::LblShape(const char* label) : m_label(nullptr) {
        if (label) {
            m_label = ut.alocpy(label); 
        }
    }

    // Destructor
    LblShape::~LblShape() {
        delete[] m_label; 
    }

    
    const char* LblShape::label() const {
        return m_label;
    }

    
    void LblShape::getSpecs(std::istream& is) {
        char temp[81];
        is.getline(temp, 81, ','); 
        
        
        delete[] m_label; 
        m_label = ut.alocpy(temp);
    }
}