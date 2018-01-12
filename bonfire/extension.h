//
//
// extension.h
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#ifndef EXTENSION_H
#define EXTENSION_H

#include "time.h"
#include <random>

struct Color {
	float red;
	float green;
	float blue;
	float alpha;
};

// return the validated space of color
float valid_color_space(float, float&);

// convert hex6 to color
Color hex2color(unsigned int, float);

// generate random number between two floats
float random_f(float, float);

// split the string according to a char
std::vector<std::string> split(std::string, char);

#endif