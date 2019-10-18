#include <unistd.h>
#include <stdlib.h>

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*s1 - *s2 != 0)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (0);
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

int loop_word(int plen, char *pattern, char *word)
{
    char *cptr = NULL;

    cptr = word;
    while (cptr[plen - 1] != '\0')
    {
        if (my_strncmp(pattern, cptr, plen) == 0)
            return (1);
        cptr++;
    }
    return (0);
}

int loop_words(int plen, char *pattern, char **words)
{
    char **wptr = words;

    while (*wptr != NULL)
    {
        if (loop_word(plen, pattern, *wptr) == 0)
            return (0);
        wptr++;
    }
    return (1);
}

int pattern_matching(int plen, char *sptr, char **words)
{
    while (sptr[plen - 1] != '\0')
    {
        // check through all the words
        if (loop_words(plen, sptr, words) == 1)
            return (write(1, sptr, plen));
        sptr++;
    }
    return(0);
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
    // char *pptr = NULL;
    // int plen = 0;

    // find the shortest word
    slen = find_shortest_words(words, &sptr);

    // Searching pattern by length
    // plen = slen;
    while (slen > 0)
    {
        if (pattern_matching(slen, sptr, words) > 0)
            return ;            
        slen--;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        str_maxlenoc(argv + 1);
    write(1, "\n", 1);
    return (0);
}
