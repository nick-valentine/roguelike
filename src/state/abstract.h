#ifndef STATE_ABSTRACT_H
#define STATE_ABSTRACT_H

#include <memory>

#include "../context.h"
#include "../window/abstract.h"
#include "../utility/log.h"

namespace state
{
	class Abstract;

	using ptr = std::unique_ptr<Abstract>;

	class Abstract
	{
	public:
		Abstract();
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

		virtual void setLogger(utility::logger::ptr log);
	protected:
		int mMsgDown = 0;
		int mMsgUp = 0;
		int mRecvMsgDown = 0;
		int mRecvMsgUp = 0;
		Abstract *mNextState = nullptr;
		bool mShouldClose = false;

		utility::logger::ptr mLog = nullptr;
	};
}

#endif // STATE_ABSTRACT_H