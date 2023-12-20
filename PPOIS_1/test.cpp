#include "pch.h"
#include "D:\Проекты\PPOIS_Lab_1\PPOIS_Lab_1\Lab_1.cpp"

TEST(TestingGetters, Get_negative) {
    Long_int A(1), B(-1);
    EXPECT_FALSE(A.getnegative());
    EXPECT_TRUE(B.getnegative());
}
TEST(TestingGetters, Get_number) {
    Long_int A(1), B(-1);
    EXPECT_EQ(A.getnumber(), "1");
    EXPECT_EQ(B.getnumber(), "1");
}
TEST(TestingGetters, Get_size) {
    Long_int A(123), B(-1);
    EXPECT_EQ(A.getsize(), 3);
    EXPECT_EQ(B.getsize(), 1);
}
TEST(TestingGetters, Get_full_number) {
    Long_int A(1), B(-11);
    EXPECT_EQ(A.getfullnumber(), "1");
    EXPECT_EQ(B.getfullnumber(), "-11");
}

TEST(TestingInitialization, Test_Init_with_int)
{
    Long_int Number1(5), Number2(-3);
    EXPECT_EQ(Number1.getfullnumber(), "5");
    EXPECT_EQ(Number2.getfullnumber(), "-3");
}
TEST(TestingInitialization, Test_Init_with_string)
{
    Long_int Number1("5"), Number2("-3");
    EXPECT_EQ(Number1.getfullnumber(), "5");
    EXPECT_EQ(Number2.getfullnumber(), "-3");
}
TEST(TestingInitialization, Test_Init_default)
{
    Long_int Number1;
    EXPECT_EQ(Number1.getfullnumber(), "0");
}

TEST(TestingEqEq, Test_EqEq_Long)
{
    Long_int A(1), B(11), C(-111);
    EXPECT_TRUE(A == A);
    EXPECT_TRUE(B == B);
    EXPECT_TRUE(C == C);

}
TEST(TestingEqEq, Test_Not_EqEq_Long)
{
    Long_int A(1), B(11), C(111);
    EXPECT_FALSE(A == B);
    EXPECT_FALSE(C == B);
    EXPECT_FALSE(A == C);
    EXPECT_FALSE(B == A);
    EXPECT_FALSE(B == C);
    EXPECT_FALSE(C == A);
}
TEST(TestingEqEq, Test_EqEq_int)
{
    Long_int A(1), B(11), C(-111);
    EXPECT_TRUE(A == 1); EXPECT_TRUE(A.getfullnumber() == "1");
    EXPECT_TRUE(B == 11); EXPECT_TRUE(B.getfullnumber() == "11");
    EXPECT_TRUE(C == -111); EXPECT_TRUE(C.getfullnumber() == "-111");
}
TEST(TestingEqEq, Test_Not_EqEq_int)
{
    Long_int A(1), B(11), C(-111);
    EXPECT_FALSE(A == 11); EXPECT_FALSE(A.getfullnumber() == "11");
    EXPECT_FALSE(C == 11); EXPECT_FALSE(C.getfullnumber() == "11");
    EXPECT_FALSE(A == 111); EXPECT_FALSE(A.getfullnumber() == "111");
    EXPECT_FALSE(B == 1); EXPECT_FALSE(B.getfullnumber() == "1");
    EXPECT_FALSE(B == 111); EXPECT_FALSE(B.getfullnumber() == "111");
    EXPECT_FALSE(C == 1); EXPECT_FALSE(C.getfullnumber() == "1");
}

TEST(TestingEqual, Test_Long_to_Long)
{
    Long_int A(165), B(1);
    A = B;
    EXPECT_TRUE(A.getfullnumber() == B.getfullnumber());
}
TEST(TestingEqual, Test_Long_to_int)
{
    Long_int A(165);
    A = 1;
    EXPECT_TRUE(A.getfullnumber() == "1");
}

