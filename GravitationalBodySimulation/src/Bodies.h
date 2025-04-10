#pragma once
#include "primitives.h"

class Body
{
public:

	Vec3 velocity;
	Vec3 position;
	float mass;
	float radius;

	Body(float mass=1, float radius=1, Vec3 pos=Vec3(0,0,0), Vec3 vel=Vec3(0,0,0));

	void applyForceImmediately(Vec3 force);

	void addForce(Vec3 force);
	void applyAllForces();

	void updatePosition(double dt);

	void _printInfo();

private:
	Vec3 totalForce;
};