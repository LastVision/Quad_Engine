#pragma once
#include "Time.h"
namespace CommonLibs
{
	namespace Time
	{
		class Timer
		{
		public:
			Timer();
			~Timer();
			void AddTime(const TimeUnit aMicroSeconds);

			Time GetTime() const;
			void Pause();
			void Start();
		private:
			bool myPaused;
			TimeUnit myTotalTime;
			TimeUnit myFrameTime;
		};

	};
};
namespace CL = CommonLibs;

namespace CommonLibs
{
	namespace Time
	{
		inline Time Timer::GetTime() const
		{
			return Time(myTotalTime, myFrameTime);
		}

		inline void Timer::Pause()
		{
			myPaused = true;
		}

		inline void Timer::Start()
		{
			myPaused = false;
		}
	};
};
namespace CL = CommonLibs;