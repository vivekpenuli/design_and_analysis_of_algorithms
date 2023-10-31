#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void KmpSearch(char *pat, char *txt)
{
int m =strlen(pat);
int n = strlen(txt);
int *lps= (int *)malloc(sizeof(int)*m);
int j=0;
ComputeLpsArray(pat,m,lps);
int i=0;
while(i<n)
{
    if(pat[j]==txt[i])
    {
        j++;
        i++;
    }
    if(j==m)
    {
        printf("Pattern at index %d \n",i-j);
        j= lps[j-1];

    }
    else if(i<n && pat[j]!=txt[i])
    {
        if(j!=0)
        {
            j= lps[j-1];
        }
        else{
            i=i+1;
        }
    }
}
free(lps);

}
void ComputeLpsArray(char *pat,int m, int *lps){
 int len =0;
 int i=1;
 lps[0]=0;
   while(i<m){
    if(pat[i]==pat[len]){
        len++;
        lps[i]=len;
        i++;
    }
    else{
        if(len!=0){
            len=lps[len-1];    
        }
        else{
            lps[i]=0;
            i++;
        }
    }
   }
}
void main()
{
    char pat[10],text[20];
    printf("Enter Pattern: ");
    gets(pat);
    printf("Enter Text: ");
    gets(text);
    KmpSearch(pat,text);
}
