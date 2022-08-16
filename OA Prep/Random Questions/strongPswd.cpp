#include<bits/stdc++.h>
using namespace std;

void solve(Node *head, int cnt, int *st, int &maxi)
{
    if(head == NULL){
        maxi = max(maxi, cnt);
        return;
    }

    if(st.find(head->val) == st.end()){
        st.insert(head->val);
        solve(head->next, cnt + 1, st, maxi);
    }

    else {
        maxi = max(maxi, cnt);
        solve(head->next, 0, st, maxi);
    }
}

int strongest_password(Node* head){

    if(head == NULL) return 0;

    int maxi = 0;

    int arr[26] = 0;

    solve(head, 0, arr, maxi);

    return maxi;

}

int main()
{
    
    return 0;
}