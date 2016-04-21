#pragma once
#include "Timer.h"
#include <vector>
#include <unordered_map>
namespace CommonLibs
{
	namespace Time
	{
		typedef unsigned int TimerHandle;
		class TimerManager
		{
		public:
			TimerManager();
			~TimerManager();

			void StartTimer(const std::string& aName);
			Time StopTimer(const std::string& aName);
			const Timer& GetTimer(TimerHandle aId) const;
			const Timer& GetMasterTimer() const;
			TimerHandle CreateTimer();
			void Update();
			void PauseAll();
			void StartAll();

			void CapFrameRate(float aFrameRate);
		private:
			Timer myMasterTimer;
			TimeUnit GetTime();
			std::vector<Timer> myTimerList;
			TimeUnit myLastTime;
			unsigned long long myFrequency;

			std::unordered_map<std::string, TimeUnit> myTimers;
		};
	};
};
namespace CL = CommonLibs;

namespace CommonLibs
{
	namespace Time
	{
		inline const Timer& TimerManager::GetMasterTimer() const
		{
			return myMasterTimer;
		}

		inline TimerHandle TimerManager::CreateTimer()
		{
			myTimerList.push_back(Timer());
			return static_cast<TimerHandle>(myTimerList.size() - 1);
		}

		inline const Timer& TimerManager::GetTimer(TimerHandle aID) const
		{
			return myTimerList[aID];
		}

		inline void TimerManager::PauseAll()
		{
			for (int i = 0; i < myTimerList.size(); ++i)
			{
				myTimerList[i].Pause();
			}
		}

		inline void TimerManager::StartAll()
		{
			for (int i = 0; i < myTimerList.size(); ++i)
			{
				myTimerList[i].Start();
			}
		}
	};
};
namespace CL = CommonLibs;