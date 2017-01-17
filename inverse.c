#include <stdio.h>

int main()
{
    int t, i;
    long j, n, x;
    scanf("%d",&t);
    for(i=0; i<t; ++i)
    {
        int isinverse = 1;
        scanf("%ld",&n);
        for(j=1; j<=n; ++j)
        {
            scanf("%ld",&x);
            if(x!=j)
            {
                isinverse = 0;
            }
        }
        //isinverse ? printf("inverse\n") : printf("not inverse\n");
        printf("%s\n", isinverse ? "inverse\n" : "not inverse\n");
    }
    return 0;
}