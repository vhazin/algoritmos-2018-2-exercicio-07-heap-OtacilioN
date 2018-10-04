#include <stdio.h>

int main(void)
{
    int interactions, x;
    while (1)
    {
        scanf("%d", &interactions);
        int priority[interactions], level[interactions], lowest = 1;
        char label[interactions];
        if (!interactions)
            break;

        scanf(" %c/%d", &label[0], &priority[0]);
        level[0] = 1;

        for (x = 1; x < interactions; x++)
        {
            scanf(" %c/%d", &label[x], &priority[x]);
            if (priority[x] > priority[x - 1])
            {
                level[x] = level[x - 1] - 1;
            }
            else
                level[x] = level[x - 1] + 1;

            if (level[x] < lowest)
                lowest = level[x];
        }
        printf("level %d lowest %d \n", level[0], lowest);
        for (x = 0; x < level[0] + 1 - lowest; x++)
        {
            printf("(");
        }
        printf("%c/%d", label[0], priority[0]);
        for (x = 1; x < interactions; x++)
        {
            if (level[x] > level[x - 1])
            {
                printf("(");
            }
            else
            {
                printf(")");
            }
            printf("%c/%d", label[x], priority[x]);
        }
        for (x = 0; x < level[interactions - 1] + 1 - lowest; x++)
        {
            printf(")");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}