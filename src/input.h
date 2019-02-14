#ifndef INPUT_H
#define INPUT_H

#include <string>

enum class Input {
	IGNORED = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SELECT,
	BACK,
	ESCAPE
};

namespace inputMapping
{
	Input convert(std::string inputName);
}

#endif // INPUT_H