#include <stdio.h>

int test(void *p, int len)
{
    int i = 0;
    int *ptr = p;

    for(i=0;i<len;i++)
    {
        printf("%d,%d\n", i, ptr[i]);
    }

    return len;
}

#if 0

int main(void)
{
    int buf[] = {0, 1, 2, 3, 4, 5};
    printf("size=%ld\n", sizeof(buf)/sizeof(int));
    test(buf, sizeof(buf)/sizeof(int));

    return 0;
}
#endif
