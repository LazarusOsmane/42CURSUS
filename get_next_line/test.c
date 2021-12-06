#include <unistd.h>
#include <stdlib.h>

char	*ft_function()
{
	char *new;

	new = malloc(sizeof(char) * 2);
	if (!new)
		return (NULL);
	return (new);
}

int main(void)
{
	char *c;

	c = ft_function();
	c[0] = 'a';
	c[1] = '\0';
	printf("%s", c);
	return (0);
}

