#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      //functions prototype of private class
      private:
      char* name; // Pointer for cardholder's name
      unsigned long long number; // Credit card number
      short cvv; // CVV
      short expMon; // Expiration month
      short expYear; // Expiration year
      
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      bool validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const;
              
      void prnNumber(unsigned long long no)const;
      //functions prototype of public class
      public:
      // Constructor and Destructor
       CC();
      ~CC();
      void set();
      void cleanUp();
      bool isEmpty() const;
      //set (overloaded with five arguments)
      void set(const char* cc_name, 
         unsigned long long cc_no, 
         short cvv, 
         short expMon = 12, 
         short expYear= 24);
      //display (overload with no arguments)
      void display() const;
   };
}
#endif // !SENECA_CC_H_
