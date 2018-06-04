#pragma once
#include "vector.h"

struct Matrix {
	//data[ n ][ 0 ]:X²
	//data[ n ][ 1 ]:Y²
	//data[ n ][ 2 ]:Z²
	//data[ 0 ]:X²
	//data[ 1 ]:Y²
	//data[ 2 ]:Z²
	//data[ 3 ]:•½sˆÚ“®
	//data[ n ][ n ]:Šg‘åk¬
	float data[ 4 ][ 3 ]; 
	Matrix( );
	template< typename T > inline static Matrix makeTransformTranslation( const Vector3< T >& inTrans );
	template< typename T > inline static Matrix makeTransformScaling( const Vector3< T >& inScale );
	template< typename T > inline static Matrix makeTransformRotation( const Vector3< T >& inAxis, const float& inRadian );
	template< typename T > inline Vector3< T > multiply( const Vector3< T >& inVector ) const;
	inline Matrix multiply(const Matrix& inMat ) const;
};


Matrix::Matrix( ) {
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			if ( i == j ) {
				data[ i ][ j ] = 1;
			} else {
				data[ i ][ j ] = 0;
			}
		}
	}
}


// •½sˆÚ“®‚Ì•ÏŠ·s—ñ‚ğì‚é
template< typename T > inline static Matrix Matrix::makeTransformTranslation( const Vector3< T >& inTrans ) {
	Matrix mat;
	mat.data[ 3 ][ 0 ] = ( float )inTrans.x;
	mat.data[ 3 ][ 1 ] = ( float )inTrans.y;
	mat.data[ 3 ][ 2 ] = ( float )inTrans.z;
	return mat;
}

// Šg‘åk¬‚Ì•ÏŠ·s—ñ‚ğì‚é
template< typename T > inline static Matrix Matrix::makeTransformScaling( const Vector3< T >& inScale ) {
	Matrix mat;
	mat.data[ 0 ][ 0 ] = ( float )inScale.x;
	mat.data[ 1 ][ 1 ] = ( float )inScale.y;
	mat.data[ 2 ][ 2 ] = ( float )inScale.z;
	return mat;
}

// ”CˆÓ²‰ñ“]‚Ì•ÏŠ·s—ñ‚ğì‚é
template< typename T > inline Matrix Matrix::makeTransformRotation( const Vector3< T >& inAxis, const float& inRadian ) {
	Matrix mat;	
	Vector3< T > axis = inAxis.normalize( );
	float cosRadian = cosf( inRadian );
	float sinRadian = sinf( inRadian );
	float c = ( 1 - cosRadian );

	mat.data[ 0 ][ 0 ] = axis.x * axis.x * c + cosRadian;
	mat.data[ 0 ][ 1 ] = axis.x * axis.y * c - axis.z * sinRadian;
	mat.data[ 0 ][ 2 ] = axis.x * axis.z * c + axis.y * sinRadian;

	mat.data[ 1 ][ 0 ] = axis.y * axis.x * c + axis.z * sinRadian;
	mat.data[ 1 ][ 1 ] = axis.y * axis.y * c + cosRadian;
	mat.data[ 1 ][ 2 ] = axis.y * axis.z * c - axis.x * sinRadian;

	mat.data[ 2 ][ 0 ] = axis.z * axis.x * c - axis.y * sinRadian;
	mat.data[ 2 ][ 1 ] = axis.z * axis.y * c + axis.x * sinRadian;
	mat.data[ 2 ][ 2 ] = axis.z * axis.z * c + cosRadian;

	return mat;
}

//æZ
template< typename T >
inline Vector3< T > Matrix::multiply(const Vector3< T >& inVector ) const {
	return Vector3< T >(
		data[ 0 ][ 0 ] * inVector.x + data[ 1 ][ 0 ] * inVector.y + data[ 2 ][ 0 ] * inVector.z + data[ 3 ][ 0 ],
		data[ 0 ][ 1 ] * inVector.x + data[ 1 ][ 1 ] * inVector.y + data[ 2 ][ 1 ] * inVector.z + data[ 3 ][ 1 ],
		data[ 0 ][ 2 ] * inVector.x + data[ 1 ][ 2 ] * inVector.y + data[ 2 ][ 2 ] * inVector.z + data[ 3 ][ 2 ]
	);
}

//æZ
inline Matrix Matrix::multiply( const Matrix& inMat ) const {
	Matrix mat;
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			mat.data[ i ][ j ] = 0;
			for ( int k = 0; k < 3; k++ ) {
				mat.data[ i ][ j ] += data[ i ][ k ] * inMat.data[ k ][ j ];
			}
		}
	}
	return mat;
}
