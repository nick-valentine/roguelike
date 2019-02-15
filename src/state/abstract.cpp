#include "abstract.h"

namespace state
{
	Abstract::Abstract()
	{
		mLog = std::make_shared<utility::logger::Null>();
	}

	int Abstract::passDown()
	{
		return mMsgDown;
	}

	int Abstract::passUp()
	{
		return mMsgUp;
	}

	void Abstract::recvDown(int msg)
	{
		mRecvMsgDown = msg;
	}

	void Abstract::recvUp(int msg)
	{
		mRecvMsgUp = msg;
	}

	Abstract *Abstract::nextState()
	{
		return mNextState;
	}

	void Abstract::clearNextState()
	{
		mNextState = nullptr;
	}

	bool Abstract::shouldClose()
	{
		return mShouldClose;
	}

	void Abstract::setLogger(utility::logger::ptr log)
	{
		mLog = log;
	}
}