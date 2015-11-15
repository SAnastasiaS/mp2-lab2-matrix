// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	try
	{
		TMatrix<int> a(5), b(5), c(5);
		int i, j;

		setlocale(LC_ALL, "Russian");
		cout << "Тестирование программ поддержки представления треугольных матриц"
			<< endl;
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++ )
			{
				a[i][j] =  i * 10 + j;
				b[i][j] = (i * 10 + j) * 100;
			}
			c = a - b;
			cout << "Matrix a = " << endl << a << endl;
			cout << "Matrix b = " << endl << b << endl;
			cout << "Matrix c = a - b" << endl << c << endl;

			TMatrix<int> m(2);
			m[0][0] = 1;
			m[0][1] = 2;

			TMatrix<int> m1(2);
			m1[0][0] = 2;
			m1[0][1] = 3;

			TMatrix<int> m2(2);
			m2[0][0] = -1;
			m2[0][1] = -1;

			TMatrix<int> m3(2);
			m3 = m - m1;


			if (m2 == m3)
				cout << "true"<< endl;
	}
	catch(const char* s)
	{
		std::cout << "Error: " << s << endl;
	}
}
//---------------------------------------------------------------------------
