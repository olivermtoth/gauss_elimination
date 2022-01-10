#include <stdio.h>	
#include <stdlib.h>	
#include <iostream>
#include "Fraction.h"

int gcd( int m, int n )
{
	int	p = ( m < 0 ) ? -m : m;	
	int	q = ( n < 0 ) ? -n : n;	
	while ( q ) { int r = p % q; p = q; q = r; }
	return	p;
}	


void Fraction::reduce( void )
{	
	int	g = gcd( this->num, this->den );
	if ( this->den < 0 ) g = -g;
	if ( g != 0 ) { this->num /= g; this->den /= g; }
}


int Fraction::ipart( void )
{
	int	quot = this->num / this->den;	
	int	rem = this->num % this->den;
	if ( rem < 0 ) --quot;
	return	quot;
}	


Fraction Fraction::fpart( void )
{
	Fraction	f = *this;
	f -= f.ipart();
	return	f;
}	


Fraction Fraction::operator +( const Fraction& f ) const
{
	Fraction	sum;

	sum.num = this->num * f.den + this->den * f.num;
	sum.den = this->den * f.den;
	sum.reduce();
	return	sum;
}


Fraction Fraction::operator -( const Fraction& f ) const
{
	Fraction	diff;

	diff.num = this->num * f.den - this->den * f.num;
	diff.den = this->den * f.den;
	diff.reduce();
	return	diff;
}


Fraction Fraction::operator *( const Fraction& f ) const
{
	Fraction	prod;

	prod.num = this->num * f.num;
	prod.den = this->den * f.den;
	prod.reduce();
	return	prod;
}


Fraction Fraction::operator /( const Fraction& f ) const
{
	Fraction	quot;

	if ( f.num == 0 ) { std::cout << "\nDivision by zero!\n"; exit(1); }
	quot.num = this->num * f.den;
	quot.den = this->den * f.num;
	quot.reduce();
	return	quot;
}


Fraction Fraction::operator +=( const Fraction& f )
{
	return *this = *this + f;	
}


Fraction Fraction::operator -=( const Fraction& f )
{
	return *this = *this - f;	
}


Fraction Fraction::operator *=( const Fraction& f )
{
	return *this = *this * f;	
}


Fraction Fraction::operator /=( const Fraction& f )
{
	return *this = *this / f;	
}


Fraction Fraction::operator =( const int c ) 
{
	this->num = c;
	this->den = 1;
	return	*this;
}


int operator ==( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den == f.den * g.num );
}


int operator !=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den != f.den * g.num );
}


int operator < ( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den < f.den * g.num );
}


int operator > ( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den > f.den * g.num );
}


int operator <=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den <= f.den * g.num );
}


int operator >=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den >= f.den * g.num );
}


int operator ==( const Fraction& f, const int& i )
{
	Fraction	g( i );
	return	( f.num * g.den == f.den * g.num );
}


int operator !=( const Fraction& f, const int& i )
{
	Fraction	g( i );
	return	( f.num * g.den != f.den * g.num );
}


Fraction operator / ( const int i, const Fraction f )
{
		Fraction	recip;
		recip.num = f.den;
		recip.den = f.num * i;
		recip.reduce();
		return	recip;
}
	

Fraction operator * ( const int i, const Fraction f )
{
		Fraction	prod;
		prod.num = f.num * i;
		prod.den = f.den;
		prod.reduce();
		return	prod;
}
	



