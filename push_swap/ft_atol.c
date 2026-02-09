static int	ft_atol_isspace(int ch)
{
	return (ch == ' ' || ch == '\f' || ch == '\n'
		|| ch == '\r' || ch == '\t' || ch == '\v');
}

static long	ft_atol_power(long nb, int power)
{
	long	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

static long	ft_atol_numfromstr(const char *str, int idx_start, int idx_end)
{
	long	number;
	int		digit; 

	number = 0;
	digit = 0;
	while (idx_end - digit > idx_start)
	{
		number += ((str[idx_end - digit - 1] - '0') * ft_atoi_power(10, digit));
		digit++;
	}
	return (number);
}

long	ft_atol(const char *str)
{
	long	number;
	int		index_start;
	int		index_end;
	int		is_negative;

	index_start = 0;
	is_negative = 1;
	while (ft_atol_isspace(str[index_start]))
		index_start++;
	if (str[index_start] == '+' || str[index_start] == '-')
	{
		if (str[index_start] == '-')
			is_negative = -1;
		index_start++;
	}
	index_end = index_start;
	while (ft_isdigit(str[index_end]))
		index_end++;
	number = ft_atol_numfromstr(str, index_start, index_end);
	return (number * is_negative);
}
