
#include "asm.h"

int		ft_write(t_asm *sfile)
{
	int		fd;

	fd = open(sfile->file, O_CREAT | O_WRONLY | S_IRWXU);
	write(fd, sfile->header, PROG_NAME_LENGTH + COMMENT_LENGTH);
	close(fd);
	return (0);
}
