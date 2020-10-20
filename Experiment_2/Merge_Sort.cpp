#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int left[n1 + 1], right[n2 + 1];
    for (i = 1; i < n1 + 1; i++)
    {
        left[i] = arr[p + i - 1];
    }
    for (i = 1; i < n2 + 1; i++)
    {
        right[i] = arr[q + i];
    }
    left[n1 + 1] = 1000000;
    right[n2 + 1] = 100000;
    i = 1;
    j = 1;
    for (k = p; k < r + 1; k++)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i += 1;
        }
        else
        {
            arr[k] = right[j];
            j += 1;
        }
    }
}
void merge_sort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main()
{
    int n, p, r, i, j;
    cout << "Enter the Number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto start = steady_clock::now();
    merge_sort(arr, 0, n - 1);
    auto stop = steady_clock::now();
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;
}