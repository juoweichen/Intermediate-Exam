#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  // DELETE THIS

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

/*
    Find the shortest word and length.
    Base on the length of shortest words, searching if other words
    has matching the same pattern in the shorest word. 
    If not, shrinking the length by 1, searching all words by shorten word, 
    keep repeat until a pattern found match in all the other words. 
*/
int str_maxlenoc(char **words)
{
    char *sptr = NULL;  // shortest word pointer
    int slen = 0;       // shorest word len
    char *pptr = NULL;
    int plen = 0;
    char **wsptr = NULL;
    char *wptr = NULL;
    int all_pattern_match = 0;

    // find the shortest word
    slen = find_shortest_words(words, &sptr);
    // printf("sptr: %s, slen: %d\n", sptr, slen);

    // Searching pattern by length
    plen = slen;
    while (plen > 0)
    {
        // printf("current pattern length: %d\n", plen);
        // window sliding the shortest word to get the current pattern
        pptr = sptr;
        while ((pptr - sptr) + plen <= slen)
        {
            // printf("%.*s\n", plen, pptr);
            // loop througn each words
            wsptr = words;
            while (*wsptr != NULL)
            {
                // printf("\t%s\n", *wsptr);
                // flag to set when at least one word not match
                all_pattern_match = 0;
                // compare pattern in word
                wptr = *wsptr;
                while (*(wptr + plen - 1) != '\0')
                {
                    // printf("\t\t%.*s\n", plen, wptr);
                    if (my_strncmp(wptr, pptr, plen) == 0)
                        all_pattern_match = 1;
                    wptr++;
                }
                if (!all_pattern_match)
                    break ;
                wsptr++;
            }
            if (all_pattern_match)
                write(1, pptr, plen);
            pptr++;
        }
        plen--;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        str_maxlenoc(argv + 1);
    write(1, "\n", 1);
    return (0);
}