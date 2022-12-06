#include "cub3d.h"

int main(void)
{
	char len[100] = "abcdefghij";
	char find[100] = "de";
	size_t size = 2;

	printf("%s\n",ft_strnstr(len, find, size));
}