#include <iostream>
#include "Account.h"
using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   //conversion operators PART!!!!

   /*
         1.operator bool
         returns true if the Account is valid and otherwise false. This operator can not modify the Account object.
   */
      Account::operator bool() const{
         return m_number >= 10000 &&  m_number <= 99999 && m_balance >= 0; // if all conditions is correct it will return true 
                                                                      // else will return false without modify object
      } 

   /*
         2.operator int
         returns the Account number. This operator can not modify the Account object.
   */
     Account::operator int() const{
      return m_number; // returning account number 
     } 

   /*
         3.operator double 
         returns the balance value. This operator can not modify the Account object.
   */
     Account::operator double() const{
      return m_balance;
     }

   //Unary member operator PART!!

   /*
         1.bool operator ~()
         This operator returns true if the Account is new or not set (i.e. if the Account number is zero), otherwise it will return false. 
         This operator can not modify the Account object.
   */
  //Unary syntax : return_type operator symbol 
     bool Account::operator ~() const{
      return m_number == 0;  // Returns true if the account number is 0 (new or not set)
      }

  //Binary member operators PART!!
  //syntax: return_type operator symbol (type [identifier])

   /*
          Note: All the binary member operators will not take any action if the Account is in an invalid state.
   */

   //Assignment operators PART!!
 
   /*
         part1
         overload the assignment operator so a NEW Account can be set to an integer. 
         In doing so, you should set the Account number of the Account to the integer value.
         If the integer value is an invalid Account number, the object should be set to an invalid empty state instead.
         If the Account is not new, then this operator should not perform any action.
         In any case, a reference of the current object (Account) should be returned.
   */
  Account& Account::operator=(int number) {
   // Check if the account is NEW
   if (m_number == 0) { 
       if (number >= 10000 && number <= 99999) { // Check if the int value is valid
           m_number = number; // Assign valid number
       } else{
          setEmpty(); // Set to empty state since it was invalid 
       }
       
   }
   return *this; // Return reference of the current object
   }
   /*
        part2
        overload the assignment operator so a NEW Account can be set to another Account object. 
        This action should move the balance and the Account number from one Account to another; 
        therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; 
        the balance of the left Account will be set to the balance of the right Account and then the balance of the right Account will be set to zero. 
        The same will happen to the Account number
        If the left Account operand is not new or the right Account operand is not valid, no action should be taken.
        In any case, a reference of the current object (Account) should be returned.
   */
   //Copy Assignment Operator
  //syntax: Type& operator=(const Type&);
  // src means : source of the code (file etc...) 
  Account& Account::operator=(Account& right){
   //condition to check self assign to make sure im not try to assign object to itself
   if (this != &right){
      //condition to check the left Account operand is not new or the right Account operand is not valid
      if (m_number == 0 && (right.m_number >= 10000 && right.m_number <= 99999)){
          m_number = right.m_number; // Move the account number
          m_balance = right.m_balance; // Move the balance
          //balance of the right account set to zero
          right.m_number=0;
          right.m_balance=0.0;  
   }
   }
   return *this; // Return reference of the current object
   }

 //Binary operators with side-effect PART !!

   /*
        part1
        overload the += operator to add a double value to an Account. 
        This should act like depositing money into an Account. (i.e. the value of the double should be added to the balance)
        if the Account is in an invalid state or the double value is negative, no action should be taken.
        In any case, a reference of the current object (Account) should be returned.
   */
  Account& Account::operator+=(double deposit){
   //condition to check the Account is in an invalid state or the double value is negative
   if (m_number >= 10000 &&  m_number <= 99999 && m_balance > 0 && deposit>0){
       m_balance += deposit; //adding deposit to m_balance 
   }
   return *this; // Return reference of the current object
  }

  /*
        part2
       overload the -= operator to reduce an Account balance by a double value. 
       This should act like withdrawing money from an Account. (i.e. the value of the balance should be reduced by the double value)
       if the Account is in an invalid state, the double value is negative or there is not enough money in the Account no action should be taken.
       In any case, a reference of the current object (Account) should be returned.
   */
  Account& Account::operator-=(double withdrawing){
   //condition to check the Account is in an invalid /valid state, the double value is negative or there is not enough money
   if (m_number >= 10000 &&  m_number <= 99999 && m_balance > 0 && withdrawing>0 && m_balance >= withdrawing){
      m_balance -= withdrawing; //adding deposit to m_balance 
   }
   return *this; // Return reference of the current object
  }

  /*
        part3
       overload the << operator (left shift operator) to move funds from the right Account to the left. 
       After this operation, the balance of the left Account will be the sum of both and the balance of the right Account will be zero.
       Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
       In any case, a reference of the current object (Account) should be returned.
   */
  Account& Account::operator<<(Account& right){
   //condition to check self assign to make sure im not try to assign object to itself and check the validation of right account 
   if (this != &right && (right.m_number >= 10000 && right.m_number <= 99999) && right.m_balance > 0)
   {
      m_balance+=right.m_balance; //the balance of the left Account will be the sum of both
      right.m_balance=0;//the balance of the right Account will be zero
      
   }
   return *this; // Return reference of the current object
  }
  /*
        part4
       overload the >> operator (right shift operator) to move funds from the left Account to the right. 
       After this operation, the balance of the right Account will be the sum of both and the balance of the left Account will be zero.
       Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
       In any case, a reference of the current object (Account) should be returned.
   */
  Account& Account::operator >>(Account& left){
   //condition to check self assign to make sure im not try to assign object to itself and check the validation of left account 
   if (this != &left && (m_number >= 10000 && m_number <= 99999) && left.m_balance > 0)
   {
      left.m_balance += m_balance; //the balance of the right Account will be the sum of both
      m_balance=0;//the balance of the left Account will be zero
      
   }

   return *this; // Return reference of the current object
  }

  //Binary helper operators PART!!
  /*
        part1
       Create a binary stand-alone helper + operator that accepts a constant Account reference at left and another constant Account 
       reference at right and returns a double value.
       The double value should be the sum of the balances of the two accounts.
       If any of the two accounts is invalid, then zero is returned.
   */
  double operator+(const Account& left, const Account& right) {
    // Check validation of both accounts 
    if ((left.m_number >= 10000 && left.m_number <= 99999) ||(right.m_number >= 10000 && right.m_number <= 99999)) {
         return left.m_balance + right.m_balance; // return sum since it was valid 
        
    }
    return 0.0; // Return zero since it was invalid 
}

  /*
        part2
       Create a binary stand-alone helper += operator that accepts a double reference at left and a constant Account reference at right and returns a double value.
       The value of the balance of the right operand (Account reference) should be added to the left operand (double reference)
       Then the value of the double reference is returned.
   */
  double operator+=(double& left, const Account& right) {
    // Check if the right account is valid
    if (right.m_number >= 10000 && right.m_number <= 99999) {
        // Add the right account's balance to the left reference
        left += right.m_balance; // Add the balance of the right account
    }
    // Return the left value
    return left; 
}
}