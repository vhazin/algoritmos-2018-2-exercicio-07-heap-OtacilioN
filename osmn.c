#include <stdio.h>

int main(void)
{
    int interactions, x, y;
    while (1)
    {
        scanf("%d", &interactions);
        int priority[interactions], level[interactions], lowest = 1;
        int lastParent = -1, opened = 0;
        char label[interactions];
        if (interactions == 0)
            return 0;

        scanf(" %c/%d", &label[0], &priority[0]);
        level[0] = 1;

        for (x = 1; x < interactions; x++)
        {
            scanf(" %c/%d", &label[x], &priority[x]);
            if (priority[x] > priority[x - 1])
            {
                if (lastParent > 0)
                {
                    level[x] = level[x - 1] - 1 - lastParent;
                    // lastParent--;
                }

                else
                {
                    level[x] = level[x - 1] - 1;
                    if (lastParent == -1)
                    {
                        lastParent = 0;
                    }
                    else
                    {
                        lastParent = -2;
                    }
                }
            }
            else
            {
                if (lastParent > 0)
                {
                    level[x] = level[x - 1] + 1 + lastParent;
                    lastParent--;
                }
                else
                {
                    level[x] = level[x - 1] + 1;

                    if (lastParent == 0)
                    {
                        lastParent++;
                    }
                    else
                    {
                        lastParent = -1;
                    }
                }
            }
            if (level[x] < lowest)
                lowest = level[x];
        }
        for (x = 0; x < level[0] + 1 - lowest; x++)
        {
            printf("(");
        }
        printf("%c/%d", label[0], priority[0]);
        for (x = 1; x < interactions; x++)
        {
            if (level[x] > level[x - 1])
            {
                for (y = level[x - 1]; y < level[x]; y++)
                    printf("(");
            }
            else
            {
                for (y = level[x]; y < level[x - 1]; y++)
                    printf(")");
            }
            printf("%c/%d", label[x], priority[x]);
        }
        if (lastParent > 0)
            level[interactions - 1]++;
        for (x = 0; x < level[interactions - 1] + 1 - lowest; x++)
        {
            printf(")");
        }
        printf("\n\n");
        // for (x = 0; x < interactions; x++)
        // {
        //     printf(" %d ", level[x] + 1 - lowest);
        // }
    }
    printf("OTA \n");
    return 0;
}