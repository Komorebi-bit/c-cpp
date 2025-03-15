#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int main()
{
    int n;
    int sum=0;
    int a[310];
    int ans[155];
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%2!=0)
    {
        printf("no\n");
        return 0;
    }
    int m=sum/2;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    dp[1][a[1]]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(dp[i-1][j]||dp[i-1][j-a[i]])
            {
                dp[i][j]=1;
            }
        }
    }
    if(!dp[n][m])
    {

        printf("no\n");
        return 0;
    }
    int cnt=0;
    for(int j=m; j>=0; j--)
    {
        for(int i=n; i>=1; i--)
        {
            if(dp[i][j]&&!dp[i-1][j])
            {
                ans[cnt]=a[i];
                cnt++;
                j=j-a[i];
                if(j==0)
                {
                    break;
                }
            }
        }
    }
    for(int i=0; i<cnt-1; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt-1]);
    system("pause");
    return 0;
}