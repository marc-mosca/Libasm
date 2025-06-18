/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:04:11 by mmosca            #+#    #+#             */
/*   Updated: 2025/06/18 12:18:48 by mmosca           ###   ########.fr       */
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

static void	test_write(void)
{
	size_t	i;
	size_t	j;
	size_t	length_params;
	size_t	length_fds;
	int		result;
	int		expected;
	int		result_errno;
	int		expected_errno;
	char	*params[] = {"", "42", "Hello, World!", "!@#$%^&*_+=-"};
	int		fds[] = {-1, open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644), 10};

	printf("Testing write...\n");
	i = 0;
	length_params = sizeof(params) / sizeof(params[0]);
	length_fds = sizeof(fds) / sizeof(fds[0]);
	while (i < length_params)
	{
		j = 0;
		while (j < length_fds)
		{
			errno = 0;
			expected = write(fds[j], params[i], strlen(params[i]));
			expected_errno = errno;

			errno = 0;
			result = ft_write(fds[j], params[i], strlen(params[i]));
			result_errno = errno;

			assert(expected == result);
			assert(expected_errno == result_errno);

			j++;
		}
		i++;
	}

	j = 0;
	while (j < length_fds)
	{
		errno = 0;
		expected = write(fds[j], NULL, 1000);
		expected_errno = errno;

		errno = 0;
		result = ft_write(fds[j], NULL, 1000);
		result_errno = errno;

		assert(expected == result);
		assert(expected_errno == result_errno);

		j++;
	}

	printf("Tests related to write succedded !\n\n");
	close(fds[1]);
}

static void	test_read(void)
{
	size_t	i;
	size_t	length;
	char	result_ref[1000];
	char	expected_ref[1000];
	ssize_t	expected;
	ssize_t	result;
	int		result_errno;
	int		expected_errno;
	int		fds[] = {-1, open("output.txt", O_CREAT | O_RDONLY, 0644), 10};

	printf("Testing read...\n");
	i = 0;
	length = sizeof(fds) / sizeof(fds[0]);
	while (i < length)
	{
		errno = 0;
		expected = read(fds[i], expected_ref, 1000);
		expected_errno = errno;
		expected_ref[expected == -1 ? 0 : expected] = '\0';

		lseek(fds[i], 0, SEEK_SET);

		errno = 0;
		result = ft_read(fds[i], result_ref, 1000);
		result_errno = errno;
		result_ref[result == -1 ? 0 : result] = '\0';

		assert(expected == result);
		assert(expected_errno == result_errno);
		assert(strcmp(expected_ref, result_ref) == 0);
		i++;
	}

	printf("Tests related to read succedded !\n\n");
	close(fds[1]);
}

static void	test_strdup(void)
{
	size_t	i;
	size_t	length;
	char	*expected;
	char	*result;
	char	*params[] = {"", "\0", "42", "Hello, World!", "!@#$%^&*_+=-", "Long string to check if memory allocation is good"};

	printf("Testing strdup...\n");
	i = 0;
	length = sizeof(params) / sizeof(params[0]);
	while (i < length)
	{
		expected = strdup(params[i]);
		result = ft_strdup(params[i]);

		assert(expected != (void *) 0);
		assert(result != (void *) 0);
		assert(strcmp(expected, result) == 0);

		free(expected);
		free(result);
		i++;
	}
	printf("Tests related to strdup succedded !\n\n");
}

int	main(void)
{
	printf("\n");
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}
