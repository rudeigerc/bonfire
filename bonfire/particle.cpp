//
//
// particle.cpp
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#include "extension.h"
#include "particle.h"

Particle::Particle() {
	life = 2.0f;
	color = glm::vec4(1.0f, 1.0f, 0.4f, 1.0f);
	position = glm::vec3(0.0f, 1.0f, 0.0f);
	velocity = glm::vec3(0.0f, 0.5f, 0.0f);
	acceleration = glm::vec3(0.0f, 0.05f, 0.0f);
	size = 1.0f;
	fading_rate = random_f(0.0f, 100.0f) / 1600.0f + 0.002f;
	status = true;
}

void Particle::reset() {
	size = 1.0f;
	life = 2.0f;
	fading_rate = random_f(0.0f, 100.0f) / 1600.0f + 0.002f;
	position = glm::vec3(0.0f, 1.0f, 0.0f);
	velocity = glm::vec3(random_f(-30.0f, 30.0f), random_f(-30.0f, 30.0f), random_f(-30.0f, 30.0f));
	acceleration = glm::vec3(0.0f, 0.3f, 0.0f);
}

void Particle::update() {
	position += velocity / (3072.0f);
	velocity += acceleration;
	life -= fading_rate;
	size -= 0.05f;
	if (life <= 0.0f) { 
		reset();
	}
}

void Particle::display(ObjLoader loader, float red) {
	if (!status) { 
		return; 
	}

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glPushMatrix();
	
	float x = position.x;
	float y = position.y;
	float z = position.z - 50.0f;
	float alpha = life / 2.0f;

	glColor4f(valid_color_space(color.r, red), color.g * alpha, color.b * alpha, alpha);
	glDepthMask(GL_FALSE);

	if (loader.is_loaded) {
		glRotated(45, 1.0, 1.0, 1.0);
		loader.calculate();
		GLfloat scale_coef = loader.scale / (size * 5.0f);
		glScalef(scale_coef, scale_coef, scale_coef);
		loader.draw();
	}
	else {
		glBegin(GL_QUADS);
		glTexCoord2i(0, 1);	glVertex3f(x - size, y + size, z);
		glTexCoord2i(0, 0);	glVertex3f(x - size, y - size, z);
		glTexCoord2i(1, 0);	glVertex3f(x + size, y - size, z);
		glTexCoord2i(1, 1);	glVertex3f(x + size, y + size, z);
		glEnd();
	}

	glDepthMask(GL_TRUE);
	glPopMatrix();
	glPopMatrix();
	update();
}