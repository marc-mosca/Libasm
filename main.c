/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:04:11 by mmosca            #+#    #+#             */
/*   Updated: 2025/06/17 12:05:30 by mmosca           ###   ########.fr       */
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

static void	test_strcpy(void)
{
	char	message[] = "Lorem ipsum dolor sit, amet consectetur.";
	char	destination1[42];
	char	destination2[42];

	strcpy(destination1, "");
	ft_strcpy(destination2, "");
	assert(strcmp(destination1, destination2) == 0);

	strcpy(destination1, "42");
	ft_strcpy(destination2, "42");
	assert(strcmp(destination1, destination2) == 0);

	strcpy(destination1, "Hello, World!");
	ft_strcpy(destination2, "Hello, World!");
	assert(strcmp(destination1, destination2) == 0);

	strcpy(destination1, "!@#$%^&*_+=-");
	ft_strcpy(destination2, "!@#$%^&*_+=-");
	assert(strcmp(destination1, destination2) == 0);

	strcpy(destination1, message);
	ft_strcpy(destination2, message);
	assert(strcmp(destination1, destination2) == 0);

	printf("Tests for strcpy succedded.\n");
}

int	main(void)
{
	test_strlen();
	test_strcpy();
	return (0);
}
