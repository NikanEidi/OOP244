#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
   class Numbers {
      //Member Functions and Member operator+= overload
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const; 
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      /*
      numberCount() (to be implemented)
      ****This private function**** (that is incapable of modifying the current object), 
      will return the number of lines in the data file (hence returning the number of double values in the file).
      */
      int numberCount() const;
      /*
      load() (to be implemented)
      This function returns true if all the double values are read from the data file and stored in a dynamically allocated memory pointed by m_numbers, 
      otherwise returns false.
      */
     bool load();
     /*
     save() (to be implemented)
     */
     void save();
   public:
      //Default constructor
      Numbers();
      //One argument constructor
      Numbers(const char* filename);
      //Destructor
      ~Numbers();
      Numbers(const Numbers& other);
      Numbers& operator=(const Numbers& other);
      double average()const;
      double max()const;
      double min()const;
      Numbers& operator+=(double value);

      friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
      friend std::istream& operator>>(std::istream& istr, Numbers& N);

   };
}
#endif // !SENECA_NUMBERS_H_