TEST(TestingMoreFunk, Sign_comparison) {
    Long_int Larger(1), Smaller(-2);
    EXPECT_TRUE(Larger > Smaller);
    EXPECT_FALSE(Smaller > Larger);
    
    Long_int Smaller_more_size(-63);
    EXPECT_TRUE(Larger > Smaller);
    EXPECT_FALSE(Smaller > Larger);
}
TEST(TestingMoreFunk, Size_comparison) {
    Long_int Larger(100), Smaller(3);
    EXPECT_TRUE(Larger > Smaller);
    EXPECT_FALSE(Smaller > Larger);

    Long_int Smaller_more_size(99);
    EXPECT_TRUE(Larger > Smaller);
    EXPECT_FALSE(Smaller > Larger);
}
TEST(TestingMoreFunk, Body_comparison) {
	Long_int Larger_plus(2), Smaller_plus(1);
    EXPECT_TRUE(Larger_plus > Smaller_plus);
    EXPECT_FALSE(Smaller_plus > Larger_plus);

    Long_int Larger_minus(-1), Smaller_minus(-2);
    EXPECT_TRUE(Larger_minus > Smaller_minus);
    EXPECT_FALSE(Smaller_minus > Larger_minus);

    Long_int Larger_plus_more_size(21), Smaller_plus_more_size(19);
    EXPECT_TRUE(Larger_plus_more_size > Smaller_plus_more_size);
    EXPECT_FALSE(Smaller_plus_more_size > Larger_plus_more_size);

    Long_int Larger_minus_more_size(-19), Smaller_minus_more_size(-21);
    EXPECT_TRUE(Larger_minus_more_size > Smaller_minus_more_size);
    EXPECT_FALSE(Smaller_minus_more_size > Larger_minus_more_size);

    Long_int Equal(1);
    EXPECT_FALSE(Equal > Equal);
}

TEST(TestingLessFunk, Sign_comparison) {
    Long_int Larger(1), Smaller(-2);
    EXPECT_FALSE(Larger < Smaller);
    EXPECT_TRUE(Smaller < Larger);

    Long_int Smaller_more_size(-63);
    EXPECT_FALSE(Larger < Smaller);
    EXPECT_TRUE(Smaller < Larger);
}
TEST(TestingLessFunk, Size_comparison) {
    Long_int Larger(100), Smaller(3);
    EXPECT_FALSE(Larger < Smaller);
    EXPECT_TRUE(Smaller < Larger);

    Long_int Smaller_more_size(99);
    EXPECT_FALSE(Larger < Smaller);
    EXPECT_TRUE(Smaller < Larger);
}
TEST(TestingLessFunk, Body_comparison) {
    Long_int Larger_plus(2), Smaller_plus(1);
    EXPECT_FALSE(Larger_plus < Smaller_plus);
    EXPECT_TRUE(Smaller_plus < Larger_plus);

    Long_int Larger_minus(-1), Smaller_minus(-2);
    EXPECT_FALSE(Larger_minus < Smaller_minus);
    EXPECT_TRUE(Smaller_minus < Larger_minus);

    Long_int Larger_plus_more_size(21), Smaller_plus_more_size(19);
    EXPECT_FALSE(Larger_plus_more_size < Smaller_plus_more_size);
    EXPECT_TRUE(Smaller_plus_more_size < Larger_plus_more_size);

    Long_int Larger_minus_more_size(-19), Smaller_minus_more_size(-21);
    EXPECT_FALSE(Larger_minus_more_size < Smaller_minus_more_size);
    EXPECT_TRUE(Smaller_minus_more_size < Larger_minus_more_size);

    Long_int Equal(1);
    EXPECT_FALSE(Equal < Equal);
}

