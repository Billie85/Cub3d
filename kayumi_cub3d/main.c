#include "cub3d.h"

size_t main(size_t argc, char *argv[])
{
	int test;
	test = set_map("original.txt");
	printf("set map return ->[%d]\n", test);
}