#pragma once

namespace CommonLibs
{
	namespace Math
	{
		template <typename Type>
		class Vector2
		{
		public:
			Vector2();
			Vector2(Type aX, Type aY);
			~Vector2();

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
		};
	}
}