#ifndef __CA__COLOR_H__
#define __CA__COLOR_H__


#include "BasicDeclaration.h"




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
	static const ColorT<T> Silver;


public:
	ColorT();
	explicit ColorT(i32 argb);
	ColorT(const ColorT<T>& original, const T& newAlpha);
	ColorT(const T& r, const T& g, const T& b);
	ColorT(const T& a, const T& r, const T& g, const T& b);
	virtual ~ColorT();


public:
	T a, r, g, b;


public:
	i32 getArgb() const;
	i32 getRgba() const;

	void setArgb(i32 argb);
	void setArgb(const T& a, const T& r, const T& g, const T& b);
	void setRgb(const T& r, const T& g, const T& b);


public:
	template <typename T2>
	explicit operator ColorT<T2>() const;


public:
	bool operator== (const ColorT<T>& right) const;
	bool operator!= (const ColorT<T>& right) const;


private:
	template <typename ID_TYPE>
	struct Identity { };

	template <typename ARG_TYPE>
	bool equals(const ColorT<T>& right, Identity<ARG_TYPE>) const;
	bool equals(const ColorT<T>& right, Identity<f32>) const;
};


using Color = ColorT<i32>;
using ColorF = ColorT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Color.inl"


#endif