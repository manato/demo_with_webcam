// 
// Copyright (c) 2003-2011, MIST Project, Nagoya University
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
// 
// 3. Neither the name of the Nagoya University nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
// IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 

/// @file mist/operator/operator_array2.h
//!
//! @brief 2次元画像用のオペレータ定義
//!
#ifndef __INCLUDE_MIST_OPERATOR_ARRAY2__
#define __INCLUDE_MIST_OPERATOR_ARRAY2__



/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator +=( array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	typedef typename array2< T, Allocator >::size_type size_type;
#if _CHECK_ARRAY2_OPERATION_ != 0
	if( a1.size( ) != a2.size( ) )
	{
		// 足し算できません例外
		::std::cerr << "can't add array2s." << ::std::endl;
		return( a1 );
	}
#endif
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] += static_cast< T >( a2[i] );
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator -=( array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	typedef typename array2< T, Allocator >::size_type size_type;
#if _CHECK_ARRAY2_OPERATION_ != 0
	if( a1.size( ) != a2.size( ) )
	{
		// 引き算できません例外
		::std::cerr << "can't subtract array2s." << ::std::endl;
		return( a1 );
	}
#endif
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] -= static_cast< T >( a2[i] );
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator *=( array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	typedef typename array2< T, Allocator >::size_type size_type;
#if _CHECK_ARRAY2_OPERATION_ != 0
	if( a1.size( ) != a2.size( ) )
	{
		// 掛け算できません例外
		::std::cerr << "can't multiply array2s." << ::std::endl;
		return( a1 );
	}
#endif
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] *= static_cast< T >( a2[i] );
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator /=( array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	typedef typename array2< T, Allocator >::size_type size_type;
#if _CHECK_ARRAY2_OPERATION_ != 0
	if( a1.size( ) != a2.size( ) )
	{
		// 割り算できません例外
		::std::cerr << "can't divide array2s." << ::std::endl;
		return( a1 );
	}
#endif
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] /= static_cast< T >( a2[i] );
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1  … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator +=( array2< T, Allocator > &a1, typename array2< T, Allocator >::value_type val )
{
	typedef typename array2< T, Allocator >::size_type size_type;
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] += val;
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1  … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator -=( array2< T, Allocator > &a1, typename array2< T, Allocator >::value_type val )
{
	typedef typename array2< T, Allocator >::size_type size_type;
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] -= val;
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1  … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator *=( array2< T, Allocator > &a1, typename array2< T, Allocator >::value_type val )
{
	typedef typename array2< T, Allocator >::size_type size_type;
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] *= val;
	return( a1 );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1  … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline const array2< T, Allocator >& operator /=( array2< T, Allocator > &a1, typename array2< T, Allocator >::value_type val )
{
	typedef typename array2< T, Allocator >::size_type size_type;
	typedef typename array2< T, Allocator >::value_type value_type;
#if _CHECK_ARRAY2_OPERATION_ != 0
	if( val == value_type( 0 ) )
	{
		// ゼロ除算発生
		::std::cerr << "zero division occured." << ::std::endl;
		return( a1 );
	}
#endif
	for( size_type i = 0 ; i < a1.size( ) ; i++ ) a1[i] /= val;
	return( a1 );
}



/// @brief 符号反転
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator -( const array2< T, Allocator > &a )
{
	typedef typename array2< T, Allocator >::size_type size_type;
	array2< T, Allocator > o( a.size1( ), a.size2( ), a.reso1( ), a.reso2( ) );
	for( size_type i = 0 ; i < o.size( ) ; i++ ) o[i] = -a[i];
	return( o );
}



/// @brief 足し算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator +( const array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	array2< T, Allocator > tmp( a1 );
	return( tmp += a2 );
}



/// @brief 引き算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator -( const array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	array2< T, Allocator > tmp( a1 );
	return( tmp -= a2 );
}



/// @brief 掛け算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator *( const array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	array2< T, Allocator > tmp( a1 );
	return( tmp *= a2 );
}



/// @brief 割り算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a1 … 引数の説明
//! @param[in] a2 … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator /( const array2< T, Allocator > &a1, const array2< T, Allocator > &a2 )
{
	array2< T, Allocator > tmp( a1 );
	return( tmp /= a2 );
}



/// @brief 定数との足し算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a   … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator +( const array2< T, Allocator > &a, typename array2< T, Allocator >::value_type val )
{
	array2< T, Allocator > tmp( a );
	return( tmp += val );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] val … 引数の説明
//! @param[in] a   … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator +( typename array2< T, Allocator >::value_type val, const array2< T, Allocator > &a )
{
	array2< T, Allocator > tmp( a );
	return( tmp += val );
}


/// @brief 定数との引き算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a   … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator -( const array2< T, Allocator > &a, typename array2< T, Allocator >::value_type val )
{
	array2< T, Allocator > tmp( a );
	return( tmp -= val );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] val … 引数の説明
//! @param[in] a   … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator -( typename array2< T, Allocator >::value_type val, const array2< T, Allocator > &a )
{
	array2< T, Allocator > tmp( a.size1( ), a.size2( ), val );
	return( tmp -= a );
}


/// @brief 定数との掛け算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a   … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator *( const array2< T, Allocator > &a, typename array2< T, Allocator >::value_type val )
{
	array2< T, Allocator > tmp( a );
	return( tmp *= val );
}


/// @brief 関数・クラスの概要を書く
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] val … 引数の説明
//! @param[in] a   … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator *( typename array2< T, Allocator >::value_type val, const array2< T, Allocator > &a )
{
	array2< T, Allocator > tmp( a );
	return( tmp *= val );
}


/// @brief 定数との割り算
//! 
//! 詳細な説明や関数の使用例を書く
//! 
//! @param[in] a   … 引数の説明
//! @param[in] val … 引数の説明
//! 
//! @return 戻り値の説明
//! 
template < class T, class Allocator >
inline array2< T, Allocator > operator /( const array2< T, Allocator > &a, typename array2< T, Allocator >::value_type val )
{
	array2< T, Allocator > tmp( a );
	return( tmp /= val );
}


#endif // __INCLUDE_MIST_OPERATOR_ARRAY2__
