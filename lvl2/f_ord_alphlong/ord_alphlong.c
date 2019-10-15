#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> //del this

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
			break ;
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

	if (line == NULL)
		return ;

	// extract words
	words = split(line);

	ptr = words;
	while (*ptr != NULL)
		printf("word: %s\n", *(ptr++));

	// sort words
	

	// display
	// meet new len print a newline
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}