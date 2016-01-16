/*
Hint:
一个矩阵被全部攻击到，要么是其中每一行都有车，或者是每一列都有车。
有车的行/列标记1，统计前缀和，每个query即可O(1)算出其中行/列是否都有车。

Time: O(k+n+q)
Space: O(n)
*/
#include <cstdio>
#include <cstring>

#define MAXN 100010

int a[MAXN];
int b[MAXN];
int n,m;

int main()
{
    int T,k,q;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&q);
        memset(a,0,sizeof(int)*(n+1));
        memset(b,0,sizeof(int)*(m+1));
        for (int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=1;
            b[y]=1;
        }
        for (int i=2;i<=n;i++)
            a[i]+=a[i-1];
        for (int i=2;i<=m;i++)
            b[i]+=b[i-1];
        for (int i=0;i<q;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (a[x2]-a[x1-1]==x2-x1+1 || b[y2]-b[y1-1]==y2-y1+1)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
