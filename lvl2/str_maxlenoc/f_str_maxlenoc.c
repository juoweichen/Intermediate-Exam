#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>	//delete this

int ft_strlen(char *str);
void print_str(char *str);
char *find_shortest_str(int argc, char **argv);
int find_short_in_long(char *shrt, char *lng);

char *find_shortest_str(int argc, char **argv)
{
	int i;
	int len;
	char *sstr = NULL;
	int sstrlen = 99999999;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (sstrlen > len)
		{
			sstr = argv[i];
			sstrlen = len;
		}
		i++;
	}
	return (sstr);
}

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int find_short_in_long(char *shrt, char *lng)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*lng != '\0')
	{
		i = 0;
		j = 0;
		while (lng[j] != '\0')
		{
			if (lng[j] != shrt[i])
				break ;
			i++;
			j++;
		}
		if (shrt[i] == '\0')
			return (1);
		lng++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *sstr;

		//find the shortest string
		sstr = find_shortest_str(argc, argv);
		printf("sstr = %s\n", sstr);

		//loop each possible string in the shortest string
		//compare with other string to find match or not
		char *sptr;
		int i;

		sptr = sstr;
		while (*sptr != '\0')
		{
			i = 1;
			while (i < argc)
			{
				printf("sptr = %s\n", sptr);
				if (find_short_in_long(sptr, argv[i]) == 0)
					break ;
				i++;
			}
			if (i == argc)
			{
				print_str(sptr);
				return (0);
			}
			sptr++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
