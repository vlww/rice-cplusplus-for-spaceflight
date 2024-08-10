#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  /* Declare the variables, for example:
  float exhaustVelocity, massFlow, exhaustPressure, exitArea;
  */
  float isp, f, q, c, g0, ve, ae;
  // Define the variables - enter the values for each variables
  g0 = 9.8067;
  f = 1000*1000;
  q = 400;
  isp = f/(q*g0);
  // Implement the calculation 
  cout << isp << endl;
  return 0;
  
}