#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  // Declare and initialize the vector
  double height[18];
    double weight[18];     // Declaring an array to store the values
    double x =0.0;  
    double y =0.0;                    
    ifstream inFile1, inFile2;      // File stream objects
    
    inFile1.open("height.txt");    // open file 

  // read 1st file line by line
    int iter = 0;
    while (inFile1 >> x) {         // We are using x as a temporary variable
        height[iter] = x;          // Save the value in an array
        iter++;                    // Keeping a track of the number of entries in the array
    }

    inFile1.close();   
                 // Closing files
    inFile2.open("weight.txt");
    iter = 0;
    while (inFile2 >> y) {         // We are using x as a temporary variable
        weight[iter] = y;          // Save the value in an array
        iter++;                    // Keeping a track of the number of entries in the array
    }
    inFile2.close();
    vector<double> g; 
    cout << "vector g1" << endl;


    return 0;
}
