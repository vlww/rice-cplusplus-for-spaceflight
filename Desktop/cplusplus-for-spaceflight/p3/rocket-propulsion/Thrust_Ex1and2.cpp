#include <iostream>
#include <math.h>

using namespace std;

int main(){
  
  /* Declare the variables. 
   * Keep their data type in mind. Should everything be an integer? 
   * For example: */
  
  float exhaustVelocity, massFlow, exhaustPressure, exitArea;
  
  // Define the variables - enter the values for each variables
  massFlow = 30000; // kg/s
  exitArea = 0.7; // m2
  exhaustVelocity = 3100;
  exhaustPressure = 105;
  float ambientPressure = 100;
  
  // Implement the calculation 
  float thrust = massFlow * exhaustVelocity + (exhaustPressure-ambientPressure) * exitArea;
  float changeV = exhaustVelocity * log(massFlow) - 31767;
  // Output the results
  cout << "Change in velocity = " << changeV << " N" << endl;
  
  
  return 0;
  
}