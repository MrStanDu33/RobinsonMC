/*
** main.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Wed Feb 15 12:19:23 2017 daniel_s
** Last update Thu Feb 16 15:22:44 2017 daniel_s
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (0);
      i++;
    }
  return (1);
}

char	*my_revstr(char *str)
{
  int   i;
  int   y;
  int   a;

  a = 0;
  i = 0;
  y = my_strlen(str) - 1;
  while (i < y)
    {
      a = str[i];
      str[i++] = str[y];
      str[y--] = a;
    }
  return (str);
}

int	my_transl_nbr(char *str, int result)
{
  int   i;
  int   flag;
  int   signe;

  flag = 0;
  signe = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == '-' || str[i] == '+') && flag == 0)
        {
          if (str[i] == '-')
            signe = -signe;
        }
      else if (str[i] >= '0' && str[i] <= '9')
        {
          flag = 1;
          result = result * 10 + (str[i] - '0');
        }
      else
        return (signe * result);
      i++;
    }
  return (signe * result);
}

int	my_getnbr(char *str)
{
  int   result;

  result = 0;
  result = my_transl_nbr(str, result);
  return (result);
}

int	mainclient(int ac, char **av)
{
  int	pidserv;

  pidserv = my_getnbr(av[1]);
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
  kill(pidserv, SIGUSR1);
  testforsigusr();
  init_game(av[2]);
}
