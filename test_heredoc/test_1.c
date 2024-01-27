
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

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
	int	x;

	x = ft_strlen(str);
	x--;
	str[x] = 'a';
	while (str[x] <= 'z' && access(str, F_OK) == 0)
		str[x]++;
	return (str);
}

char	*get_name_heredoc(char *name)
{
	char	*res;
	char	*temp;
	char	*rand;

	rand = malloc(2);
	rand[1] = '\n';
	res = ft_strjoin("/tmp/", name);
	if (!res)
	{
		free (rand);
		return (0);
	}
	while (access(res, F_OK) == 0)
	{
		temp = ft_strjoin(res, "a");
		free (res);
		if (!temp)
		{
			free (rand);
			return (0);
		}
		res = find_free_name(temp);
	}
	free (rand);
	return (res);
}

void open_file(char *str)
{
    int fd;
    
    fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    close(fd);
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
            open_file(result);
            free(result);  // Assurez-vous de libérer la mémoire allouée dynamiquement.
        } else {
            printf("Erreur lors de la création du nom de fichier unique.\n");
        }
        i++;
    }

    return 0;
}
