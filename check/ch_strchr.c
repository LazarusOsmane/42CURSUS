#include <stdio.h>
#include <string.h>
#include "../libft.h"

int ft_cmp(int x, int y)
{
	return (x - y);
}

void ch_strchr(void)
{
	char	a[27];
	char	*x;
	char 	*y;
	int	i;
	int	j;

	i = -1;
	while (++i < 26)
		a[i] = i;
	a[i] = '\0';
	i = -1;
	while (++i < 27)
	{
		j = 0;
		while (j < 26)
		{
			a[j] = i;
			j += 2;
		}
		j = i;
		x = ft_strchr(a, i);
		y = strchr(a, i);
		if ((!x && y) || (!y && x))
		{
			printf("ft_strchr KO value test:%c ascii_nbr:%d ft_function:%s lib_function:%s", i, i, x, y);
			return ;
		}
		if (ft_cmp(ft_strlen(x), ft_strlen(y)) != 0)
		{
			printf("ft_strchr KO value test:%c aiscii_nbr:%d ft_function:%s lib_function:%s", i, i, x, y);
			return ;
		}
		i = -1;
		while (++i < 26)
			a[i] = i;
		a[i] = '\0';
		i = j;
	}
	printf("ft_strchr OK");
}

int main()
{
	ch_strchr();
	return (0);
}
