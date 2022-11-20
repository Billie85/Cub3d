#include <stdio.h>
# include "libft/libft.h"


int main(void)
{
	char s[50] = "11111111111111111111";
	char *find;

	find = ft_strchr(s, ' ');
	if (find == NULL)
		printf("every one its same\n");
	printf("%s ", find);
}