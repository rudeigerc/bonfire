//
//
// camera.h
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
private:
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 position;
	glm::vec3 target;

public:
	Camera();
	glm::mat4 getView();
	glm::mat4 getProjection();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBackward();
	void rotateLeft();
	void rotateRight();
	
};

#endif