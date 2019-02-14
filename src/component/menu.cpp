#include "menu.h"

namespace component
{
	Menu::Menu(std::string head, std::vector<std::string> options, iPoint pos, iPoint size) :
	mHead(head), mOptions(options), mPos(pos), mSize(size)
	{}

	void Menu::render(window::ptr &win)
	{
		int maxHeight = std::min(mSize.y, (int)mOptions.size());
		win->putstr(iPoint(mPos.x + 1, mPos.y + 1), mHead, 0);
		for (int i = 0; i < maxHeight; ++i) {
			int color = mSelected == i ? 1 : 0;
			win->putstr(iPoint(mPos.x + 1, mPos.y + i + 2), mOptions[i], color);
		}
		this->drawBorder(win);
	}

	int Menu::update(Context *ctx)
	{
		switch (ctx->input) {
		case Input::UP:
			mSelected = std::max(mSelected - 1, 0);
			return -1;
		case Input::DOWN:
			mSelected = std::min(mSelected + 1, (int)mOptions.size() - 1);
			return -1;
		case Input::SELECT:
			return mSelected;
		case Input::BACK:
			return -2;
		default:
			return -1;
		}
	}

	void Menu::setDims(iPoint pos, iPoint size)
	{
		mPos = pos;
		mSize = size;
	}

	void Menu::drawBorder(window::ptr &win)
	{
		this->drawBar(win, iPoint(mPos.x, mPos.y), mSize.x);
		this->drawBar(win, iPoint(mPos.x, mPos.y + mSize.y), mSize.x);
		this->drawPipe(win, iPoint(mPos.x, mPos.y), mSize.y);
		this->drawPipe(win, iPoint(mPos.x + mSize.x, mPos.y), mSize.y);
	}

	void Menu::drawBar(window::ptr &win, iPoint pos, int width)
	{
		for (int i = 0; i < width; ++i) {
			win->put(0, 999, '-', iPoint(pos.x + i, pos.y));
		}
	}

	void Menu::drawPipe(window::ptr &win, iPoint pos, int height)
	{
		for (int i = 0; i < height; ++i) {
			win->put(0, 999, '|', iPoint(pos.x, pos.y + i));
		}
	}
}