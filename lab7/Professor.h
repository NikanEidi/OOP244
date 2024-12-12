/***********************************************************************
// OOP244 Workshop 6 lab: Professor
//
// File	Professor.cpp
// Version 1.0
// Date	2024/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nikan Eidi
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include "Employee.h"
#include "Utils.h"

//initialize name space seneca
namespace seneca{
    // Derive a class from Employee named Professor
    class Professor : public Employee{
        //Subject Name: A dynamically allocated C-string that stores the subject the professor teaches.
        char* m_subject;
        //Number of Sections: An integer that stores the number of sections the professor teaches.
        int m_sections;
        //devPay => calculate additional pay based on the number of sections
        double devPay() const;
    public:
    // No-argument constructor
        Professor();
    //5-Argument Constructor
        Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary); 
    //Destructor
       ~Professor();
    //Reads the Professor data in the following format from an istream
       std::istream& read(std::istream& istr = std::cin);
    //Outputs Professor data 
       std::ostream& write(std::ostream& ostr = std::cout) const;
    //ostream& title(ostream& ostr = cout) const;
       std::ostream& title(std::ostream& ostr = std::cout) const;

};// end of Derived Class definition  

// Overloaded operators
    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P); 
} 


#endif 