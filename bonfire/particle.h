//
//
// particle.h
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <gl/glut.h>
#include "obj_loader.h"

class Particle {
private:
	glm::vec4 color;	// red, green, blue, alpha
	glm::vec3 position;	// x, y, z
	glm::vec3 velocity;
	glm::vec3 acceleration;
	float size;
	float life;
	float fading_rate;
	bool status;

	void reset();
	void update();

public:
	Particle();
	void display(ObjLoader, float);
};

#endif