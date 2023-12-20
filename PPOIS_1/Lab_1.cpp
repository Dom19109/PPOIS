/*!
	\brief Implementation of the long int class
	\author Dom
	\version 1.8
	\date December 2023
	\details Contains a set of constructors, rewrited operation (math expresions, logical)
*/

#include "Lab_1.h"

bool Long_int::size_equally(int right_operand_size) const
{
		return _size == right_operand_size;
}
bool Long_int::size_comparison(int right_operand_size) const
{
		return _size > right_operand_size;
}
bool Long_int::body_comparison(string right_operand_number) const
{
	int i = 0;
	while (_number[i] == right_operand_number[i] && i < _size)
		i++;
	if (_number[i] > right_operand_number[i])
			return true;
		else
			return false;
	return false;
}
bool Long_int::module_comparison(Long_int& Long_right_operand) const
{
	bool result = size_comparison(Long_right_operand._size);
	result = result || (size_equally(Long_right_operand._size) && body_comparison(Long_right_operand._number));
	return result;
}
bool Long_int::all_comparison(Long_int& Long_right_operand) const
{
	if (_negative != Long_right_operand._negative)
		return !_negative;
	bool size_compare = size_comparison(Long_right_operand._size);
	if (!size_equally(Long_right_operand._size))
		return ((size_compare && !_negative) || (!size_compare && _negative));
	return ((body_comparison(Long_right_operand._number) && !_negative) || (!body_comparison(Long_right_operand._number) && _negative));
}
void Long_int::delete_first_0_from_convert_sizes(Long_int& Result)
{
	const unsigned CODE_OF_ZERO = '0';
	while (Result._number[0] == CODE_OF_ZERO)
	{
		Result._number.erase(0, 1);
		Result._size--;
	}
	if (!Result._size)
	{
		const string STRING_OF_ZERO = "0";
		Result._number = STRING_OF_ZERO;
		Result._size = 1;
		Result._negative = false;
	}
}
void Long_int::convert_to_same_size(Long_int& Long_left_operand, Long_int& Long_right_operand)
{
	const string STRING_OF_ZERO = "0";
	for (int i = Long_left_operand._size; i < Long_right_operand._size; i++)
		Long_left_operand._number = STRING_OF_ZERO + Long_left_operand._number;
	for (int i = Long_right_operand._size; i < Long_left_operand._size; i++)
		Long_right_operand._number = STRING_OF_ZERO + Long_right_operand._number;
	Long_left_operand._size = max(Long_left_operand._size, Long_right_operand._size);
	Long_right_operand._size = Long_left_operand._size;
}
Long_int Long_int::sum_control_block(Long_int& Long_right_operand)
{
	Long_int Result = *this;
	if (_negative == Long_right_operand._negative)
		sum_main_work(Result, Long_right_operand);
	else
		Result = comparison_for_difference(Result, Long_right_operand);
	return Result;
}
void Long_int::sum_main_work(Long_int& Result, Long_int Long_right_operand)
{
	const int CODE_OF_ZERO = '0'; const string STRING_OF_ONE = "1";
	convert_to_same_size(Result, Long_right_operand);
	int this_sum_for_next_digit = 0;
	for (int i = Result._size - 1; i > -1; i--)
	{
		int sum_of_2_digits = Result._number[i] + Long_right_operand._number[i] - 2 * CODE_OF_ZERO + this_sum_for_next_digit;
		this_sum_for_next_digit = sum_of_2_digits / 10;
		Result._number[i] = sum_of_2_digits % 10 + CODE_OF_ZERO;
	}
	if (this_sum_for_next_digit != 0)
	{
		Result._number = STRING_OF_ONE + Result._number;
		Result._size++;
	}
}
Long_int Long_int::difference_control_block(Long_int& Long_right_operand)
{
	Long_int Result = *this;
	if (_negative != Long_right_operand._negative)
		sum_main_work(Result, Long_right_operand);
	else
	{
		Result = comparison_for_difference(*this, Long_right_operand);
		if (*this > Long_right_operand || *this == Long_right_operand)
			Result._negative = false;
		else
			Result._negative = true;
	}
	return Result;
}
void Long_int::finding_not_zero_symbol(Long_int& Result, int i)
{
	const unsigned CODE_OF_ZERO = '0', TEN = 10;
	if (Result._number[i] == CODE_OF_ZERO)
		finding_not_zero_symbol(Result, i - 1);
	Result._number[i]--;
	Result._number[i + 1] += TEN;
}
Long_int Long_int::comparison_for_difference(Long_int& Long_left_operand, Long_int& Long_right_operand)
{
	Long_int Result = Long_left_operand;
	if (module_comparison(Long_right_operand))
		Result = difference_main_work(Long_left_operand, Long_right_operand);
	else
		Result = difference_main_work(Long_right_operand, Long_left_operand);
	delete_first_0_from_convert_sizes(Result);
	return Result;
}
Long_int Long_int::difference_main_work(Long_int Larger_module, Long_int Smaller_module)
{
	const unsigned CODE_OF_ZERO = '0';
	convert_to_same_size(Larger_module, Smaller_module);
	Long_int Result = Larger_module;
	for (int i = 0, difference = 0; i < Larger_module._size; i++)
	{
		difference = Larger_module._number[i] - Smaller_module._number[i];
		if (difference < 0)
		{
			finding_not_zero_symbol(Result, i - 1);
			Result._number[i] += difference - Larger_module._number[i] + CODE_OF_ZERO;
		}
		else
			Result._number[i] = difference + CODE_OF_ZERO;
	}
	return Result;
}
void Long_int::divide_proccesing(Long_int& Intermediate_number, Long_int& Long_right_module, Long_int& Result, int i, int &iterations)
{
	const int CODE_OF_ZERO = '0';
	Intermediate_number = Intermediate_number * 10 + (this->_number[i] - CODE_OF_ZERO);
	if (Intermediate_number >= Long_right_module)
	{
		int j = 0; Result *= 10; iterations = 0;
		for (; Intermediate_number >= Long_right_module; j++)
			Intermediate_number -= Long_right_module;
		Result += j;
	}
}
Long_int Long_int::divide_main_work(Long_int& Long_right_operand)
{
	if (zero_checker(Long_right_operand))
		throw "Devition by zero";
	Long_int Long_right_module = Long_right_operand;
	Long_right_module._negative = false;
	if (zero_checker(*this) || (!module_comparison(Long_right_operand) && !(*this == Long_right_operand || *this == Long_right_module)))
		return 0;
	Long_int Result("");
	Long_int Intermediate_number(0); int iterations = 0;
	for (int i = 0; i < _size; i++, iterations++)
		divide_proccesing(Intermediate_number, Long_right_module, Result, i, iterations);
	for (int i = 0; i < iterations - 1; i++)
		Result *= 10;
	Result._negative = !(this->_negative == Long_right_operand._negative);
	return Result;
}
bool Long_int::zero_checker(Long_int& Long_right_operand)
{
	const string STRING_OF_ZERO = "0";
	return (Long_right_operand._number == STRING_OF_ZERO);
}
int Long_int::converter_Long_to_int(Long_int& Operand)
{
	Long_int Max("2147483647"), Min("-2147483648");
	if (Operand > Max || Operand < Min)
	{
		return 0;
		//throw "borders exception";
	}
	if (_negative)
		_number = "-" + _number;
	int result = stoi(_number); 
	return result;
}
void Long_int::initialize_result_for_multiplication(Long_int& Operand)
{
	const string STRING_OF_ZERO = "0";
	for (int i = 1; i < Operand._size; i++)
		Operand._number = STRING_OF_ZERO + Operand._number;
}
Long_int Long_int::multiplication_control_block(Long_int& Long_left_operand, Long_int& Long_right_operand)
{
	if (size_comparison(Long_right_operand._size))
		return multiplication_main_work(Long_left_operand, Long_right_operand);
	else
		return multiplication_main_work(Long_right_operand, Long_left_operand);
}
Long_int Long_int::multiplication_main_work(Long_int Larger_operand, Long_int Smaller_operand)
{
	Long_int Result; int multiplication = 0, sum_for_next_digit = 0, sum_for_this_digit = 0; const unsigned CODE_OF_ZERO = '0';
	Result._size = Larger_operand._size + Smaller_operand._size; 
	Result._negative = !(Larger_operand._negative == Smaller_operand._negative);
	initialize_result_for_multiplication(Result);
	convert_to_same_size(Result, Larger_operand);
	for (int i = Smaller_operand._size - 1; i > -1; i--)
		for (int j = Larger_operand._size - 1; j > -2 + Smaller_operand._size; j--)
		{
			multiplication = (Larger_operand._number[j]-CODE_OF_ZERO) * (Smaller_operand._number[i]-CODE_OF_ZERO) + sum_for_next_digit;
			sum_for_this_digit = multiplication + Result._number[j - (Smaller_operand._size - 1 - i)] - CODE_OF_ZERO;
			sum_for_next_digit = sum_for_this_digit / 10;
			Result._number[j - (Smaller_operand._size - 1 - i)] = sum_for_this_digit % 10 + CODE_OF_ZERO;
		}
	delete_first_0_from_convert_sizes(Result);
	return Result;
}
Long_int::Long_int(string input)
{
	_number = input;
	if (_number[0] == '-')
	{
		_negative = true;
		_number.erase(0, 1);
	}
	else
		_negative = false;
	
	_size = _number.size();
}
Long_int::Long_int(int input)
{
	_number = to_string(input);
	if (_number[0] == '-')
	{
		_negative = true;
		_number.erase(0, 1);
	}
	else
		_negative = false;
	_size = _number.size();
}
Long_int::Long_int()
{
	const string STRING_OF_ZERO = "0";
	const unsigned one = 1;
	_number = STRING_OF_ZERO;
	_size = one;
	_negative = false;
}
Long_int::Long_int(const Long_int &copied)
{
	_number = copied._number;
	_negative = copied._negative;
	_size = copied._size;
}
Long_int Long_int::operator=(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	*this = Long_right_operand;
	return *this;
}
string Long_int::getnumber()
{
	return _number;
}
int Long_int::getsize()
{
	return _size;
}
bool Long_int::getnegative()
{
	return _negative;
}
string Long_int::getfullnumber()
{
	string full_number = _number;
	if (_negative)
		full_number = "-" + full_number;
	return full_number;
}
bool Long_int::operator==(Long_int& Long_right_operand) const
{
	return ((_number == Long_right_operand._number) && (_negative == Long_right_operand._negative));
}

