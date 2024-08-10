#include<iostream>
#include <cmath>

int radius = 10;
double height = 50.93;
double flow = -8;
int timee = 24;

int main() {
  double flowrate = 3.6*flow;
  double pi = M_PI;
  double tankvol = pi*(radius*radius)*height;
  double volume = flowrate*timee+tankvol;
  double percentfull = volume/tankvol;
  std::cout << volume << std::endl;
  if (percentfull >= 0.50) {
    std::cout << "Good to Go!" << std::endl;
  } else if (percentfull >= 0.25) {
    std::cout << "Look for More Fuel!" << std::endl;
  } else {
    std::cout << "Refuel Now!" << std::endl;
  }
  return 0;
}