TEST(TestingMoreEqualFunk, Sign_comparison) {
    Long_int Larger(1), Smaller(-2);
    EXPECT_TRUE(Larger >= Smaller);
    EXPECT_FALSE(Smaller >= Larger);

    Long_int Smaller_more_size(-63);
    EXPECT_TRUE(Larger >= Smaller);
    EXPECT_FALSE(Smaller >= Larger);
}
TEST(TestingMoreEqualFunk, Size_comparison) {
    Long_int Larger(100), Smaller(3);
    EXPECT_TRUE(Larger >= Smaller);
    EXPECT_FALSE(Smaller >= Larger);

    Long_int Smaller_more_size(99);
    EXPECT_TRUE(Larger >= Smaller);
    EXPECT_FALSE(Smaller >= Larger);
}
TEST(TestingMoreEqualFunk, Body_comparison) {
    Long_int Larger_plus(2), Smaller_plus(1);
    EXPECT_TRUE(Larger_plus >= Smaller_plus);
    EXPECT_FALSE(Smaller_plus >= Larger_plus);

    Long_int Larger_minus(-1), Smaller_minus(-2);
    EXPECT_TRUE(Larger_minus >= Smaller_minus);
    EXPECT_FALSE(Smaller_minus >= Larger_minus);

    Long_int Larger_plus_more_size(21), Smaller_plus_more_size(19);
    EXPECT_TRUE(Larger_plus_more_size >= Smaller_plus_more_size);
    EXPECT_FALSE(Smaller_plus_more_size >= Larger_plus_more_size);

    Long_int Larger_minus_more_size(-19), Smaller_minus_more_size(-21);
    EXPECT_TRUE(Larger_minus_more_size >= Smaller_minus_more_size);
    EXPECT_FALSE(Smaller_minus_more_size >= Larger_minus_more_size);

    Long_int Equal(1);
    EXPECT_TRUE(Equal >= Equal);
}

TEST(TestingLessEqualFunk, Sign_comparison) {
    Long_int Larger(1), Smaller(-2);
    EXPECT_FALSE(Larger <= Smaller);
    EXPECT_TRUE(Smaller <= Larger);

    Long_int Smaller_more_size(-63);
    EXPECT_FALSE(Larger <= Smaller);
    EXPECT_TRUE(Smaller <= Larger);
}
TEST(TestingLessEqualFunk, Size_comparison) {
    Long_int Larger(100), Smaller(3);
    EXPECT_FALSE(Larger <= Smaller);
    EXPECT_TRUE(Smaller <= Larger);

    Long_int Smaller_more_size(99);
    EXPECT_FALSE(Larger <= Smaller);
    EXPECT_TRUE(Smaller <= Larger);
}
TEST(TestingLessEqualFunk, Body_comparison) {
    Long_int Larger_plus(2), Smaller_plus(1);
    EXPECT_FALSE(Larger_plus <= Smaller_plus);
    EXPECT_TRUE(Smaller_plus <= Larger_plus);

    Long_int Larger_minus(-1), Smaller_minus(-2);
    EXPECT_FALSE(Larger_minus <= Smaller_minus);
    EXPECT_TRUE(Smaller_minus <= Larger_minus);

    Long_int Larger_plus_more_size(21), Smaller_plus_more_size(19);
    EXPECT_FALSE(Larger_plus_more_size <= Smaller_plus_more_size);
    EXPECT_TRUE(Smaller_plus_more_size <= Larger_plus_more_size);

    Long_int Larger_minus_more_size(-19), Smaller_minus_more_size(-21);
    EXPECT_FALSE(Larger_minus_more_size <= Smaller_minus_more_size);
    EXPECT_TRUE(Smaller_minus_more_size <= Larger_minus_more_size);

    Long_int Equal(1);
    EXPECT_TRUE(Equal <= Equal);
}

