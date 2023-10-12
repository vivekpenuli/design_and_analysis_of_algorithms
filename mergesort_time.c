
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int a[],int low, int mid,int high)
{
    int i,j,k,b[20];
    i =low,j=mid+1,k=low;
    while((i<=mid && j <=high))
    {
        if(a[i]<=a[j])
        b[k++]=a[i++];
        else
        b[k++]=a[j++];

    }
    while(i<=mid)
    b[k++] = a[i++];
    while (j<=high)
    b[k++]=a[j++]; 

    for(k=low;k<=high;k++)
    a[k]=b[k];

}

void mergesort(int a[],int low, int high)
{
    int mid;
    if(low >= high)
    return ;
mid =(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}

void main()
{
    int n,a[200],k;
    clock_t st,et;
    double ts;
    printf("Enter the number of elements");
scanf("%d",&n);
printf("\n the rando number are");
for(k=0;k<=n;k++)
{
a[k]= rand();
printf("\n%d",a[k]);
}
st=clock();
mergesort(a,1,n);
et=clock();
ts= (double)(et-st);

printf("\n sorted element are");
for(k =1;k<=n;k++)
printf("\n %d ",a[k]);
printf("\nthe time taken by your program is %lf sec\n",ts/CLOCKS_PER_SEC);
}




// Objective is to find how much time required to run the allgo
