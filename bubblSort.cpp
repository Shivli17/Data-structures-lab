#include <iostream>

// Function to perform the Bubble Sort
void bubbleSort(int list[], int last) {
    int current = 0;
    bool sorted = false;

    while (current <= last && !sorted) {
        int walker = last;
        sorted = true;

        while (walker > current) {
            if (list[walker] < list[walker - 1]) {
                // Swap the elements if they are in the wrong order
                int temp = list[walker];
                list[walker] = list[walker - 1];
                list[walker - 1] = temp;
                sorted = false;
            }
            walker--;
        }
        current++;
    }
}
    int partition(int a[],int l,int h){
        int pivot=a[l];
        int i=l;
        int j=h;
        while(i<j){
            while(a[i]<=pivot)i++;
            while(a[j]>pivot)j--;
            if(i<j){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        int t=a[j];
        a[j]=a[l];
        a[l]=t;
        return j;
    }
    void QuickSort(int a[],int l,int h){
        if(l<h){
            int pivot=partition(a,l,h);
            QuickSort(a,l,pivot-1);
            QuickSort(a,pivot+1,h);
        }
    }


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    //bubbleSort(arr, n - 1);
    QuickSort(arr,0,n-1);

    std::cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
