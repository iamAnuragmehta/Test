#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For using strlen()

char str[100], pat[100], rep[100], ans[100];
int i = 0, j = 0, m = 0, c = 0, k, flag = 0;

void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
}

void strs()
{
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')
            { // Match found
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++)
                {
                    ans[j] = rep[k];
                }
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

void main()
{
    printf("Enter the string:\n");
    fgets(str, 100, stdin);
    remove_newline(str);

    printf("Enter the pattern:\n");
    fgets(pat, 100, stdin);
    remove_newline(pat);

    printf("Enter the replacement:\n");
    fgets(rep, 100, stdin);
    remove_newline(rep);

    strs();

    if (flag == 1)
    {
        printf("%s\n", ans);
    }
    else
    {
        printf("Pattern not found.\n");
    }
}
