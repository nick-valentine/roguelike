#include "keyMap.h"

const std::string Keymap::mapFile = "GameData/keymap.txt";

Keymap::Keymap()
{
	auto m = loadFile();
	createMap(m);
	mInputMap[27] = Input::ESCAPE;
}

Input Keymap::convert(int rawInput)
{
	if (mInputMap.find(rawInput) != mInputMap.end()) {
		return mInputMap[rawInput];
	}
	return Input::IGNORED;
}

Keymap::flat Keymap::loadFile()
{
	flat configPairs;
	std::ifstream ifile(Keymap::mapFile.c_str());
	while (ifile.good()) {
		std::string tmp;
		std::getline(ifile, tmp);

		std::stringstream ss;
		ss.str(tmp);
		std::pair<std::string, std::string> mapPair;
		ss>>mapPair.first>>mapPair.second;
		configPairs.push_back(mapPair);
	}
	return configPairs;
}

void Keymap::createMap(Keymap::flat mappings)
{
	for (const auto &i : mappings) {
		if (i.first.size() == 1) {
			mInputMap[i.first[0]] = inputMapping::convert(i.second);
		}
	}
}