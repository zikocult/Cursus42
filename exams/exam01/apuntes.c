// para ir pasando bit a bit, el + '0' es para volverlo un char

void funcion x (char var)
{
	char bit;
	int i;

	// esto es especial, asignamos 8 pues sabemos que es el tamaño "normal" de un byte
	i = 8;
	// Pero lo suyo seria jugar con CHAR_BIT, definido en limits.h, que nos dara el numero correcto segun el tipo de variable y el sistema en el que estamos.
	// i = CHAR_BIT * sizeof(var);
	// el sizeof es para que tambien se fije el tamaño segun variable
	// un mixto mas correto podria ser:
	i = 8 * sizeof(var);

	while (i)
	{
		bit = (var >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

// devolver una variable intercambiando los 4 bits del inicio con los del final
// pongo dos casos, a mi me gusta mas el segundo:

1º - return (octet >> 4) | (octet << 4);

2º
char funcion x (char octet)
{
	char temp;
	temp = octet >> 4;
	octet = temp | octet << 4;
	return (octet)
}

// siempre es bueno hacer un remember del putnbr o la parte mas esencial del mismo

void	ft_putnbr(int nb)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		lnb *= -1;
		ft_putchar('-');
	}
	if (lnb >= 10)
	{
		ft_putnbr(lnb / 10);
		lnb = lnb % 10;
	}
	if (lnb < 10)
		ft_putchar(lnb + '0');
}

// y voy a guardar aqui la esencia del atoi_base, siendo la definicion del mismo:

int ft_atoi_base(const char *str, int str_base);

result = (result x base) + valor;
// valor podran ser varios casos, que tendremos que valorar con ifs:
// si num es de 0 a 9:
valor = *str - '0';
// si num es de 'a' a 'f' (repetir con mayusculas)
valor = *str - 'a' + 10;
// Cualquier otro caso devolver un valor que haga detener el bucle:
else valor = -1; //por ejemplo
