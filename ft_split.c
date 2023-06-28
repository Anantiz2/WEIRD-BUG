#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *src, int from, int to)
{
	int		i;
	int		range;
	char	*copy;

	
	printf("%d:%d:%d\n", from, to, to - from);
	range = to - from;
	copy = malloc((range + 1) * sizeof(char));
	i = 0;
	while (i <= range)
	{
		copy[i] = src[from + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	in_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (c);
		i++;
	}
	return (-1);
}

int	ct_w(const char *str, char *charset)
{
	int	count;
	int	await;
	int	i;

	await = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (in_sep(str[i], charset) > -1)
			await = 1;
		else if (await)
		{
			await = 0;
			count++;
		}
		i++;
	}
	return (count);
}

void	split(const char *str, char *charset, char **ret_arr, int str_len)
{
	int	last_sep;
	int	i;
	int	j;

	i = 0;
	j = 0;
	last_sep = 0;
	while (i < str_len)
	{
		while ((in_sep(str[i], charset) > -1))
		{
			i++;
			last_sep = i;
		}		
		while (str[i] != '\0' && in_sep(str[i], charset) == -1)
			i++;
		if (last_sep != i)
			ret_arr[j++] = ft_strdup(str, last_sep, i - 1);
	}
	ret_arr[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	int		str_len;
	char	**ret_arr;

	word_count = ct_w(str, charset);
	ret_arr = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!ret_arr)
		return (NULL);
	str_len = 0;
	while (str[str_len])
		str_len++;
	split(str, charset, ret_arr, str_len);
	return (ret_arr);
}


#include <stdio.h>
int	main (int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Program started\n\n");
		char ** result = ft_split(argv[1], argv[2]);
		if (result[0] == 0)
			printf("Result is empty\n");
		for (int i = 0; result[i] != 0; i++)
		{
			printf("str %d: %s\n", i, result[i]);
		}
		printf("\nProgram terminated\n");
	}
	else 
	{
		printf(	"🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡\n"
				"🤡🤡🤡                                            🤡🤡🤡\n"
				"🤡🤡🤡    This program takes 2 arguments          🤡🤡🤡\n"
				"🤡🤡🤡                                            🤡🤡🤡\n"
				"🤡🤡🤡  _string_to_split_ _separators_string_     🤡🤡🤡\n"
				"🤡🤡🤡                                            🤡🤡🤡\n"
				"🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡🤡");
	}
	return (0);
}
