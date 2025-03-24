void	error_per(char *str, int flag)
{
	if(flag == 0)
		perror(str);
	exit(1);
}

void	error_msg(char *str, int flag)
{
	if(flag == 0)
		ft_putendl(str, 2);
	exit(1);
}