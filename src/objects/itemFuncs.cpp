#include "itemFuncs.h"

namespace objects
{
	void createMapping()
	{
		std::vector<bool(*)(Item *i, EntityAttribute *)> v{
			heal<5>,
			heal<10>,
			heal<-5>,
			heal<-10>,
		};
		std::vector<int> assign{
			0,
			1,
			2,
			3,
			4
		};

		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> dist(0, v.size()-1);

		mapping.clear();
		for (const auto &i : assign) {
			mapping[i] = v[dist(mt)];
		}
	}
}