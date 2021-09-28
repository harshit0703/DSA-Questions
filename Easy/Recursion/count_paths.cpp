#include<iostream>
using namespace std;

int count_path(int start, int end){
    if (start == end){
        return 1; // base condition here we are assuming that there is one way to go from start to start 
    }else if (start > end){
        return 0;
    }

    int count = 0;
    for(int i=1; i<=6; i++){
        count += count_path(start + i, end);
    }

    return count;

}

int main(){
    // find the number of ways to reach from one end to another by making jumps of different sizes possible using recursion
    int start,end;
    cin>>start>>end;
    int ans = count_path(start, end);
    cout<<ans;
    return 0;
}