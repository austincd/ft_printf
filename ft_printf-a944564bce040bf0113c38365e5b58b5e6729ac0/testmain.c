#include "libft/libft.h"

int ft_find_replace(char **p_big, char *p_little, char *p_new);

int main(int argc, char **argv)
{
	char *str;
	if (argc == 4)
	{
		str = ft_strdup(argv[1]);
		ft_putendl(str);
		ft_find_replace(&str, argv[2], argv[3]);
		ft_putendl(str);
	}
	return (1);
}
