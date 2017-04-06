#ifndef __CA__VECTOR_H__
#define __CA__VECTOR_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class VectorT
{
public:
	static const VectorT<T> Zero;


public:
	VectorT();
	VectorT(const T& x, const T& y);
	virtual ~VectorT();


public:
	T x, y;


public:
	void setVector(const T& x, const T& y);
	void addVector(const T& deltaX, const T& deltaY);
	void normalize(const T& length = T(1));
	VectorT<T> getNormalized(const T& length = T(1)) const;


public:
	const T getLength() const;
	const T getLengthSq() const;


public:
	const T dotProduct(const VectorT<T>& right) const;


public:
	template <typename T2>
	explicit operator VectorT<T2>() const;
	VectorT<T> operator+ () const;
	VectorT<T> operator- () const;
	VectorT<T> operator+ (const VectorT<T>& right) const;
	VectorT<T>& operator+= (const VectorT<T>& right);
	VectorT<T> operator- (const VectorT<T>& right) const;
	VectorT<T>& operator-= (const VectorT<T>& right);
	VectorT<T> operator* (const T& right) const;
	VectorT<T>& operator*= (const T& right);
	VectorT<T> operator/ (const T& right) const;
	VectorT<T>& operator/= (const T& right);
	bool operator== (const VectorT<T>& right) const;
	bool operator!= (const VectorT<T>& right) const;


private:
	template <typename ID_TYPE>
	struct Identity { };

	template <typename ARG_TYPE>
	void normalize(const T& length, Identity<ARG_TYPE>);
	void normalize(const T& length, Identity<f32>);

	template <typename ARG_TYPE>
	bool equals(const VectorT<T>& right, Identity<ARG_TYPE>) const;
	bool equals(const VectorT<T>& right, Identity<f32>) const;
};


using Vector = VectorT<i32>;
using VectorF = VectorT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Vector.inl"


#endif