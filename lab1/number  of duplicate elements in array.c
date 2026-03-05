#include<stdio.h>
int main()
{
    int n;
    int count=0;
    printf("enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i]==arr[j]){
                count++;
                break;
            }
        }
    }
    printf("count of duplicate elements in an array is %d",count);
    return 0;
}

