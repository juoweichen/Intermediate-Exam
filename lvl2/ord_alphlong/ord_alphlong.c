#include <stdlib.h>
#include <unistd.h>
// #include <stdio.h> //del this

int my_strlen(char *s)
{
	int count = 0;

	while ((*s++) != '\0')
		count++;
	return (count);
}

int my_strcmp(char *s1, char *s2)
{
	int a, b;

	a = my_strlen(s1);
	b = my_strlen(s2);
	if (a != b)
		return a - b;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void sort_words(char **words)
{
	int is_unsort = 1;
	int i = 0;
	char *tmp;

	while (is_unsort)
	{
		is_unsort = 0;
		i = 0;
		while (words[i + 1] != NULL)
		{
			if (my_strcmp(words[i], words[i + 1]) > 0)
			{
				// swap
				tmp = words[i];
				words[i] = words[i + 1];
				words[i + 1] = tmp;
				// set to unsort
				is_unsort = 1;
			}
			i++;
		}
	}
}

void extract_words(char *line, char **words, int wcount)
{
	char *whead = line;
	char *wend = NULL;
	int wlen = 0;
	int i = 0;
	int j = 0;

	while (i < wcount)
	{
		// skip space
		wend = whead;
		while (*wend != '\0' && (*wend == ' ' || *wend == '\t'))
			wend++;
		if (*wend == '\0')
			break;
		// start from head of the word
		whead = wend;
		while (*wend != '\0' && *wend != ' ' && *wend != '\t')
			wend++;
		// allocte word mem
		wlen = wend - whead;
		words[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		// record word by chars
		j = 0;
		while (j < wlen)
			words[i][j++] = *(whead++);
		words[i][j] = '\0';
		i++;
	}
	words[i] = NULL;
}

int word_count(char *line)
{
	char *ptr = line;
	int wcount = 0;

	while (*ptr != '\0')
	{
		// skip space
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		if (*ptr == '\0')
			return (wcount);
		// move through word
		while (*ptr != '\0' && *ptr != ' ' && *ptr != '\t')
			ptr++;
		// increase count
		wcount++;
	}
	return (wcount);
}

char **split(char *line)
{
	char **words = NULL;
	int wcount = 0;

	// count words numbers
	wcount = word_count(line);
	// allocate words mem
	words = (char **)malloc(sizeof(char *) * wcount + 1);
	// extract word to words
	extract_words(line, words, wcount);
	// return words
	return (words);
}

void ord_alphlong(char *line)
{
	char **words = NULL;
	char **ptr = NULL;
	int wlen = 0;

	if (line == NULL)
		return;

	// extract words
	words = split(line);
	if (words[0] == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	// // test
	// ptr = words;
	// while (*ptr != NULL)
	// 	printf("word: %s\n", *(ptr++));
	// printf("====\n");

	// sort words
	sort_words(words);

	// // test
	// ptr = words;
	// while (*ptr != NULL)
	// 	printf("word: %s\n", *(ptr++));
	// printf("====\n");

	// display, meet new wlen print a newline
	ptr = words;
	while (*ptr != NULL)
	{
		wlen = my_strlen(*ptr);
		write(1, *ptr, wlen);
		ptr++;
		if (*ptr == NULL || my_strlen(*ptr) > wlen)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
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