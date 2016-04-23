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


END_NAMESPACE_CA_DRAWING

