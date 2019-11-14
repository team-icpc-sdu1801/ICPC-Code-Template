//有两个字符串a,b,要求输出b与a的每一个后缀的最长公共前缀
//nxt里为b的next数组，extend里是b与a的每一个后缀的最长公共前缀
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>


#define N 1000010 

using namespace std;

int q,nxt[N],extend[N];
string s,t;

void getnxt()
{
    nxt[0]=t.size();//nxt[0]一定是T的长度
    int now=0;
    while(t[now]==t[1+now]&&now+1<(int)t.size())now++;//这就是从1开始暴力
    nxt[1]=now;
    int p0=1;
    for(int i=2;i<(int)t.size();i++)
    {
        if(i+nxt[i-p0]<nxt[p0]+p0)nxt[i]=nxt[i-p0];//第一种情况
        else
        {//第二种情况
            int now=nxt[p0]+p0-i;
            now=max(now,0);//这里是为了防止i>p的情况
            while(t[now]==t[i+now]&&i+now<(int)t.size())now++;//暴力
            nxt[i]=now;
            p0=i;//更新p0
        }
    }
}

void exkmp()
{
    getnxt();
    int now=0;
    while(s[now]==t[now]&&now<min((int)s.size(),(int)t.size()))now++;//暴力
    extend[0]=now;
    int p0=0;
    for(int i=1;i<(int)s.size();i++)
    {
        if(i+nxt[i-p0]<extend[p0]+p0)extend[i]=nxt[i-p0];//第一种情况
        else
        {//第二种情况
            int now=extend[p0]+p0-i;
            now=max(now,0);//这里是为了防止i>p的情况
            while(t[now]==s[i+now]&&now<(int)t.size()&&now+i<(int)s.size())now++;//暴力
            extend[i]=now;
            p0=i;//更新p0
        }
    }
}

int main()
{
    cin>>s>>t;
    exkmp();
    int len=t.size();
    for(int i=0;i<len;i++)printf("%d ",nxt[i]);//输出nxt
    puts("");
    len=s.size();
    for(int i=0;i<len;i++)printf("%d ",extend[i]);//输出extend
    return 0;
}