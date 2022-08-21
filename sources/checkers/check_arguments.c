/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:33:53 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 16:56:14 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	is_greater_than_int(char **argv, int argc)
{
	while (argc-- > 1)
	{
		if (ft_atol(argv[argc]) > MAX_INT || \
			ft_atol(argv[argc]) < MIN_INT)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
}

static void	check_if_has_number(int argc, char **argv)
{
	int	index_array;
	int	index_str;

	is_greater_than_int(argv, argc);
	if (!argv)
		exit(EXIT_FAILURE);
	index_array = 1;
	while (index_array < argc)
	{
		index_str = 0;
		while (argv[index_array][index_str] && \
			!ft_isdigit(argv[index_array][index_str]))
			index_str++;
		if (!argv[index_array][index_str])
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		index_array++;
	}
}

void	check_arguments(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	check_if_has_number(argc, argv);
	while (argv[i])
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_strncmp(argv[j], argv[i], ft_strlen(argv[i])) == 0 \
				&& ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])) == 0)
			{
				ft_putendl_fd("Error", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
