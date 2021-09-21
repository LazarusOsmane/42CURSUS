#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../libft.h"

int	ft_cmp(int c1, int c2)
{
	return (c1 - c2);
}

void	ch_strncmp(void)
{
	char	test_a[383];
	char	test_b[383];
	int	i;
	int	j;
	int	s;
	int	x;
	int	y;
	size_t	size;

	i = -1;
	s = -127;
	srand(time(NULL));
	while (++i < 383)
	{	
		if (s++ < 0)
		{
			test_b[i++] = -1 * ((rand() % 126) + 1);
			test_a[i++] = -1 * ((rand() % 126) + 1);
		}
		else
		{
			test_b[i++] = (rand() % 256);
			test_a[i++] = (rand() % 256);
		}
	}
	test_a[i] = '\0';
	test_b[i] = '\0';
	i = 0;
	while (++i < 1000)
	{
		size = (rand() % 385);
		if (ft_cmp(x = ft_strncmp(test_a, test_b, size), y = strncmp(test_a, test_b, size)) != 0)
		{
			printf("test size:%ld *---* ft_function:%d *---* lib_function:%d\n", size, x, y);
			return ;
		}
	}
	printf("ch_strncmp OK\n");
}

int	main(void)
{
	ch_strncmp();
	return (0);
}
