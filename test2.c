# include <ft_malloc.h>

int			main(int ac, char **av)
{
	int		i = 0;
	char *addr;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	show_alloc_mem();
	return (0);
}