bool Long_int::operator==(int right_operand) const
{
	Long_int Long_right_operand(right_operand);
	return *this == Long_right_operand;
}

bool Long_int::operator>(Long_int& Long_right_operand) const
{
	return all_comparison(Long_right_operand);
}

bool Long_int::operator>(int right_operand) const
{
	Long_int Long_right_operand(right_operand);
	return all_comparison(Long_right_operand);
}

bool Long_int::operator>=(Long_int& Long_right_operand) const
{
	return (*this > Long_right_operand || *this == Long_right_operand);
}

bool Long_int::operator>=(int right_operand) const
{
	Long_int Long_right_operand(right_operand);
	return (*this > Long_right_operand || *this == Long_right_operand);
}

bool Long_int::operator<(Long_int& Long_right_operand)  const
{
	return !all_comparison(Long_right_operand) && !(*this == Long_right_operand);
}

bool Long_int::operator<(int right_operand)  const
{
	Long_int Long_right_operand(right_operand);
	return all_comparison(Long_right_operand) && !(*this == Long_right_operand);
}

bool Long_int::operator<=(Long_int& Long_right_operand) const
{
	return (*this < Long_right_operand || *this == Long_right_operand);
}

bool Long_int::operator<=(int right_operand) const
{
	Long_int Long_right_operand(right_operand);
	return (*this > Long_right_operand || *this == Long_right_operand);
}

