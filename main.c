/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:04:11 by mmosca            #+#    #+#             */
/*   Updated: 2025/06/17 11:44:19 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_strlen(void)
{
	char	message[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus tempus felis sollicitudin leo interdum, at luctus elit consequat.";

	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("42") == strlen("42"));
	assert(ft_strlen("Hello, World!") == strlen("Hello, World!"));
	assert(ft_strlen("!@#$%^&*_+=-") == strlen("!@#$%^&*_+=-"));
	assert(ft_strlen(message) == strlen(message));
	printf("Tests for strlen succedded.\n");
}

int	main(void)
{
	test_strlen();
	return (0);
}
