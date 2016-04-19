#pragma once

namespace CommonLibs
{
	namespace Math
	{
		template <typename Type>
		class Vector3
		{
		public:
			Vector3();
			Vector3(Type aX, Type aY, Type aZ);
			~Vector3();

			union
			{
				Type myX;
				Type myR;
			};
			union
			{
				Type myY;
				Type myG;
			};
			union
			{
				Type myZ;
				Type myB;
			};
		};
	}
}