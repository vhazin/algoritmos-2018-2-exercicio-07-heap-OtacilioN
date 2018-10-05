#include <stdio.h>
#include <math.h>

int main(void)
{
    int interactions, x, y;
    while (1)
    {
        scanf("%d", &interactions);
        int priority[interactions], level[interactions], maxNumber = 0, maxN, nIndex;
        int lastParent = -1, opened = 0;
        char label[interactions][105];
        if (interactions == 0)
            return 0;

        for (x = 0; x < interactions; x++)
        {
            scanf(" %[a-z]/%d", label[x], &priority[x]);
            for (nIndex = 1; pow(2, nIndex) < (((interactions - priority[x])) + 2); nIndex++)
                ;
            level[x] = nIndex;
        }

        for (x = 0; x < level[0]; x++)
        {
            printf("(");
            opened++;
        }
        printf("%s/%d", label[0], priority[0]);

        for (x = 1; x < interactions; x++)
        {
            if (level[x] > level[x - 1])
            {
                for (y = level[x - 1]; y < level[x]; y++)
                {
                    printf("(");
                    opened++;
                }
            }
            else if (level[x] < level[x - 1])
            {
                for (y = level[x]; y < level[x - 1]; y++)
                {
                    printf(")");
                    opened--;
                }
            }
            else
            {
                printf("(");
                opened++;
            }

            printf("%s/%d", label[x], priority[x]);
        }
        for (x = 0; x < opened; x++)
        {
            printf(")");
        }
        printf("\n");

        // for (x = 0; x < level[0]; x++)
        // {
        //     printf("(");
        // }
        // printf("%s/%d", label[0], priority[0]);
        // for (x = 1; x < interactions; x++)
        // {
        //     if (level[x] > level[x - 1])
        //     {
        //         for (y = level[x - 1]; y < level[x]; y++)
        //             printf("(");
        //     }
        //     else
        //     {
        //         for (y = level[x]; y < level[x - 1]; y++)
        //             printf(")");
        //     }
        //     printf("%s/%d", label[x], priority[x]);
        // }
        // if (lastParent > 0)
        //     level[interactions - 1]++;
        // for (x = 0; x < level[interactions - 1]; x++)
        // {
        //     printf(")");
        // }
        // printf("\n");
        // for (x = 0; x < interactions; x++)
        // {
        //     printf("(%d|%d) ", priority[x], level[x]);
        // }
        // printf("\n");
    }
    printf("OTA \n");
    return 0;
}