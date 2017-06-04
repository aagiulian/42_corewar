
#include "asm.h"

int		ft_write(t_asm *sfile)
{
	int		fd;
	char	*str;
	int		total;

	total = PROG_NAME_LENGTH + COMMENT_LENGTH + sfile->size;
	ft_printf("couille:%x\n", sfile->size);
	str = ft_strljoin(sfile->header, sfile->content, PROG_NAME_LENGTH + COMMENT_LENGTH, sfile->size);
	fd = open(sfile->file, O_CREAT | O_WRONLY | S_IRWXU);
	write(fd, str, total);
	close(fd);
	return (0);
}
