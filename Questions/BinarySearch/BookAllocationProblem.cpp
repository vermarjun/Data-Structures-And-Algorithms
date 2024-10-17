#include<iostream>

using namespace std;

bool check(int arr[], int n, int maxPages, int m){
    int pages = 0, i = 0;
    while (i<n){
        if (m == 0) return false; // bache khatam books bachi hui hain wala case, idhar return false and low=mid+1 such that i can try with more pages per child
        if (pages+arr[i]<=maxPages){
            pages+=arr[i];
            i++;
        }
        else {
            // current book kisi bache ko nahi de sakta, here return false and try with more books per child
            if (pages == 0) return false;
            m--;
            pages = 0;
        }
    }
    // ye case hai ki books khatam hogyi hain, 
    // NOTE in this case there is a possibility ki har student ko book na mili ho
    // But this possibility will be corrected once i do high = mid - 1; for minimum book;
    return true;
}

long long findPages(int n, int arr[], int m) {
    if (m>n) return -1;
    long long ans = -1;
    int low = 0, high = 0;
    for (int i = 0; i<n; i++){
        high+=arr[i];
    }
    while (low<=high){
        int mid = (low+high)/2;
        if (check(arr, n, mid, m)){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n = 4;
    int arr[4] = {12, 34, 67, 90};
    int m = 2;
    cout<<findPages(n, arr, m);
}