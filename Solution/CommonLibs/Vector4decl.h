#pragma once

namespace CommonLibs
{
	namespace Math
	{
		template <typename Type>
		class Vector4
		{
		public:
			Vector4();
			Vector4(Type aX, Type aY, Type aZ, Type aW);
			~Vector4();

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
			union
			{
				Type myW;
				Type myA;
			};
		};
	}
}