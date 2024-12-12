#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include "Shape.h"
#include <iostream>

namespace seneca {

    class LblShape : public Shape {
    private:
        char* m_label; // Dynamically allocated label for the shape

    protected:
        // function to return the label
        const char* label() const;

    public:
        // Default constructor
        LblShape();

        // Constructor with label initialization
        LblShape(const char* label);

        // Destructor 
        virtual ~LblShape();

        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;

        // Override the pure virtual function
        void getSpecs(std::istream& is) override;

        // Pure virtual draw function 
        virtual void draw(std::ostream& os) const override= 0 ;
    };

}

#endif // SENECA_LABELEDSHAPE_H