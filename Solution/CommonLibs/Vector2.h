#pragma once
#include <cmath>
#include <cassert>
#include "Vector2decl.h"
namespace CommonLibs
{
	namespace Math
	{
		template <typename Type>
		Vector2<Type>::Vector2()
			: myX(0)
			, myY(0)
		{
		}

		template <typename Type>
		Vector2<Type>::Vector2(Type aX, Type aY)
			: myX(aX)
			, myY(aY)
		{
		}

		template <typename T>
		Vector2<T>::~Vector2()
		{
		}

		template <typename T>
		T Length(const Vector2<T>& aVector)
		{
			return T(sqrt(Length2(aVector)));
		}
		template <typename T>
		T Length2(const Vector2<T>& aVector)
		{
			return Dot(aVector, aVector);
		}

		template <typename T>
		void Normalize(Vector2<T>& aVector)
		{
			aVector = GetNormalized(aVector);
		}

		template <typename T>
		Vector2<T> GetNormalized(const Vector2<T>& aVector)
		{
			T length = Length(aVector);
			if (length == 0)
			{
				return Vector2<T>();
			}
			return Vector2<T>(aVector / length);
		}

		template <typename T>
		T Dot(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			return aFirstVector.myX * aSecondVector.myX + aFirstVector.myY * aSecondVector.myY;
		}

		template <typename T>
		bool operator==(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			return aFirstVector.myX == aSecondVector.myX && aFirstVector.myY == aSecondVector.myY;
		}

		template <typename T>
		bool operator!=(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			return !(aFirstVector == aSecondVector);
		}

		template <typename T>
		Vector2<T> operator+(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			Vector2<T> result(aFirstVector);
			result += aSecondVector;
			return result;
		}
		template <typename T>
		Vector2<T> operator+=(Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			aFirstVector.myX += aSecondVector.myX;
			aFirstVector.myY += aSecondVector.myY;
			return aFirstVector;
		}

		template <typename T>
		Vector2<T> operator-(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			Vector2<T> result(aFirstVector);
			result -= aSecondVector;
			return result;
		}
		template <typename T>
		Vector2<T> operator-=(Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			aFirstVector.myX -= aSecondVector.myX;
			aFirstVector.myY -= aSecondVector.myY;
			return aFirstVector;
		}

		template <typename T>
		Vector2<T> operator*(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			Vector2<T> result(aFirstVector);
			result *= aSecondVector;
			return result;
		}
		template <typename T>
		Vector2<T> operator*=(Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			aFirstVector.myX *= aSecondVector.myX;
			aFirstVector.myY *= aSecondVector.myY;
			return aFirstVector;
		}

		template <typename T>
		Vector2<T> operator/(const Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			Vector2<T> result(aFirstVector);
			result /= aSecondVector;
			return result;
		}
		template <typename T>
		Vector2<T> operator/=(Vector2<T>& aFirstVector, const Vector2<T>& aSecondVector)
		{
			assert(aSecondVector.myX != 0 && aSecondVector.myY != 0 && "Division by zero.");
			aFirstVector.myX /= aSecondVector.myX;
			aFirstVector.myY /= aSecondVector.myY;
			return aFirstVector;
		}

		template <typename T>
		Vector2<T> operator+(const Vector2<T>& aVector, T aScalar)
		{
			Vector2<T> result(aVector);
			result += aScalar;
			return result;
		}
		template <typename T>
		Vector2<T> operator+(T aScalar, const Vector2<T>& aVector)
		{
			return aVector + aScalar;
		}
		template <typename T>
		Vector2<T> operator+=(Vector2<T>& aVector, T aScalar)
		{
			aVector.myX += aScalar;
			aVector.myY += aScalar;
			return aVector;
		}

		template <typename T>
		Vector2<T> operator-(const Vector2<T>& aVector, T aScalar)
		{
			Vector2<T> result(aVector);
			result -= aScalar;
			return result;
		}

		template <typename T>
		Vector2<T> operator-=(Vector2<T>& aVector, T aScalar)
		{
			aVector.myX -= aScalar;
			aVector.myY -= aScalar;
			return aVector;
		}

		template <typename T>
		Vector2<T> operator*(const Vector2<T>& aVector, T aScalar)
		{
			Vector2<T> result(aVector);
			result *= aScalar;
			return result;
		}
		template <typename T>
		Vector2<T> operator*(T aScalar, const Vector2<T>& aVector)
		{
			return aVector * aScalar;
		}
		template <typename T>
		Vector2<T> operator*=(Vector2<T>& aVector, T aScalar)
		{
			aVector.myX *= aScalar;
			aVector.myY *= aScalar;
			return aVector;
		}

		template <typename T>
		Vector2<T> operator/(const Vector2<T>& aVector, T aScalar)
		{
			Vector2<T> result(aVector);
			result /= aScalar;
			return result;
		}
		template <typename T>
		Vector2<T> operator/=(Vector2<T>& aVector, T aScalar)
		{
			assert(aScalar != 0 && "Division by zero.");
			aVector.myX /= aScalar;
			aVector.myY /= aScalar;
			return aVector;
		}

		template <typename T>
		Vector2<T> operator-(const Vector2<T>& aVector)
		{
			return Vector2<T>(-aVector.myX, -aVector.myY);
		}
	}
}