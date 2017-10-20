#include "celestialbody.h"

CelestialBody::CelestialBody(vec3 pos, vec3 vel, double mass_, std::string objectName) {
    position = pos;
    velocity = vel;
    mass = mass_;
    angularMomentum = vec3();
    this->objectName = objectName;

}

CelestialBody::CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_, std::string objectName) {
    position = vec3(x,y,z);
    velocity = vec3(vx,vy,vz);
    mass = mass_;
    angularMomentum = vec3();
    this->objectName = objectName;
}

void CelestialBody::resetForce() {
    force.zeros();
}
