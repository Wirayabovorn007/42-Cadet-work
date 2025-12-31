
#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

int	ft_atoi(char *str);
void	send_bit(int server_pid, char c);
void	bit_to_str(int signal);
int	all_num(char *str);

#endif
