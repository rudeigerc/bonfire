//
//
// config.h
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#ifndef CONFIG_H
#define CONFIG_H

#define KEY_ESC 27
#define KEY_SPACE 32

enum MENU_LIST {
	MENU_EXIT = 0,
	MENU_RESET,
	MENU_IMPORT_CUBE
};

const GLfloat material_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat material_ambient[] = { 0.15f, 0.15f, 0.15f, 1.0f };
const GLfloat material_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat material_shininess = 100.0f;

const GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light0_position[] = { -20.0f, 20.0f, 20.0f, 0.0f };
const GLfloat light1_position[] = { 50.0f, 20.0f, -50.0f, 1.0f };

const int max_particle = 100;
const int min_particle = 10;
const float delta_color_step = 5.0f / 255.0f;
const int particle_step = 2;

GLuint texture[1];
float delta_red_of_fire = 0.0f;

#endif