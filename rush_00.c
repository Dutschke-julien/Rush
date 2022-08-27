/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <unistd.h>

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void write_line(int x, char separator)
{
    ft_putchar(separator);
    x = x-2;
    if (x <= 0)
        return ;
    while(x)
    {
        ft_putchar(' ');
        x--;
    }
    ft_putchar(separator);
    ft_putchar('\n');
}

void write_else(int x, char f_letter, char l_letter)
{
    ft_putchar(f_letter);
    x = x-2;
    if (x <= 0)
        return ;
    while(x)
    {
        ft_putchar('-');
        x--;
    }
    ft_putchar(l_letter);
    ft_putchar('\n');
}

int main(int ac, char **av)
{
    int x = ft_atoi(av[1]);
    int y = ft_atoi(av[2]);
    int save_y  = y;
    if (ac != 3)
        return (1);
    if (!x || !y)
        return(1);
    if (x ==1 && y ==1)
    {
        write(1,"o\n",1);
        return (0);
    }
    write_else(x, 'o', 'o');
    while (y != 1)
    {
    y--;
    write_line(x, '|');
    }
    write_else(x, 'o', 'o');
    return (0);
}
