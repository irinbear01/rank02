#include "push_swap.h"

int	count_words(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
			count++;
		while (*s && *s != ' ')
			s++;
	}
	return (count);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ps_atol(char *s)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num * sign);
}