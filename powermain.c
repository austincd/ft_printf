#include "libft.h"

int main(int argc, char **argv)
{
	long double num = 3.14159;
	long double result;
	long long operand;
//	long long power;
//	long long base;
	if (argc != 2)
		return (1);
	operand = ft_atoi(argv[1]);
//	base = ft_atoi(argv[2]);
//	num = ft_power(power, base);
	result = ft_floatmod(num, operand);
	printf("result is : %Lf\n", result);
}
