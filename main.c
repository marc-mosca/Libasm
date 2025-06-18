/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:04:11 by mmosca            #+#    #+#             */
/*   Updated: 2025/06/18 11:46:00 by mmosca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_strlen(void)
{	
	size_t	i;
	size_t	length;
	size_t	result;
	size_t	expected;
	char	*params[] = {"", "42", "Hello, World!", "!@#$%^&*_+=-"};

	printf("Testing strlen...\n");
	i = 0;
	length = sizeof(params) / sizeof(params[0]);
	while (i < length)
	{
		expected = strlen(params[i]);
		result = ft_strlen(params[i]);
		assert(expected == result);
		i++;
	}
	printf("Tests related to strlen succedded !\n\n");
}

static void	test_strcpy(void)
{
	size_t	i;
	size_t	length;
	char	dummy[1000];
	void	*result_ptr;
	void	*expected_ptr;
	char	result_dest[1000];
	char	expected_dest[1000];
	char	*params[] = {"", "42", "Hello, World!", "!@#$%^&*_+=-"};

	printf("Testing strcpy...\n");
	i = 0;
	length = sizeof(params) / sizeof(params[0]);
	while (i < length)
	{
		expected_ptr = strcpy(dummy, params[i]);
		result_ptr = ft_strcpy(dummy, params[i]);
		assert(expected_ptr == result_ptr);

		strcpy(expected_dest, params[i]);
		ft_strcpy(result_dest, params[i]);
		assert(strcmp(expected_dest, result_dest) == 0);

		i++;
	}
	printf("Tests related to strcpy succedded !\n\n");
}

static void	test_strcmp(void)
{
	size_t	i;
	size_t	length;
	int		result;
	int		expected;
	char	*params1[] = {"", "Hello, World!", "42", "Short", "Longer"};
	char	*params2[] = {"", "Hello, World!", "24", "Shorter", "Long"};

	printf("Testing strcmp...\n");
	i = 0;
	length = sizeof(params1) / sizeof(params1[0]);
	while (i < length)
	{
		expected = strcmp(params1[i], params2[i]);
		result = ft_strcmp(params1[i], params2[i]);
		assert(expected == result);
		i++;
	}
	printf("Tests related to strcmp succedded !\n\n");
}

static void	test_write(int fd)
{
	size_t	i;
	size_t	length;
	int		result;
	int		expected;
	int		result_errno;
	int		expected_errno;
	char	*params[] = {"", "42", "Hello, World!", "!@#$%^&*_+=-"};

	printf("Testing write...\n");
	i = 0;
	length = sizeof(params) / sizeof(params[0]);
	while (i < length)
	{
		errno = 0;
		expected = write(fd, params[i], strlen(params[i]));
		expected_errno = errno;

		errno = 0;
		result = ft_write(fd, params[i], strlen(params[i]));
		result_errno = errno;

		assert(expected == result);
		assert(expected_errno == result_errno);
		i++;
	}

	errno = 0;
	expected = write(fd, NULL, 1000);
	expected_errno = errno;

	errno = 0;
	result = ft_write(fd, NULL, 1000);
	result_errno = errno;

	assert(expected == result);
	assert(expected_errno == result_errno);
	printf("Tests related to write succedded !\n\n");
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		return (-1);
	}
	printf("\n");
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write(fd);
	close(fd);
	return (0);
}
