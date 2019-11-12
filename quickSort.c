#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void swapC(int a, int b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int swapLeftRight(int arr[], int low, int high)
{
    int left = low;
    int right = high - 1;
    int pivot = high;
    while (1)
    {
        while (arr[left] < arr[pivot])
            left++;
        while (arr[right] > arr[pivot])
            right--;
        if (left >= right){
            break;
        }
    }
    swapC(arr[left], arr[pivot]);
    return left;
}

int quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int temp = swapLeftRight(arr, low, high);
        quickSort(arr, low, temp );
        quickSort(arr, temp + 1, high);
    }
}
int main()
{
    srand(time(NULL));
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 1000;
    }
    for(int k=0;k<100;k++){
        printf("%d",arr[k]);
    }

    quickSort(arr,0,99);
    for(int j=0;j<100;j++){
        printf("%d\t",arr[j]);
    }
    return 0;
}