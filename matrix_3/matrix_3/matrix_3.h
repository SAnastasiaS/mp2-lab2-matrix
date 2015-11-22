#include <iostream>
#include <assert.h>
#include <math.h>

template <class ValType>
class Matrix
{
private:
	int Size;
	int	Length;
	int* ptr;

public:

	Matrix(int n, int value = 0);
	~Matrix();
	Matrix(const Matrix& matr);
	int GetSize() const;
	ValType& element (int i, int j);
	ValType& element (int i, int j) const;
	//	int lines() const;
	//	int columns() const;
	Matrix operator+(const Matrix& matr) const;
	Matrix operator-(const Matrix& matr) const;
	Matrix& operator=(const Matrix& matr);
	Matrix operator*(const Matrix& matr) const;
	//	Matrix& scalar(int a);
	//	Matrix& transpose();
};
template <class ValType>
std::ostream& operator<<(std::ostream& stream, const Matrix<ValType> &matr);
template <class ValType>
std::istream& operator>>(std::istream& stream, Matrix <ValType> &matr);

template <class ValType>
Matrix<ValType>::Matrix(int n, int value)//конструктор
{
	if (n<0)
		throw "Size<0";
	int result = 0;
	Size = n;
	for (n; n > 0; n--)
	{
		result += n;
	}
	Length = result;
	ptr = new ValType[Length];
	for (int i=0; i <Length; ++i)
		ptr[i] = ValType(value);
}

template <class ValType>
Matrix<ValType>::~Matrix()//декструктор
{
	delete[] ptr;
}

template <class ValType>
int Matrix<ValType>::GetSize() const
{
	return this->Size;
}

template <class ValType>
Matrix<ValType>::Matrix(const Matrix<ValType> &matr)
{
	Size = matr.Size;
	Length = matr.Length;
	ptr = new ValType[Length];
	for(int i = 0; i < Length; i++)
	{
		ptr[i] = matr.ptr[i];
	}
}

template <class ValType>
ValType& Matrix<ValType>::element (int i, int j)
{
	if ((i>j)||(i>=Size)||(j>=Size)||(i<0)||(j<0))
		throw ("Incorrect entries");
	return ptr[i*Size-i*(i-1)/2+(j-i)];
}

template <class ValType>
ValType& Matrix<ValType>::element (int i, int j) const
{
	if ((i>j)||(i>=Size)||(j>=Size)||(i<0)||(j<0))
		throw ("Incorrect entries");
	return ptr[i*Size-i*(i-1)/2+(j-i)];
}

template <class ValType>
std::ostream& operator<<(std::ostream& stream, const Matrix<ValType> &matr)
{
	for(int i = 0; i < matr.GetSize(); i++)
	{
		stream << "\n" ;
		for(int k = 0; k<i; ++k)
			stream<< "0 ";
		for(int j = i; j < matr.GetSize(); j++)
			stream << matr.element(i,j) << " ";
	}
	return stream;
}

//std::istream& operator>>(std::istream& stream, Matrix& matr)
//{
//	int lines = 0;
//	int columns = 0;
//	stream >> lines;
//	stream >> columns;
//	matr = Matrix(lines, columns, 0);
//	for(int i = 0; i < matr.lines();i++)
//	{
//		for(int j = 0; j < matr.columns(); j++)
//			stream >> matr.element(i,j);
//	}
//	return stream;
//}
//


template <class ValType>
Matrix<ValType> Matrix<ValType>::operator+(const Matrix<ValType> &matr) const
{
	if (Size != matr.Size)
		throw "Different sizes";
	Matrix<ValType> result(Size);
	for(int i = 0; i < Length; i++)
	{
		result.ptr[i] = ptr[i] + matr.ptr[i];
	}
	return result;

}

template <class ValType>
Matrix<ValType> Matrix<ValType>::operator-(const Matrix<ValType> &matr) const
{
	if (Size != matr.Size)
		throw "Different sizes";
	Matrix<ValType> result(Size);
	for(int i = 0; i < Length; i++)
	{
		result.ptr[i] = ptr[i] - matr.ptr[i];
	}
	return result;

}

template <class ValType>
Matrix<ValType>& Matrix<ValType>::operator=(const Matrix<ValType> &matr)
{
	if(&matr == this)
	{
		return *this;
	}
	else
	{
		delete[] ptr;
		Size = matr.Size;
		Length = matr.Length;
		ptr = new ValType[Length];
		for (int i = 0; i < Length; ++i)
			ptr[i] = matr.ptr[i];
		return *this;
	}
}

template <class ValType>
Matrix<ValType> Matrix<ValType>::operator*(const Matrix<ValType> &matr) const
{
	if (Size != matr.Size)
		throw "Different sizes";
	Matrix<ValType> result(Size); 
	for (int i=0; i<Size; ++i)
	{
		for (int j = i; j < Size; ++j)
		{
			int sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum+=element(i, k)*matr.element(k, j);
			}
			result.element(i,j)=sum;
		}
	}
	return result;
}

//Matrix& Matrix:: scalar (int a)
//{
//	for (int i = 0; i<m; ++i)
//	{
//		for (int j = 0; j<n; ++j)
//			this->ptr[i][j]=this->ptr[i][j]*a;
//	}
//	return *this;
//}
//
//Matrix& Matrix:: transpose()
//{
//	Matrix result(this->n, this->m);
//	for (int i=0; i < m; ++i)
//	{
//		for (int j=0; j < n ; ++j)
//			result.element(j, i) = ptr[i][j];
//	}
//	*this = result;
//	return *this;
//}