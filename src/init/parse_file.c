#include "constants.h"
#include "minimap.h"

int	ft_open_readfile(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (fd == -1)
		perror_exit("Open");
	return (fd);
}

void	parse_file(char *file_path)
{
	int	fd;

	fd = ft_open_readfile(file_pth);	
}