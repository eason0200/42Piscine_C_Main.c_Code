/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:06:38 by cping-xu          #+#    #+#             */
/*   Updated: 2022/08/28 10:07:39 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int board[4][4], int col, int num)  //we will provide 3 example
{
	int	i;
	int	max;
	int	count;

	i = 0;
	count = 1;
	max = board[i][col];      //col will loop from 0 to 3 when pass into checkboard function                            
	while (i < 4)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i++;
	}
	if (count == num)       //if the puzzle is valid , count in col up function = count in col down function (== num in both function)
		return (1);
	return (0);
}

int	check_col_down(int board[4][4], int col, int num)  //we will provide 3 example
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = board[i][col];
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i--;
	}
	if (count == num)				////if the puzzle is valid , count in col up function = count in col down function (== num in both function)
		return (1);
	return (0);
}

int	check_row_left(int board[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	count = 1;
	max = board[row][i];
	while (i < 4)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_row_right(int board[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = board[row][i];
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int	checkboard(int board[4][4], int *in_num)
{
	int	i;

	i = 0;
	while (in_num[i])
	{
		if (i >= 0 && i <= 3)
			if (!check_col_up(board, i, in_num[i]))       //check num = count
 				return (0);
		if (i >= 4 && i <= 7)
			if (!check_col_down(board, i - 4, in_num[i]))
				return (0);
		if (i >= 8 && i <= 11)
			if (!check_row_left(board, i - 8, in_num[i]))
				return (0);
		if (i >= 12 && i <= 15)
			if (!check_row_right(board, i - 12, in_num[i]))
				return (0);
		i++;
	}
	return (1);
}
