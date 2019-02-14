#ifndef UTILITY_ROUTE_H
#define UTILITY_ROUTE_H

#include "matrix.h"

namespace utility
{
	class InvalidMap : public std::exception
	{
	public:
		virtual char const *what() const noexcept
		{
			return "can not route a map of size 0";
		}
	};

	template <typename T>
	class Route
	{
	public:
		Route(Matrix<T> map);
		std::vector<iPoint> find(iPoint from, iPoint to, bool(*collidable)(T));
	private:
		static const int mMoveCost = 10;

		std::vector< std::vector<int> > heuristic(iPoint from, iPoint to, bool(*collidable)(T));
		bool validElement(iPoint x);
		bool inList(const std::vector<iPoint> &list, iPoint p);
		void addOpenList(iPoint p);
		void addElement(iPoint n, iPoint c);
		iPoint findSmallestOpen();

		Matrix<T> mMap;
		iPoint mSize;
		Matrix<int> mHeuristic;
		Matrix<int> mMovementCost;
		Matrix<int> mGPlusH;
		Matrix<iPoint> mParent;
		std::vector<iPoint> mClosedList;
		std::vector<iPoint> mOpenList;
	};

	template <typename T>
	Route<T>::Route(Matrix<T> map) : mMap(map)
	{
		if (map.size() == 0) {
			throw InvalidMap();
		}
		if (map[0].size() == 0) {
			throw InvalidMap();
		}
	}

	template <typename T>
	std::vector<iPoint> Route<T>::find(iPoint from, iPoint to, bool(*collidable)(T))
	{
		mSize = iPoint(mMap.size(), mMap[0].size());
		static const int initValSentinel = 9999;
		matrix::fill(mMovementCost, mSize, initValSentinel);
		matrix::fill(mGPlusH, mSize, initValSentinel);
		matrix::fill(mParent, mSize, iPoint(-1,-1));
		mHeuristic = this->heuristic(from, to, collidable);
		mClosedList.push_back(from);
		addOpenList(from);

		while (true) {
			if (mOpenList.empty()) {
				// no route to to
				return std::vector<iPoint>();
			}
			auto nextNode = findSmallestOpen();
			if (nextNode.x == to.x && nextNode.y == to.y) {
				//end was found
				break;
			}
			mClosedList.push_back(nextNode);
			std::remove_if(mOpenList.begin(), mOpenList.end(), [=](iPoint f)->bool { return f.x == nextNode.x && f.y == nextNode.y; });
			addOpenList(nextNode);
		}
		iPoint it = to;
		std::vector<iPoint> route;
		while (it.x != from.x && it.y != from.y) {
			route.push_back(it);
			it = mParent[it.x][it.y];
		}
		return route;
	}

	template <typename T>
	std::vector< std::vector<int> > Route<T>::heuristic(iPoint from, iPoint to, bool(*collidable)(T))
	{
		static const int wallSentinel = 9999;
		std::vector< std::vector<int> > heuristic;

		for (int i = 0; i < mMap.size(); ++i) {
			heuristic.push_back(std::vector<int>());
			for (int j = 0; j < mMap[i].size(); ++j) {
				if (collidable(mMap[i][j])) {
					heuristic[i].push_back(wallSentinel);
				} else {
					auto x = std::abs(i - to.x);
					auto y = std::abs(j - to.y);
					heuristic[i].push_back(x + y);
				}
			}
		}
		return heuristic;
	}

	template <typename T>
	bool Route<T>::validElement(iPoint x)
	{
		return x.x < mSize.x && x.x >= 0 && x.y < mSize.y && x.y >= 0;
	}

	template <typename T>
	bool Route<T>::inList(const std::vector<iPoint> &list, iPoint p)
	{
		auto it = std::find_if(list.begin(), list.end(), [=](iPoint f)->bool { return f.x == p.x && f.y == p.y; });
		return it != list.end();
	}

	template <typename T>
	void Route<T>::addOpenList(iPoint p)
	{
		// top
		addElement(iPoint{p.x, p.y-1}, p);
		// bottom
		addElement(iPoint{p.x, p.y+1}, p);
		// left
		addElement(iPoint{p.x-1, p.y}, p);
		// right
		addElement(iPoint{p.x+1, p.y}, p);
	}

	template <typename T>
	void Route<T>::addElement(iPoint n, iPoint c)
	{
		if (!validElement(n) || inList(mClosedList, n)) {
			return;
		}
		if (!inList(mOpenList, n)) {
			mOpenList.push_back(n);
			mParent[n.x][n.y] = c;
			mGPlusH[n.x][n.y] = mHeuristic[n.x][n.y] + mMoveCost;
			return;
		}
		int newG = mMovementCost[c.x][c.y] + mMoveCost;
		if (newG < mMovementCost[n.x][n.y]) {
			mParent[n.x][n.y] = c;
		}
	}

	template <typename T>
	iPoint Route<T>::findSmallestOpen()
	{
		int smallestGPH = 99999;
		iPoint smallestItem{0,0};
		int gph = 0;

		for (const auto &i : mOpenList) {
			gph = mGPlusH[i.x][i.y];
			if (gph < smallestGPH) {
				smallestGPH = gph;
				smallestItem = i;
			}
		}
		return smallestItem;
	}
}

#endif // UTILITY_ROUTE_H