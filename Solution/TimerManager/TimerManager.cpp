#include "stdafx.h"

#include "Time.h"
#include "TimerManager.h"
#include <SDL.h>

namespace CommonLibs
{
	namespace Time
	{
		TimerManager::TimerManager()
		{
			myLastTime = static_cast<TimeUnit>(SDL_GetTicks());
		}

		TimerManager::~TimerManager()
		{
		}

		void TimerManager::Update()
		{
			TimeUnit time = GetTime();

			myMasterTimer.AddTime(time);

			for (unsigned int i = 0; i < myTimerList.size(); ++i)
			{
				myTimerList[i].AddTime(time);
			}

			myLastTime += time;
		}

		void TimerManager::StartTimer(const std::string& aName)
		{
			TimeUnit current = static_cast<TimeUnit>(SDL_GetTicks());

			myTimers[aName] = current;
		}

		Time TimerManager::StopTimer(const std::string& aName)
		{
			if (myTimers.find(aName) == myTimers.end()) return Time(0, 0);

			TimeUnit current = static_cast<TimeUnit>(SDL_GetTicks());
			TimeUnit result = current - myTimers[aName];

			return Time(result, 0);
		}

		

		TimeUnit TimerManager::GetTime()
		{
			TimeUnit current = static_cast<TimeUnit>(SDL_GetTicks());
			return (current - myLastTime);
		}
	};
};
namespace CL = CommonLibs;