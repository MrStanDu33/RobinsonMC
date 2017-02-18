/*
** Game.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Thu Feb 16 14:13:04 2017 daniel_s
** Last update Sat Feb 18 14:25:07 2017 daniel_s
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*my_strdup(char *str, char*src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i = i + 1;
    }
  return (str);
}

char	**map_init(char **str)
{
  str[0] = my_strdup(str[0], "my positions:");
  str[1] = my_strdup(str[1], " |A B C D E F G H");
  str[2] = my_strdup(str[2], "-+---------------");
  str[3] = my_strdup(str[3], "1|. . . . . . . .");
  str[4] = my_strdup(str[4], "2|. . . . . . . .");
  str[5] = my_strdup(str[5], "3|. . . . . . . .");
  str[6] = my_strdup(str[6], "4|. . . . . . . .");
  str[7] = my_strdup(str[7], "5|. . . . . . . .");
  str[8] = my_strdup(str[8], "6|. . . . . . . .");
  str[9] = my_strdup(str[9], "7|. . . . . . . .");
  str[10] = my_strdup(str[10], "8|. . . . . . . .");
  return (str);
}

char	**malloc2D(int x, int y, char **str)
{
  int backup;

  backup = 0;
  str = malloc(sizeof (char *) * x);
  while (backup != x)
    {
      str[backup] = malloc(sizeof (char) * y);
      backup = backup + 1;
    }
  str = map_init(str);
  return (str);
}

void	printab(char **str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      my_putstr(str[i]);
      i = i + 1;
      my_putchar('\n');
    }
}

int	poslettre(char c, char **str)
{
  int	i;

  i = 0;
  while (str[1][i] != c)
    i = i + 1;
  return (i);
}

int	poschiffre(char c, char **str)
{
  int	i;

  i = 2;
  while (str[i][0] != c)
    i = i + 1;
  return (i);
}

int	vectorcalculator(char *buffer, int left, char **str, int pos)
{
  int	backup;

  backup = left;
  while (left != 1)
    {
      pos = pos + 8;
      left = left - 1;
    }
  left = backup;
  if (buffer[pos] == buffer[pos + 3])
    {
      if (buffer[pos + 1] < buffer[pos + 4])
	return (1);     // is down
      else
	return (2);     //is up
    }
  else
    {
      if (buffer[pos] < buffer[pos + 3])
	return (3);     //is Right
      else
	return (4);     //is Left
    }
}

char	**putship_vertical(char **map, int x, int y, int len, int vector)
{
  int	size;

  size = len + 49;
  if (vector == 1)
    while (len != -1)
	{
	  map[x][y] = size;
	  len = len - 1;
	  x = x + 1;
	}
  if (vector == 2)
    while (len != -1)
	{
	  map[x][y] = size;
	  len = len - 1;
	  x = x - 1;
	}
  return (map);
}

char	**putship_horizontal(char **map, int x, int y, int len, int vector)
{
  int	size;

  size = len + 49;
  if (vector == 3)
    while (len != -1)
	{
	  map[x][y] = size;
	  len = len - 1;
	  y = y + 2;
	}
  if (vector == 4)
    while (len != -1)
	{
	  map[x][y] = size;
	  len = len - 1;
	  y = y - 2;
	}
  return (map);
}

char	**setupmap(char **str, char *buffer)
{
  int	x;
  int	y;
  int	left;
  int	vector;
  int	bufferlettre;
  int	bufferchiffre;

  left = 4;
  bufferlettre = 26;
  bufferchiffre = 27;
  while (left != 0)
    {
      x = poschiffre(buffer[bufferchiffre], str);
      y = poslettre(buffer[bufferlettre], str);
      vector = vectorcalculator(buffer, left, str, 2);
      str = putship_horizontal(str, x, y, left, vector);
      str = putship_vertical(str, x, y, left, vector);
      left = left - 1;
      bufferlettre = bufferlettre - 8;
      bufferchiffre = bufferchiffre - 8;
    }
  return (str);
}

char	**positionning(char **str, char *file)
{
  char	*buffer;
  int	i;
  int	fd;

  buffer = malloc(sizeof (char) * 32);
  buffer[31] = '\0';
  i = 0;

  fd = open(file, O_RDONLY);
  read(fd, buffer, 32);
  str = setupmap(str, buffer);
  return (str);
}

int	init_game(char *file, int server)
{
  char	**my_str;
  char	**enemy;

  my_str = malloc2D(12, 18, my_str);
  enemy = malloc2D(12, 18, enemy);
  enemy[0] = my_strdup(enemy[0], "enemy's positions:");
  my_str = positionning(my_str, file);
  printab(my_str);
  printab(enemy);
  starter(my_str, enemy, server);
}
