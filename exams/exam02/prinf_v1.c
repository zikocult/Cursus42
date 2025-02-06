#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i = 0;
	if (!str)
		ft_putstr("(null)", count);
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}

void	ft_putdigit(long long int nbr, int base, int *count)
{
	char	*hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr = -nbr;
		*count += 1;
		write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putdigit((nbr / base), base, count);
	*count += 1;
	write(1, &hex[nbr % base], 1);
}

void	ft_select_type (va_list args, const char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format == 'd')
		ft_putdigit((long long int)va_arg(args, int), 10, count);
	if (format == 'x')
		ft_putdigit((long long int)va_arg(args, unsigned int), 16, count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		count = 0;
	int		i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_select_type(args, format[i], &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

int main (void)
{
	int test, test2;
	test = ft_printf("Un número cualquiera: %d, un hexa: %x, probando ahora string: %s", 234, 456, "Hola mundo\n");
	test2 = printf("Un número cualquiera: %d, un hexa: %x, probando ahora string: %s", 234, 456, "Hola mundo\n");
	ft_printf("Mi test: %d\nEl test original: %d\n", test, test2);
	ft_printf("%s\n", NULL);
	// printf("%s\n", NULL);
}
