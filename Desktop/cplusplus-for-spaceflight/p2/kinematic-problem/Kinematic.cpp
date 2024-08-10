#include<iostream>
using namespace std;

// Define the given values
int start_velocity = 23;
float t = 0;  //time
float height = 0;  //don't need for this problem but good to get in habit of defining all variables
float acceleration = (-9.81); //acceleration due to gravity
float velocity;

int main() {
  while (velocity > -10) {
    t = t + 0.00001; //be mindful of the time interval you choose
    velocity = (start_velocity + (acceleration*t));  //Define the realtionship between the given values
    height = ((velocity+start_velocity)/2)*t;
  }
  cout << "Time is " << t << endl;  //Display the time when the while loop is exited
  cout << "Velocity is " << velocity << endl;  //Display the velocity when the while loop is exited
  cout << "Height is " << height << endl;

}
