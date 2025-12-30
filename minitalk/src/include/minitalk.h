
#ifndef CLIENT_H
#define CLIENT_H

# include <signal.h>
# include <unistd.h>

int	ft_atoi(char *str);
void	send_char_as_bit(int server_pid, char c);

#endif