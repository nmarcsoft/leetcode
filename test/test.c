#include "test.h"

int my_strcmp(char *a, char *b)
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] != b[i])
            return -1;
        i++;
    }
    return (b[i] == '\0');
}

int main(void)
{
    printf("test2\n");
    int returned_str = my_strcmp("test", "other");
    returned_str = strlen("test");
    printf("len of the string = %d\n", returned_str);
    int returned_str2 = my_strcmp("test", "other");
    if (returned_str == 1)
        return -1;
    return 0;
}
