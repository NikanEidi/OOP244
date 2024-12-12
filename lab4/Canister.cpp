#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {

   const double PI = 3.14159265;
   

   bool Canister::isEmpty() const {
      return m_contentVolume < 0.00001;
   }

   bool Canister::usable() const
   {
      return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
   }

   void Canister::setToUnusable(){
      freeMem(m_contentName);
      m_diameter = m_height = -1.0;
   }

   double Canister::capacity() const {
      return PI * (m_height-0.267) * (m_diameter/2) * (m_diameter / 2);
   }

      bool Canister::hasSameContent(const Canister& C)const {
      return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
   }

   double Canister::volume() const {
      return m_contentVolume;
   }
   //constructor declaration
   /*No-Argument Constructor (Default)
   Sets the attributes to their default values.*/
   Canister::Canister(){
      //Sets the attributes to their default values.
       m_contentName = nullptr;
       m_diameter = 10.0; 
       m_height = 13.0;   
       m_contentVolume = 0; 
   }
   /*one-Argument Constructor 
   Sets the attributes to their default values.
   Dynamically allocates and copies the contentName into memory pointed to by m_contentName (use the provided alocpy function).
   */
   Canister::Canister(const char* contentName){
      //Sets the attributes to their default values.
       m_contentName = nullptr;
       m_diameter = 10.0; 
       m_height = 13.0;   
       m_contentVolume = 0; 
       // Dynamically allocate and copy the contentName into memory pointed to by m_contentName
       alocpy(m_contentName,contentName);
   }
   /*two-Argument Constructor:(IT IS NOT PROVIDE IN GITHUB BUT FOR RUNING IS IMPORTANT)*/
   Canister::Canister(double height, double diameter){
      m_height=height;
      m_diameter=diameter;
      m_contentVolume = 0; 
      m_contentName = nullptr;
      if (!usable()) {
         setToUnusable();
      }
   }
   /*Three-Argument Constructor:
   Use usable method and alocpy function in this logic
   Sets the content name and the content value to their default values.
   Sets the height and diameter attributes to the corresponding incoming arguments.
   If the object is usable (use the private method):
   Dynamically allocates and copies the contentName into memory pointed to by m_contentName (use alocpy).
   */
   Canister::Canister(double height, double diameter, const char* contentName){
       //content name and the content value to their default values
       m_contentName = nullptr;
       m_contentVolume = 0;
       //height and diameter attributes to the corresponding incoming arguments.
       m_height = height;
       m_diameter = diameter; 
       //If the object is usable (use the private method):
       //Dynamically allocates and copies the contentName into memory pointed to by m_contentName (use alocpy).

       if (usable()) // condition to check object is usable
       {
         alocpy(m_contentName, contentName);
       }
   }
   /*Destructor declaration
   Deallocates the dynamic memory pointed to by the content name attribute (use freemem).*/
   Canister::~Canister(){
      //Deallocates the dynamic memory pointed to by the content name
      freeMem(m_contentName);
   }
   /*clear MethodClears a Canister back to an empty state by:
     Deallocating the memory pointed to by the content name attribute (use the freemem function)
     Setting the content volume attribute to 0.0
     At the end, it returns the reference to the current object.*/
   Canister& Canister::clear(){
      freeMem(m_contentName);//Deallocating the memory pointed to by the content name
      m_contentVolume = 0;//setting the content volume attribute to 0.0
      return *this;//returns the reference to the current object.
   }
   /*setContent Method*/
   Canister& Canister::setContent(const char* contentName){
      if (contentName != nullptr && usable()) //condition to check contentName argument is not null and the Canister is usable
      {
         if (m_contentName == nullptr || isEmpty())//condition to check the content name is null or the Canister is empty
         {
           alocpy(m_contentName, contentName);//set the name to the value pointed to by the contentName argument dynamically
         }
         else if (!hasSameContent(contentName)) //condition to check contentName argument and the object’s content name are not the same
         {
            setToUnusable();//the Canister will be rendered unusable.
         }            
      }
      return *this; //return the reference to the current Canister.
   }
   /*pour Method*/
   Canister& Canister::pour(double quantity){
      if (usable())//condition to check Canister is usable
      {
         if (quantity > 0 && (quantity + volume() <= capacity())) //condition to check quantity is positive and the sum of the quantity and the current volume is less than the capacity,
         {
             m_contentVolume += quantity; // add the quantity to the content volume.
         }
         else
         {
            setToUnusable();// render the Canister unusable.
         }         
      }
      return *this;//returns the reference to the current object.  
   }
   /*the pour method overload*/
   Canister& Canister::pour(Canister& can){
      if (usable())//condition to check Canister is usable
      {
         double space_available = capacity() - volume();
         if (can.volume() > space_available)//condition to check volume of the Canister argument is more than the (capacity - volume) of the current Canister
         {
            m_contentVolume = capacity();//the content volume of the current Canister will be set to the maximum that is the capacity of the Canister
            can.m_contentVolume -= space_available;//the content volume of the Canister argument will be reduced by the (capacity - volume) of the current Canister
         }
         else
         {
           pour(can.volume());//pour the content volume of the argument Canister into the current Canister
           can.m_contentVolume = 0.0;//set the content volume of the argument to zero
         }
         setContent(can.m_contentName);/*set the content of the current canister to the content name of the argument canister. 
                                       This will automatically render the current canister unusable if the contents are not the same.*/
      }
      return *this; //optional, returns the reference to the current object. 
   }
   std::ostream& Canister::display() const {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.width(7);
      cout << capacity() << "cc (";
      cout.width(4);
      cout << m_height << "x";
      cout.width(4);
      cout << m_diameter << ") Canister";
      if (!usable()) {
         cout << " is  Unusable   recycle!";
      }
      else {
         cout << " of ";
         cout.width(7);
         cout << volume() << "cc   " << (m_contentName?m_contentName:"Sanetized and Empty");
      }
      return cout;
   }
}
