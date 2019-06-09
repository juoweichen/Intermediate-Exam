#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> //del this

typedef struct		s_word
{
	char			*word;
	struct s_word	*next;
}					t_word;

typedef struct		s_len
{
	int				wlen;
	t_word			*wordlist;
	struct s_len	*next;
}					t_len;

t_word *init_word_node(char *word)
{
	t_word *new;

	new = (t_word *)malloc(sizeof(t_word));
	new->word = word;
	new->next = NULL;
	return (new);
}

t_len *init_len_node(int len)
{
	t_len *new;

	new = (t_len *)malloc(sizeof(t_len));
	new->wlen = len;
	new->wordlist = NULL;
	new->next = NULL;
	return (new);
}

int ft_strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

void store_to_wlist(t_len *llist, char *word)
{
	t_word *wordptr;
	t_word *tmp;

	wordptr = llist->wordlist;

	printf("lol1\n");

	while (wordptr != NULL)
	{
		printf("%s->", wordptr->word);
		wordptr = wordptr->next;
	}
	printf("\n");

	wordptr = llist->wordlist;
	while (wordptr->next != NULL && ft_strcmp(wordptr->next->word, word) < 0)
		wordptr = wordptr->next;
	printf("lol2\n");

	tmp = wordptr->next;
	wordptr->next = init_word_node(word);
	wordptr = wordptr->next;
	wordptr->next = tmp;

	printf("lol3\n");
}

void store_to_list(t_len **lenlist, char *word, int wlen)
{
	t_len *lenptr;
	t_len *tmp;

	if (*lenlist == NULL)
	{
		*lenlist = init_len_node(wlen);
		(*lenlist)->wordlist = init_word_node(word);
	}
	else
	{
		lenptr = *lenlist;
		while (lenptr->next != NULL && lenptr->next->wlen < wlen)
			lenptr = lenptr->next;
		if (lenptr->next != NULL && lenptr->next->wlen == wlen)
			store_to_wlist(lenptr->next, word);
		else
		{
			tmp = lenptr->next;
			lenptr->next = init_len_node(wlen);
			lenptr = lenptr->next;
			lenptr->next = tmp;
		}
	}
}

int get_next_word(char *str, char **next_word, char **ptr)
{
	char *cur;
	int i;
	int wlen;

	if (str == NULL)
		return (0);
	if (*ptr == NULL)
		*ptr = str;
	
	// skip space
	while (**ptr != '\0' && (**ptr == ' ' || **ptr == '\t'))
		(*ptr)++;
	if (**ptr == '\0')
		return (0);

	// count word
	cur = *ptr;
	while (*cur != '\0' && *cur != ' ')
		cur++;

	// store word
	wlen = cur - *ptr;
	*next_word = (char *)malloc(sizeof(char) * wlen + 1);
	i = 0;
	while (*ptr != cur)
	{
		(*next_word)[i] = **ptr;
		i++;
		(*ptr)++;
	}
	(*next_word)[i] = '\0';

	return (wlen);
}

void ord_alphlong(char *str)
{
	char *next_word;
	int wlen;
	char *ptr = NULL;
	t_len *lenlist = NULL;

	if (str == NULL)
		return ;
	while ((wlen = get_next_word(str, &next_word, &ptr)) != 0)
	{
		printf("next: %s, wlen: %d\n", next_word, wlen); //del this
		store_to_list(&lenlist, next_word, wlen);

	//print list
	t_len *lenptr;
	t_word *wordptr;
	int first_flag;

	lenptr = lenlist;
	while (lenptr != NULL)
	{
		first_flag = 1;
		wordptr = lenptr->wordlist;
		while (wordptr != NULL)
		{
			if (first_flag == 1)
			{
				first_flag = 0;
				ft_putstr(wordptr->word);
			}
			else
			{
				write(1, " ", 1);
				ft_putstr(wordptr->word);
			}
			wordptr = wordptr->next;
		}
		write(1, "\n", 1);
		lenptr = lenptr->next;
	}

	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
