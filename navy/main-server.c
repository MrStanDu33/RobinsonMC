/*
** server.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Wed Feb 15 12:38:20 2017 daniel_s
** Last update Thu Feb 16 15:22:31 2017 daniel_s
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void    my_put_nbr(int nb)
{
  int   result;
  int   diviseur;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar('-');
          nb = -nb;
        }
      diviseur = 1;
      while ((nb / diviseur) >= 10)
        diviseur = diviseur * 10;
      while (diviseur > 0)
        {
          result = (nb / diviseur) % 10;
          my_putchar(result + '0');
          diviseur = diviseur / 10;
        }
    }
}

static void hdl (int sig, siginfo_t *siginfo, void *context)
{
  if (sig == 10)
    {
      my_putstr("enemy connected");
      my_putchar('\n');
      my_putchar('\n');
      usleep(2000);
      kill(siginfo->si_pid, SIGUSR2);
      return (1);
    }
  if (sig == 12)
    {
      my_putstr("successfully connected");
      my_putchar('\n');
      my_putchar('\n');
      return (2);
    }
}

int testforsigusr()
{
  struct sigaction act;

  memset(&act, '\0', sizeof(act));
  act.sa_sigaction = &hdl;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) < 0)
    return 1;
  if (sigaction(SIGUSR2, &act, NULL) < 0)
    return 1;
  pause();
  return (0);
}

int	mainserv(int ac, char **av)
{
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
  my_putstr("waiting for enemy connection...\n");
  my_putchar('\n');
  testforsigusr();
  init_game(av[1]);
}
