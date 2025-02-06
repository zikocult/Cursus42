#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char s, int *count)
{
	write(1, &s, 1);
	*count += 1;
}

void ft_putstr(char *s, int *count)
{
	int i = 0;

	if (!s)
	{
		ft_putstr("(null)", count);
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void ft_putdigit(long long int nbr, int base, int *count)
{
	char *hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr = nbr * - 1;
		*count += 1;
		write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putdigit(nbr / base, base, count);
	*count += 1;
	write (1, &hex[nbr % base], 1);
}

void ft_select_type(va_list args, const char format, int *count)
{
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format == 'd')
		ft_putdigit((long long int)va_arg(args, int), 10, count);
	if (format == 'x')
		ft_putdigit((long long int)va_arg(args, int), 16, count);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
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

int main(void)
{
	printf("\nEste es el mio: \n\n");
	ft_printf("El resultat es: %d\n", ft_printf("Frase: %s\nDecimal: %d\nHexa: %x\n", "Hola", 233, 233));
	printf("\nEste es el original: \n\n");
	printf("El resultat es: %d\n", printf("Frase: %s\nDecimal: %d\nHexa: %x\n", "Hola", 233, 233));
	printf("\nPruebas extra: \n\n");
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
