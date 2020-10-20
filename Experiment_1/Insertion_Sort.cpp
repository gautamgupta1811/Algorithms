#include<iostream>
#include <chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){
struct timespec start, end; 
clock_gettime(CLOCK_MONOTONIC, &start); 
int n, i, j, key;
cout<<"Enter the Number of Elements: ";
cin>>n;
int arr[n];
cout<<"Enter the Elements: ";
for(i=0;i<n;i++){
cin>>arr[i];
}
clock_gettime(CLOCK_MONOTONIC, &start); 
for(i=0;i<n;i++){
key = arr[i];
j = i-1;
while(j>=0 && arr[j]>key){
arr[j+1] = arr[j];
j = j -1;
}
arr[j+1] = key;
}
clock_gettime(CLOCK_MONOTONIC, &end); 
cout<<"Sorted array is: ";
for(j=0;j<n;j++){
cout<<arr[j]<<" ";
}
double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
    cout << "Time taken by program is : " << setprecision(10) << fixed
         << time_taken; 
    cout << " nanosec" << endl; 
// auto duration = duration_cast<nanoseconds>(stop - start);
// cout <<setprecision(10)<<fixed<<"\nTime taken by function: "<< duration.count() << " nanoseconds" << endl;
}