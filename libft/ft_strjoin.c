/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizitout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:06:19 by sizitout          #+#    #+#             */
/*   Updated: 2024/03/16 03:36:15 by sizitout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_string(char const c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char const s2)
{
	int		len;
	int		i;
	char	*str;

	if (s1 == NULL)
		return (ft_string(s2));
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = s2;
	str[i] = '\0';
	free(s1);
	return (str);
}
//s1 et s2 vont se joindre 
//tu pointe str vers une nvl adresse pour creer sa chaine

/*int main()
{
	char a[] = "Bonjour comment vas tu ?";
	char b[] = " Je vais tres bien";

	printf("%s\n", ft_strjoin(a, b));
}*/