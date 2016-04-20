#pragma once
#include <cassert>
namespace CommonLibs
{
	namespace Time
	{
		typedef unsigned long long TimeUnit;

		class Time
		{
		public:
			Time(TimeUnit aMicroSeconds, TimeUnit aFrameMicroSeconds);
			~Time();
			
			TimeUnit GetHours() const;
			TimeUnit GetMinutes() const;
			TimeUnit GetSeconds() const;
			TimeUnit GetMilliseconds() const;
			TimeUnit GetMicroseconds() const;
			TimeUnit GetFPS() const;
			float GetFrameTime() const;

		private:
			TimeUnit myMicroSeconds;
			TimeUnit myFrameMicroSeconds;
		};

	};
};
namespace CL = CommonLibs;

namespace CommonLibs
{
	namespace Time
	{
		inline TimeUnit Time::GetHours() const
		{
			return GetMinutes() / 60;
		}
		inline TimeUnit Time::GetMinutes() const
		{
			return myMicroSeconds / 60000000;
		}
		inline TimeUnit Time::GetSeconds() const
		{
			return myMicroSeconds / 1000000;
		}
		inline TimeUnit Time::GetMilliseconds() const
		{
			return myMicroSeconds / 1000;
		}
		inline TimeUnit Time::GetMicroseconds() const
		{
			return myMicroSeconds;
		}
		inline TimeUnit Time::GetFPS() const
		{
			assert(myFrameMicroSeconds > 0 && "GetFps tried to divide by 0. Can't Check FPS while timer is paused.");
			return 1000000 / myFrameMicroSeconds;
		}
		inline float Time::GetFrameTime() const
		{
			return myFrameMicroSeconds / 1000.f;
		}
	}
};
namespace CL = CommonLibs;