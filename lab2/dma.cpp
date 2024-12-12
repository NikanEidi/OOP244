//Nikan EIdi
#include <iostream>//cout and cin identifier
#include "dma.h" //define our header and use "" cause its my header
using namespace std;//using namespace to dont write std in cout

namespace seneca {
   // Reverses an array of double values entered by the user
   void reverse() {
      int elements;  // Number of elements in the array
      
      // Get the number of double values to be entered
      cout << "Enter the number of double values:\n> ";
      cin >> elements;

      // Dynamically allocate an array for 'n' double values
      double* array = new double[elements];

      // Get the double values from the user
      for (int i = 0; i < elements; i++) {
         cout << (i + 1) << "> ";
         cin >> array[i];
      }

      // Print the values in reverse order
      for (int i = elements - 1; i >= 0; i--) {
         cout << array[i] << endl;
      }

      // Deallocate the dynamic array
      delete[] array;
   }

   // y creates and write  a Contact with user input
   Contact* getContact() {
      Contact* newContact = new Contact;  // Dynamically allocate a new Contact

      // Get the contact details from the user
      cout << "Name: ";
      cin >> newContact->m_name;
      cout << "Last name: ";
      cin >> newContact->m_lastname;
      cout << "Phone number: ";
      cin >> newContact->m_phoneNumber;

      return newContact;  // Return the pointer to the created Contact
   }

   // Displays the cotacts
   void display(const Contact& C) {
      cout << C.m_name << " " << C.m_lastname << ", +" << C.m_phoneNumber << endl;
   }

   // memory deallocation
   void deallocate(Contact* C) {
      delete C;  // Free the memory occupied by the Contact
   }

   
   void setEmpty(Contact& C) {//pass by refreunce
      C.m_name[0] = '\0';  // Set name to an empty string
      C.m_lastname[0] = '\0';  // Set last name to an empty string
      C.m_phoneNumber = 0;  // Set phone number to zero
   }
}
