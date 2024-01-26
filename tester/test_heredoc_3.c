/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heredoc_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:07:13 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/26 21:24:51 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

size_t ft_strlen(const char *str) {
    size_t len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

char *ft_strjoin(const char *s1, const char *s2) {
    if (!s1 || !s2)
        return NULL;

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = (char *)malloc(len1 + len2 + 1);

    if (!result)
        return NULL;

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}


char	*find_free_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	str[i] = 'a';
	while (str[i] <= 'z' && access(str, F_OK) == -1)
		str[i]++;
	return (str);
}

char	*get_name_heredoc(char *name)
{
	char	*temp;

    temp = malloc(9);
    if (!temp)
        return (NULL);
    temp = strcpy(temp, "/tmp/");
    if (!temp)
        return (NULL);
	while (access(temp, F_OK) == 0)
	{
		temp = ft_strjoin(temp, "a");
		if (!temp)
			return (NULL);
		temp = find_free_name(temp);
	}
	return (temp);
}

int main(void)
{
    char *result;
    int i;

    i = 0;
    while (i < 10)
    {
        result = get_name_heredoc("a");
        if (result) {
            printf("Unique name: %s\n", result);
            free(result);  // Assurez-vous de libérer la mémoire allouée dynamiquement.
        } else {
            printf("Erreur lors de la création du nom de fichier unique.\n");
        }
        i++;
    }

    return 0;
}