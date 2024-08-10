// Your code starts from here

#include <iostream>
#include <cmath>
using namespace std;

double G = 6.67300*pow(10,-11);  // N-m/kg^2
double M = 5.972*pow(10,24); // kg
double R = 6380; // km
double h = 336e3;

int main() {
  double Vescape = sqrt(2 * G * M / R);
  double V_kmh = 3.90e4;
  double V = V_kmh * (1000.0 / 3600.0);
  cout << Vescape << " m/s" << endl;
  cout << V << "m/s" << endl;
  if (V<=Vescape) {
    cout << "Escaped" << endl;
  } else {
    cout << "Didn't escape" << endl;
  }
  return 0;
}