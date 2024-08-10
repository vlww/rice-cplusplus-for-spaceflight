#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  /* Declare the variables, for example:
  float exhaustVelocity, massFlow, exhaustPressure, exitArea;
  */
  float increaseV, C, ogMass, finMass, param, result;
  C = 3100;
  finMass = 75000;
  increaseV = 700;
  ogMass = finMass*exp(increaseV/C);
  float prop = ogMass - finMass;
	
  // Define the variables - enter the values for each variables
  
  // Implement the calculation 
  cout << prop << endl;
  return 0;
  
}