Long_int Long_int::operator+(Long_int& Long_right_operand)
{
	return sum_control_block(Long_right_operand);
}

Long_int Long_int::operator+(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	return *this + Long_right_operand;
}

Long_int Long_int::operator++()
{
	*this += 1;
	return *this;
}

Long_int Long_int::operator++(int value)
{
	Long_int Temp(*this);
	*this += 1;
	return Temp;
}

Long_int Long_int::operator+=(Long_int& Long_right_operand)
{
	*this = *this + Long_right_operand;
	return *this;
}

Long_int Long_int::operator+=(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	*this = *this + Long_right_operand;
	return *this;
}

Long_int Long_int::operator-(Long_int& Long_right_operand)
{
	return difference_control_block(Long_right_operand);
}
Long_int Long_int::operator-(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	return *this + Long_right_operand;
}

Long_int Long_int::operator--()
{
	*this -= 1;
	return *this;
}
Long_int Long_int::operator--(int value)
{
	Long_int Temp(*this);
	*this -= 1;
	return Temp;
}

Long_int Long_int::operator-=(Long_int& Long_right_operand)
{
	*this = *this - Long_right_operand;
	return *this;
}
Long_int Long_int::operator-=(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	*this = *this - Long_right_operand;
	return *this;
}

Long_int Long_int::operator/(Long_int& Long_right_operand)
{
	try { Long_int Result = divide_main_work(Long_right_operand); 
	return Result; }
	catch (...) { throw "Divide by 0"; }
}
Long_int Long_int::operator/(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	try { Long_int Result = divide_main_work(Long_right_operand); return Result; }
	catch (...) { throw "Divide by 0"; }
}

Long_int Long_int::operator/=(Long_int& Long_right_operand)
{
	try { *this = *this / Long_right_operand; return *this; }
	catch (...) { throw "Divide by 0"; }
}
Long_int Long_int::operator/=(int right_operand)
{
	try { *this = *this / right_operand; return *this; }
	catch (...) { throw "Divide by 0"; }
}

Long_int Long_int::operator*(Long_int& Long_right_operand)
{
	return multiplication_control_block(*this, Long_right_operand);
}
Long_int Long_int::operator*(int right_operand)
{
	Long_int Long_right_operand(right_operand);
	return multiplication_control_block(*this, Long_right_operand);
}

Long_int Long_int::operator*=(Long_int& Long_right_operand)
{
	*this = *this * Long_right_operand;
	return *this;
}
Long_int Long_int::operator*=(int right_operand)
{
	*this = *this * right_operand;
	return *this;
}

Long_int::operator int()
{
	try 
	{
		int result = converter_Long_to_int(*this);
		return result;
	}
	catch (...) { throw "borders exception"; }
}
