#pragma once
#include <math.h>

#define PI = 3.1415926535897932384626433832795

template< typename T >
struct Vector2 {
	T x;
	T y;
	Vector2( );
	Vector2( const T& inX, const T& inY );
	inline void operator= ( const Vector2& inVec );
	inline void operator+=( const Vector2& inVec );
	inline void operator-=( const Vector2& inVec );
	inline void operator*=( const int& inValue );
	inline bool operator==( const Vector2& inVec );
	inline bool operator!=( const Vector2& inVec );
	inline const Vector2 operator+( const Vector2& inVec )	const;
	inline const Vector2 operator-( const Vector2& inVec )	const;
	inline const Vector2 operator*( const int& inValue    )	const;
	inline const Vector2 normalize( )							const;
	inline const bool isOrijin( )								const;
	inline const double getLength( )							const;
	inline const double getLengthSquare( )						const;
	inline const double dot  ( const Vector2& inVec )			const;
	inline const double cross( const Vector2& inVec )			const;
	inline const double angle( const Vector2& inVec )			const;
};

template< typename T >
struct Vector3 {
	T x;
	T y;
	T z;
	Vector3( );
	Vector3( const T& inX, const T& inY, const T& inZ );
	inline void operator= ( const Vector3& inVec );
	inline void operator+=( const Vector3& inVec );
	inline void operator-=( const Vector3& inVec );
	inline void operator*=( const int& inValue );
	inline bool operator==( const Vector3& inVec );
	inline bool operator!=( const Vector3& inVec );
	inline const Vector3 operator+( const Vector3& inVec )	const;
	inline const Vector3 operator-( const Vector3& inVec )	const;
	inline const Vector3 operator*( const int& inValue    )	const;
	inline const Vector3 normalize( )							const;
	inline const Vector3 cross( const Vector3& inVec )			const;
	inline const bool isOrijin( )								const;
	inline const double dot  ( const Vector3& inVec )			const;
	inline const double getLength( )							const;
	inline const double getLengthSquare( )						const;
	inline const double angle( const Vector3& inVec )			const;
};

/*-----------------------------------------*/
/*----------------Vector2-----------------*/
/*-----------------------------------------*/
template< typename T >
Vector2< T >::Vector2( ) {
}

template< typename T >
Vector2< T >::Vector2( const T& inX, const T& inY ) {
}

template< typename T >
inline void Vector2< T >::operator= ( const Vector2& inVec ) {
	x = inVec.x;
	y = inVec.y;
}

template< typename T >
inline void Vector2< T >::operator+=( const Vector2& inVec ) {
	x += inVec.x;
	y += inVec.y;
}

template< typename T >
inline void Vector2< T >::operator-=( const Vector2& inVec ) {
	x -= inVec.x;
	y -= inVec.y;
}

template< typename T >
inline void Vector2< T >::operator*=( const int& inValue ) {
	x *= inValue;
	y *= inValue;
}

template< typename T >
inline bool Vector2< T >::operator==( const Vector2& inVec ) {
	return ( x == inVec.x && y == inVec.y );
}

template< typename T >
inline bool Vector2< T >::operator!=( const Vector2& inVec ) {
	return ( x != inVec.x || y != inVec.y );
}

template< typename T >
inline const Vector2< T > Vector2< T >::operator+( const Vector2& inVec ) const {
	return Vector2( x + inVec.x, y + inVec.y );
}

template< typename T >
inline const Vector2< T > Vector2< T >::operator-( const Vector2& inVec ) const {
	return Vector2( x - inVec.x, y - inVec.y );
}

template< typename T >
inline const Vector2< T > Vector2< T >::operator*( const int& inValue ) const {
	return Vector2( x * inValue, y * inValue );
}

//原点確認
template< typename T >
inline const bool Vector2< T >::isOrijin( ) const {
	return x == 0 && y == 0;
}

//正規化
//大きさを"1"にしたベクトル
template< typename T >
inline const Vector2< T > Vector2< T >::normalize( ) const {
	double length = getLength( );
	if ( length == 0 ) {
		return Vector2( );
	}
	double n = 1 / length;
	return Vector2( ( int )( x * n ), ( int )( y * n ) );
}

