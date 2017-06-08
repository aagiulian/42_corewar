
#include "asm.h"

int		ft_check_error(char *file, t_asm *sfile)
{
	int		len;
	char	**tab;

	len = ft_strlen(file);
	if (len < 2 || file[len - 1] != 's' || file[len - 2] != '.')
	{
		ft_printf("Mauvaise extension de fichier\n");
		return (0);
	}
	else if ((sfile->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Erreur lors de l'ouverture du fichier\n");
		return (0);
	}
	tab = ft_strsplit(file, '.');
	sfile->file = ft_strjoin(tab[0], ".cor", 0);
	ft_free_strtab(tab);
	return (1);
}

int		ft_launcher(char *file)
{
	t_asm	sfile;

	ft_bzero(&sfile, sizeof(t_asm));
	sfile.content = ft_strnew(1);
	ft_check_error(file, &sfile);
	ft_head(&sfile);
	ft_asm(&sfile);
	ft_write(&sfile);
	return (0);
}


