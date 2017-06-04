#include "asm.h"

int		ft_stock_champ(t_asm *sfile)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	while ((ret = get_next_line(sfile->fd, &line)) > 0)
	{
		if (i > 0)
			sfile->champ = ft_strtab(sfile->champ, line);
		free(line);
		i++;
	}
return (0);
}


int		ft_trt_champ(t_asm *sfile, char **tab)
{
	if (tab[0][0] == COMMENT_CHAR)
		ft_printf("osef\n");
	else if (ft_strchr(tab[0], LABEL_CHAR) != 0)
		ft_printf("label:%s\n", tab[0]);
	else
		ft_trt_instr(sfile, tab);
	return (0);
}

int		ft_parse(t_asm *sfile)
{
	int		i;
	char	**tab;

	i = 0;
	while (sfile->champ[i])
	{
		tab = ft_strsplitif(sfile->champ[i], ft_isspace);
		ft_printf("tab0: %s\n", tab[0]);
		if (tab[0])
		ft_trt_champ(sfile,tab);
		//ft_free_strtab(tab);
		i++;
	}
	ft_printf("OLOLOLOLOL\n");
	return (0);
}

int		ft_asm(t_asm *sfile)
{
	ft_stock_champ(sfile);
	ft_parse(sfile);
	return (0);
}
