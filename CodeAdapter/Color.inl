#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
const ColorT<T> ColorT<T>::Transparent = { T(0), T(0), T(0), T(0) };
template <typename T>
const ColorT<T> ColorT<T>::Black = { T(255), T(0), T(0), T(0) };
template <typename T>
const ColorT<T> ColorT<T>::White = { T(255), T(255), T(255), T(255) };
template <typename T>
const ColorT<T> ColorT<T>::Gray = { T(255), T(128), T(128), T(128) };
template <typename T>
const ColorT<T> ColorT<T>::Red = { T(255), T(255), T(0), T(0) };
template <typename T>
const ColorT<T> ColorT<T>::Green = { T(255), T(0), T(255), T(0) };
template <typename T>
const ColorT<T> ColorT<T>::Blue = { T(255), T(0), T(0), T(255) };
template <typename T>
const ColorT<T> ColorT<T>::Yellow = { T(255), T(255), T(255), T(0) };
template <typename T>
const ColorT<T> ColorT<T>::Magenta = { T(255), T(255), T(0), T(255) };
template <typename T>
const ColorT<T> ColorT<T>::Cyan = { T(255), T(0), T(255), T(255) };
template <typename T>
const ColorT<T> ColorT<T>::Silver = { T(255), T(192), T(192), T(192) };

//###########################################################################

template <typename T>
ColorT<T>::ColorT()
	: a(T())
	, r(T())
	, g(T())
	, b(T())
{

}


template <typename T>
ColorT<T>::ColorT(i32 argb)
{
	setArgb(argb);
}


template <typename T>
ColorT<T>::ColorT(const ColorT<T>& original, const T& newAlpha)
	: a(newAlpha)
	, r(T(original.r))
	, g(T(original.g))
	, b(T(original.b))
{

}


template <typename T>
ColorT<T>::ColorT(const T& r, const T& g, const T& b)
	: a(T(255))
{
	setRgb(r, g, b);
}


template <typename T>
ColorT<T>::ColorT(const T& a, const T& r, const T& g, const T& b)
{
	setArgb(a, r, g, b);
}


template <typename T>
ColorT<T>::~ColorT()
{

}

//###########################################################################

template <typename T>
i32 ColorT<T>::getArgb() const
{
	return (((static_cast<i32>(a) & 0x000000ff) << 24)
		| ((static_cast<i32>(r) & 0x000000ff) << 16)
		| ((static_cast<i32>(g) & 0x000000ff) << 8)
		| (static_cast<i32>(b) & 0x000000ff));
}


template <typename T>
i32 ColorT<T>::getRgba() const
{
	return (((static_cast<i32>(r) & 0x000000ff) << 24)
		| ((static_cast<i32>(g) & 0x000000ff) << 16)
		| ((static_cast<i32>(b) & 0x000000ff) << 8)
		| (static_cast<i32>(a) & 0x000000ff));
}

//--------------------------------------------------------------------------

template <typename T>
void ColorT<T>::setArgb(i32 argb)
{
	a = static_cast<T>((argb >> 24) & 0x000000ff);
	r = static_cast<T>((argb >> 16) & 0x000000ff);
	g = static_cast<T>((argb >> 8) & 0x000000ff);
	b = static_cast<T>(argb & 0x000000ff);
}


template <typename T>
void ColorT<T>::setArgb(const T& a, const T& r, const T& g, const T& b)
{
	this->a = a;
	this->r = r;
	this->g = g;
	this->b = b;
}


template <typename T>
void ColorT<T>::setRgb(const T& r, const T& g, const T& b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

//###########################################################################

template <typename T>
template <typename T2>
ColorT<T>::operator ColorT<T2>() const
{
	return ColorT<T2>(static_cast<T2>(a),
		static_cast<T2>(r),
		static_cast<T2>(g),
		static_cast<T2>(b));
}

//###########################################################################

template <typename T>
bool ColorT<T>::operator== (const ColorT<T>& right) const
{
	return equals(right, Identity<T>());
}


template <typename T>
bool ColorT<T>::operator!= (const ColorT<T>& right) const
{
	return !this->operator==(right);
}

//###########################################################################

template <typename T>
template <typename ARG_TYPE>
bool ColorT<T>::equals(const ColorT<T>& right, Identity<ARG_TYPE>) const
{
	return ((a == right.a)
		&& (r == right.r) && (g == right.g) && (b == right.b));
}


template <typename T>
bool ColorT<T>::equals(const ColorT<T>& right, Identity<f32>) const
{
	const float epsilon = std::numeric_limits<T>::epsilon();
	return (abs(a - right.a) < epsilon
		&& abs(r - right.r) < epsilon
		&& abs(g - right.g) < epsilon
		&& abs(b - right.b) < epsilon);
}


END_NAMESPACE_CA_DRAWING