//ベクトルの長さ
template< typename T >
inline const double Vector2< T >::getLength( ) const {
	return sqrt( getLengthSquare( ) );
}

//ベクトルの長さの２乗 ( 処理軽減用 )
template< typename T >
inline const double Vector2< T >::getLengthSquare( ) const {
	return x * x + y * y; 
}

//内積
template< typename T >
inline const double Vector2< T >::dot( const Vector2& inVec ) const {
	return ( x * inVec.x + y * inVec.y );
}

//外積
template< typename T >
inline const double Vector2< T >::cross( const Vector2& inVec ) const {
	return ( x * inVec.y - y * inVec.x );
}

//ベクトル間の角度π
template< typename T >
inline const double Vector2< T >::angle( const Vector2& inVec ) const {
	Vector2 v1 = normalize( );
	Vector2 v2 = inVec.normalize( );
	return acos( v1.dot( v2 ) );
}


/*-----------------------------------------*/
/*----------------Vector3-----------------*/
/*-----------------------------------------*/
template< typename T >
Vector3< T >::Vector3( ) {
	x = 0;
	y = 0;
	z = 0;
}

template< typename T >
Vector3< T >::Vector3( const T& inX, const T& inY, const T& inZ ) {
	x = inX;
	y = inY;
	z = inZ;
}

template< typename T >
inline void Vector3< T >::operator= ( const Vector3& inVec ) {
	x = inVec.x;
	y = inVec.y;
}

template< typename T >
inline void Vector3< T >::operator+=( const Vector3& inVec ) {
	x += inVec.x;
	y += inVec.y;
}

template< typename T >
inline void Vector3< T >::operator-=( const Vector3& inVec ) {
	x -= inVec.x;
	y -= inVec.y;
}

template< typename T >
inline void Vector3< T >::operator*=( const int& inValue ) {
	x *= inValue;
	y *= inValue;
}

template< typename T >
inline bool Vector3< T >::operator==( const Vector3& inVec ) {
	return ( x == inVec.x && y == inVec.y );
}

template< typename T >
inline bool Vector3< T >::operator!=( const Vector3& inVec ) {
	return ( x != inVec.x || y != inVec.y );
}

template< typename T >
inline const Vector3< T > Vector3< T >::operator+( const Vector3& inVec ) const {
	return Vector3( x + inVec.x, y + inVec.y );
}

template< typename T >
inline const Vector3< T > Vector3< T >::operator-( const Vector3& inVec ) const {
	return Vector3( x - inVec.x, y - inVec.y );
}

template< typename T >
inline const Vector3< T > Vector3< T >::operator*( const int& inValue ) const {
	return Vector3( x * inValue, y * inValue );
}

//原点確認
template< typename T >
inline const bool Vector3< T >::isOrijin( ) const {
	return x == 0 && y == 0 && z == 0;
}

//正規化
//大きさを"1"にしたベクトル
template< typename T >
inline const Vector3< T > Vector3< T >::normalize( ) const {
	double length = getLength( );
	if ( length == 0 ) {
		return Vector3( );
	}
	double n = 1 / length;
	return Vector3( ( T )( x * n ), ( T )( y * n ), ( T )( z * n ) );
}

//外積
template< typename T >
inline const Vector3< T > Vector3< T >::cross( const Vector3& inVec ) const {
	return Vector3< T >( y * inVec.z - z * inVec.y, z * inVec.x - x * inVec.z, x * inVec.y - y * inVec.x );
}

//内積
template< typename T >
inline const double Vector3< T >::dot( const Vector3& inVec ) const {
	return ( x * inVec.x + y * inVec.y );
}

//ベクトルの長さ
template< typename T >
inline const double Vector3< T >::getLength( ) const {
	return sqrt( getLengthSquare( ) );
}

//ベクトルの長さの２乗 ( 処理軽減用 )
template< typename T >
inline const double Vector3< T >::getLengthSquare( ) const {
	return x * x + y * y; 
}

//ベクトル間の角度π
template< typename T >
inline const double Vector3< T >::angle( const Vector3& inVec ) const {
	Vector3 v1 = normalize( );
	Vector3 v2 = inVec.normalize( );
	return acos( v1.dot( v2 ) );
}