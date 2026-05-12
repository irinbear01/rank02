#include "push_swap.h"

static int	word_len(char const *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (len);
}

static char	*dup_word(char const *s)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(s);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_partial(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

char	**ps_split(char const *s)
{
	char	**arr;
	int		words;
	int		i;

	words = count_words(s);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			arr[i] = dup_word(s);
			if (!arr[i])
				return (free_partial(arr, i), NULL);
			i++;
			while (*s && *s != ' ')
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}