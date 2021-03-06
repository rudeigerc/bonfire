//
//
// bonfire.cpp
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#include "windows.h"
#include "stdlib.h"
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include "config.h"
#include "camera.h"
#include "particle.h"
#include "texture_loader.h"
#include "obj_loader.h"

std::vector<Particle> particles;
Camera camera;
ObjLoader loader;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	for (Particle &particle : particles) {
		particle.display(loader, delta_red_of_fire);
	}
	
	glutSwapBuffers();
}

void idle() {
	display();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 200.0f);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 1.5, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case KEY_ESC:
		exit(0);
		break;
	case KEY_SPACE:
		delta_red_of_fire = 0.0f;
		while (particles.size() < max_particle) {
			particles.push_back(Particle());
		}
		break;
	case 'm':
		delta_red_of_fire += delta_color_step;
		break;
	case 'n':
		delta_red_of_fire -= delta_color_step;
		break;
	case 'w':
		camera.moveForward();
		break;
	case 'a':
		camera.rotateLeft();
		break;
	case 's':
		camera.moveBackward();
		break;
	case 'd':
		camera.rotateRight();
		break;
	case 'q':
		camera.moveUp();
		break;
	case 'e':
		camera.moveDown();
		break;
	case '-':
		for (int i = 0; i < particle_step; i++) {
			if (particles.size() > min_particle) {
				particles.pop_back();
			}
		}
		break;
	case '=':
		for (int i = 0; i < particle_step; i++) {
			if (particles.size() < max_particle) {
				particles.push_back(Particle());
			}
		}
		break;
	default:
		break;
	}
}

void menu_options(int option) {
	const char* path;
	switch (option) {
	case MENU_EXIT:
		exit(0);
		break;
	case MENU_RESET:
		delta_red_of_fire = 0.0f;
		while (particles.size() < max_particle) {
			particles.push_back(Particle());
		}
		break;
	case MENU_IMPORT_CUBE:
		loader.is_loaded = true;
		path = "cube.obj";
		if (!loader.load(path)) {
			printf("load object failed\n");
		}
		break;
	}
}

void create_menu() {
	int menu;
	menu = glutCreateMenu(menu_options);
	glutAddMenuEntry("Load", MENU_IMPORT_CUBE);
	glutAddMenuEntry("Reset", MENU_RESET);
	glutAddMenuEntry("Exit", MENU_EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);
	BuildTexture("fire.bmp", texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	for (int count = 0; count < max_particle; count++) {
		particles.push_back(Particle());
	}

	create_menu();
}

void print_info() {
	std::cout << "Bonfire" << std::endl;
	std::cout << "Author: Yuchen Cheng <rudeigerc@gmail.com>" << std::endl;
	std::cout << std::endl;
	std::cout << "- Instructions -" << std::endl;
	std::cout << "esc - Exit the particle system." << std::endl;
	std::cout << "esc - Reset the particle system." << std::endl;
	std::cout << "N - Decrease the 'Red' of RGBA." << std::endl;
	std::cout << "M - Increase the 'Red' of RGBA." << std::endl;
	std::cout << "- - Decrease the count of particles." << std::endl; 
	std::cout << "+ - Increase the count of particles." << std::endl;
}

int main(int argc, char *argv[]) {
	print_info();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bonfire");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
