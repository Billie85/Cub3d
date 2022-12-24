int	is_space(char c)
{
	return (c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

int	is_map_elm(char c)
{
	return (c == '1' || is_space(c));
}
