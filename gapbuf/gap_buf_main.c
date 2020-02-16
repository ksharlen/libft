#include "gap_buf.h"
#include <termios.h>
#include <unistd.h>
#include <term.h>

FILE *fp;

enum	key
{
	LEFT_ARROW = 1000,
	RIGHT_ARROW,
	DEL_KEY,
	BKCSPACE_KEY = 127,
	CTR_U = 21,
	CTR_P = 16,
	CTR_Y = 25
};

typedef struct	cursor
{
	int x;
	int y;
}				cursor;

void	ftsh_entry_not_canon(struct termios *st_copy)
{
	struct termios	chg_mode;

	if (st_copy)
	{
		tcgetattr(STDIN_FILENO, &chg_mode);
		*st_copy = chg_mode;
		chg_mode.c_lflag &= ~(ICANON | ECHO | ISIG);
		tcsetattr(STDIN_FILENO, TCSANOW, &chg_mode);
	}
}

void	ftsh_entry_canon(struct termios *st_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, st_term);
}

int			getch(void)
{
	ssize_t	nread;
	char	sym;

	nread = read(STDIN_FILENO, &sym, 1);
	if (nread == 1 && sym == '\e')
	{
		nread = read(STDIN_FILENO, &sym, 1);
		if (sym == '[')
		{
// exit(EXIT_FAILURE);
			nread = read(STDIN_FILENO, &sym, 1);
			if (sym == 'C')//RIGHT
				return (RIGHT_ARROW);
			else if (sym == 'D')//LEFT
				return (LEFT_ARROW);
			else if (sym >= '0' && sym <= '9')
			{
				char	digit = sym;

				nread = read(STDIN_FILENO, &sym, 1);
				if (sym == '~')
				{
					if (digit == '3')
						return (DEL_KEY);
				}
			}
		}
	}
	return (sym);
}

void	init_cursor(void)
{
	write(STDOUT_FILENO, "\e[2J", 4);
	write(STDOUT_FILENO, "\e[H", 3);
}

void	print_buf(t_gapbuf *buf)
{
	size_t	i;

	i = 0;
	write(STDOUT_FILENO, "\e[?25l", 6);
	write(STDOUT_FILENO, "\e[12;0H", 7);
	write(STDOUT_FILENO, "\e[2K", 4);
	while (i < SIZE_BUF)
	{
		write(STDOUT_FILENO, &buf->buf[i], sizeof(char));
		++i;
	}
	write(STDOUT_FILENO, "\e[?25h", 6);
}

void	print_stat(t_gapbuf *buf, const char *str)
{
	char	buf_w[200] = {0};

	snprintf(buf_w, sizeof(buf_w), "buf->len_string: %zd	buf->slide: %zd	buf->size_gap_buf: %zd	buf->gap_start: %zd	buf->gap_end: %zd	LEN_OUT: %zd",
								buf->len_string, buf->slide, buf->size_gap_buf, buf->gap_start, buf->gap_end, strlen(str));
	write(STDOUT_FILENO, "\e[10;0H", 7);
	write(STDOUT_FILENO, "\e[2K", 4);
	write(STDOUT_FILENO, buf_w, 200);
print_buf(buf);
	// fprintf(fp, "%s", buf_w);
}

void		input(t_gapbuf *buf)
{
	int		key;
	char	*str;
	cursor	cr = {1, 0};
	char	buf_w[32] = {0};

	init_cursor();
	do
	{
		key = getch();
		if (key == LEFT_ARROW)
		{
			// write(STDOUT_FILENO, "\e[D", 3);
			if (cr.x)
				cr.x--;
			gap_slide_left(buf);
		}
		else if (key == RIGHT_ARROW)
		{
			cr.x++;
			gap_slide_right(buf);
		}
		else if (key >= 32 && key <= 126)
		{
			cr.x++;
			gap_putchar_in_buf(buf, key);
		}
		else if (key == BKCSPACE_KEY)
		{
// exit(EXIT_FAILURE);
			if (cr.x)
				cr.x--;
			gap_del_sym_before_slide(buf);
		}
		else if (key == DEL_KEY)
		{
			gap_del_sym_on_slide(buf);
		}
		else if (key == CTR_U)
		{
			gap_cut_str(buf);
			cr.y = 0;
			cr.x = 0;
		}
		else if (key == CTR_P)
		{
			gap_paste_str(buf, "how are you?");
			cr.x += strlen("how are you?");
		}
			str = gap_get_buf(buf);
			init_cursor();
			write(STDOUT_FILENO, str, buf->len_string);
print_stat(buf, str);
			snprintf(buf_w, sizeof(buf_w), "\x1b[%d;%dH", cr.y, cr.x);
			write(STDOUT_FILENO, buf_w, strlen(buf_w));
	} while (key != '\n');
	printf("\n");
}

int			main(void)
{
#ifndef PRINT_KEY
	struct termios	copy;
	t_gapbuf buf;

	gap_init(&buf, 20, 10);
	fp = fopen("output", "w");
ftsh_entry_not_canon(&copy);

	input(&buf);

ftsh_entry_canon(&copy);
	print_buf_char(buf.buf, buf.size_buf);
	print_stat_t_gapbuf(&buf);
#else
	struct termios	copy;
	char	key[5] = {0};
	char	*p_key = key;

	ftsh_entry_not_canon(&copy);
	read(STDIN_FILENO, &key, 5);
	ftsh_entry_canon(&copy);

	while (*p_key)
		printf("%zd	", *p_key++);

#endif
	return (0);
}
