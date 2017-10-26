#include "solarsystem.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

SolarSystem::SolarSystem() :
    m_kineticEnergy(0),
    m_potentialEnergy(0)
{
}

void SolarSystem::createCelestialBody(vec3 position, vec3 velocity, double mass, std::string objectName) {
    m_bodies.push_back( CelestialBody(position, velocity, mass, objectName) );
}

void SolarSystem::calculateForcesAndEnergy()
{
    m_kineticEnergy = 0;
    m_potentialEnergy = 0;
    m_ang_mom.zeros();

    for(CelestialBody &body : m_bodies) {
        // Reset forces on all bodies
        body.force.zeros();
    }

    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = m_bodies[i];

        //calculate angular momentum
        vec3 pos = body1.position;
        vec3 vel = body1.velocity;
        double m = body1.mass;

        body1.angularMomentum = pos.cross(vel)*m;

        m_ang_mom += body1.angularMomentum;

        //m_ang_mom(0) = m*(pos(1)*vel(2) - pos(2)*vel(1));
        //m_ang_mom(1) = m*(pos(2)*vel(0) - pos(0)*vel(2));
        //m_ang_mom(2) = m*(pos(0)*vel(1) - pos(1)*vel(0));



        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = m_bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();
            // Calculate the force and potential energy here
            double G = 4*pow(M_PI,2);
            vec3 tempForce = G*body1.mass * body2.mass * deltaRVector/pow(dr,3);
            body1.force -= tempForce;
            body2.force += tempForce;
            m_potentialEnergy += -G*body1.mass*body2.mass/dr;

        }

        m_kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();
    }
}

int SolarSystem::numberOfBodies() const
{
    return m_bodies.size();
}

double SolarSystem::totalEnergy() const
{
    return m_kineticEnergy + m_potentialEnergy;
}

double SolarSystem::potentialEnergy() const
{
    return m_potentialEnergy;
}

double SolarSystem::kineticEnergy() const
{
    return m_kineticEnergy;
}

vec3 SolarSystem::angularMomentum() const
{
    return m_ang_mom;
}

void SolarSystem::writeToFile(string filename)
{
    if(!m_file.good()) {
        m_file.open(filename.c_str(), ofstream::out);
        if(!m_file.good()) {
            cout << "Error opening file " << filename << ". Aborting!" << endl;
            terminate();
        }
    }

    for(CelestialBody &body : m_bodies) {
        m_file << setprecision(10) << body.position.x() << " " << setprecision(10) << body.position.y() << " " << setprecision(10) << body.position.z()<< " ";
    }
    m_file << "\n";
}

std::vector<CelestialBody> &SolarSystem::bodies()
{
    return m_bodies;
}
