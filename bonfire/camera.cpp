//
//
// camera.cpp
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#include "camera.h"

Camera::Camera() {

}

glm::mat4 Camera::getView() {
	return view;
}

glm::mat4 Camera::getProjection() {
	return projection;
}

void Camera::moveUp() {
	return;
}

void Camera::moveDown() {
	return;
}

void Camera::moveForward() {
	return;
}

void Camera::moveBackward() {
	return;
}

void Camera::rotateLeft() {
	return;
}

void Camera::rotateRight() {
	return;
}