#include "asm.h"

int		ft_head(t_asm *sfile)
{
	int		i;
	int		ret;
	char	**tab;
	char	*line;

	i = 0;
	while ((ret = get_next_line(sfile->fd, &line) > 0))
	{
		tab = ft_strsplit(line, ' ');
		if (i == 0)
		{
			if (ft_strcmp(tab[0], ".name") == 0)
				ft_printf("name: %s\n", tab[0]);
		}
	}
	return (0);
}
