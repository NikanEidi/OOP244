#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   //  define Constructor to prevent unmodified behaviour 
   CC::CC() {
      // Call the set() function to initialize to a safe empty state
      set();
   }

   // Destructor
   CC::~CC() {
      // Clean up the dynamic memory before the object is destroyed
      cleanUp();
   }
//function definition of Private
//CC:: definition the function name identified as member of cc type
    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }
   bool CC::validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const{
               //statement to check name is null pointer (return false) or not (true)and to check name has more than 2 char long or not
               if (name == nullptr || strlen(name) <= 2) {
                   return false;
               }
               //cardNo: values between 4000000000000000ull and 4099999999999999ull
               if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull){
                  return false;
               }
               /*condition to check cvv: a three-digit number
                 expMon: values between 1 and 12
                 expYear: values between 24 and 32
                 */
                if (cvv < 100 || cvv > 999)
                {
                  return false;
                }
                if (expMon < 1 || 12 < expMon)
                {
                  return false;
                }
                if (expYear < 24 || 32 < expYear)
                {
                  return false;
                }
                return true;
               
   }
   void CC::prnNumber(unsigned long long no)const{

      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   
   //function definition of Public
   void CC::set(){
      /*Sets the object to a safe empty state by setting all the values to zero and the name pointer to nullptr.*/
      number = 0;     // Set values to zero
      cvv = 0;
      expMon = 0;
      expYear = 0;
      name = nullptr; // set name pointer to nullptr

   }
   void CC::cleanUp(){
      /*First, it will deallocate the cardholder's (using freeMem in cstr.h) name 
      and then it will call the set() method to set the object to a safe empty state.*/
      freeMem(name);
      //call the set() method to set the object to a safe empty state.
      set();
   }
   bool CC::isEmpty()const{
      /*Returns if the CC object is in a safe empty state or not; 
      by returning true if the cardholder name pointer attribute of the object is nullptr, 
      otherwise, it will return false.*/
      return name == nullptr;
   }
   //set (overloaded with five arguments)
   void CC::set(const char* cc_name, 
         unsigned long long cc_no, 
         short cvv, 
         short expMon, 
         short expYear){
      /*First, it will cleanUp() the object to a safe empty state. Then if all the arguments are valid using validate(), 
      it will dynamically keep a copy of the name in the name attribute (using alocpy function in cstr.h) 
      and then sets the rest of the attributes to their corresponding values.*/
      cleanUp();
      if (validate(cc_name, cc_no, cvv, expMon, expYear))
      {
         alocpy(name, cc_name);
         number = cc_no;
        this->cvv = cvv;
        this->expMon = expMon; // using this-> or I was able to use new 
        this->expYear = expYear;
      }
      
   }
   //display (overload with no arguments)
   void CC::display() const{
         /*If the object isEmpty(), print "Invalid Credit Card Record" and go to newline;
           If it is not in a safe empty state, display the CC class using the private display method.
           */
          if (isEmpty())
          {
            cout << "Invalid Credit Card Record" << endl;
          }
          else
          {
            display(name, number, expYear, expMon, cvv);
          }  

    }
    
}