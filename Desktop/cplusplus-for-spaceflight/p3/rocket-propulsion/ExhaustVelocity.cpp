#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  /* Declare the variables, for example:
  float exhaustVelocity, massFlow, exhaustPressure, exitArea;
  */
  float ve, k, r, m, tc, pe, pc;
  // Define the variables - enter the values for each variables
  k = 1.2;
  r = 8314.46;
  tc = 3050.0;
  m = 21.4;
  pe = 1.0;
  pc = 50.0;
  // Implement the calculation 
  ve = sqrt(((2*k)/(k-1))*((r*tc)/m)*pow(1-(pe/pc),((k-1)/k)))-1000;
  cout << ve << endl;
  return 0;
  
}