#include<iostream>

// Define the given values
int start_velocity = 15;
float t = 0;  //time
int height = 0;  //don't need for this problem but good to get in habit of defining all variables
float acceleration = (-9.81); //acceleration due to gravity
float velocity;
// Let's define the function first
float CalculateDrag(float Cd, float density, float velocity, float area) 
{
  // Declare the output variable
  float dragForce;
  
  // Applies the lift equation to calculate the lift force on an object
  liftForce = 0.5 * density * velocity * velocity * area * Cd;
  
  // The output of the function is the drag force
  return dragForce;
}

int main() {
  float mass, horizontalVelocity, densityAir, CrossSectionArea, Cd;

  while (VertVelocity > -8 && HorVelocity > 0) {
    DragForce = CalculateDrag (Cd, densityAir, HorVelocity, CrossSectionArea)
    HorAcceleration = DragForce / mass;
    t = t + 0.1; //be mindful of the time interval you choose
    VertVelocity = (start_Vvelocity + (VertAcceleration*t));  //Define the realtionship between the given values
    HorVelocity = (start_Hvelocity + (HorAcceleration*t));  //Define the realtionship between the given values

  }
  std::cout << "Time is " << t << std::endl;  //Display the time when the while loop is exited
  std::cout << "Velocity is " << velocity << std::endl;  //Display the velocity when the while loop is exited

}
