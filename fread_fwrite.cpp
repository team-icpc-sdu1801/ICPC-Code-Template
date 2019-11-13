#include <iostream>
#include <cstdio>
#include <cctype>

#define SIZE (1 << 21) 

#define Getchar() (pr1 == pr2 && (pr2 = (pr1 = fr) + fread(fr, 1, SIZE, stdin), pr1 == pr2) ? EOF : *pr1++) 
#define Putchar(ch) (pw < SIZE ? fw[pw++] = (ch) : (fwrite(fw, 1, SIZE, stdout), fw[(pw = 0)++] = (ch))) 

char fr[SIZE], * pr1 = fr, * pr2 = fr;
char fw[SIZE];
int pw;

int Read() 
{
    int res = 0, sign = 1;
    char ch = Getchar();
    while(!isdigit(ch)){if(ch == '-') sign = -1;ch = Getchar();}
    while(isdigit(ch)){res = res * 10 + ch - '0';ch = Getchar();}
    return res * sign;
}
void Write(int val) 
{
    char a[15];
    int len = 0;
    if(val < 0) {val = -val;Putchar('-');}
    do {a[++len] = val % 10 + '0';val /= 10;}
    while(val);
    
    while(len){Putchar(a[len--]);}
    return;
}

int main() 
{
    // program... 
    return 0;
}

