#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	max_bit(int n)
{
	int	max_l;

	while ((n >> max_l))
		max_l++;
	return (max_l);
}

int pow_(int a, int b)
{
	int	t;

	t = a;
	if (!b)
		return (1);
	while (--b)
		a *= t;
	return (a);
}


int main(int ac, char **av)
{
	int	i;
	int	c;
	int	nb_bits;
	int	pid;

	i = 0;
	if (ac != 3)
		return (0);
	pid = atoi(av[1]);
	//printf("%d\n", pid);
	if (ac == 3)
	{
		while (av[2][i])
		{
			c = av[2][i];
			nb_bits = 0;
			int	r = 0;
			while (nb_bits < 8)//(c >> nb_bits)
			{
				if ((c >> nb_bits)&1)
				{
					//write(1, "1 sent\n", 7);
					r += pow_(2, nb_bits);
					kill(pid, SIGUSR1);
				}
				else{
					//write(1, "0 sent\n", 7);
					kill(pid, SIGUSR2);
				}
				nb_bits++;
				usleep(20);
			}
			i++;
		}
	}
}
