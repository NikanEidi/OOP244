#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace seneca {

  // Default constructor
   Numbers::Numbers() { 
      setEmpty(); //Sets the object to a safe empty state (setEmpty()).
      m_isOriginal = false; //Sets the m_isOriginal flag to false.
   }
   //One argument constructor 
   Numbers::Numbers(const char* filename) {  
      setEmpty(); //Sets the object to a safe empty state (setEmpty()).
      m_isOriginal = true;//Sets the m_isOriginal flag to true.
      setFilename(filename); //Sets the filename of the class (setFilename())
      m_numCount = numberCount(); //Sets the number of the double values to be read from the file (sets m_numCount using numberCount())

      //If m_numCount is greater than zero and load() is successful, the values will be sorted.
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers; //If not successful, it will free the memory pointed by m_numbers and m_filename
         delete[] m_filename;
         setEmpty();                  //sets the object back to the safe empty state and sets the class NOT TO BE original anymore.
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   //initialize Deconstructor 
   Numbers::~Numbers(){
      //Save the values in the file by calling the save method 
       save();
       //delete the memory pointed by m_numbers and m_filename
       delete[] m_numbers;
       delete[] m_filename;
   }
   Numbers::Numbers(const Numbers& other) {
       setEmpty();
       m_isOriginal = false;
       if (!other.isEmpty()) {
           m_numCount = other.m_numCount;
           m_numbers = new double[m_numCount];
           for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = other.m_numbers[i];
           }
       }
   }
    
   Numbers& Numbers::operator=(const Numbers& other) {
       if (this != &other) {
           delete[] m_numbers;
           if (!other.isEmpty()) {
               m_numCount = other.m_numCount;
               m_numbers = new double[m_numCount];
               for (int i = 0; i < m_numCount; i++) {
                   m_numbers[i] = other.m_numbers[i];
               }
           }
       }
       return *this;
   }

   // !!!!!!!!!!!!! Member Functions and Member operator+= overload PART !!!!!!!!!!!!!!!!!

   //returns true if m_numbers is null
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr; 
   }
   //sets m_numbers and m_filename to nullptr. sets m_numCount to zero.
   void Numbers::setEmpty() { 

      //sets m_numbers and m_filename to nullptr.
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0; //sets m_numCount to zero.
   }
   /*
   setFilename() (implemented)
   Receives a constant Cstring for the data file name
   Frees the memory pointed by m_filename pointer
   Allocates memory to hold the data file name as a Cstring.
   Copies the data file name to the newly allocated memory.
   */
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   /*
      numberCount() (to be implemented)
      ****This private function**** (that is incapable of modifying the current object), 
      will return the number of lines in the data file (hence returning the number of double values in the file).

      1.Create an instance of ifstream to open the data file name.
      2.While the ifstream object has not failed keep reading single characters from the file
       .Count the number of newline characters in an integer variable
      4.Return the number of counted newlines when all characters in the file are scanned.
   */
  int Numbers::numberCount() const {
       int number_count = 0; 
       std::ifstream file(m_filename);
       char character;
       while (file.get(character)) {
           if (character == '\n'){
            number_count++;
           } 
       }
       return number_count;
   }
   /*load() (to be implemented)
     This function returns true if all the double values are read from the data file and stored in a dynamically allocated memory
     pointed by m_numbers, otherwise returns false.
     If the number of double values in the file is greater than zero (m_numCount > 0)
     Allocate m_numCouut doubles to hold the double values in an array pointed by m_numbers.
     Create an instance of ifstream using the data file name.
     While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)
     Make sure to add to the index of the loop only if the istream object has not failed in its last reading
     If the number of doubles read, is not equal to the m_numCount member variable, set the object to the safe empty state after deallocating the memory. Set the function to return false at the end.
     If the number of doubles read, is equal to the m_numCount member variable, set the function to return true at the end.
     return the success status.
     */
    bool Numbers:: load(){
      //condition to check is num count grather than zero
      if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           std::ifstream file(m_filename);
           int i = 0;
           while (file&& i < m_numCount) {
               file >> m_numbers[i++];
           }
           if (i != m_numCount) {
               delete[] m_numbers;
               setEmpty();
               return false;
           }
           return true;
       }
       return false;
    }
    //Sorts the double values in ascending order
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }
    /*
    save() (to be implemented)
   If the current object is the original and it is not in a safe empty state
   Create an instance of ofstream to overwrite the data file
   Write all the elements of the m_numbers array using the ofstream object.
   Write a newline after each double value.
   */
  void Numbers::save() {
       if (m_isOriginal && !isEmpty()) {
           std::ofstream file(m_filename);
           for (int i = 0; i < m_numCount; i++) {
               file << m_numbers[i] << std::endl;
           }
       }
   }
   //Returns the average of the double numbers in the list.
   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   //Returns the smallest double number in the list
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   //Returns the average of the double numbers in the list.
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   Numbers& Numbers::operator+=(double value) {
       if (!isEmpty()) {
           double* temp = new double[m_numCount + 1];
           for (int i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];
           }
           temp[m_numCount++] = value;
           delete[] m_numbers;
           m_numbers = temp;
           sort();
       }
       return *this;
   }

   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       if (N.isEmpty()) {
           os << "Empty list";
       }
       else {
           os << "=========================" << std::endl;
           os << (N.m_isOriginal ? N.m_filename : "*** COPY ***") << std::endl;
           for (int i = 0; i < N.m_numCount; i++) {
               int integerPart = static_cast<int>(N.m_numbers[i]);
               int decimalPart = static_cast<int>((N.m_numbers[i] - integerPart) * 100 + 0.5);
               os << integerPart << "." << (decimalPart < 10 ? "0" : "") << decimalPart;

               if (i < N.m_numCount - 1) os << ", ";
           }

           os << std::endl << "-------------------------" << std::endl;
           os << "Total of " << N.m_numCount << " number(s)" << std::endl;
           int maxInt = static_cast<int>(N.max());
           int maxDec = static_cast<int>((N.max() - maxInt) * 100 + 0.5);
           os << "Largest number:  " << maxInt << "." << (maxDec < 10 ? "0" : "") << maxDec << std::endl;

           int minInt = static_cast<int>(N.min());
           int minDec = static_cast<int>((N.min() - minInt) * 100 + 0.5);
           os << "Smallest number: " << minInt << "." << (minDec < 10 ? "0" : "") << minDec << std::endl;

           int avgInt = static_cast<int>(N.average());
           int avgDec = static_cast<int>((N.average() - avgInt) * 100 + 0.5);
           os << "Average:         " << avgInt << "." << (avgDec < 10 ? "0" : "") << avgDec << std::endl;

           os << "=========================";
       }
       return os;
   }

   std::istream& operator>>(std::istream& istr, Numbers& N) {
       double value;
       if (istr >> value) {
           N += value;
       }
       return istr;
   }

}
