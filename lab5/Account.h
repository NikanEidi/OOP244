#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

   //conversion operators PART!!!!

   /*
         1.operator bool
         returns true if the Account is valid and otherwise false. This operator can not modify the Account object.
   */
      operator bool() const; //use const for can not modify the account object


   /*
         2.operator int
         returns the Account number. This operator can not modify the Account object.
   */
     operator int() const; //use const for can not modify the account object

   /*
         3.operator double 
         returns the balance value. This operator can not modify the Account object.
   */
     operator double() const;//use const for can not modify the account object

   //Unary member operator PART!!

   /*
         1.bool operator ~()
         This operator returns true if the Account is new or not set (i.e. if the Account number is zero), otherwise it will return false. 
         This operator can not modify the Account object.
   */
      bool operator ~() const;//use const for can not modify the account object
   
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
      Account& operator=(int number);
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
      Account& operator=(Account& src); // src means : source of the code (file etc...) 

  //Binary operators with side-effect PART !!
  //syntax: return_type operator symbol (type [identifier])

   /*
        part1
        overload the += operator to add a double value to an Account. 
        This should act like depositing money into an Account. (i.e. the value of the double should be added to the balance)
        if the Account is in an invalid state or the double value is negative, no action should be taken.
        In any case, a reference of the current object (Account) should be returned.
   */
  // adding double value and identifier is deposit since its like deposit
  Account& operator+=(double deposit);

  /*
        part2
       overload the -= operator to reduce an Account balance by a double value. 
       This should act like withdrawing money from an Account. (i.e. the value of the balance should be reduced by the double value)
       if the Account is in an invalid state, the double value is negative or there is not enough money in the Account no action should be taken.
       In any case, a reference of the current object (Account) should be returned.
   */
  // reduce, double value and identifier is withdrawing since it is looks like withdrawing money from an Account
  Account& operator-=(double withdrawing);

  /*
        part3
       overload the << operator (left shift operator) to move funds from the right Account to the left. 
       After this operation, the balance of the left Account will be the sum of both and the balance of the right Account will be zero.
       Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
       In any case, a reference of the current object (Account) should be returned.
   */
  
   Account& operator<<(Account& right);
   /*
        part4
       overload the >> operator (right shift operator) to move funds from the left Account to the right. 
       After this operation, the balance of the right Account will be the sum of both and the balance of the left Account will be zero.
       Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.
       In any case, a reference of the current object (Account) should be returned.
   */
  Account& operator>>(Account& left);

  //Binary helper operators PART!!
  /*
        part1
       Create a binary stand-alone helper + operator that accepts a constant Account reference at left and another constant Account 
       reference at right and returns a double value.
       The double value should be the sum of the balances of the two accounts.
       If any of the two accounts is invalid, then zero is returned.
   */

  //Friendship grants helper functions access to the private members of a class.
  friend double operator+(const Account& left, const Account& right);

  /*
        part2
       Create a binary stand-alone helper += operator that accepts a double reference at left and a constant Account 
       reference at right and returns a double value.
       The value of the balance of the right operand (Account reference) should be added to the left operand (double reference)
       Then the value of the double reference is returned.
   */

  //Friendship grants helper functions access to the private members of a class.
  friend double operator+=(double &left, const Account& right);




   };

}
#endif // SENECA_ACCOUNT_H_