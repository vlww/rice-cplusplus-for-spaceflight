// This code implements numerical integration (4th order Range-Kutta) method and 
// solves the equations of motion of different planetary objects to compute the
// trajectory in space

#include <iostream>
#include <cmath>
#include <vector>
#include <string> 
#include "matplotlibcpp.h" 

using namespace std; 
namespace plt = matplotlibcpp;

const double SUN_MASS = 1.989e30;
const double SUN_RADIUS = 695700000.0;
const double G = 6.67408e-11;
const double EARTH_X0 = -147095000000.0;
const double EARTH_Y0 = 0.0;
const double EARTH_VX0 = 0.0;
const double EARTH_VY0 = -30038.6;          // trying to get a uniform circular motion. Change this
const double EARTH_MASS = 5.972e24;
const double EARTH_RADIUS = 6371000.0;
const double dt = 86400.0; // 1 earth day in seconds

#define PI 3.14159265

class Body {          // The class
  public:             // Access specifier
    string Name;        
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double Mass;
    double Radius;
    
    //Constructor
    Body(string a1,double a2, double a3, double a4, double a5, double a6, double a7){
        Name = a1;
        pos_x = a2;
        pos_y = a3;
        vel_x = a4;
        vel_y = a5;
        Mass = a6;
        Radius = a7;
    }
    
    //Function
    void compute_acc(double x,double y,double & ax,double & ay);
    void step(double dt, Body * sun);
};

void Body::compute_acc(double x,double y,double & ax,double & ay){
    ax = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (pos_x-x)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
    ay = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (pos_y-y)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
}
void Body::step(double dt, Body * sun){
    double k1x, k1y, k2x, k2y, k3x, k3y, k4x, k4y;
    double k1vx, k1vy, k2vx, k2vy, k3vx, k3vy, k4vx, k4vy;
    
    // Computing coefficients for 4th order Runge-Kutta integrator
    k1x = vel_x;
    k1y = vel_y;    
    sun->compute_acc(pos_x, pos_y, k1vx, k1vy);    // k1vx, k1vy
    k2x = vel_x + dt/2 * k1vx;
    k2y = vel_y + dt/2 * k1vy;    
    sun->compute_acc( pos_x + dt/2 * k1x , pos_y + dt/2 * k1y , k2vx , k2vy);    // k2vx, k2vy
    k3x = vel_x + dt/2 * k2vx;
    k3y = vel_y + dt/2 * k2vy;    
    sun->compute_acc( pos_x + dt/2 * k2x , pos_y + dt/2 * k2y , k3vx , k3vy);    // k3vx, k3vy
    k4x = vel_x + dt * k3vx;
    k4y = vel_y + dt * k3vy;    
    sun->compute_acc( pos_x + dt * k3x , pos_y + dt * k3y , k4vx , k4vy);        // k4vx, k4vy
    
    // finding position and velocity at next time step using Runge-Kutta Numerical Integration
    pos_x = pos_x + dt/6 * (k1x + 2*k2x + 2*k3x + k4x);
    pos_y = pos_y + dt/6 * (k1y + 2*k2y + 2*k3y + k4y);
    vel_x = vel_x + dt/6 * (k1vx + 2*k2vx + 2*k3vx + k4vx);
    vel_y = vel_y + dt/6 * (k1vy + 2*k2vy + 2*k3vy + k4vy);
}

int main(){
    // Creating the celestial bodies
    Body sun("Sun",0,0,0,0,SUN_MASS,SUN_RADIUS);    // x, y, vx, vy of sun are all 0 since its set as the center
    Body earth("Earth", EARTH_X0, EARTH_Y0,EARTH_VX0, EARTH_VY0, EARTH_MASS, EARTH_RADIUS);
    
    // Some important variables
    int N_len = 365;            // Simulation time in number of days
    string title_str;
    std::vector<double> x, y;
    plt::figure_size(600, 600);

    // The sun
    std::vector<double> x1_sun_vis, y1_sun_vis, theta_vis, x2_sun_vis, y2_sun_vis;
    for (int del_theta = 0; del_theta <360; del_theta++){
        // theta_vis.push_back(del_theta);
        x1_sun_vis.push_back(10*cos(PI*del_theta/180));
        y1_sun_vis.push_back(10*sin(PI*del_theta/180));
        x2_sun_vis.push_back(6*cos(PI*del_theta/180));
        y2_sun_vis.push_back(6*sin(PI*del_theta/180));
    }

    // Exercise: implement a for loop to compute the trajectory of a single planet around the Sun
    for (int nstep=0; nstep < N_len-1; nstep++){
        x.push_back(earth.pos_x/1e9);       // Units: million Km
        y.push_back(earth.pos_y/1e9);       // Units: million Km
        
        // plotting
        plt::clf();
        plt::plot(x1_sun_vis,y1_sun_vis,"yo-");
        plt::plot(x2_sun_vis,y2_sun_vis,"ro-");
        plt::plot(x, y,"b:");
        plt::xlim(-200, 200);
        plt::ylim(-200, 200);
        plt::xlabel("Millions of Km");
        plt::ylabel("Millions of Km");
        plt::text(12, 12, "Sun");
        title_str = "Earth's Trajectory\n" + to_string(nstep) + " Days";
        plt::title(title_str);
 
        
        // Crashing condition
        if ( ( abs(x.back()) < 8 ) && ( abs(y.back()) < 8 )){
          break;
        }
        // Compute the next position and velocity 
        earth.step(dt, &sun);
        plt::pause(0.001);
    }
    plt::show();
    return 0;
}


