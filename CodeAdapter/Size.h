#ifndef __CA__SIZE_H__
#define __CA__SIZE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class SizeT
{
public:
	static const SizeT<T> Zero;


public:
	SizeT();
	SizeT(const T& width, const T& height);
	virtual ~SizeT();


public:
	T width, height;


public:
	void setSize(const T& width, const T& height);
	void addSize(const T& deltaWidth, const T& deltaHeight);


public:
	SizeT<T> operator+ (const SizeT<T>& right) const;
	SizeT<T>& operator+= (const SizeT<T>& right);
	SizeT<T> operator- (const SizeT<T>& right) const;
	SizeT<T>& operator-= (const SizeT<T>& right);
	SizeT<T> operator* (const T& right) const;
	SizeT<T>& operator*= (const T& right);
	SizeT<T> operator/ (const T& right) const;
	SizeT<T>& operator/= (const T& right);
	bool operator== (const SizeT<T>& right) const;
	bool operator!= (const SizeT<T>& right) const;


private:
	template <typename ID_TYPE>
	struct Identity { };

	template <typename ARG_TYPE>
	bool equals(const SizeT<T>& right, Identity<ARG_TYPE>) const;
	bool equals(const SizeT<T>& right, Identity<f32>) const;
};


using Size = SizeT<i32>;
using SizeF = SizeT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Size.inl"


#endif