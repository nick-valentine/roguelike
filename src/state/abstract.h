#ifndef STATE_ABSTRACT_H
#define STATE_ABSTRACT_H

#include <memory>

#include "../context.h"
#include "../window/abstract.h"

namespace state
{
	class Abstract;

	using ptr = std::unique_ptr<Abstract>;

	class Abstract
	{
	public:
		virtual ~Abstract() = default;
		virtual void update(Context *ctx) = 0;
		virtual void render(window::ptr &win) = 0;

		virtual Abstract *nextState();
		virtual void clearNextState();
		virtual bool shouldClose();
		virtual int passDown();
		virtual int passUp();
		virtual void recvDown(int msg);
		virtual void recvUp(int msg);
	protected:
		int mMsgDown = 0;
		int mMsgUp = 0;
		int mRecvMsgDown = 0;
		int mRecvMsgUp = 0;
		Abstract *mNextState = nullptr;
		bool mShouldClose = false;
	};
}

#endif // STATE_ABSTRACT_H