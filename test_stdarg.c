#include <stdio.h>
#include <stdarg.h>

int main (int argc, char **argv)
{
  if (argc == 2)
  {
    printf("output is: %d\n", ft_test(argv[1]));
  }
}
int ft_test (char *str, ...)
{
  va_list args;
  int ret;
  int current;

  ret = 0;
  current = 0;
  va_start(ap, str);
  va_arg(ap, )
  
}
