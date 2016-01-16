/*
Hint:
当出现一对匹配的括号时，删去，统计最终删去了多少对括号

Time: O(n)
Space: O(1)
*/
#include <cstdio>
#include <cstring>

char s[1010];

int main()
{
    int T,l,a,ans;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        l=strlen(s);
        a=0;
        ans=0;
        for (int i=0;i<l;i++)
        {
            if (s[i]=='(')
                a++;
            else if (a>0)
            {
                a--;
                ans++;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
