#include <ctype.h>
#include "../libft.h"
#include <stdio.h>

int ft_cmp(int x, int y)
{
	return (x - y);
}

void ch_tolower(void)
{
	int             test_a[383];
	int             test_b[383];
	int             i;
	int             j;

	j = -1;
	i = -128;
	while (++i < 255)
	{
		test_a[j] = ft_tolower(i);
		test_b[j] = tolower(i);
		++j;

	}
	i = -1;
	while (++i < 255)
	{
		if (ft_cmp(test_a[i], test_b[i]) != 0)
		{
			printf("ft_tolower KO: value cmp:%d *---* ft_function:%d *---* lib_function:%d\n", ft_cmp(test_a[i], test_b[i]), test_a[i], test_b[i]);
			return ;
		}

	}
	printf("ft_tolower OK\n");
}

int main()
{
	ch_tolower();
	return (0);
}

