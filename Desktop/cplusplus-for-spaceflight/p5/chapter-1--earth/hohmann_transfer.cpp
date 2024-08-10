#include <iostream>
#include <cmath>
using namespace std;

double G = 6.67300 * pow(10, -11);
double M = 5.972 * pow(10, 24);
double Emu = 398600.442;  // Emu = G * M (It is also called gravitational parameter)

int main() {
    // Given values
    double a_parking = 7000;  // km
    double a_target = 20000;  // km

    // Parking speed orbit
    double V_parking = sqrt(Emu / a_parking);

    // Semi-major axis of the transfer trajectory
    double a_trans = (a_target + a_parking) / 2;

    // Velocity at periapsis of the transfer trajectory
    double V_perigee_trans = sqrt(Emu * (2.0 / a_parking - 1.0 / a_trans));

    // Delta V of the first maneuver
    double V1 = V_perigee_trans - V_parking;

    // Velocity at apoapsis of the transfer trajectory
    double V_apogee_trans = sqrt(Emu * (2.0 / a_target - 1.0 / a_trans));

    // Velocity of the target orbit
    double V_target = sqrt(Emu / a_target);

    // Delta V of the second maneuver
    double V2 = V_target - V_apogee_trans;

    // Total Delta V required
    double totalV = V1 + V2;

    cout << "Total V = " << totalV << endl;

    return 0;
}