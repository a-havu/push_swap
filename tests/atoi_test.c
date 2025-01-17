#include "../headers/push_swap.h"
#include <stdio.h>

static int	ft_atoi_loop(long result, int neg, const char *nptr, int i)
{
	long	prev_result;

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		prev_result = result;
		result = result * 10 + (nptr[i] - '0');
		if (prev_result > result && neg == 1)
			return (-1);
		if (prev_result > (result + 1) && neg == -1)
			return (0);
		i++;
	}
	return (result * neg);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		neg;

	i = 0;
	result = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		neg = -neg;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (ft_atoi_loop(result, neg, nptr, i));
}

int main()
{
    printf("%d", ft_atoi("54867543867438"));
}