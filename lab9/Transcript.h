/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File    Transcript.h
// Version 1.0
// Date    2024-11-18
// started by Fardad
// Description
// Header file for the Transcript class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nikan Eidi
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H

#include "Marks.h"

namespace seneca {

    class Transcript : public Marks {
        char* m_name;          // Dynamically allocated student's name
        size_t m_number;       // Student number

    public:
        // Constructor
        Transcript(const char* name, size_t number);

        // Copy Constructor
        Transcript(const Transcript& T);

        // Copy Assignment Operator
        Transcript& operator=(const Transcript& T);

        // Destructor
        ~Transcript();

        // Overridden display function
        std::ostream& display(std::ostream& ostr = std::cout) const override;
    };

}

#endif // SENECA_TRANSCRIPT_H