TEST(TestingPlusFunk, Test_Same_sign_Same_size) {
    Long_int A(1), B(2), Result = A + B;
    EXPECT_EQ(Result.getfullnumber(), "3");
    Long_int D(10), C(12); 
    Result = C + D;
    EXPECT_EQ(Result.getfullnumber(), "22");
    Long_int E(1234), F(8765);
    Result = F + E;
    EXPECT_EQ(Result.getfullnumber(), "9999");
}
TEST(TestingPlusFunk, Test_Same_sign_Diff_size) {
    Long_int A(1), B(23), Result = A + B;
    EXPECT_EQ(A.getfullnumber(), "1");
    EXPECT_EQ(B.getfullnumber(), "23");
    EXPECT_EQ(Result.getfullnumber(), "24");
    Long_int C(6367), D(232);
    Result = C + D;
    EXPECT_EQ(C.getfullnumber(), "6367");
    EXPECT_EQ(D.getfullnumber(), "232");
    EXPECT_EQ(Result.getfullnumber(), "6599");
    Long_int E(12345), F(987001);
    Result = F + E;
    EXPECT_EQ(E.getfullnumber(), "12345");
    EXPECT_EQ(F.getfullnumber(), "987001");
    EXPECT_EQ(Result.getfullnumber(), "999346");
}
TEST(TestingPlusFunk, Test_Diff_sign_Same_size) {
    Long_int A(1), B(-2), Result = A + B;
    EXPECT_EQ(Result.getfullnumber(), "-1");
    Long_int D(-10), C(12);
    Result = C + D;
    EXPECT_EQ(Result.getfullnumber(), "2");
    Long_int E(1234), F(-8765);
    Result = F + E;
    EXPECT_EQ(Result.getfullnumber(), "-7531");
    Long_int G(-1);
    Result = A + G;
    EXPECT_EQ(Result.getfullnumber(), "0");
}
TEST(TestingPlusFunk, Test_Diff_sign_Diff_size) {
    Long_int A(-1), B(23), Result = A + B;
    EXPECT_EQ(A.getfullnumber(), "-1");
    EXPECT_EQ(B.getfullnumber(), "23");
    EXPECT_EQ(Result.getfullnumber(), "22");
    Long_int C(-6367), D(232);
    Result = C + D;
    EXPECT_EQ(C.getfullnumber(), "-6367");
    EXPECT_EQ(D.getfullnumber(), "232");
    EXPECT_EQ(Result.getfullnumber(), "-6135");
    Long_int E(-12345), F(987001);
    Result = F + E;
    EXPECT_EQ(E.getfullnumber(), "-12345");
    EXPECT_EQ(F.getfullnumber(), "987001");
    EXPECT_EQ(Result.getfullnumber(), "974656");
}

TEST(TestingPlusEqFunk, Test_sum_eq)
{
    Long_int A(2), B(3), C(-4), D(-1), E(154), F(-265);
    A += B;
    EXPECT_EQ(A.getfullnumber(), "5");
    A += C;
    EXPECT_EQ(A.getfullnumber(), "1");
    A += D;
    EXPECT_EQ(A.getfullnumber(), "0");
    A += E;
    EXPECT_EQ(A.getfullnumber(), "154");
    A += F;
    EXPECT_EQ(A.getfullnumber(), "-111");
}

TEST(TestingPlusPlus, Test_Pre_plus_plus)
{
    Long_int A(8), B;
    B = ++A;
    EXPECT_EQ(A.getfullnumber(), "9");
    EXPECT_EQ(B.getfullnumber(), "9");
    EXPECT_EQ(A.getfullnumber(), B.getfullnumber());
    B = ++A;
    EXPECT_EQ(A.getfullnumber(), "10");
    EXPECT_EQ(B.getfullnumber(), "10");
    EXPECT_EQ(A.getfullnumber(), B.getfullnumber());
}
TEST(TestingPlusPlus, Test_Post_plus_plus)
{
    Long_int A(8), B;
    B = A++;
    EXPECT_EQ(A.getfullnumber(), "9");
    EXPECT_EQ(B.getfullnumber(), "8");
    EXPECT_FALSE(A.getfullnumber() == B.getfullnumber());
    B = A++;
    EXPECT_EQ(A.getfullnumber(), "10");
    EXPECT_EQ(B.getfullnumber(), "9");
    EXPECT_FALSE(A.getfullnumber() == B.getfullnumber());
}

