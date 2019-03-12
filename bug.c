#include <stdio.h>
#include <stdlib.h>

char someGlobal[128] = {
    1,2,3,5,8,11
};

void doWork(char *s)
{
    char badbad[128];
    FILE *fp=fopen(s, "r");
    fscanf(fp, "%s", badbad);
    int index = atoi(badbad);
    printf("%d\n", someGlobal[index]);
}

int main(int argc, char *argv[])
{
    if (argc>1)
        doWork(argv[1]);
    return 0;
}
