                // Binary Search Algorithm

// #include<iostream>
// using namespace std;

// int binarySearch(int arr[], int size, int key){
//     int start = 0;
//     int end = size - 1;
//     int mid = start + (end - start)/2;
    
//     while(start<=end){
//         if(arr[mid]==key){
//             return mid;
//         }
        
//         else if(arr[mid]<key){
//             start = mid + 1;
//         }
        
//         else if(arr[mid]>key){
//             end = mid - 1;
//         }
        
//         mid = start + (end - start)/2;
//     }
    
//     return -1;
// }

// int main(){
//     int odd[5]={1,3,5,7,9};
//     int even[6]={3,4,7,8,23,45};
    
//     int oddIndex = binarySearch(odd, 5, 5);
//     int evenIndex = binarySearch(even, 6, 23);
//     cout<<oddIndex<<endl;
//     cout<<evenIndex<<endl;
//     return 0;
// }


// Code for searching the first and last occurence of the element 

// #include<iostream>
// #include<vector>
// using namespace std;
// int leftSearch(int arr[], int size, int key){
//     int start = 0;
//     int end = size - 1;
//     int mid = start + (end - start)/2;
//     int ans;
    
//     while(start<=end){
//         if(arr[mid]==key){
//             ans = mid;
//             end = mid-1;
//         }
        
//         else if(arr[mid]<key){
//             start = mid + 1;
//         }
        
//         else if(arr[mid]>key){
//             end = mid - 1;
//         }
        
//         mid = start + (end - start)/2;
//     }
    
//     return ans;
// }


// int rightSearch(int arr[], int size, int key){
//     int start = 0;
//     int end = size - 1;
//     int mid = start + (end - start)/2;
//     int ans;
    
//     while(start<=end){
//         if(arr[mid]==key){
//             ans = mid;
//             start = mid+1;
//         }
        
//         else if(arr[mid]<key){
//             start = mid + 1;
//         }
        
//         else if(arr[mid]>key){
//             end = mid - 1;
//         }
        
//         mid = start + (end - start)/2;
//     }
    
//     return ans;
// }


// int main(){
//     int odd[5]={5,5,5,5,5};
//     int t = leftSearch(odd, 5, 5);
//     int r = rightSearch(odd, 5, 5);
//     cout<<t<<" "<<r<<endl;
//     return 0;
// }


// Code for finding the pivot index
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int rightSum = 0, leftSum = 0;
//         for (int i = 1; i < nums.size(); i++) {
//             rightSum += nums[i];
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (rightSum == leftSum) {
//                 return i;
//             }

//             leftSum += nums[i];
            
//             if (i + 1 < nums.size()) {
//                 rightSum -= nums[i+1];
//             }
//         }
//         return -1;
//     }
// };


// Code for finding the peak element in an array
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int start = 0;
//         int end = arr.size() - 1;
//         int mid = start + (end - start)/2;
    
//     while(start<end){
//     if(arr[mid+1]>arr[mid]){
//         start=mid+1;
//     }

//     else{
//         end=mid;
//     }

//     mid = start + (end - start)/2;
//     }
//     return mid;
//     }
// };


// Searching in a sorted rotated array
// int getpivot(vector<int>&arr, int n){
// int s = 0;
// int e = n-1;
// int mid = s + (e - s)/2;

// while(s<e){
//     if(arr[mid]>=arr[0]){
//         s = mid + 1;
//     }

//     else{
//         e = mid;
//     }
    
//     mid = s + (e - s)/2;
//     }
// return s;
// }


// int binarySearch(vector<int>& arr, int s, int e, int key){
//     int start = s;
//     int end = e; 
//     int mid = start + (end - start)/2;
    
//     while(start<=end){
//         if(arr[mid]==key){
//             return mid;
//         }
        
//         else if(arr[mid]<key){
//             start = mid + 1;
//         }
        
//         else if(arr[mid]>key){
//             end = mid - 1;
//         }
        
//         mid = start + (end - start)/2;
//     }
    
//     return -1;
// }


// int search(vector<int>& arr, int n, int k){

//     int pivot=getpivot(arr, n);

//     if(k>=arr[pivot] && k<=arr[n-1]){
//         return binarySearch(arr, pivot, n-1, k);
//     }

//     else{
//         return binarySearch(arr, 0, pivot-1, k);
//     }
// }


// Book Allocating Problem
// bool isPossible(vector<int>& arr, int n, int m, int maxPages) {
//     int studentCount = 1;
//     int pagesAssigned = 0;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] > maxPages) {
//             return false;  // Cannot assign a book with more pages than maxPages
//         }

//         if (pagesAssigned + arr[i] > maxPages) {
//             studentCount++;
//             pagesAssigned = arr[i];

//             if (studentCount > m) {
//                 return false;  // Exceeded the number of students allowed
//             }
//         } else {
//             pagesAssigned += arr[i];
//         }
//     }

//     return true;
// }

// int findPages(vector<int>& arr, int n, int m) {
//     int totalPages = 0;
//     int maxPages = 0;

//     // Calculate the total number of pages and the maximum number of pages in a single book
//     for (int i = 0; i < n; i++) {
//         totalPages += arr[i];
//         maxPages = max(maxPages, arr[i]);
//     }

//     int start = maxPages;  // Start with the maximum number of pages in a single book
//     int end = totalPages;  // End with the total number of pages
//     int result = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (isPossible(arr, n, m, mid)) {
//             result = mid;
//             end = mid - 1;  // Look for a smaller value to minimize the maximum pages assigned
//         } else {
//             start = mid + 1;  // Look for a larger value
//         }
//     }

//     return result;
// }


//Painter Partition Problem
// bool isPossible(vector<int>& boards, int k, int maxPages) {
//     int studentCount = 1;
//     int pagesAssigned = 0;

//     for (int i = 0; i < boards.size(); i++) {
//         if (boards[i] > maxPages) {
//             return false;  // Cannot assign a book with more pages than maxPages
//         }

//         if (pagesAssigned + boards[i] > maxPages) {
//             studentCount++;
//             pagesAssigned = boards[i];

//             if (studentCount > k) {
//                 return false;  // Exceeded the number of students allowed
//             }
//         } else {
//             pagesAssigned += boards[i];
//         }
//     }

//     return true;
// }

// int findLargestMinDistance(vector<int>& boards, int k) {
//     int totalPages = 0;
//     int maxPages = 0;

//     // Calculate the total number of pages and the maximum number of pages in a single book
//     for (int i = 0; i < boards.size(); i++) {
//         totalPages += boards[i];
//         maxPages = max(maxPages, boards[i]);
//     }

//     int start = maxPages;  // Start with the maximum number of pages in a single book
//     int end = totalPages;  // End with the total number of pages
//     int result = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (isPossible(boards, k, mid)) {
//             result = mid;
//             end = mid - 1;  // Look for a smaller value to minimize the maximum pages assigned
//         } else {
//             start = mid + 1;  // Look for a larger value
//         }
//     }

//     return result;
// }