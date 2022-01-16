
#include "fraction.h"

class FractionMatrix
{
	Fraction 	*table;
	unsigned int 	rows, cols;
	unsigned int	locn( unsigned int r, unsigned int k );
public:
	FractionMatrix( int r, int k );	// default constructor	
	~FractionMatrix( void ) { delete [] table; }

	Fraction obtain( unsigned int i, unsigned int j );
	void assign( unsigned int i, unsigned int j, Fraction f );
	void swapRows( int i, int j );
	void rescaleRow( Fraction x, int i );
	void combineRows( Fraction x, int i, int j );
	int solve( Fraction& determinant );
	
	friend ostream& operator << ( ostream& s, FractionMatrix& a );
	friend istream& operator >> ( istream& s, FractionMatrix& a );
};


inline unsigned int FractionMatrix::locn( unsigned int r, unsigned int k )
{	
	return	k + cols * r;
}	


FractionMatrix::FractionMatrix( int r, int k )
{
	unsigned int	size;	

	rows = ( r > 0 ) ? r : 0;
	cols = ( k > 0 ) ? k : 0;
	size = rows * cols;
	
	table = new Fraction[ size ];
}	


void FractionMatrix::swapRows( int i, int j )
{
	Fraction temp;
	for (int k = 0; k < cols; k++)
		{
		temp = table[ locn(i,k) ];
		table[ locn(i,k) ] = table[ locn(j,k) ];
		table[ locn(j,k) ] = temp;
		}
}	


void FractionMatrix::rescaleRow( Fraction x, int i )
{
	if ( x == 0 ) return;
	for (int k = 0; k < cols; k++) {table[ locn(i,k) ] /= x;}
}


void FractionMatrix::combineRows( Fraction x, int i, int j )
{
	for (int k = 0; k < cols; k++){table[ locn(j,k) ] -= x * table[ locn(i,k) ];}
}


int FractionMatrix::solve( Fraction& determinant )
{
	int	r = 0, k = 0;	// dimensions of row-reduced submatrix
	while (( r < rows )&&( k < cols ))
		{
		int	u = r;	// scan for the next unreduced submatrix
		while (( table[ locn(u,k) ] == 0 )&&( ++u < rows ));
		if (( u == rows )&&( ++k < cols )) continue;
		if ( k == cols ) { determinant = 0; break; }
		
		Fraction	x = table[ locn(u,k) ];
		if ( x != 1 )
			{ rescaleRow( x, u ); determinant *= x; return 0; }
		if ( u > r )
			{ swapRows( u, r ); determinant *= -1; return 0; }
		for (int i = 0; i < rows; i++)
			if (( i != u )&&( (x = table[ locn(i,k) ] )!= 0 ))
				{ combineRows( x, u, i ); return 0; }	
		++r;
		}
	return	1;
}

Fraction FractionMatrix::obtain( unsigned int i, unsigned int j )
{
	if (( i < rows )&&( j < cols )) 
		return	this->table[ locn(i,j) ];
	else	return 0;
}

void FractionMatrix::assign( unsigned int i, unsigned int j, Fraction f )
{
	if (( i < rows )&&( j < cols )) this->table[ locn(i,j) ] = f;
}


ostream& operator << ( ostream& s, FractionMatrix& a )
{
	for (int i = 0; i < a.rows; i++)
		{
		s << endl;
		for (int j = 0; j < a.cols; j++)
			s << a.table[ a.locn(i,j) ] << "\t";
	      	}
	s << endl;
	return	s;	
}
	

istream& operator >> ( istream& s, FractionMatrix& a )
{
	// fill the matrix by rowa
	for (int i = 0; i < a.rows; i++)
		{
		cout << "Fill the #" << 1+i << " row of the matrix "<<":\n" << endl;
		for (int j = 0; j < a.cols; j++)
			{
			Fraction	x;
			cin >> x;
			a.assign( i, j, x );
			}
		cout << endl;
		}
	return	s;
}


