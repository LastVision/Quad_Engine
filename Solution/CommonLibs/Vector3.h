#pragma once

#include <cmath>
#include <cassert>
#include "Vector3decl.h"

namespace CommonLibs
{
	namespace Math
	{
		template <typename T>
		Vector3<T>::Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		template <typename T>
		Vector3<T>::Vector3(T aX, T aY, T aZ)
		{
			x = aX;
			y = aY;
			z = aZ;
		}

		template <typename T>
		Vector3<T>::~Vector3()
		{
		}

		template <typename T>
		T Length(const Vector3<T>& aVector)
		{
			return sqrt(Length2(aVector));
		}

		template <typename T>
		T Length2(const Vector3<T>& aVector)
		{
			return Dot(aVector, aVector);
		}

		template <typename T>
		void Normalize(Vector3<T>& aVector)
		{
			if (aVector.myX == 0 && aVector.myY == 0 && aVector.myZ == 0)
			{
				//DL_DEBUG("Warning: Normalize zero vector.");
				return;
			}
			aVector = GetNormalized(aVector);
		}

		template <typename T>
		Vector3<T> GetNormalized(const Vector3<T>& aVector)
		{
			T length = Length(aVector);
			if (length == 0)
			{
				return aVector;
			}
			//assert(length != 0 && "Division by zero.");
			return Vector3<T>(aVector / length);
		}

		template <typename T>
		T Dot(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			return aFirstVector.myX * aSecondVector.myX + aFirstVector.myY * aSecondVector.myY + aFirstVector.myZ * aSecondVector.myZ;
		}

		template <typename T>
		Vector3<T> Cross(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			return Vector3<T>(
				aFirstVector.myY * aSecondVector.myZ - aFirstVector.myZ * aSecondVector.myY,
				aFirstVector.myZ * aSecondVector.myX - aFirstVector.myX * aSecondVector.myZ,
				aFirstVector.myX * aSecondVector.myY - aFirstVector.myY * aSecondVector.myX);
		}

		// operator with vector

		template <typename T>
		bool operator==(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			return aFirstVector.myX == aSecondVector.myX && aFirstVector.myY == aSecondVector.myY && aFirstVector.myZ == aSecondVector.myZ;
		}

		template <typename T>
		bool operator!=(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			return !(aFirstVector == aSecondVector);
		}

		template <typename T>
		Vector3<T> operator+(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			Vector3<T> result(aFirstVector);
			result += aSecondVector;
			return result;
		}
		template <typename T>
		Vector3<T> operator+=(Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			aFirstVector.myX += aSecondVector.myX;
			aFirstVector.myY += aSecondVector.myY;
			aFirstVector.myZ += aSecondVector.myZ;
			return aFirstVector;
		}

		template <typename T>
		Vector3<T> operator-(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			Vector3<T> result(aFirstVector);
			result -= aSecondVector;
			return result;
		}
		template <typename T>
		Vector3<T> operator-=(Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			aFirstVector.myX -= aSecondVector.myX;
			aFirstVector.myY -= aSecondVector.myY;
			aFirstVector.myZ -= aSecondVector.myZ;
			return aFirstVector;
		}

		template <typename T>
		Vector3<T> operator*(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			Vector3<T> result(aFirstVector);
			result *= aSecondVector;
			return result;
		}
		template <typename T>
		Vector3<T> operator*=(Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			aFirstVector.myX *= aSecondVector.myX;
			aFirstVector.myY *= aSecondVector.myY;
			aFirstVector.myZ *= aSecondVector.myZ;
			return aFirstVector;
		}

		template <typename T>
		Vector3<T> operator/(const Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			Vector3<T> result(aFirstVector);
			result /= aSecondVector;
			return result;
		}
		template <typename T>
		Vector3<T> operator/=(Vector3<T>& aFirstVector, const Vector3<T>& aSecondVector)
		{
			assert(aSecondVector.myX != 0 && aSecondVector.myY != 0 && aSecondVector.myZ != 0 && "Division by zero.");
			aFirstVector.myX /= aSecondVector.myX;
			aFirstVector.myY /= aSecondVector.myY;
			aFirstVector.myZ /= aSecondVector.myZ;
			return aFirstVector;
		}

		// operator with scalar

		template <typename T>
		Vector3<T> operator+(const Vector3<T>& aVector, T aScalar)
		{
			Vector3<T> result(aVector);
			result += aScalar;
			return result;
		}
		template <typename T>
		Vector3<T> operator+(T aScalar, const Vector3<T>& aVector)
		{
			return aVector + aScalar;
		}
		template <typename T>
		Vector3<T> operator+=(Vector3<T>& aVector, T aScalar)
		{
			aVector.myX += aScalar;
			aVector.myY += aScalar;
			aVector.myZ += aScalar;
			return aVector;
		}

		template <typename T>
		Vector3<T> operator-(const Vector3<T>& aVector, T aScalar)
		{
			Vector3<T> result(aVector);
			result -= aScalar;
			return result;
		}
		template <typename T>
		Vector3<T> operator-=(Vector3<T>& aVector, T aScalar)
		{
			aVector.myX -= aScalar;
			aVector.myY -= aScalar;
			aVector.myZ -= aScalar;
			return aVector;
		}

		template <typename T>
		Vector3<T> operator*(const Vector3<T>& aVector, T aScalar)
		{
			Vector3<T> result(aVector);
			result *= aScalar;
			return result;
		}
		template <typename T>
		Vector3<T> operator*(T aScalar, const Vector3<T>& aVector)
		{
			return aVector * aScalar;
		}
		template <typename T>
		Vector3<T> operator*=(Vector3<T>& aVector, T aScalar)
		{
			aVector.myX *= aScalar;
			aVector.myY *= aScalar;
			aVector.myZ *= aScalar;
			return aVector;
		}

		template <typename T>
		Vector3<T> operator/(const Vector3<T>& aVector, T aScalar)
		{
			Vector3<T> result(aVector);
			result /= aScalar;
			return result;
		}
		template <typename T>
		Vector3<T> operator/=(Vector3<T>& aVector, T aScalar)
		{
			//assert(aScalar != 0 && "Division by zero.");
			aVector.myX /= aScalar;
			aVector.myY /= aScalar;
			aVector.myZ /= aScalar;
			return aVector;
		}

		template <typename T>
		Vector3<T> operator-(const Vector3<T>& aVector)
		{
			return Vector3<T>(-aVector.myX, -aVector.myY, -aVector.myZ);
		}
	}
}