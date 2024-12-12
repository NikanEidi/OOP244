/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File    Transcript.cpp
// Version 1.0
// Date    2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nikan Eidi
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include "Transcript.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    // Constructor
   Transcript::Transcript(const char* name, size_t number) : Marks(), m_name(nullptr) { // Explicitly initialize m_name
    if (name) {
        ut.alocpy(m_name, name); // Allocate and copy name
    }
    m_number = number;
}

    // Copy Constructor
   Transcript::Transcript(const Transcript& T) : Marks(T), m_name(nullptr) {
    if (T.m_name) {
        ut.alocpy(m_name, T.m_name); // Allocate and copy name
    }
    m_number = T.m_number; // Copy student number
}

    // Assignment Operator
    Transcript& Transcript::operator=(const Transcript& T) {
    if (this != &T) { // Avoid self-assignment
        Marks::operator=(T); // Assign base class attributes
        ut.alocpy(m_name, T.m_name); // Allocate and copy new name
        m_number = T.m_number; // Copy student number
    }
    return *this;
}

    // Destructor
    Transcript::~Transcript() {
        delete[] m_name;
        m_name = nullptr;
    }

    // Display Function
   std::ostream& Transcript::display(std::ostream& ostr) const {
    if (m_name && m_number > 0) {
        ostr << m_name << " (" << m_number << ")\n";
        ostr << "--------------------------------------------------------------------------\n";
        Marks::display(ostr); // Call base class display to output marks
    } else {
        ostr << "Invalid Transcript.\n";
    }
    return ostr;
   }

}