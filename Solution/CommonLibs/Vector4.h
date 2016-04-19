#pragma once

#include <cmath>
#include <cassert>
#include "Vector4decl.h"

namespace CommonLibs
{
	namespace Math
	{
		template <typename T>
		Vector4<T>::Vector4()
			: myX(0)
			, myY(0)
			, myZ(0)
			, myW(0)
		{
		}

		template <typename T>
		Vector4<T>::Vector4(T aX, T aY, T aZ, T aW)
			: myX(aX)
			, myY(aY)
			, myZ(aZ)
			, myW(aW)
		{
		}

		template <typename T>
		Vector4<T>::~Vector4()
		{
		}

		template <typename T>
		T Length(const Vector4<T>& aVector)
		{
			return sqrt(Length2(aVector));
		}

		template <typename T>
		T Length2(const Vector4<T>& aVector)
		{
			return Dot(aVector, aVector);
		}

		template <typename T>
		void Normalize(Vector4<T>& aVector)
		{
			if (aVector.myX == 0 && aVector.myY == 0 && aVector.myZ == 0 && aVector.myW == 0)
			{
				//DL_DEBUG("Warning: Normalize zero vector.");
				return;
			}
			aVector = GetNormalized(aVector);
		}

		template <typename T>
		Vector4<T> GetNormalized(const Vector4<T>& aVector)
		{
			T length = Length(aVector);
			if (length == 0)
			{
				return aVector;
			}
			//assert(length != 0 && "Division by zero.");
			return Vector4<T>(aVector / length);
		}

		template <typename T>
		T Dot(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			return aFirstVector.myX * aSecondVector.myX + aFirstVector.myY * aSecondVector.myY + aFirstVector.myZ * aSecondVector.myZ + aFirstVector.myW * aSecondVector.myW;
		}

		// operator with vector

		template <typename T>
		bool operator==(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			return aFirstVector.myX == aSecondVector.myX && aFirstVector.myY == aSecondVector.myY && aFirstVector.myZ == aSecondVector.myZ && aFirstVector.myW == aSecondVector.myW;
		}

		template <typename T>
		bool operator!=(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			return !(aFirstVector == aSecondVector);
		}

		template <typename T>
		Vector4<T> operator+(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			Vector4<T> result(aFirstVector);
			result += aSecondVector;
			return result;
		}
		template <typename T>
		Vector4<T> operator+=(Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			aFirstVector.myX += aSecondVector.myX;
			aFirstVector.myY += aSecondVector.myY;
			aFirstVector.myZ += aSecondVector.myZ;
			aFirstVector.myW += aSecondVector.myW;
			return aFirstVector;
		}

		template <typename T>
		Vector4<T> operator-(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			Vector4<T> result(aFirstVector);
			result -= aSecondVector;
			return result;
		}
		template <typename T>
		Vector4<T> operator-=(Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			aFirstVector.myX -= aSecondVector.myX;
			aFirstVector.myY -= aSecondVector.myY;
			aFirstVector.myZ -= aSecondVector.myZ;
			aFirstVector.myW -= aSecondVector.myW;
			return aFirstVector;
		}

		template <typename T>
		Vector4<T> operator*(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			Vector4<T> result(aFirstVector);
			result *= aSecondVector;
			return result;
		}
		template <typename T>
		Vector4<T> operator*=(Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			aFirstVector.myX *= aSecondVector.myX;
			aFirstVector.myY *= aSecondVector.myY;
			aFirstVector.myZ *= aSecondVector.myZ;
			aFirstVector.myW *= aSecondVector.myW;
			return aFirstVector;
		}

		template <typename T>
		Vector4<T> operator/(const Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			Vector4<T> result(aFirstVector);
			result /= aSecondVector;
			return result;
		}
		template <typename T>
		Vector4<T> operator/=(Vector4<T>& aFirstVector, const Vector4<T>& aSecondVector)
		{
			assert(aSecondVector.myX != 0 && aSecondVector.myY != 0 && aSecondVector.myZ != 0 && aSecondVector.myW != 0 && "Division by zero.");
			aFirstVector.myX /= aSecondVector.myX;
			aFirstVector.myY /= aSecondVector.myY;
			aFirstVector.myZ /= aSecondVector.myZ;
			aFirstVector.myW /= aSecondVector.myW;
			return aFirstVector;
		}

		// operator with scalar

		template <typename T>
		Vector4<T> operator+(const Vector4<T>& aVector, T aScalar)
		{
			Vector4<T> result(aVector);
			result += aScalar;
			return result;
		}
		template <typename T>
		Vector4<T> operator+(T aScalar, const Vector4<T>& aVector)
		{
			return aVector + aScalar;
		}
		template <typename T>
		Vector4<T> operator+=(Vector4<T>& aVector, T aScalar)
		{
			aVector.myX += aScalar;
			aVector.myY += aScalar;
			aVector.myZ += aScalar;
			aVector.myW += aScalar;
			return aVector;
		}

		template <typename T>
		Vector4<T> operator-(const Vector4<T>& aVector, T aScalar)
		{
			Vector4<T> result(aVector);
			result -= aScalar;
			return result;
		}
		template <typename T>
		Vector4<T> operator-=(Vector4<T>& aVector, T aScalar)
		{
			aVector.myX -= aScalar;
			aVector.myY -= aScalar;
			aVector.myZ -= aScalar;
			aVector.myW -= aScalar;
			return aVector;
		}

		template <typename T>
		Vector4<T> operator*(const Vector4<T>& aVector, T aScalar)
		{
			Vector4<T> result(aVector);
			result *= aScalar;
			return result;
		}
		template <typename T>
		Vector4<T> operator*(T aScalar, const Vector4<T>& aVector)
		{
			return aVector * aScalar;
		}
		template <typename T>
		Vector4<T> operator*=(Vector4<T>& aVector, T aScalar)
		{
			aVector.myX *= aScalar;
			aVector.myY *= aScalar;
			aVector.myZ *= aScalar;
			aVector.myW *= aScalar;
			return aVector;
		}

		template <typename T>
		Vector4<T> operator/(const Vector4<T>& aVector, T aScalar)
		{
			Vector4<T> result(aVector);
			result /= aScalar;
			return result;
		}
		template <typename T>
		Vector4<T> operator/=(Vector4<T>& aVector, T aScalar)
		{
			//assert(aScalar != 0 && "Division by zero.");
			aVector.myX /= aScalar;
			aVector.myY /= aScalar;
			aVector.myZ /= aScalar;
			aVector.myW /= aScalar;
			return aVector;
		}

		template <typename T>
		Vector4<T> operator-(const Vector4<T>& aVector)
		{
			return Vector4<T>(-aVector.myX, -aVector.myY, -aVector.myZ, -aVector.myW);
		}
	}
}