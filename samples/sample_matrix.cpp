// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <ctime>
//---------------------------------------------------------------------------

void main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			cout << "Few arguments" << endl;
			return;
		}
		int N = atoi(argv[1]);
		int i, j;

		setlocale(LC_ALL, "Russian");
		cout << "Тестирование программ поддержки представления треугольных матриц"<< endl;
		/*for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++ )
		{
		a[i][j] =  i * 10 + j;
		b[i][j] = (i * 10 + j) * 100;
		}
		c = a + b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a + b" << endl << c << endl;*/

		//TMatrix<int> m(2);
		//m[0][0] = 1;
		//m[0][1] = 2;

		//TMatrix<int> m1(2);
		//m1[0][0] = 2;
		//m1[0][1] = 3;

		//TMatrix<int> m2(2);
		//m2[0][0] = -1;
		//m2[0][1] = -1;

		//TMatrix<int> m3(2);

		//m3 = m - m1;

		////cout<<m3[0][0]<<" "<<m3[0][1]<<" "<<m3[1][1]<<endl;
		////cout<<m2[0][0]<<" "<<m2[0][1]<<" "<<m2[1][1]<<endl;
		//cout<<m3[1].GetStartIndex()<<endl;
		//cout<<m2[1].GetStartIndex()<<endl;
		//cout<<m3.GetSize()<<endl;
		//cout<<m2.GetSize()<<endl;

		//if (m2 == m3)
		//	cout << "true"<< endl;
		//else
		//	cout << "false" << endl;

		//TMatrix<int> m(2);
		//m[0][0] = 1;
		//m[0][1] = 1;
		//m[1][1] = 1;

		//TMatrix<int> m1(2);
		//m1[0][0] = 2;
		//m1[0][1] = 2;
		//m1[1][1] = 2;

		////TMatrix<int> m2(2);
		////m2[0][0] = -1;
		////m2[0][1] = -1;


		//TMatrix<int> m3(2);

		//m3 = m*m1;
		//cout <<m<< endl;
		//cout <<m1<< endl;
		//cout << m3 <<endl;
		for(N; N<=5000; N+=100)
		{
			TMatrix<int> a(N), b(N), c(N);
			for (i = 0; i < N; i++){
				for (j = i; j < N; j++ )
				{
					a[i][j] =  i;
					b[i][j] = 2*i;
				}
			}
			clock_t start, finish;
			double time;
			start = clock();
			c = a*b;
			finish = clock();
			time = (double)(finish-start)/CLOCKS_PER_SEC;
			cout <<"Size: " << N << " time: "<< time << endl;
		}
	}
	catch(const char* s)
	{
		std::cout << "Error: " << s << endl;
	}
}
//---------------------------------------------------------------------------
