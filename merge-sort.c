#include<stdio.h>
#define max 100     //Number of elements to be sorted
void mergesort(int*,int, int);
void merg(int*,int ,int ,int);
int n;
int a[max];
int main(){
    int i;
    printf("\n\t\t\tMERGE SORT\n\n");
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    printf("Enter Elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted Array : ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}
void mergesort(int a[],int p,int r){
    int q;
    if(p<r){
        q=(p+r)/2;
    mergesort(a,p,q);
        mergesort(a,q+1,r);
        merg(a,p,q,r);
    }
}
void merg(int a[],int p,int q,int r){           //TO merge two simplest arrays
    int i,j,k,m1,m2;
    m1=q-p+1;
    m2=r-q;
    int M1[m1],M2[m2];
    for(i=0;i<m1;i++){
        M1[i]=a[p+i];
    }
    for(j=0;j<m2;j++){
        M2[j]=a[q+1+j];
    }
    i=j=0;
    k=p;
    while (i<m1 && j<m2)
    {
        if (M1[i]<=M2[j])
        {
            a[k]=M1[i];
            i++;
        }
        else
        {
            a[k]=M2[j];
            j++;
        }
        k++;
    }
     while (i < m1)
    {
        a[k] = M1[i];
        i++;
        k++;
    }
    while (j < m2)
    {
        a[k] = M2[j];
        j++;
        k++;
    }
}
