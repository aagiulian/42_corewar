#include "asm.h"

extern t_op op_tab[17];

int		ft_set_codage(char *str, t_asm *sfile)
{
	int i;
	char desc;
	char **tab;

	i = 0;
	tab = ft_strsplit(str, SEPARATOR_CHAR);
	while (tab[i])
	{
		if (tab[i][0] == 'r')
			desc |= 0b00000001;
		else if (tab[i][0] == DIRECT_CHAR)
			desc |= 0b00000010;
		else
			desc |= 0b00000011;
		desc <<= 2;
		i++;
	}
	while (i < 4)
	{
		desc <<= 2;
		i++;
	}
	sfile->instr[1] = desc;
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
		else
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

	ft_printf("mich:%s\n", tab[1]);
	size = ft_size_instr(tab[1], sfile);
	ft_start_instr(tab[0], sfile);
	ft_set_codage(tab[1], sfile);
	sfile->content = ft_strljoin(sfile->content, sfile->instr, sfile->size, size);
	sfile->size += size + 2;
	free(sfile->instr);
	ft_printf("newcontent\n");
	return (0);
}
