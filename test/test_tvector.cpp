#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)//на конструктор
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_zero_length)
{
  ASSERT_ANY_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}
//_________________________________________________________________
TEST(TVector, can_create_copied_vector)//на конструктор копирования
{
  TVector<int> v;

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(5);
  v[0] = 1;
  TVector<int> v1(v);
  EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(5);
  v[0] = 1;
  TVector<int> v1(v);
  v[1] = 2;
  EXPECT_NE(v[1], v1[1]);
}

//_________________________________________________________________
TEST(TVector, can_get_size)//на получение размера 
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}
//_________________________________________________________________
TEST(TVector, can_get_start_index)//на получение стартового индекса
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}
//_________________________________________________________________
TEST(TVector, can_set_and_get_element)//[]
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  	TVector<int> v;
	ASSERT_ANY_THROW(v[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(5);
  ASSERT_ANY_THROW(v[6]);
}
//________________________________________________________________
TEST(TVector, compare_equal_vectors_return_true) //==
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  TVector<int> v1(v);
  EXPECT_TRUE(v1==v); 
}

TEST(TVector, compare_different_vectors_with_equal_size_return_false)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  TVector<int> v1(v);
  v1[3] = 2;
  EXPECT_FALSE(v1==v); 
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  EXPECT_TRUE(v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)//?????????????
{
  TVector<int> v (5), v1 (2);
  EXPECT_NE(v, v1);
}

TEST(TVector, compare_vectors_with_different_size_return_false) //?????????
{
  TVector<int> v (5), v1 (2);
  EXPECT_FALSE(v == v1);
}

TEST(TVector, compare_vector_with_different_start_index_return_false)
{
  TVector<int> v (5, 2);
  TVector<int> v1 (5, 3);
  EXPECT_FALSE(v==v1);
}
//___________________________________________________________________________
TEST(TVector, ne_compare_different_vectors_with_equal_size_return_true_) //!=
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  TVector<int> v1(v);
  v1[3] = 2;
  EXPECT_TRUE(v1!=v); 
}

TEST(TVector, ne_compare_vector_with_itself_return_false)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  EXPECT_FALSE(v!=v);
} 

TEST(TVector, ne_compare_vectors_with_different_size_return_true_) 
{
  TVector<int> v (5), v1(2);
  EXPECT_TRUE(v1!=v); 
}

TEST(TVector, ne_compare_equal_vectors_return_false) 
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  TVector<int> v1(v);
  EXPECT_FALSE(v1!=v); 
}

TEST(TVector, ne_compare_vector_with_different_start_index_and_equal_size_return_true)
{
  TVector<int> v (5, 2);
  TVector<int> v1 (5, 3);
  EXPECT_TRUE(v!=v1);
}
//_________________________________________________________________
TEST(TVector, can_assign_vector_to_itself) //=
{
  TVector<int> v (2);
  v[0] = 5;
  v[1] = 1;
  v = v;
  EXPECT_EQ(5, v[0]);
  EXPECT_EQ(1, v[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;
  TVector<int> v1 = v;
  EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v (5);
  v = TVector<int> (6);
  EXPECT_EQ(6, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;

  TVector<int> v1(7);
  v1 = v;

  EXPECT_EQ(v, v1);
}

TEST(TVector, can_assign_vectors_of_different_startindex)
{
  TVector<int> v (5);
  v[2] = 5;
  v[1] = 1;

  TVector<int> v1(5, 2);
  v1 = v;

  EXPECT_EQ(v, v1);
}

//_________________________________________________________
TEST(TVector, can_add_scalar_to_vector)//+скаляр
{
  TVector<int> v (3), v1 (5), v2(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  v1 = v + 2;

  v2[0] = 3;
  v2[1] = 4;
  v2[2] = 5;

  EXPECT_EQ(v2, v1);
}
//_________________________________________________________
TEST(TVector, can_subtract_scalar_from_vector)// - скаляр
{
  TVector<int> v (3), v1 (5), v2(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  v1 = v - 2;

  v2[0] = -1;
  v2[1] = 0;
  v2[2] = 1;

  EXPECT_EQ(v2, v1);
}
//_________________________________________________________
TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v (3), v1 (5), v2(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  v1 = v*2;

  v2[0] = 2;
  v2[1] = 4;
  v2[2] = 6;

  EXPECT_EQ(v2, v1);
}
//_________________________________________________________
TEST(TVector, can_add_vectors_with_equal_size) //сложение векторов
{
  TVector<int> v(2), v1(2), v2(5), v3(2);
  v[0] = 1;
  v[1] = 2;

  v1[0] = 2;
  v1[1] = 4;

  v3[0] = 3;
  v3[1] = 6;

  v2 = v + v1;

  EXPECT_EQ(v3, v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(2), v1(3);

  ASSERT_ANY_THROW(v + v1);
}
//__________________________________________________________вычитание векторов
TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v(2), v1(2), v2(5), v3(2);
  v[0] = 1;
  v[1] = 2;

  v1[0] = 2;
  v1[1] = 4;

  v3[0] = -1;
  v3[1] = -2;

  v2 = v - v1;

  EXPECT_EQ(v3, v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(2), v1(3);

  ASSERT_ANY_THROW(v - v1);
}
//___________________________________________________________скалярное произведение
TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(2), v1(2);
  v[0] = 3;
  v[1] = 2;

  v1[0] = 2;
  v1[1] = 4;

  EXPECT_EQ(14, v*v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(2), v1(3);

  ASSERT_ANY_THROW(v*v1);
}


