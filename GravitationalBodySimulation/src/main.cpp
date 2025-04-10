// SETUP HERE:: https://www.youtube.com/watch?v=uO__ntYT-2Q
#include <iostream>
#include "Bodies.h"
#include "UI.h"

#define EPSILON 1e-7

double G = 6.6743E-11;
double M_e = 5.972E24;
double M_m = 7.34767309E22;
double E_M_dist = 384400000;




class Simulation : public Window {
public:

	static const int n_bodies = 3;
	
	Body bodies[n_bodies];
	Vec3 bodyCols[n_bodies];

	std::vector<Vec3> trails[n_bodies];

	double simulationSpeed = 1E-2;
	int itterationsPerFrame = 100;

	double zoomRate = 1E-3;
	double panRate = 2E-2;
	Vec3 initalScalefactor = Vec3(1E-2, 1E-2, 1);


	// Correctly calling the base class constructor using the initializer list
	Simulation(unsigned int height, unsigned int width)
		: Window(height, width) {
		wireframe = true;
	
	}





	Vec3 ForceFromBodiesInteraction(Body b1, Body b2) {
		Vec3 fVec = (b1.position - b2.position).unit() * -((G * b1.mass * b2.mass) / pow((b1.position - b2.position).magnitude(), 2));
		return fVec;
	}


	void update(Body bodies[2], int n_bodies) {

		for (int i = 0; i < n_bodies; i++)
		{
			for (int j = 0; j < n_bodies; j++)
			{

				if (i != j) {
					Vec3 force = ForceFromBodiesInteraction(bodies[i], bodies[j]);
					bodies[i].addForce(force);
				}

			}
		}

		for (int i = 0; i < n_bodies; i++)
		{
			bodies[i].applyAllForces();
			bodies[i].updatePosition(simulationSpeed);
		}
	}







	bool OnUserCreate() override {

		SetScaleFactor(initalScalefactor);

		// Orbit
		bodies[0] = Body(2e10, 3, Vec3(0, 0, 0));
		bodies[1] = Body(1e4, 1.5, Vec3(50, 0, 0), Vec3(0, 2, 0));
		bodies[2] = Body(1e3, 1, Vec3(80, 0, 0), Vec3(0, -1.5, 0));


		// Three Body
		//bodies[0] = Body(1e8, 1, Vec3(-20, -20, 0));
		//bodies[1] = Body(1e8, 1, Vec3(0, 15, 0));
		//bodies[2] = Body(1e8, 1, Vec3(20, -20, 0));



		bodyCols[0] = Vec3(1, 0, 0);
		bodyCols[1] = Vec3(0, 1, 0);
		bodyCols[2] = Vec3(0, 0, 1);


		for (int i = 0; i < n_bodies; i++)
		{
			trails[i].push_back(bodies[i].position);
		}

		return true;
	}



	bool OnUserUpdate() override {
		
		if (GetMousePosition().x >= 0 && GetMousePosition().y >= 0) {
			if (GetMousePosition().x <= 25) {
				SetScreenOrigin(GetScreenOrigin() + Vec3(-panRate, 0, 0));
			}
			else if (GetMousePosition().x >= GetScreenSize().x - 25) {
				SetScreenOrigin(GetScreenOrigin() + Vec3(panRate, 0, 0));
			}
			else if (GetMousePosition().y <= 25) {
				SetScreenOrigin(GetScreenOrigin() + Vec3(0, panRate, 0));
			}
			else if (GetMousePosition().y >= GetScreenSize().y - 25) {
				SetScreenOrigin(GetScreenOrigin() + Vec3(0, -panRate, 0));
			}
		}



		if (IsScrollUp()) {
			SetScaleFactor(GetScaleFactor() + Vec3(zoomRate, zoomRate, 1));
		}

		if (IsScrollDown()) {
			SetScaleFactor(GetScaleFactor() - Vec3(zoomRate, zoomRate, 1));
		}


		for (int i = 0; i < itterationsPerFrame; i++)
		{
			update(bodies, n_bodies);
		}


		for (int i = 0; i < n_bodies; i++)
		{
			trails[i].push_back(bodies[i].position);

			DrawCircle(Circle(bodies[i].radius, bodies[i].position, 24), bodyCols[i]);

			for (int j = 0; j < trails[i].size() - 1; j++)
			{
				double width = bodies[i].radius / 2;

				DrawQuad(Quad(
					Vec3(trails[i][j])		- Vec3(width/2, 0, 0),
					Vec3(trails[i][j])		- Vec3(0, width/2, 0),
					Vec3(trails[i][j + 1])	+ Vec3(width/2, 0, 0),
					Vec3(trails[i][j + 1]	+ Vec3(0, width/2, 0))
				), bodyCols[i]);
			}
		
		}

		return true;

	}
};





int main() {

	Simulation sim = Simulation(800,1000);
	sim.Init();

}