TEST(TestingMinusFunk, Test_Same_sign_Same_size) {
    Long_int A(1), B(2), Result = A - B;
    EXPECT_EQ(Result.getfullnumber(), "-1");
    Long_int D(10), C(12);
    Result = C - D;
    EXPECT_EQ(Result.getfullnumber(), "2");
    Long_int E(1234), F(8765);
    Result = E - F;
    EXPECT_EQ(Result.getfullnumber(), "-7531");
    Result = A - A;
    EXPECT_EQ(Result.getfullnumber(), "0");
}
TEST(TestingMinusFunk, Test_Same_sign_Diff_size) {
    Long_int A(1), B(23), Result = A - B;
    EXPECT_EQ(A.getfullnumber(), "1");
    EXPECT_EQ(B.getfullnumber(), "23");
    EXPECT_EQ(Result.getfullnumber(), "-22");
    Long_int C(6367), D(232);
    Result = C - D;
    EXPECT_EQ(C.getfullnumber(), "6367");
    EXPECT_EQ(D.getfullnumber(), "232");
    EXPECT_EQ(Result.getfullnumber(), "6135");
    Long_int E(12345), F(987001);
    Result = F - E;
    EXPECT_EQ(E.getfullnumber(), "12345");
    EXPECT_EQ(F.getfullnumber(), "987001");
    EXPECT_EQ(Result.getfullnumber(), "974656");
}
TEST(TestingMinusFunk, Test_Diff_sign_Same_size) {
    Long_int A(1), B(-2), Result = A - B;
    EXPECT_EQ(Result.getfullnumber(), "3");
    Long_int D(-10), C(12);
    Result = C - D;
    EXPECT_EQ(Result.getfullnumber(), "22");
    Long_int E(1234), F(-8765);
    Result = F - E;
    EXPECT_EQ(Result.getfullnumber(), "-9999");
}
TEST(TestingMinusFunk, Test_Diff_sign_Diff_size) {
    Long_int A(-1), B(23), Result = A - B;
    EXPECT_EQ(A.getfullnumber(), "-1");
    EXPECT_EQ(B.getfullnumber(), "23");
    EXPECT_EQ(Result.getfullnumber(), "-24");
    Long_int C(-6367), D(232);
    Result = D - C;
    EXPECT_EQ(C.getfullnumber(), "-6367");
    EXPECT_EQ(D.getfullnumber(), "232");
    EXPECT_EQ(Result.getfullnumber(), "6599");
    Long_int E(-12345), F(987001);
    Result = F - E;
    EXPECT_EQ(E.getfullnumber(), "-12345");
    EXPECT_EQ(F.getfullnumber(), "987001");
    EXPECT_EQ(Result.getfullnumber(), "999346");
}

TEST(TestingMinusEqFunk, Test_difference_eq)
{
    Long_int A(2), B(3), C(-4), D(-1), E(154), F(-265);
    A -= B;
    EXPECT_EQ(A.getfullnumber(), "-1");
    A -= C;
    EXPECT_EQ(A.getfullnumber(), "3");
    A -= D;
    EXPECT_EQ(A.getfullnumber(), "4");
    A -= E;
    EXPECT_EQ(A.getfullnumber(), "-150");
    A -= F;
    EXPECT_EQ(A.getfullnumber(), "115");
}

TEST(TestingMinusMinus, Test_Pre_minus_minus)
{
    Long_int A(-8), B;
    B = --A;
    EXPECT_EQ(A.getfullnumber(), "-9");
    EXPECT_EQ(B.getfullnumber(), "-9");
    EXPECT_EQ(A.getfullnumber(), B.getfullnumber());
    B = --A;
    EXPECT_EQ(A.getfullnumber(), "-10");
    EXPECT_EQ(B.getfullnumber(), "-10");
    EXPECT_EQ(A.getfullnumber(), B.getfullnumber());
}
TEST(TestingMinusMinus, Test_Post_minus_minus)
{
    Long_int A(-8), B;
    B = A--;
    EXPECT_EQ(A.getfullnumber(), "-9");
    EXPECT_EQ(B.getfullnumber(), "-8");
    EXPECT_FALSE(A.getfullnumber() == B.getfullnumber());
    B = A--;
    EXPECT_EQ(A.getfullnumber(), "-10");
    EXPECT_EQ(B.getfullnumber(), "-9");
    EXPECT_FALSE(A.getfullnumber() == B.getfullnumber());
}

