#include<stdio.h>
#define max 100       //No. of elements to be sorted
void quicksort(int , int);
int partition(int , int);
int n;
int a[max];
int main(){
    int i;
	  printf("\n\t\t\tQUICK SORT\n\n");
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    printf("Enter Elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(0,n-1);
    printf("\nSorted Array : ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}
void quicksort(int p,int r){
    int q;
    if(p<r){
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
int partition(int p,int r){
    int i,j,x,temp=0;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}
