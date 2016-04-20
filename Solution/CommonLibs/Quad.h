#pragma once
#include "Vector2.h"

namespace CommonLibs
{
	namespace Math
	{
		namespace Shape
		{
			struct Quad
			{
				Quad(){};
				Quad(const Vector2<float>& aSize)
					: myExtents(aSize)
				{}

				void Update(const Vector2<float>& aCenter)
				{
					myMin = aCenter - myExtents / 2.f;
					myMax = aCenter + myExtents / 2.f;
					myCenter = aCenter;
				}

				Vector2<float> myMin;
				Vector2<float> myMax;
				Vector2<float> myExtents;
				Vector2<float> myCenter;
			};
		};
	};
};
namespace CL = CommonLibs;