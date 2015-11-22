#include "matrix_3.h"

#include <iostream>
#include <ctime>

using namespace std;
//int main()
//{
// Matrix matr(4, 3);
// int b = matr.GetSize();
// cout << b << endl;
// Matrix matr1(matr);
// Matrix matr2 (4, 2);
// matr1 = matr + matr2;
// matr1 = matr - matr2;
// cout << matr1 <<endl;
// cout << matr2 << "*\n" << matr << "\n" << matr2*matr<<endl;
// //matr.element(0, 1) = 10;
// //Matrix matr1(3, 3, 1);
// ////Matrix matr1(matr);
// //Matrix matr2(3, 4);
// //matr2 = matr * matr1;
// //cout << matr << endl;
// //cout << matr1 << endl;
// ////cout << matr2 << endl;
// //Matrix matr3(1,1);
// //cin >> matr3;
// ///*cout << matr3 << endl;
// //matr2.scalar(5);
// //cout << matr2<< endl;*/
// //matr3.transpose();
// //cout << matr3 << endl;
//}


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
		int N = /*100*/atoi(argv[1]);
		int i, j;

		setlocale(LC_ALL, "Russian");
		cout << "Тестирование программ поддержки представления треугольных матриц"<< endl;

		for(N; N<= 5000; N+=100)
		{
			Matrix<int> a(N), b(N), c(N);
			for (i = 0; i < N; i++){
				for (j = i; j < N; j++ )
				{
					a.element(i, j) =  i;
					b.element(i, j)  = 2*i;
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
