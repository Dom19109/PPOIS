#pragma once
#include <string>
using namespace std;

class Long_int
{
private:
	string _number; int _size; bool _negative;
	bool size_equally(int) const;
	bool size_comparison(int) const;
	bool body_comparison(string) const;
	bool module_comparison(Long_int&) const;
	bool all_comparison(Long_int&) const;

	void delete_first_0_from_convert_sizes(Long_int&);
	void convert_to_same_size(Long_int&, Long_int&);
	Long_int sum_control_block(Long_int&);
	void sum_main_work(Long_int&, Long_int);
	Long_int difference_control_block(Long_int&);
	void finding_not_zero_symbol(Long_int&, int);
	Long_int comparison_for_difference(Long_int&, Long_int&);
	Long_int difference_main_work(Long_int, Long_int);

	void divide_proccesing(Long_int&, Long_int&, Long_int&, int, int&);
	Long_int divide_main_work(Long_int&);
	bool zero_checker(Long_int&);

	int converter_Long_to_int(Long_int&);

	void initialize_result_for_multiplication(Long_int&);
	Long_int multiplication_control_block(Long_int&, Long_int&);
	Long_int multiplication_main_work(Long_int, Long_int);
public:
 /**
     @brief Long_int object constructor
     @param  - string
 **/
	Long_int(string);
 /**
     @brief Long_int object constructor
     @param  - int
 **/
	Long_int(int);
 /**
     @brief Long_int default object constructor
	 @details Initialize Long_int as "0"
 **/
	Long_int();
 /**
     @brief Long_int object constructor
     @param  - other Long int
 **/
	Long_int(const Long_int&);
 /**
     @brief  operator=
     @param   - int 
     @retval  - this object reference
 **/
	Long_int operator=(int);
 /**
     @brief  Getter
     @retval  - _number
 **/
	string getnumber();
 /**
     @brief  Getter
     @retval  - _szie
 **/
	int getsize();
 /**
     @brief  Getter
     @retval  - _negative
 **/
	bool getnegative();
 /**
     @brief  Getter
	 @details Return !_negative + _number (if _negative return -_number, else _number)
     @retval  - FullNumber
 **/
	string getfullnumber();
 /**
     @brief  operator==
     @param   - right operand (Long int)
     @retval  - true, if objects are equal
 **/
	bool operator==(Long_int&) const;
 /**
     @brief  operator==
     @param   - right operand (int)
     @retval  - true, if objects are equal
 **/
	bool operator==(int) const;
 /**
     @brief  operator>
     @param   - right operand (Long int)
     @retval  - true, if left object is greater than right
 **/
	bool operator>(Long_int&) const;
 /**
     @brief  operator>
     @param   - right operand (u=int)
     @retval  - true, if left object is greater than right
 **/
	bool operator>(int) const;
 /**
     @brief  operator>=
     @param   - right operand (Long int)
     @retval  - true, if left object is greater or equal than right
 **/
	bool operator>=(Long_int&) const;
 /**
     @brief  operator>=
     @param   - right operand (int)
     @retval  - true, if left object is greater or equal than right
 **/
	bool operator>=(int) const;
 /**
     @brief  operator<
     @param   - right operand (Long int)
     @retval  - true, if left object is less than right
 **/
	bool operator<(Long_int&) const;
 /**
     @brief  operator<
     @param   - right operand (int)
     @retval  - true, if left object is less than right
 **/
	bool operator<(int) const;
 /**
     @brief  operator<=
     @param   - right operand (Long_int)
     @retval  - true, if left object is less or equal than right
 **/
	bool operator<=(Long_int&) const;
 /**
     @brief  operator<=
     @param   - right operand (int)
     @retval  - true, if left object is less or equal than right
 **/
	bool operator<=(int) const;
 /**
     @brief  operator+
     @param   - right operand (Long int)
     @retval  - left operand (this) + right operand (Long int)
 **/
	Long_int operator+(Long_int&);
/**
	@brief  operator+
	@param   - right operand (int)
	@retval  - left operand (this) + Long_int (input)
**/
	Long_int operator+(int);
 /**
     @brief  operator++
     @retval  - Operand + 1
 **/
	Long_int operator++();
 /**
     @brief  operator++
     @param   - construction for post++
     @retval  - *this
 **/
	Long_int operator++(int);
 /**
     @brief  operator+=
     @param   - right operand (Long int)
     @retval  - this object reference
 **/
	Long_int operator+=(Long_int&);
 /**
     @brief  operator+=
     @param   - right operand (int)
     @retval  - this object reference
 **/
	Long_int operator+=(int);
 /**
     @brief  operator-
     @param   - right operand (Long int)
     @retval  - *this - right operand
 **/
	Long_int operator-(Long_int&);
    /**
    @brief  operator-
    @param   - right operand (int)
    @retval  - *this - right operand
**/
	Long_int operator-(int);
 /**
     @brief  operator--
     @retval  - *this - 1
 **/
	Long_int operator--();
 /**
     @brief  operator--
     @param   - construction for post--
     @retval  - *this before operation
 **/
	Long_int operator--(int);
 /**
     @brief  operator-=
     @param   - right operand (Long int)
     @retval  - this object reference
 **/
	Long_int operator-=(Long_int&);
 /**
     @brief  operator-=
     @param   - right operand (int)
     @retval  - this object reference
 **/
	Long_int operator-=(int);
 /**
     @brief  operator/
     @param   - right operand (Long int)
     @retval  - *this / right operand or throw exception
 **/
	Long_int operator/(Long_int&);
 /**
     @brief  operator/
     @param   - right operand (int)
     @retval  - *this / right operand or throw exception
 **/
	Long_int operator/(int);
 /**
     @brief  operator/=
     @param   - right operand (Long int)
     @retval  - this object reference
 **/
	Long_int operator/=(Long_int&);
 /**
     @brief  operator/=
     @param   - right operand (int)
     @retval  - this object reference
 **/
	Long_int operator/=(int);
 /**
     @brief  operator*
     @param   - right operand (Long int)
     @retval  - *this * right operand
 **/
	Long_int operator*(Long_int&);
 /**
     @brief  operator*
     @param   - right operand (int)
     @retval  - *this * right operand
 **/
	Long_int operator*(int);
 /**
     @brief  operator*=
     @param   - right operand (Long int)
     @retval  - this object reference
 **/
	Long_int operator*=(Long_int&);
 /**
     @brief  operator*=
     @param   - right operand (int)
     @retval  - this object reference
 **/
	Long_int operator*=(int);
 /**
     @brief  Converter_Long_to_int
     @retval  - *this but with type of int; Or 0 if *this not in the border of int
 **/
	operator int();
};