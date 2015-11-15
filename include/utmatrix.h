// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int Size;       // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	explicit TVector(int s = 10, int si = 0); 
	TVector(const TVector &v);                // конструктор копирования
	~TVector();
	int GetSize()      { return Size;       } // размер вектора
	int GetStartIndex(){ return StartIndex; } // индекс первого элемента
	ValType& operator[](int pos);             // доступ
	bool operator==(const TVector &v) const;  // сравнение
	bool operator!=(const TVector &v) const;  // сравнение
	TVector& operator=(const TVector &v);     // присваивание

	// скалярные операции
	TVector  operator+(const ValType &val) const;   // прибавить скаляр
	TVector  operator-(const ValType &val) const;   // вычесть скаляр
	TVector  operator*(const ValType &val) const;   // умножить на скаляр

	// векторные операции
	TVector  operator+(const TVector &v) const;     // сложение
	TVector  operator-(const TVector &v) const;     // вычитание
	ValType  operator*(const TVector &v) const;     // скалярное произведение

	// ввод-вывод
	template <class ValType>//??
	friend istream& operator>>(istream &in, TVector<ValType> &v);

	template<class ValType> 
	friend ostream& operator<<(ostream &out, const TVector<ValType> &v);

};

template <class ValType>
istream& operator>>(istream &in, TVector<ValType> &v)
{
	for (int i = 0; i < v.Size; i++)
	in >> v.pVector[i];
	return in;
} 

template <class ValType>
ostream& operator<<(ostream &out, const TVector<ValType> &v)
{
	for (int i = 0; i < v.Size; i++)
		out << v.pVector[i] << ' ';
	return out;
}

template <class ValType>
TVector<ValType>::TVector(int s, int si) 
{
	if (s<0) 
		throw "Size < 0";
	if (s>MAX_VECTOR_SIZE) 
		throw "Size > MAX_VECTOR_SIZE";
	if (si<0) 
		throw "StartIndex < 0";

	pVector = new ValType[s];
	if (pVector != NULL)
	{
		Size = s;
		StartIndex = si;
		for(int i = 0; i < s; i++)
		{
			pVector[i] = ValType(0);
		}
	}

	if (pVector == NULL)
	{
		throw "Memory has not been allocated";
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; ++i)
	{
		pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete [] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos<StartIndex)
	{
		throw "[Index] < StartIndex";//СДЕЛАТЬ ТЕСТ?
	}

	if (pos>=(StartIndex+Size))
	{
		throw "[Index] >= StartIndex+Size"; 
	}

	return pVector[pos-StartIndex]; 
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (this==&v) 
		return true; 

	if (Size!=v.Size)
	{
		return false;
	}
	else
	{
		if (StartIndex!=v.StartIndex)
			return false;
		else
			for (int i = 0; i < Size; ++i)
			{
				if (pVector[i]!=v.pVector[i])
				{
					return false; 
				}
			}
	}

	return true;

} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (this==&v) //?
		return false; 

	if (Size!=v.Size)
	{
		return true;
	}
	else 
		if (StartIndex!=v.StartIndex)
			return true;
		else
			for (int i = 0; i < Size; ++i)
			{
				if (pVector[i]!=v.pVector[i])
				{
					return true; 
				}
			}
			return false;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if(&v == this)
	{
		return *this;
	}

	if (Size != v.Size)
	{
		delete[] pVector;
		Size = v.Size;
		pVector = new ValType[Size];
	}

	if (StartIndex != v.StartIndex)
		StartIndex = v.StartIndex;

	for(int i = 0; i < Size; i++)
	{
		pVector[i]=v.pVector[i];
	}

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val) const//
{
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] + val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val) const
{
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] - val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val) const
{
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i]*val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v) const
{
	if (StartIndex != v.StartIndex)
		throw "StartIndex != v.StartIndex";//КАКОЙ ВАРИАНТ ПРАВИЛЬНЫЙ? ЧТО ДЕЛАТЬ, КОГДА ОНИ НЕ РАВНЫ?
	if (Size != v.Size)
		throw "Size != v.Size";
	TVector temp(Size);
	for (int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v) const
{
	if (StartIndex != v.StartIndex)
		throw "StartIndex != v.StartIndex";//КАКОЙ ВАРИАНТ ПРАВИЛЬНЫЙ? ЧТО ДЕЛАТЬ, КОГДА ОНИ НЕ РАВНЫ?
	if (Size != v.Size)
		throw "Size != v.Size";
	TVector temp(Size);
	for (int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] - v.pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v) const
{
	if (StartIndex != v.StartIndex)
		throw "StartIndex != v.StartIndex";//КАКОЙ ВАРИАНТ ПРАВИЛЬНЫЙ? ЧТО ДЕЛАТЬ, КОГДА ОНИ НЕ РАВНЫ?
	if (Size != v.Size)
		throw "Size != v.Size";
    ValType temp = ValType(0);
	for (int i = 0; i < Size; ++i)
		temp += pVector[i]*v.pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);                           
	TMatrix(const TMatrix &mt);                    // копирование
	TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
	bool operator==(const TMatrix &mt) const;      // сравнение
	bool operator!=(const TMatrix &mt) const;      // сравнение
	TMatrix& operator= (const TMatrix &mt);        // присваивание
	TMatrix  operator+ (const TMatrix &mt);        // сложение
	TMatrix  operator- (const TMatrix &mt);        // вычитание

	 //ввод / вывод
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<( ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};


template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)//
{
	if (s<=0)
		throw "Size<=0";
	if (s>MAX_MATRIX_SIZE)
		throw "Size>MAX_MATRIX_SIZE";
	for (int i = 0; i < s; ++i)
		pVector[i] = TVector<ValType>(s-i, i);
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (this==&mt) 
		return true; 

	if (Size!=mt.Size)
	{
		return false;
	}
	else
	{
		for(int j = 0; j < Size; ++j)
			if (pVector[j]!=mt.pVector[j])
				return false;
	}

	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	if (this==&mt) 
		return false; 

	if (Size!=mt.Size)
	{
		return true;
	}
	else
	{
		for(int j = 0; j < Size; ++j)
			if (pVector[j]!=mt.pVector[j])
					return true;
	}

	return false;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if(&mt == this)
	{
		return *this;
	}

	if (Size != mt.Size)
	{
		delete[] pVector;
		Size = mt.Size;
		pVector = new TVector <ValType> [Size];
	}

	for(int i = 0; i < Size; i++)
	{
		pVector[i]=mt.pVector[i];
	}

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение //ВООБЩЕ МОЖНО СДЕЛАТЬ ПО-ДРУГОМУ
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (Size!=mt.Size)
		throw "Different sizes of matrixes";
	TMatrix<ValType> temp (Size);
		for(int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] + mt.pVector[i];
		//for(int j = 0; j < Size; ++j)
		//	for (int k = j; k < Size; ++k)
		//		temp.pVector[j][k] = pVector[j][k] + mt.pVector[j][k];
		return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание //ВООБЩЕ МОЖНО СДЕЛАТЬ ПО-ДРУГОМУ
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
		if (Size!=mt.Size)
		throw "Different sizes of matrixes";
	TMatrix<ValType> temp (Size);
	for(int i = 0; i < Size; ++i)
		temp.pVector[i] = pVector[i] + mt.pVector[i];//НЕВЕРНО!
		//for(int j = 0; j < Size; ++j)
		//	for (int k = j; k < Size; ++k)
		//		temp.pVector[j][k] = pVector[j][k] - mt.pVector[j][k];
		return temp;
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
