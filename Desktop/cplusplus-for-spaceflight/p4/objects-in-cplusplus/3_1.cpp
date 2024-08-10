#include <iostream>
#include <string>
using namespace std; 

// <Your code goes here>

class car {       // The class
  public:             // Access specifier
    string name;
    int weight;        // Attribute (int variable)
    string color;  // Attribute (string variable)
    string bodyType;
    double fuelLevel;
};

int main(){
  car tesla;
  tesla.name = "Tesla_Model3_CCV2544";
  tesla.weight = 3552;
  tesla.color = "Pearl White";
  tesla.bodyType = "Sedan";
  tesla.fuelLevel = 13.75;
  car lexus;
  lexus.name = "Lexus_ES350_FTG7677";
  lexus.weight = 3649;
  lexus.color = "Atomic Silver";
  lexus.bodyType = "Sedan";
  lexus.fuelLevel = 16.13;
  cout << tesla.name << endl;
  return 0;
}