/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:25:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:41 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"


// void	ft_free(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	while (i >= 0)
// 		free(str[i--]);
// }

// void	ft_error(char *msg)
// {
// 	ft_putendl_fd(msg, 1);
// 	exit(0);
// }

// int	ft_contains(int num, char **argv, int i)
// {
// 	i++;
// 	while (argv[i])
// 	{
// 		if (ft_atoi(argv[i]) == num)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_isnum(char *num)
// {
// 	int	i;

// 	i = 0;
// 	if (num[0] == '-' || num[0] == '+')
// 		i++;
// 	while (num[i])
// 	{
// 		if (!ft_isdigit(num[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_check_args(int argc, char **argv)
// {
// 	int i;
// 	long tmp;
// 	char **args;

// 	i = 0;
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = argv;
// 	}
// 	while (args[i])
// 	{
// 		tmp = ft_atol(args[i]);
// 		if (!ft_isnum(args[i]))
// 			ft_error("Error");
// 		if (ft_contains(tmp, args, i))
// 			ft_error("Error");
// 		if (tmp < -2147483648 || tmp > 2147483647)
// 			ft_error("Error");
// 		i++;
// 	}
// 	if (argc == 2)
// 		ft_free(args);
// 	ft_isnum("abc");
// 	ft_contains(3, argv, 3);
// }

