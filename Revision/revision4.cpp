#include<bits/stdc++.h>
using namespace std;

int sumTillN(int n){
    if(n == 0){
        return 0;
    }
    return n + sumTillN(n-1);
}

void increasingOrder(int n){
    if(n == 0){
        return;
    }
    increasingOrder(n-1);   // right call
    cout<<n<<" ";
}

void decreasingOrder(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    decreasingOrder(n-1);
}

void fibonacci(int n, int a, int b){
    if(n == 0){
        return;
    }
    int c = a + b;
    cout<<c<<" ";
    fibonacci(n-1, b, c);
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int power(int n, int p){
    if(p == 0){
        return 1;
    }
    return n * power(n, p-1);
}

int firstOcc(int arr[], int n, int key, int i){
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstOcc(arr, n, key, i+1);
}

int lastOcc(int arr[], int n, int key, int i){
    if(i == n){
        return -1;
    }
    int prevAns = lastOcc(arr, n, key, i+1);
    if(prevAns != -1){
        return prevAns;
    }
    else if(arr[i] == key){
        return i;
    }
    return -1;
}

bool checkArr(int arr[], int n){
  if(n == 1){
      return true;
  }
  bool ans = checkArr(arr+1, n-1);
  if(arr[0] < arr[1] && checkArr){
      return true;
  }
  return false;
}

void subSequence(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<" ";
        return;
    }
    // two choices either add the char in ans or not
    char ch = str[0];
    str = str.substr(1);
    subSequence(str, ans);
    subSequence(str, ans + ch);
}

int main()
{
    // cout<<sumTillN(10);
    // increasingOrder(5);
    // decreasingOrder(5);
    // fibonacci(10, 0, 1);
    // cout<<factorial(5);
    // cout<<power(2, 10);
    subSequence("abc", "");
    return 0;
}