#ifndef KEYMAP_H
#define KEYMAP_H

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>

#include "input.h"

class Keymap
{
public:
	Keymap();

	Input convert(int rawInput);
private:
	const static std::string mapFile;

	using flat = std::vector< std::pair< std::string, std::string > >;
	flat loadFile();
	void createMap(flat mappings);
	
	std::map<int, Input> mInputMap;
};

#endif // KEYMAP_H