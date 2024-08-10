#include <iostream>
#include <cmath>
using namespace std;

double G = 6.67300 * pow(10, -11);    // N.m/kg^2
double M = 5.972 * pow(10, 24);       // kg
double Earth_mu = 3.986 * pow(10, 5); // km^3/s^2
double Ri = 8228;    // km
double Rj = 389.0;   // km
double Rk = 6888;    // km
double Vi = -0.7000; // km/s
double Vj = 6.600;   // km/s
double Vk = -0.6000; // km/s
double R, V, E, u, a;

int main() {
    R = sqrt(Ri * Ri + Rj * Rj + Rk * Rk);
    V = sqrt(Vi * Vi + Vj * Vj + Vk * Vk);
    u = G * M / 1e9; 
    E = (V * V) / 2 - (u / R);
    a = -u / (2 * E);
    cout << "a = " << a << endl;
    return 0;
}