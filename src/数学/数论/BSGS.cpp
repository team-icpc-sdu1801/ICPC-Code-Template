
//A^X=B(mod C)求X C为整数
#define MOD 76543
int hs[MOD],head[MOD],next[MOD],id[MOD],top;
void insert(int x, int y)
{
    int k = x%MOD;
    hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}
int find(int x)
{
    int k = x%MOD;
    for(int i = head[k]; i != -1; i = next[i])
        if(hs[i] == x)
            return id[i];
    return -1;
}
int BSGS(int a,int b,int c)
{
    memset(head, -1, sizeof(head));
    top = 1;
    if(b == 1)
        return 0;
    int m = sqrt(c*1.0), j;
    long long x = 1, p = 1;
    for(int i = 0; i < m; ++i, p = p*a%c)
        insert(p*b%c, i);//存的是(a^j*b, j)
    for(long long i = m; ;i += m)
    {
        if( (j = find(x = x*p%c)) != -1 )
            return i-j;  //a^(ms-j)=b(mod c)
        if(i > c)
            break;
    }
    return -1;
}
//EXBSGS
LL xiao(LL &a, LL &b, LL &c)
{
    LL r = 0, d, x, y, a1 = 1;
    while((d = extend_Euclid(a, c, x, y)) != 1)
    {
        if(b % d)
            return -1;
        c /= d;
        b /= d;
        a1 = a1*(a/d)%c;
        r++;
    }
    if(r == 0)
        return 0;
    extend_Euclid(a1, c, x, y);
    b = (b*x%c+c)%c;
    return r;
}
LL extend_BSGS(LL a,LL b,LL c)
{
    a %= c;   //简化运算
    LL r = 1;
    for(int i = 0;i < 50;i++)
    {
        if((r-b) % c == 0)
            return i;
        r *= a; r %= c;
    }
    memset(head, -1, sizeof(head));
    LL cnt = xiao(a, b, c);
    if(cnt == -1)
        return -1;
    top = 1;
    if(b == 1)
        return cnt;
    LL m = ceil(sqrt(c*1.0)), j;
    LL x = 1, p = 1;
    for(LL i = 0; i < m; ++i, p = p*a%c)
        insert(p*b%c, i);
    for(LL i = m; ;i += m)
    {
        if( (j = find(x = x*p%c)) != -1 )
            return i-j+cnt;
        if(i > c)
            break;
    }
    return -1;
}