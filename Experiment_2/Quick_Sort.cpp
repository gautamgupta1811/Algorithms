#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int partition(int arr[], int p, int r)
{
    int temp;
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
void quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}
int main()
{
    int n, i, j;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto start = steady_clock::now();
    quicksort(arr, 0, n - 1);
    auto stop = steady_clock::now();
    cout << "Sorted Array is: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;
}