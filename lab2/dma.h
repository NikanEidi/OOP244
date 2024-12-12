#ifndef SENECA_DMA_H
namespace seneca {
   struct Contact{
      char
         m_name[21],
         m_lastname[31];
      long long
         m_phoneNumber;
   };

   /// <summary>
   /// Receives an unknown number of double numbers from the console and prints them in reverse order.
   /// </summary>
   void reverse();


   /// <summary>
   /// dynamically and gets its content from the console, then returns its address.
   /// </summary>
   /// <returns>Contact*: The address of the dynamically allocated Contact</returns>
   Contact* getContact();


   /// <summary>
   /// Prints a Contact in a line
   /// </summary>
   /// <param name="C">const reference of the Contact to be printed</param>
   void display(const Contact& C);
 

   /// <summary>
   ///
   /// </summary>
   /// <param name="C">Contact*: The address of the Contact to be deallocated</param>
   void deallocate(Contact* C); 
 

   /// <summary>
   /// 
   /// </summary>
   /// <param name="C">Contact&: Reference of a Contact to be emptied</param>
   void setEmpty(Contact& C);


}
#endif // !SENECA_DMA_H

