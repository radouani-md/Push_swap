/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:41:04 by mradouan          #+#    #+#             */
/*   Updated: 2025/03/10 22:35:27 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*md_strjoin(char *s1, char *s2)
{
	size_t	lens;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (md_strdup(s2));
	if (!s2)
		return (md_strdup(s1));
	lens = md_strlen(s1) + md_strlen(s2);
	str = (char *)malloc(lens + 1);
	if (!str)
		return (free(s1), NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*md_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	str = malloc(md_strlen(src) + 1);
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	md_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checksign_long(int res)
{
	if (res > 0)
		return (-1);
	return (0);
}

long	md_atoi(const char *str)
{
	int		i;
	int		sign;
	long	t;

	i = 0;
	sign = 1;
	t = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		t = t * 10 + (str[i] - 48);
		if (t > 2147483648)
			return (2147483648);
		i++;
	}
	return (t * sign);
}
