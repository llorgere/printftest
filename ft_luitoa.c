#include "libftprintf.h"

static char	*ft_luitoa_malloc(unsigned long int n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

char		*ft_luitoa(unsigned long int n)
{
	unsigned long int	i;
	int					j;

	i = n;
	j = 0;
	if (i == 0)
		j++;
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (ft_luitoa_malloc(n, j));
}
