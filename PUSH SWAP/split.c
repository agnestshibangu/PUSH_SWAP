#include "push_swap.h"

char    *my_strncpy(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
       
    s1[i] = '\0';
    return (s1);
}

char    **my_split(char *str, char delimiter)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int wc = 0;

    while (str[i])
    {
        while (str[i] && (str[i] == delimiter || str[i] == '\0' || str[i] == '\n'))
            i++;
        if (str[i])
            wc++;
        while (str[i] && (str[i] != delimiter || str[i] == '\0' || str[i] == '\n'))
            i++;
    }

    char **out = (char **)malloc(sizeof(char *) * (wc + 1));
    i = 0;

    while (str[i])
    {
        while (str[i] && (str[i] == delimiter || str[i] == '\t' || str[i] == '\n'))
            i++;
        j = i;
        while (str[i] && (str[i] != delimiter && str[i] != '\t' && str[i] != '\n'))
            i++;
        if (i > j)
        {
            out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
            my_strncpy(out[k++], &str[j], i - j);
        }
    }
    out[k] = NULL;
    return (out);
}

// void free_split_result(char **split_result)
// {
//     char **current = split_result;
//     while (*current != NULL)
//     {
//         free(*current);
//         current++;
//     }
//     free(split_result);
// }

// int main()
// {
//     char str[] = "Hello world this is a test";
//     char **result = my_split(str, ' ');

//     printf("split strings : \n");
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         printf("%s\n", result[i]);
//     }
//     free_split_result(result);

//     return (0);
// }