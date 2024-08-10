// Start your code from here

#include <iostream>
#include <cmath>
using namespace std;

double M_sun = 1.989*pow(10,30);      // Mass of the Sun in kg
double M_earth = 5.972*pow(10,24);    // Mass of the Earth in kg
double M_moon = 0.073*pow(10,24);     // Mass of the Moon in kg
double R_sun = 149593870700;          // Distance between Sun-Earth  in m
double R_earth = 6371.000;            // Radius of the Earth in k
double R_moon = 1738.100;             // Radius of the Moon in km

int main() {
  double R_SOI = pow((M_earth/M_sun), 0.4)*R_sun;
  cout << R_SOI/1000 << endl;
  return 0;
}



