#include <stdio.h>
# include "libft/libft.h"

int main(void)
{
	char *str1 = "abcdefg";
	char str2[] = "abcdefg";

	str2[2] = 'X';
	str1 = "new_string";

	printf("%s\n", str1);
	printf("%s\n", str2);
}