TEST(TestingMultiplication, Test_same_sign)
{
    Long_int A(0), B(1), C(2), D(15), F(5), G(9), H(999), Result;
    Result = A * B;
    EXPECT_EQ(A.getfullnumber(), "0");
    EXPECT_EQ(B.getfullnumber(), "1");
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = A * H;
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = B * H;
    EXPECT_EQ(Result.getfullnumber(), "999");
    Result = C * H;
    EXPECT_EQ(Result.getfullnumber(), "1998");
    Result = C * D;
    EXPECT_EQ(Result.getfullnumber(), "30");
    Result = D * F;
    EXPECT_EQ(Result.getfullnumber(), "75");
    Result = F * G;
    EXPECT_EQ(Result.getfullnumber(), "45");
}
TEST(TestingMultiplication, Test_diff_sign)
{
    Long_int A(0), B(-1), C(-2), D(15), F(-5), G(9), H(999), Result;
    Result = A * B;
    EXPECT_EQ(A.getfullnumber(), "0");
    EXPECT_EQ(B.getfullnumber(), "-1");
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = A * H;
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = B * H;
    EXPECT_EQ(Result.getfullnumber(), "-999");
    Result = C * H;
    EXPECT_EQ(Result.getfullnumber(), "-1998");
    Result = C * D;
    EXPECT_EQ(Result.getfullnumber(), "-30");
    Result = D * F;
    EXPECT_EQ(Result.getfullnumber(), "-75");
    Result = F * G;
    EXPECT_EQ(Result.getfullnumber(), "-45");
    Result = F * C;
    EXPECT_EQ(Result.getfullnumber(), "10");
}
TEST(TestingMultiplication, Test_Multi_Eq)
{
    Long_int A(0), B(-1), C(-2), D(15);
    A *= B;
    EXPECT_EQ(A.getfullnumber(), "0");
    B *= C;
    EXPECT_EQ(B.getfullnumber(), "2");
    B *= D;
    EXPECT_EQ(B.getfullnumber(), "30");
}

TEST(TestingDivide, Test_Div_int_work)
{
    Long_int A(1), B(12340), C(0), Result;
    Result = A / 1;
    EXPECT_EQ(Result.getfullnumber(), "1");
    Result = A / 2;
    EXPECT_EQ(Result.getfullnumber(), "0");

    Result = C / 1;
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = C / 2;
    EXPECT_EQ(Result.getfullnumber(), "0");

    Result = B / 1;
    EXPECT_EQ(Result.getfullnumber(), "12340");
    Result = B / 2;
    EXPECT_EQ(Result.getfullnumber(), "6170");
    Result = B / 5;
    EXPECT_EQ(Result.getfullnumber(), "2468");
    Result = B / 10;
    EXPECT_EQ(Result.getfullnumber(), "1234");
}

TEST(TestingDivide, Test_Div_Long_work)
{
    Long_int A(1), B(12340), C(0), D(-1), E(-2), F(5), G(10), H(4), Result, Resultsame;
    Result = A / D;
    EXPECT_EQ(Result.getfullnumber(), "-1");
    Result = A / E;
    EXPECT_EQ(Result.getfullnumber(), "0");

    Result = C / D;
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = C / E;
    EXPECT_EQ(Result.getfullnumber(), "0");

    Result = B / D;
    EXPECT_EQ(Result.getfullnumber(), "-12340");
    Result = B / E;
    EXPECT_EQ(Result.getfullnumber(), "-6170");
    Result = B / F;
    EXPECT_EQ(Result.getfullnumber(), "2468");
    Result = B / G;
    EXPECT_EQ(Result.getfullnumber(), "1234");

    Result = F / G;
    EXPECT_EQ(Result.getfullnumber(), "0");
    Result = G / F;
    EXPECT_EQ(Result.getfullnumber(), "2");

    Result = G / H;
    Resultsame = G / F;
    EXPECT_EQ(Result.getfullnumber(), Resultsame.getfullnumber());
}
TEST(TestingDivide, Test_Div_int_exception)
{
    Long_int A(1), B(12340);
    EXPECT_ANY_THROW(A / 0);
    EXPECT_ANY_THROW(B / 0);
}
TEST(TestingDivide, Test_Div_Long_exception)
{
    Long_int A(1), B(12340), C(0);
    EXPECT_ANY_THROW(A / C);
    EXPECT_ANY_THROW(B / C);
}
 
TEST(TestingConvertToInt, Test_converter)
{
    Long_int A;
    EXPECT_EQ(int(A), 0);
    Long_int B(123);
    EXPECT_EQ(int(B), 123);
    Long_int C(-123);
    EXPECT_EQ(int(C), -123);
    Long_int D(-21345);
    EXPECT_EQ(int(D), -21345);
}
TEST(TestingConvertToInt, Test_Exception)
{
    Long_int Larger("15"), Smaller("1000000");
    EXPECT_EQ(int(Larger), 15);
    EXPECT_EQ(int(Smaller), 0);
    //EXPECT_ANY_THROW(int(Smaller));
}