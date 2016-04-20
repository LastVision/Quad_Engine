#include "stdafx.h"
#include "Timer.h"

namespace CommonLibs
{
	namespace Time
	{
		Timer::Timer()
			: myTotalTime(0)
			, myFrameTime(0)
			, myPaused(false)
		{
		}

		Timer::~Timer()
		{
		}

		void Timer::AddTime(const TimeUnit aMicroSeconds)
		{
			if (myPaused == false)
			{
				myTotalTime += aMicroSeconds;
				myFrameTime = aMicroSeconds;
			}
			else
			{
				myFrameTime = 0;
			}
		}
	};
};
namespace CL = CommonLibs;