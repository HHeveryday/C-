#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[] = "asd@sfef.sde pj";
    char arr2[] = {0};
    strcpy(arr2, arr1);
    char *p = "@. ";
    char *pc = NULL;
    for (pc = strtok(arr2, p); pc != NULL; pc = strtok(NULL, p))
    {
        printf("%s\n", pc);
    }
}