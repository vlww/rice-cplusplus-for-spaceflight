// Start your code from here:

#include <iostream>
#include <cmath>
using namespace std;

double G = 6.67300*pow(10,-11); // Universal Gravitation Constant [N.m/kg^2]
double M = 5.972*pow(10,24);    // Mass of the Earth [kg]
double R = 6378140;             // Radius of the Earth [m]
double h1 = 250000;     // [m]
double h2 = 500000;     // [m]
double rp, ra, a, vp, va;

int main() {
  rp = R + h1;
  ra = R + h2;
  a = (ra+rp)/2;
  vp = G*M*((2/rp)-(1/a));
  va = G*M*((2/ra)-(1/a));
  cout << "Vp = " << sqrt(vp) << endl;
  cout << "Va = " << sqrt(va) << endl;
  return 0;
}