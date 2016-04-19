#pragma once

namespace CommonLibs
{
	namespace Math
	{
		template <typename T>
		class Matrix44
		{
		public:
			Matrix44();
			Matrix44(const Matrix44<T>& aMatrix);
			~Matrix44();

			void Init(T* aDataPointer);
			T myMatrix[4 * 4];

			static Matrix44<T> CreateRotateAroundX(T aAngleInRadians);
			static Matrix44<T> CreateRotateAroundY(T aAngleInRadians);
			static Matrix44<T> CreateRotateAroundZ(T aAngleInRadians);
			static Matrix44<T> RotateAroundAxis(const CU::Vector3<T>& aAxis, T aAngleInRadians);
			static Matrix44<T> CreateReflectionMatrixAboutAxis(CU::Vector3<T> aReflectionVector);
			static Matrix44<T> CreateProjectionMatrixLH(T aNearZ, T aFarZ, T aAspectRatio, T aFovAngle);
			static Matrix44<T> CreateOrthogonalMatrixLH(T aWidth, T aHeight, T aNearZ, T aFarZ);

			void SetPos(const CU::Vector3<T>& aPos);
			void SetPos(const CU::Vector4<T>& aPos);

			void NormalizeRotationVectors();

			CU::Vector3<T> GetPos() const;
			CU::Vector4<T> GetPos4() const;

			inline Matrix44<T> operator=(const Matrix44<T> aMatrix)
			{
				for (unsigned char i = 0; i < 16; ++i)
				{
					myMatrix[i] = aMatrix.myMatrix[i];
				}
				return *this;
			}

		private:
			void NormalizeVector(T* aMatrixEntry);
		};
	}
}