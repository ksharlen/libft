#ifndef ALLOCATOR_H
# define ALLOCATOR_H

//todo: удалить лишние включения
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include <string.h>

# include "libft.h"

# define DFLT_SIZE_ALLOC	20

typedef struct	s_allocator
{
	void	**table;
	size_t	current;
	size_t	size_table;
}				t_alloc;

t_alloc			g_alloc;

void	init_stack_alloc(void);

void	*malloc_nl(size_t size);
void	*memalloc_nl(size_t size);
char	*strdup_nl(const char *str);

void	close_memory();

#endif
