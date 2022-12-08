#include "cub3d.h"
//一回読み込んで格納してそれを2次元配列にして分けてあげる。
//1 or sp or 1 で構成されている行

/* else if (ft_strchr(str, '0') != 0 || ft_strchr(str, '1') != 0 || ft_strchr(str, ' ') != 0)
   printf("THIS IS A MAP!!\n"); */

void	find_map_position(t_map_info *map)
{
	char *str;
	size_t	i;

	i = 0;
	str = get_next_line(map->fd);
	while (str[i])
	{
		printf("%s\n", str);
		i++;
		str = get_next_line(map->fd);
	}
}

////もしもNOとかSO WE EA F Cの前にスペースとかタブががあったらbreakする用にしてあげたから。そこは確認する。
char *skip_direction(t_map_info *map)
{
	char	*str;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	*zero;
	char	*one;
	char	*sp;
	size_t	len;
	len = 0;

	NO = "NO";
	SO = "SO ./path_to_the_south_texture";
	WE = "WE ./path_to_the_west_texture";
	EA = "EA ./path_to_the_east_texture";
	F = "F 220,100,0";
	C = "C 225,30,0";
	int i = 0;
	str = get_next_line(map->fd);
	while(str)
	{
		if (ft_strncmp(str, NO, ft_strlen("NO")) == 0 || ft_strncmp(str, SO, ft_strlen(SO)) == 0 || \
				ft_strncmp(str, WE, ft_strlen(WE)) == 0 || ft_strncmp(str, EA, ft_strlen(EA)) == 0 || \
				ft_strncmp(str, F, ft_strlen(F)) == 0 || ft_strncmp(str, C, ft_strlen(C)) == 0 || \
				ft_strncmp(str, "\n", 2) == 0 || ft_strncmp(str, " ", 1) == 0 || ft_strncmp(str, "	", 1) == 0){
				//printf("%s", str);
				//printf("IT'S GOOD↑\n");
		}
		else
		{
			//printf("NO\n");
			str = NULL;
			break;
		}
		while (str[i])
		{

		}
		
		str = get_next_line(map->fd);
	}
	return (str);
}
