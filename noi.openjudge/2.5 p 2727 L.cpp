//OPENJUDGE 2727 L
#include<stdio.h>
#include<string.h>
bool mp[100][100];
char a[100][100];
int n,m,sa,sb,ta,tb,quq[500][2],fa[4]={1,-1,0,0},fb[4]={0,0,1,-1},dep[500],star,ass;
int main()
{
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)break;
		memset(mp,false,sizeof(mp));
		memset(quq,0,sizeof(quq));
		memset(dep,0,sizeof(dep));
		for(int i=0;i<n;i++)
			scanf("%s",a[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='@')
				{
					mp[i][j]=false;
					sa=i,sb=j;
				}
				else if(a[i][j]=='*')	
				{
					mp[i][j]=true;
					ta=i,tb=j;
				}
				else if(a[i][j]=='.')mp[i][j]=true;
				else mp[i][j]=false;
			}
		star=0,ass=0;
		int ans=-1,ya,yb,xa,xb;
		quq[0][0]=sa;quq[0][1]=sb;
		while(star<=ass)
		{
			xa=quq[star][0];
			xb=quq[star][1];
			if(xa==ta&&xb==tb)
			{
				ans=dep[star];
				break;
			}
			for(int i=0;i<=3;i++)
			{
				ya=xa+fa[i];
				yb=xb+fb[i];
				if(ya>=0&&ya<=n-1&&yb>=0&&yb<=m-1)
					if(mp[ya][yb])
						quq[++ass][0]=ya,quq[ass][1]=yb,dep[ass]=dep[star]+1,mp[ya][yb]=false;
			}
			star++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
