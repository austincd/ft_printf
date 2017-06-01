#include "ft_printf.h"

void	ft_precision(t_pfconv *current)
{
	char *strs;
	char *floats;

	strs = ft_strdup("sS");
	floats = ft_strdup("gGfFaAeE");
	if (current)
	{
		if (ft_strchr(strs, current->type))
			ft_precision_string(current);
		else if (ft_strchr(floats, current->type))
			ft_precision_float(current);
	}
	free(strs);
	free(floats);
}

void	ft_precision_string(t_pfconv *current)
{
	char 				*str;
	unsigned long long	length;

	str = NULL;
	length = 0;
	if (current)
	{
		str = current->string;
		if (str && current->precision >= 0)
		{
			length = ft_strlen(str);
			if (length > current->precision)
				str[current->precision] = 0;
		}
	}
}

void	ft_precision_float(t_pfconv *current, unsigned int precision)
{
	unsigned int		length;
	char				*ptr;

	ptr = NULL;
	if (current)
	{
		if (current->string && current->precision >= 0)
		{
			if ((ptr = ft_strchr(current->string, '.')))
			{
				length = ft_strlen(ptr);
				if (length < precision)
				{
					ptr = ft_strnew(precision - length);
					if (ptr)
					{
						ft_memset(ptr, '0', precision - length);
						ft_restrcat(&(current->string), ptr);
					}
				}
				else
					ptr[precision + 1] = 0;
			}
		}
	}
}
