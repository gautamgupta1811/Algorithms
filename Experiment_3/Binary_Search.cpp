#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int binary_search(int arr[], int first, int last, int key)
{
    if (last >= first)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binary_search(arr, first, mid - 1, key);
        return binary_search(arr, mid + 1, last, key);
    }
    return -1;
}
int main()
{
    int n, mid, last, first = 0, key, flag = 0, result;
    cout << "Enter Number of Elements: ";
    cin >> last;
    int arr[last];
    cout << "Enter elements in Sorted order: ";
    for (int i = 0; i < last; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Key: ";
    cin >> key;
    auto start = steady_clock::now();
    result = binary_search(arr, first, last, key);
    if (result != -1)
    {
        cout << "Key Found at index: " << result << endl;
    }
    else
    {
        cout << "Key not Found" << endl;
    }
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;
}