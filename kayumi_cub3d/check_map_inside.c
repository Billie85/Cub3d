#include "cub3d.h"

bool	map_inside_down(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y  = 1;
	flag = 0;
	while (map->new_map_square[y])
	{
		x = 1;
		while(map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || map->new_map_square[y][x] == 'N')
			{
				if (map->new_map_square[y + 1][x] == '1' || map->new_map_square[y + 1][x] == '0' || map->new_map_square[y + 1][x] == 'N')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}

bool	map_inside_up(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y  = 1;
	flag = 0;
	while (map->new_map_square[y])
	{
		x = 1;
		while(map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || map->new_map_square[y][x] == 'N')
			{
				if (map->new_map_square[y - 1][x] == '1' || map->new_map_square[y - 1][x] == '0' || map->new_map_square[y - 1][x] == 'N')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}

bool	map_inside_right(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y  = 1;
	flag = 0;
	while (map->new_map_square[y])
	{
		x = 1;
		while(map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || map->new_map_square[y][x] == 'N')
			{
				if (map->new_map_square[y][x + 1] == '1' || map->new_map_square[y][x + 1] == '0' || map->new_map_square[y][x + 1] == 'N')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}


bool	map_inside_left(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	flag = 0;
	y  = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while(map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || map->new_map_square[y][x] == 'N')
			{
				if (map->new_map_square[y][x -1] == '1' || map->new_map_square[y][x - 1] == '0' || map->new_map_square[y][x - 1] == 'N')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}

/* bool	check_map_inside(t_map_info *map)
   {
   size_t	x;
   size_t	y;
   size_t	flag;

   y = 1;
   x = 1;
   printf("left --%c--\n", map->new_map_square[y][x -1]);//1
   printf("right --%c--\n", map->new_map_square[y][x + 1]);//3
   printf("down --%c--\n", map->new_map_square[y + 1][x]);//5
   printf("up --%c--\n", map->new_map_square[y -1][x]);//1
   printf("main --%c--\n", map->new_map_square[y][x]);//9
   while (map->new_map_square[y])
   {
   x = 1;
   while(map->new_map_square[y][x])
   {
   if (map->new_map_square[y][x -1] == '1' || map->new_map_square[y][x -1] == '0' || map->new_map_square[y][x -1] == 'N')//left
   {
   flag = true;
   if (map->new_map_square[y][x +1] == '1' || map->new_map_square[y][x +1] == '0' || map->new_map_square[y][x +1] == 'N')
   {
   flag = true;
   }
   else if (map->new_map_square[y][x +1] == '1' || map->new_map_square[y][x +1] == '0' || map->new_map_square[y][x +1] == 'N')
   flag = false;
   }
   else if (map->new_map_square[y][x -1] == '1' || map->new_map_square[y][x -1] == '0' || map->new_map_square[y][x -1] == 'N')
   flag = false;
   if (flag == false)
   return (false);
   x++;
   }
   y++;
   }
   if (flag == false)
   return (false);
   else
   return(true);
   } */
