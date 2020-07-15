#include<bits/stdc++.h>
#define int long long 
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e5;
int n, arr[N];


int Merge(int left, int mid, int right){ 
    int i = left , j = mid, k = 0; 
    int inv_cnt = 0; 
    int temp[right - left + 1]; 
    while(i < mid && j <= right){ 
        if(arr[i] <= arr[j]){ 
            temp[k++] = arr[i++]; 
        }else{ 
            temp[k++] = arr[j++]; 
            inv_cnt += (mid - i); 
        } 
    } 
    while(i < mid){ 
        temp[k++] = arr[i++]; 
    } 
    while(j <= right){ 
        temp[k++] = arr[j++]; 
    } 
    for(i = left, k = 0; i <= right ; i++, k++){ 
        arr[i] = temp[k]; 
    } 
    return inv_cnt; 
} 
int InversionMergeSort(int left, int right){ 
    int inv_cnt = 0; 
    if(right > left){ 
        int mid = (right + left)/2; 
        inv_cnt = InversionMergeSort(left, mid); 
        inv_cnt += InversionMergeSort(mid + 1, right); 
        inv_cnt += Merge(left, mid+1, right); 
    } 
    return inv_cnt; 
} 

int inverson_count(){
    multiset<int> ms;
    ms.insert(arr[0]);
    int res = 0;
    for(int i = 1; i < n; i++){
        ms.insert(arr[i]);
        auto it = ms.upper_bound(arr[i]);
        res += distance(it, ms.end());
    }
    return res;
}

int32_t main(){


}