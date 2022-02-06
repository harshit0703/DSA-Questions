#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int ans = 0;
    while(n != 0){
        int dig = n % 10;
        n /= 10;
        ans = ans * 10 + dig;
    }

    return ans;
}


int solve(int n){
    int rev = reverse(n);
    int sum = n + rev;

    int rev_sum = reverse(sum);

    while(sum != rev_sum){
        sum += rev_sum;
        rev_sum = reverse(sum);
    }

    return sum;

}

int main()
{
    cout<<solve(195);
    return 0;
}