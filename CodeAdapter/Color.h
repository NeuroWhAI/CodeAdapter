#ifndef __CA__COLOR_H__
#define __CA__COLOR_H__


#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class ColorT
{
public:
	static const ColorT<T> Transparent;
	static const ColorT<T> Black;
	static const ColorT<T> White;
	static const ColorT<T> Gray;
	static const ColorT<T> Red;
	static const ColorT<T> Green;
	static const ColorT<T> Blue;
	static const ColorT<T> Yellow;
	static const ColorT<T> Magenta;
	static const ColorT<T> Cyan;


public:
	ColorT();
	explicit ColorT(i32 argb);
	ColorT(const T& r, const T& g, const T& b);
	ColorT(const T& a, const T& r, const T& g, const T& b);
	virtual ~ColorT();


public:
	T a, r, g, b;


public:
	i32 getArgb() const;

	void setArgb(i32 argb);
	void setArgb(const T& a, const T& r, const T& g, const T& b);
	void setRgb(const T& r, const T& g, const T& b);
};


using Color = ColorT<i32>;
using ColorF = ColorT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Color.inl"


#endif