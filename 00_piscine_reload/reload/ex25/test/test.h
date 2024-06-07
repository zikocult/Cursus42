#ifndef TEST_H
# define TEST_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int nb);
int	*ft_range(int min, int max);
void	ft_foreach(int *tab, int length, void (*f)(int));

#endif
