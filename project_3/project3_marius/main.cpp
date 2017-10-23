#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "verlet.h"
using namespace std;

int main(int numArguments, char **arguments)
{
    int numTimesteps = 100000;
    if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;
    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    // Use with: solarSystem.createCelestialBody( position, velocity, mass );
    // We don't need to store the reference, but just call the function without a left hand side

    double M_sun = 2e30;//kg
    //solarSystem.createCelestialBody(vec3(-5.2e-3,0,0), vec3(0,-2.79e-3,0), 1.0 , "the Sun"); //This is for 3-body Sun-Earth-Jupiter system
    solarSystem.createCelestialBody(vec3(-1.02e-2,0,0), vec3(0,-3.51e-3,0), 1.0 , "the Sun");
    solarSystem.createCelestialBody(vec3(0.39, 0, 0), vec3(0, 2*M_PI*0.39/0.24, 0), 3.3e23/M_sun, "Mercury");
    solarSystem.createCelestialBody(vec3(0.72, 0, 0), vec3(0, 2*M_PI*0.72/0.615, 0), 4.9e24/M_sun, "Venus");
    solarSystem.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 , "Earth");
    solarSystem.createCelestialBody(vec3(1.52, 0, 0), vec3(0, 2*M_PI*1.52/1.88, 0), 6.6e23/M_sun, "Mars");
    solarSystem.createCelestialBody(vec3(5.2, 0, 0), vec3(0, 2*M_PI*5.2/11.8, 0), 1e-3, "Jupiter");
    solarSystem.createCelestialBody(vec3(9.54, 0, 0), vec3(0, 2*M_PI*9.54/29.44, 0), 5.5e26/M_sun, "Saturn");
    solarSystem.createCelestialBody(vec3(19.19, 0, 0), vec3(0, 2*M_PI*19.19/84.01, 0), 8.8e25/M_sun, "Uranus");
    solarSystem.createCelestialBody(vec3(30.06, 0, 0), vec3(0, 2*M_PI*30.06/164.79, 0), 1.03e26/M_sun, "Neptune");
    solarSystem.createCelestialBody(vec3(39.53, 0, 0), vec3(0, 2*M_PI*39.53/247.92, 0), 1.31e22/M_sun, "not-a-planet");


    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> &bodies = solarSystem.bodies();


    for(int i = 0; i < (int)bodies.size(); i++) {

        CelestialBody &body = bodies[i]; // Reference to this body
        solarSystem.calculateForcesAndEnergy();
        cout << "The position of " << body.objectName << " is " << body.position << " with velocity " << body.velocity << " and angular momentum " << body.angularMomentum << endl;
    }

    solarSystem.calculateForcesAndEnergy();
    cout << "Total energy before: " << solarSystem.totalEnergy() << endl;
    cout << "Total angular momentum before: " << solarSystem.angularMomentum() << endl;

    double dt = 0.001;
    Verlet integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(solarSystem);
        solarSystem.writeToFile("positions_f.xyz");
        //cout << "Total energy for iteration "<< timestep << " : " << solarSystem.totalEnergy() << endl;
        //cout << "Total angular momentum: " << solarSystem.angularMomentum() << endl;

    }

    solarSystem.calculateForcesAndEnergy();
    cout << "Total energy after: " << solarSystem.totalEnergy() << endl;
    cout << "Total angular momentum after: " << solarSystem.angularMomentum() << endl;




    cout << "I just created a solar system that has " << solarSystem.bodies().size() << " objects." << endl;
    //cout << "The potential energy of the system is "<< solarSystem.potentialEnergy()<<endl;
    cout << "The program simulates " << numTimesteps*dt << " years." << endl;
    return 0;
}
