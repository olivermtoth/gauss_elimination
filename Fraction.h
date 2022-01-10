#include <stdio.h>	
#include <stdlib.h>	
#include <iostream>



class Fraction
{
	int	num, den;
public:
	void reduce( void );

	// constructors
	Fraction() { num = 0; den = 1; }	// default constructor
	Fraction( int m ) { num = m; den = 1; }
	Fraction( int m, int n ) { num = m; den = n; }

	// access functions
	int Num( void ) const { return this->num; }
	int Den( void ) const { return this->den; }
	int ipart( void );			// integer part
	Fraction fpart( void );			// fractional part
	
	// unary and binary operators
	Fraction operator -() const { return Fraction( -num, den ); }
	
	Fraction operator +( const Fraction& ) const;	
	Fraction operator -( const Fraction& ) const;
	Fraction operator *( const Fraction& ) const;	
	Fraction operator /( const Fraction& ) const;	

	// assignment operators
	Fraction operator +=( const Fraction& );
	Fraction operator -=( const Fraction& );
	Fraction operator *=( const Fraction& );
	Fraction operator /=( const Fraction& );

	Fraction operator =( const int );	

	// friend functions
	friend int operator ==( const Fraction&, const Fraction& );
	friend int operator !=( const Fraction&, const Fraction& );
	friend int operator < ( const Fraction&, const Fraction& );
	friend int operator > ( const Fraction&, const Fraction& );
	friend int operator <=( const Fraction&, const Fraction& );
	friend int operator >=( const Fraction&, const Fraction& );

	friend int operator ==( const Fraction&, const int& );
	friend int operator !=( const Fraction&, const int& );
	
	friend Fraction operator / ( const int, const Fraction );
	friend Fraction operator * ( const int, const Fraction );

};
