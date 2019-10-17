#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  // DELETE THIS

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*s1 - *s2 != 0)
            break ;
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int my_strlen(char *s)
{
    int count = 0;

    while (*(s++) != '\0')
        count++;
    return (count);
}

int find_shortest_words(char **words, char **sptr)
{
    int len = 0, slen = INT32_MAX;
    
    while (*words != NULL)
    {
        len = my_strlen(*words);
        if (slen > len)
        {
            slen = len;
            *sptr = *words;
        }
        words++;
    }
    return (slen);
}

/*
    Find the shortest word and length.
    Base on the length of shortest words, searching if other words
    has matching the same pattern in the shorest word. 
    If not, shrinking the length by 1, searching all words by shorten word, 
    keep repeat until a pattern found match in all the other words. 
*/
void str_maxlenoc(char **words)
{
    char *sptr = NULL;  // shortest word pointer
    int slen = 0;       // shorest word len
    char *pptr = NULL;
    int plen = 0;

    // find the shortest word
    slen = find_shortest_words(words, &sptr);
    printf("sptr: %s, slen: %d\n", sptr, slen);

    // Searching pattern by length
    plen = slen;
    while (plen > 0)
    {
        // window sliding the shortest word to get the current pattern
        
        plen--;
    }

    // Display result
}

int main(int argc, char **argv)
{
    if (argc > 1)
        str_maxlenoc(argv + 1);
    write(1, "\n", 1);
    return (0);
}