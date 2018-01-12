//
//
// extension.cpp
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//

#include "extension.h"

float valid_color_space(float origin, float &delta) {
	float space = origin + delta;
	if (space < 0.0f) { 
		delta = -1.0f;
		return 0.0f; 
	}
	else if (space > 1.0f) {
		delta = 0.0f;
		return 1.0f; 
	}
	else return space;
}

Color hex2color(unsigned int hex6, float alpha = 1.0f) {
	Color color = Color();
	float divisor = 255.0f;
	color.red = ((hex6 & 0xFF0000) >> 16) / divisor;
	color.green = ((hex6 & 0x00FF00) >> 8) / divisor;
	color.blue = (hex6 & 0x0000FF) / divisor;
	color.alpha = alpha;
	return color;
}

float random_f(float min, float max) {
	//srand((unsigned int)time(NULL));
	float random = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
	return random;
}

std::vector<std::string> split(std::string str, char pattern)
{
	int pos;
	std::vector<std::string> result;
	str += pattern;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		pos = str.find(pattern, i);
		if (pos < size) {
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos;
		}
	}
	return result;
}