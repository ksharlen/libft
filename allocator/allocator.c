#include "allocator.h"

t_alloc		*get_struct()
{
	static t_alloc alloc;

	return &alloc;
}

static void	check_size_table()
{
	if (g_alloc.current == g_alloc.size_table)
	{
		
	}
}

void	init_stack_alloc()
{
	g_alloc.table = (void **)malloc(DFLT_SIZE_ALLOC * sizeof(size_t *));
	g_alloc.size_table = DFLT_SIZE_ALLOC;
	g_alloc.current = 0;
}

void	close_memory(void)
{
	size_t	index;

	index = 0;
	if (g_alloc.table)
	{
		while (index < g_alloc.current)
		{
			free(g_alloc.table[index++]);
		}
		free(g_alloc.table);
		g_alloc.table = NULL;
		g_alloc.current = 0;
		g_alloc.size_table = 0;
	}
}

void	*malloc_nl(size_t size)
{
	void	*mem;

	if (!g_alloc.table)
		init_stack_alloc();
	mem = NULL;
	if (size > 0)
	{
		mem = malloc(size);
		*(g_alloc.table + g_alloc.current++) = mem;
	}
	return (mem);
}

void	*memalloc_nl(size_t size)
{
	void	*mem;

	mem = malloc_nl(size);
	if (mem)
		ft_bzero(mem, size);
	return (mem);
}


char	*strdup_nl(const char *str)
{
	size_t	size_str;
	char	*cpy_str;

	cpy_str = NULL;
	size_str = ft_strlen(str);
	if ((cpy_str = (char *)malloc_nl(sizeof(char) * size_str + 1)))
	{
		ft_strcpy(cpy_str, str);
		cpy_str[size_str] = '\0';
	}
	return (cpy_str);
}
