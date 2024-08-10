#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

float CalcVelocity(float velocity_o, float delta_v)
{
float v;

v = velocity_o + delta_v; //you'll have to redefine vo as v at the end

return v;
}

float CalcDisplacement(float velocity_o, float tiime)
{
float displacement;

displacement = (velocity_o*tiime);

return displacement;
}

float CalcDensity(float pressure, float mmass_air, float univ_gas_constant, float temperature)
{
float density;

density = (pressure*mmass_air) / (univ_gas_constant*temperature);

return density;
}

float CalcDrag(float density, float velocity, float drag_area, float drag_coeff)
{
float drag;

drag = 0.5 * density * velocity * velocity * drag_coeff;

return drag;
}

float CalcThrust(float prop_consump_rate, float exhaust_velocity, float pressure_exhaust, float pressure_ambient, float nozzle_exit_area)
{
float thrust;

thrust = (prop_consump_rate*exhaust_velocity) + ((pressure_exhaust - pressure_ambient)*nozzle_exit_area);

return thrust;
}

float CalcEffVe(float exhaust_velocity, float pressure_exhaust, float pressure_ambient, float nozzle_exit_area, float prop_consump_rate)
{
float C;

C = exhaust_velocity + (((pressure_exhaust - pressure_ambient)*nozzle_exit_area)/prop_consump_rate);

return C;
}

float CalcDeltaV(float effve, float mass_o, float mass_f)
{
float deltav;

deltav = effve*log(mass_o/mass_f);

return deltav;
}

float t = 0;
float dt = 1;
float ve;
float term1;
float term2;
float term3;
float term4;
float term5;
float term6;
float Ae = 0.7;
float Mo = 80000;
float q = 300;
float Pe = 101;
float R = 8314.46;
float v = 0;
float g = 9.81;
float vo = 0;
float Mf;
float heightreal = 0;
float dy;
float C;
float dv;
int i;
float Fd;
float Ft;
float prop;

int main(){

  float Pa;
  float Ta;
  float rho;
  float Ma = 29.5;
  float R = 8314.46;
  float cd = 0.1;
  float Ad = 240.426; //nose cone est. to be ~10% of total height

  float k = 1.2;
  float Tc = 3373.15;
  float M = 21.4;
  float Pc = 5066;
  term1 = (2*k) / (k-1);
  term2 = (R*Tc) / M;
  term5 = Pe/Pc;
  term6 = (k-1) / k;
  term4 = pow (term5, term6);
  term3 = 1 - term4;

  ve = sqrt(term1*term2*term3);

  ifstream inFileAP;
  ifstream inFileAT;
  ifstream inFileE;
  ofstream outFileD;

  inFileAP.open("AirPressure.txt");
  inFileAT.open("AirTemperature.txt");
  inFileE.open("Elevation.txt");
  outFileD.open("Data.txt", ios::trunc);

  float AP[26];
  float AT[26];
  float E[26];
  float x;
  float z;

  int iter = 0;
  while (inFileAP >> x) {
    AP[iter] = x*1e3;
    iter++;
  }

  iter = 0;
  while (inFileAT >> x) {
    AT[iter] = x;
    iter++;
  }

  iter =0;
  while (inFileE >> x) {
    E[iter] = x*1000;
    iter++;
  }

  outFileD << setw(20) << "Time" << setw(20) << "Speed" << setw(20) << "Elevation" << setw(20) << "Air Temperature" << setw(20) << "Air Pressure" << setw(20) << "Air Density" << setw(20) << "Drag Force" << setw(20) << "Thrust Force" << setw(20) << "Propellant Left" << endl;

  C = CalcEffVe(ve, Pe, 101, Ae, q);

  while (heightreal <= 500000 && t < 3600) {

    Mf = Mo - (q*t);

    dv = CalcDeltaV(C, Mo, Mf);

    v = CalcVelocity(vo, dv);

    dy = CalcDisplacement(v, dt);
    heightreal = heightreal + dy;

    i = 0;
    for (i = 0; i < 26; i++){
      if (heightreal == 0){
//        return i;
        break;
      }
      else {
        z = E[i] / heightreal;
        if (z >= 1){
//          return i;
          break;
        }
      }
    }

    Pa = AP[i];
    Ta = AT[i] + 273.15;

    rho = CalcDensity(Pa, Ma, R, Ta);

    Fd = CalcDrag(rho, v, Ad, cd);

    Ft = CalcThrust(q, ve, Pe, Pa, Ae);

    C = CalcEffVe(ve, Pe, Pa, Ae, q);

    prop = Mo - Mf;

    outFileD << setw(20) << t << setw(20) << v << setw(20) << heightreal << setw(20) << Ta << setw(20) << Pa << setw(20) << rho << setw(20) << Fd << setw(20) << Ft << setw(20) << Mf << endl;

    t = t + dt;
  }

  inFileAP.close();
  inFileAT.close();
  inFileE.close();
  outFileD.close();

  return 0;
}