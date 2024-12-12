#ifndef SENECA_INPUT_H
#define SENECA_INPUT_H
namespace seneca {
   /// <summary>
   ///
   /// </summary>
   /// <returns>The integer read from the console</returns>
   int getInt();

   /// <summary>
   ///
   /// </summary>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>The integer read from the console</returns>
   int getInt(int minVal, int maxVal);
   

   /// <summary>
   /// 
   /// </summary>
   /// <param name="number"></param>
   /// <param name="minVal">int: Minimum acceptable value</param>
   /// <param name="maxVal">int: Maximum acceptable value</param>
   /// <returns>bool: true if the number is successfully read, or false otherwise</returns>
   bool getInt(int& number,int minVal, int maxVal);
   

}
#endif // !SENECA_IO_H


