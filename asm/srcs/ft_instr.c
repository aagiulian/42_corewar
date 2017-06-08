#include "asm.h"

extern t_op op_tab[17];

int		ft_splitinstr(char c)
{
	if (ft_isspace(c) || c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		ft_set_codage(char *str, t_asm *sfile)
{
	int i;
	char desc;
	char **tab;

	i = 0;
	desc = '\0';
	ft_printf("str:%s\n", str);
	tab = ft_strsplitnbif(str, ft_splitinstr, 2);
	while (tab[i])
	{
		if (tab[i][0] == 'r')
		{
			ft_printf("tabr:%s\n", tab[i]);
			desc |= 0b00000001;
		}
		else if (tab[i][0] == DIRECT_CHAR)
		{
			ft_printf("tabd:%s\n", tab[i]);
			desc |= 0b00000010;
		}
		else if (ft_isstrdigit(tab[i]))
		{
			ft_printf("tabi:%s\n", tab[i]);
			desc |= 0b00000011;
		}
		else
			ft_printf("ntab:%s\n", tab[i]);
		desc <<= 2;
		i++;
	}
	while (i < 3)
	{
		desc <<= 2;
		i++;
	}
	sfile->instr[1] = desc;
	ft_printf("desc:%x\n\n",desc);
	ft_free_strtab(tab);
	return (0);
}

int		ft_size_instr(char *str, t_asm *sfile)
{
	char **tab;
	int size;
	int i;

	i = 0;
	size = 0;
	tab = ft_strsplit(str, SEPARATOR_CHAR);
	while (tab[i])
	{
		if (tab[i][0] == 'r')
			size += REG_SIZE;
		else if (tab[i][0] == DIRECT_CHAR)
			size += DIR_SIZE;
		else if (ft_isstrdigit(tab[i]))
			size += IND_SIZE;
		i++;
	}
	sfile->instr = ft_strnew(size + 2);
	ft_free_strtab(tab);
	return (size);
}

int		ft_start_instr(char *instr, t_asm *sfile)
{
	int i;

	i = 0;
	while (op_tab[i].instr && ft_strcmp(op_tab[i].instr, instr))
		i++;
	if (op_tab[i].instr)
	sfile->instr[0]= op_tab[i].opcode;
	return (0);
}

int		ft_trt_instr(t_asm *sfile, char **tab)
{
	int size;

	size = ft_size_instr(tab[1], sfile);
	ft_start_instr(tab[0], sfile);
	ft_set_codage(tab[1], sfile);
	sfile->content = ft_strljoin(sfile->content, sfile->instr, sfile->size, size);
	sfile->size += size + 2;
	free(sfile->instr);
	return (0);
}
