#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int	check_char(char c, va_list *args);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif