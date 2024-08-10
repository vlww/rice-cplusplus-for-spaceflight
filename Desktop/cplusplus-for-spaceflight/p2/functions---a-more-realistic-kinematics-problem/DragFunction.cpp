#include <iostream>

using namespace std;

/* If there were any "global" variables, you would declare them here, 
 * right after the header files and the namespace declarations.
 * All other variables that are defined inside a function, 
 * are only valid inside that function. 
 * For example, variables declared "inside" the function CalculateLift 
 * can't be accessed by the main() function and vice-versa.can */
float g = 9.81;   // Acceleration due to gravity

// Let's define the function first
float CalculateLift(float Cl, float density, float velocity, float area) 
{
  // Declare the output variable
  float liftForce;
  
  // Applies the lift equation to calculate the lift force on an object
  liftForce = 0.5 * density * velocity * velocity * area * Cl;
  
  // The output of the function is the drag force
  return liftForce;  
}

// Now let's try and use the lift function in the main() function
int main() {
  
  // First, as always, declare the relevant parameters
  float CL, rho, v, A, Flift;
  
  // Next we will assign values to the parameters
  CL = 0.1;    // Lift coefficient - measured experimentally or through CFD
  rho = 1.225; // Density of the air
  v = 50;      // Velocity of the object through air
  A = 34e-4;  // Lift area
  
  Flift = CalculateLift(CL, rho, v, A);
    
  cout << "The lift force is: " << Flift << " N" << endl;

  return 0;
}