// Your code starts from here
#include <iostream>
#include <cmath>
using namespace std;

double G = 6.67300*pow(10,-11);  // N.m/kg^2
double M = 5.972*pow(10,24);     // kg
double R = 3.844e8;  
double T = 2.35e6;

int main() {
  double R = pow((G * M * T * T) / (4 * M_PI * M_PI), 1.0/3.0);
  double V = sqrt(G * M / R);
  cout << V << endl;
  return 0;
}