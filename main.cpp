#include "matrix.h"

int getMatRow( void )
{
	int	m;
	cout << "#Equations? ";
	cin >> m;
	cout << endl;
	return	m;	
}

int getMatCol( void )
{
	int	n;
	cout << "#Variables? ";
	cin >> n;
	cout << endl;
	return	++n;
}

void printMatrix( int& table, FractionMatrix& a )
{	
	cout << "\nMatrix  #" << table<< "\n"<< a;
}

int main( void )
{	
	int	m = getMatRow();
	int	n = getMatCol();
	FractionMatrix	a(m,n);
	std::cin >> a;
	std::cout << "\nThe ordered matrix:\n" << a;
	getchar();
	
	Fraction	det = 1;
	int		table = 0;

	while ( !a.solve( det ) )
		{getchar(); printMatrix( ++table, a ); }
}	

