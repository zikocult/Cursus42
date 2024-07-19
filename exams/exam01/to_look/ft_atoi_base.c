// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------
//
// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.
//
// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
//
// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
//
// Minus signs ('-') are interpreted only if they are the first character of the
// string.
//
// Your function must be declared as follows:
//
// int	ft_atoi_base(const char *str, int str_base);


//Código generado por Copilot
#include <stdio.h>

int get_val(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}

int ft_atoi_base(const char *str, int str_base) {
    int i = 0;
	int result = 0;
    int sign = 1;
	int val;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i]) {
        val = get_val(str[i]);
        if (val >= str_base || val == -1)
            break;
        result = result * str_base + val;
		i++;
    }

    return result * sign;
}

int main() {
    printf("%d\n", ft_atoi_base("123", 10)); // Debería imprimir: 123
    printf("%d\n", ft_atoi_base("-123", 10)); // Debería imprimir: -123
    printf("%d\n", ft_atoi_base("7b", 16)); // Debería imprimir: 123
    printf("%d\n", ft_atoi_base("-7b", 16)); // Debería imprimir: -123
    printf("%d\n", ft_atoi_base("1111011", 2)); // Debería imprimir: 123
    printf("%d\n", ft_atoi_base("-1111011", 2)); // Debería imprimir: -123
    printf("%d\n", ft_atoi_base("173", 8)); // Debería imprimir: 123
    printf("%d\n", ft_atoi_base("-173", 8)); // Debería imprimir: -123
    printf("%d\n", ft_atoi_base("z", 36)); // Debería imprimir: 35
    printf("%d\n", ft_atoi_base("-z", 36)); // Debería imprimir: -35
    return 0;
}

