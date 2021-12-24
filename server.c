#include <signal.h>
#include <unistd.h>
#include <stdio.h>

typedef struct variables
{
	int	shifts;
	int	ascci;
}var;

var ops;

void __init__ops(var *strct)
{
	strct->shifts = 0;
	strct->ascci = 0;
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

int	reset(int bit)
{
	int	t = ops.ascci;
	char	*c;
	//printf("<<<%d\n", ops.ascci);
	if (bit == 8)
	{	
		write(1, (char *)&ops.ascci, 1);
		ops.shifts = 0;
		ops.ascci = 0;
	}
	return (0);
}

void	do_(int	sg)
{
	ops.ascci += pow_(2, ops.shifts);
	if(reset(ops.shifts))
		return ;
	ops.shifts += 1;
}

void	do_1(int sg)
{
	ops.shifts += 1;
	if(reset(ops.shifts))
		return ;

}

int main(void)
{
	__init__ops(&ops);
	printf("%d\n", getpid());
	
	
	signal(SIGUSR1, do_);
	signal(SIGUSR2, do_1);

	/*
	struct sigaction act;
	struct sigaction act1;
	act.sa_handler = &do_;
	act1.sa_handler = &do_1;
	act.sa_flags = SA_NODEFER;
	act1.sa_flags = SA_NODEFER;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	*/
	while (1)
		;
	return (0);
}
