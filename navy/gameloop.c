/*
** gameloop.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Thu Feb 16 19:41:18 2017 daniel_s
** Last update Sat Feb 18 15:04:21 2017 daniel_s
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

extern int enemypid;

int	waitforanswer()
{
  return (1);
}

char	**sendpos(char *pos)
{
  char lettre;
  char chiffre;

  lettre = 64;
  chiffre = 48;

  while ((lettre - 1) != pos[0])
    {
      kill(enemypid, SIGUSR1);
      lettre = lettre + 1;
    }
  kill(enemypid, SIGUSR2);
  while ((chiffre - 1) != pos[1])
    {
      kill(enemypid, SIGUSR1);
      chiffre = chiffre + 1;
    }
  kill(enemypid, SIGUSR2);
  waitforanswer();
}

int	starter(char **my_str, char **enemy, int tour)
{
  char	*buffer;

  buffer = malloc(sizeof (char) * 3);
  buffer[2] = '\0';
  buffer[1] = '\0';
  while (win(my_str, enemy) != 1)
    {
      if (tour == 1)
	{
	  my_putstr("attack: ");
	  read(0, buffer, 2);
	  my_putstr(buffer);
          sendpos(buffer);
	  my_putstr("waiting for enemy's attack...");
	  my_putchar('\n');
	  tour = 0;
	}
      else if (tour == 0)
	{
	  tour = 1;
	}
    }
}
