//Nikan Eidi
#include <iostream>
#include "input.h"
using namespace std;
namespace seneca {
   int getInt() {
      int num = 0;
      bool done = false;
      do {
         
         cin >> num;
         
         if (cin.fail()) {
            cout << "Bad integer entry, please try again:\n> ";
           
            cin.clear();
         }
         else {
            done = true;
         }
         
         cin.ignore(1000, '\n');
      } while (!done);
      return num;
   }
   // Overloaded version of getInt with min/max limits
   int getInt(int minVal, int maxVal)
   {
      int num = getInt();// re use getint function to avoid of repeating the logic
      while (num < minVal || num > maxVal)
      {
         cout << "Invalid value, [" << minVal << "<ENTRY<" << maxVal << "]\n> ";
         num = getInt();  // Re-prompt if the value is out of bounds
      }

      return num;  // Return the valid integer

   }
   // Boolean version of getInt to validate with min/max limits
   bool getInt(int& num, int minVal, int maxVal) {
      num = getInt();  // Get the integer
      
      // Return true if within bounds, otherwise false
      return (num >= minVal && num <= maxVal);
   }


  
}

