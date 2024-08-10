#include <iostream>
#include <cmath>
#include <string> 

using namespace std; 

const double G = 6.67408e-11;      // Gravitational constant
const double SUN_MASS = 1.989e30;  // Mass of the sun

// <Your code goes here>
class body {
  public:
    string name;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double mass;
    double radius;

    void compute_acc(double x, double y, double & ax,double & ay){
      // ax and ay are the x and y components of the acceleration vector, respectively.
      // <Insert your code here>
      int av = sqrt(ax*ax+ay*ay);
      cout << av << endl;
    }
};

int main(){
  body earth;
  body sun;
  earth.mass = 5.972e24;
  return 0;
}

