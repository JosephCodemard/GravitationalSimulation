#include "Bodies.h"

Body::Body(float m, float rad, Vec3 pos, Vec3 vel) {
	mass = m;
	radius = rad;
	position = pos;
	velocity = vel;
	totalForce = Vec3(0, 0, 0);
}


void Body::applyForceImmediately(Vec3 force) {
	velocity += (force / mass);
}

void Body::addForce(Vec3 force) {
	totalForce = totalForce + force;
}

void Body::applyAllForces() {
	velocity += (totalForce / mass);
	totalForce = Vec3(0, 0, 0);
}

void Body::updatePosition(double dt=1) {
	position += (velocity * dt);
}

void Body::_printInfo() {
	std::cout << "Radius: " << radius << ", Mass : " << mass << " | x : " << position.x << ", y : " << position.y << ", z : " << position.z << " | dx : " << velocity.x << ", dy : " << velocity.y << ", dz : " << velocity.z << std::endl;
}

