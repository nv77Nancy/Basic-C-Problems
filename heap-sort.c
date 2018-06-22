#include<stdio.h>
void max_heapify(int ar[],int n,int i){
    int max,left,right,temp;
    max=i;
    left=(2*i)+1;
    right=(2*i)+2;
    if(left<n && ar[max]<ar[left])
        max=left;
    if(right<n && ar[max]<ar[right])
        max=right;
    if(max!=i){
        temp = ar[i];
        ar[i]=ar[max];
        ar[max]=temp;
        max_heapify(ar,n,max);
    }
}
void build_max_heap(int ar[],int n){
    int i;
    for( i=(n/2)-1; i>=0;i--){
        max_heapify(ar,n,i);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf(" %d ",ar[i]);
    }
}
void heap_sort(int ar[],int n){
    int i,temp;
    build_max_heap(ar,n);
    for(i=n-1;i>=0;i--){
        temp = ar[0];
        ar[0]=ar[i];
        ar[i]=temp;
        max_heapify(ar,i,0);
    }
}
int main(){
    int n;
    printf("\n\t\t\tHEAP SORT\n");
    printf("Enter size of array : ");
    scanf("%d",&n);
    int i,j,ar[n];
    printf("Enter elements of array : \n");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("\nyour array : ");
    for(i=0;i<n;i++){
        printf(" %d ",ar[i]);
    }
    heap_sort(ar,n);
    printf("\n Sorted Array is : ");
    for(i=0;i<n;i++){
        printf(" %d ",ar[i]);
    }
    return 0;
}
