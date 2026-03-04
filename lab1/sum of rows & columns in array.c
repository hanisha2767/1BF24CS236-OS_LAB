#include<stdio.h>
void sumrc(int arr[10][10], int n, int m)
{
    int rowSum,columnSum;
    for(int i=0; i < n; i++)
    {
        rowSum=0;
        for(int j=0; j < m; j++)
        {
            rowSum=rowSum+arr[i][j];
        }
        printf("Sum of row %d = %d\n",i+1,rowSum);
    }
    for(int j=0; j < m; j++)
    {
        columnSum=0;
        for(int i=0; i < n; i++)
        {
            columnSum=columnSum+arr[i][j];
        }
        printf("Sum of column %d = %d\n",j+1,columnSum);
    }
}

int main()
{
    int arr[10][10];
    int n,m;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&n,&m);
    printf("Enter matrix elements:\n");
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    sumrc(arr,n,m);
    return 0;
}
