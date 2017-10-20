#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include "vec3.h"
#include <string>

class CelestialBody
{
public:
    vec3 position;
    vec3 velocity;
    vec3 force;
    vec3 angularMomentum;
    std::string objectName;
    double mass;

    CelestialBody(vec3 position, vec3 velocity, double mass, std::string objectName);
    CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass, std::string objectName);
    void resetForce();
};

#endif // CELESTIALBODY_H
