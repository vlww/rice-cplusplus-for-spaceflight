#include<iostream>

using namespace std;
// Define the given values
float start_vert_velocity = 14.1421; 
float vert_velocity;
float start_height = 1.5;  
float height = 1.5;
float Vert_Acceleration = (-9.81); //acceleration due to gravity

float t = 0;
float time_interval = 0.01;

float horiz_distance = 0;
float Horiz_Acceleration;
float start_horiz_velocity = 14.1421;



// Place the Drag Force Function Here
float CalculateDrag(float drag_coeffcient, float density, float velocity, float area) 
{
  // Declare the output variable
  float dragForce;
  
  // Applies the lift equation to calculate the drag force on an object
  dragForce = 0.5 * density * velocity * velocity * area * drag_coeffcient;
  
  // The output of the function is the drag force
  return dragForce;  
}
//They give//////////////////////////////////////////////////////////////


int main() {
  
  float draggyForce = CalculateDrag(0.2, 1.28, 20, 0.025);
    
  cout << "The drag force is: " << draggyForce << " N" << endl;

  return 0;
}