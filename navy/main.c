/*
** starter.c for RobinsonMC in /home/mrstandu33/Downloads/RobinsonMC/navy
**
** Made by daniel_s
** Login   <mrstandu33@epitech.net>
**
** Started on  Wed Feb 15 16:52:05 2017 daniel_s
** Last update Thu Feb 16 19:38:25 2017 daniel_s
*/

int	main(int ac, char **av)
{
  if (ac == 2)
    mainserv(ac, av);
  if (ac == 3)
    mainclient(ac, av);
}
