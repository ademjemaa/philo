
#include <unistd.h>

void	ft_putnbr(char c)
{
	write(1, &c, 1);
}

int		print_queens(int board[10][10])
{
	int			i;
	int			j;
	static int	total;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == 1)
				ft_putnbr(j + '0');
			j++;
		}
		i++;
	}
	total++;
	write(1, "\n", 1);
	return (total);
}



int		find_solution(int tab[10][10], int col)
{
	int i;

	i = 0;
	if (col == 10)
	{
		total = print_queens(tab);
		return (1);
	}
	

}

int		ft_ten_queens_puzzle(void)
{
	int tab[10][10];
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (find_solution(tab, 0));
}

int main()
{
	ft_ten_queerns_puzzle();
	return (0);
}
