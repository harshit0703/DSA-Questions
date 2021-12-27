#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int key){
    int st = 0;
    int en = arr.size()-1;
    while(st <= en){
        int mid = st + (en - st)/2;         // so that we do not get out of scope for int range
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
    return -1;
}

int firstRepeatEle(vector<int> arr){

    map<int, int>mp;
    for(auto i : arr){
        mp[i]++;
    }

    for(auto i : mp){
        if(i.second > 1){
            return i.first;
        }
    }

    return -1;

}

int gcd(int a, int b){
    while(b != 0){
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int maxSumSub(vector<int> arr){
    int currsum = 0;
    int maxSum = 0;
    for(int i = 0; i < arr.size(); i++){
        currsum += arr[i];
        if(currsum < 0){
            currsum = 0;
        }
        maxSum = max(maxSum, currsum);
    }
    return maxSum;
}

int longestArithSub(vector<int> arr){

    int len = 2;
    int currDiff = arr[1] - arr[0];
    int maxLen = INT_MIN;

    for(int i = 2; i < arr.size(); i++){
        int diff = arr[i] - arr[i-1];
        if(diff == currDiff){
            len++;
            maxLen = max(len, maxLen);
        }
        else{
            len = 2;
            currDiff = diff;
        }
    }

    return maxLen;

}

bool targetPairSum(vector<int>arr, int k){

    // for a pair to present such that the sum is equal to k the element must be smaller than k 
    // considering all elements are positive
    sort(arr.begin(), arr.end());
    // one idea is to visit each element first sub it from k and search for the remaining ele 
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] < k){
    //         int diff = k - arr[i];
    //         int ans = bs(arr, diff);
    //         if(ans != -1){
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // another idea is to use the two pointer approach but make sure that the array is sorted first
    int st = 0;
    int en = arr.size() - 1;
    while(st < en){
        if(arr[st] + arr[en] < k){
            st++;
        }
        else if(arr[st] + arr[en] > k){
            en--;
        }
        else if (arr[st] + arr[en] == k){
            return true;
        }
    }
    return false;
}

int recordBreaking(vector<int>arr){
    int maxTillNow = 0; // to handle the first edge case
    int days = 0;
    for(int i = 0; i < arr.size(); i++){
        if(i == arr.size() - 1 && arr[i] > maxTillNow){
            days++;
        }
        else if(arr[i] > maxTillNow && arr[i] > arr[i + 1]){
            days++;
            maxTillNow = arr[i];
        }
    }
    return days;
}

void soe(int n){
    int arr[n+1];
    for(int i = 0; i < n; i++){
        arr[i] = 1;
    }
    for(int i = 2; i < n; i++){
        for(int j = i*i; j < n; j+=i){
            arr[j] = 0;
        }
    }
    for(int i = 2; i < n; i++){
        if(arr[i] == 1){
            cout<<i<<" ";
        }
    }
}

void primeSieve(int n){
    int arr[n+1];
    for(int i = 0; i < n; i++){
        arr[i] = 1;
    }
    for(int i = 2; i < n; i++){
        for(int j = i*i; j < n; j+=i){
            arr[j] = 0;
        }
    }
    
    int i = 2;
    while(n != 1){
        if(n % i == 0 && arr[i] == 1){
            n /= i;
            cout<<i<<" ";
            i = 2;
        }
        else{
            i++;
        }
    }

}

void subarraySum(vector<int> arr, int sum){
    int windowSum = 0;
    int st = 0;
    int en = 0;
    // simply following a two point arrpoach since all elements are positive
    while(windowSum != sum){
        if(windowSum < sum){
            windowSum += arr[st];
            st++;
        }
        else if(windowSum > sum){
            windowSum -= arr[en];
            en++;
        }
    }
    cout<<en<<" "<<st-1;
}

int main()
{
    // binary search = searching an element in a sorted array in O(log n) time complexity
    vector<int> arr = {1, 3, 4, 5, 8, 10, 13};
    int key = 8;
    cout<<bs(arr, key)<<endl;

    // first repeating element since we have already covered maps it is simple to process this question by simply using ordered maps

    vector<int> ele = {1, 3, 4, 3, 5, 7, 7, 5, 9};
    cout<<firstRepeatEle(ele)<<endl;

    // find the gcd using inclusion exclusion principle
    // continuous division technique = inclusion exclusion principle 
    cout<<gcd(32, 108)<<endl;

    // kadane's algorithm = if sum is less than 0 make it zero
    // maximum sum subarray = that is simply the sum of the positive elements 

    vector<int> kadane = {-1, 4, -6, 7, -4};
    cout<<maxSumSub(kadane)<<endl;

    // longest arithmetic subarray
    vector<int> arithmetic = {10, 7, 4, 6, 8, 10, 11};
    cout<<longestArithSub(arithmetic)<<endl;

    // pair sum 
    vector<int> pairSum = {2, 4, 7, 11, 14, 16, 20, 21};
    cout<<targetPairSum(pairSum, 31)<<endl;

    // record breaking days 
    vector<int> days = {1, 2, 0, 7, 2, 0, 2, 2};
    cout<<recordBreaking(days)<<endl;

    // sieve of eratosthenes 
    // this algorithm helps to find the prime nos in a given range more efficiently
    // soe(50);

    // prime seive is used to give the prime factorization of a given number
    primeSieve(96);

    // subarray sum
    vector<int> v = {1, 3, 8, 4, 2, 9, 11, 5};
    // subarraySum(v, 15);

    return 0;
}