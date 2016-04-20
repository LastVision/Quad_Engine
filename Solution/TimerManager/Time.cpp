#include "stdafx.h"

#include "Time.h"
#include <time.h>

namespace CommonLibs
{
	namespace Time
	{
		Time::Time(const TimeUnit aMicroSeconds, const TimeUnit aFrameMicroSeconds)
			: myMicroSeconds(aMicroSeconds)
			, myFrameMicroSeconds(aFrameMicroSeconds)
		{
		}

		Time::~Time()
		{
		}
	};
};
namespace CL = CommonLibs;