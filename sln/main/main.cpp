#include "utmatrix.h"

int main()
{
	//TVector<int> v(5);
	//TVector<int> v1(v);
	//cout << v << endl;
	TMatrix<int> m(2);
	m[0][0]=1;
	m[0][1]=2;
	TMatrix<int> m1(m);
	cout << m1 <<endl;
	m1[0][0] = 9;
	if (m==m1)
		cout<< "Verno"<<endl;
	else
		cout<< "Neverno"<<endl;
	m1 = m;
	cout << m1<< endl;
}
