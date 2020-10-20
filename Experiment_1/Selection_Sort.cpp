#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    int i, j, n, min, temp, k;
    cout << "Enter the Number of Elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto start = steady_clock::now();
    for (i = 0; i < n - 1; i++)
    {
        temp = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[temp] > arr[j])
            {
                temp = j;
            }
        }
        min = arr[temp];
        arr[temp] = arr[i];
        arr[i] = min;
    }
    auto stop = steady_clock::now();
    cout << "Sorted Array" << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;
}