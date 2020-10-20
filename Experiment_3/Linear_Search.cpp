#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    int key, n, flag = 0;
    cout << "Enter Number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Key: ";
    cin >> key;
    auto start = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            cout << "Key found at index: " << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "key not found" << endl;
    }
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;
}