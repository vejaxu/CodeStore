#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    vector<int> maxLeft(n), minRight(n);

    maxLeft[0] = arr[0];
    for(int i = 1; i < n; i ++){
        maxLeft[i] = max(maxLeft[i-1], arr[i-1]);
    }

    minRight[n-1] = arr[n-1];
    for (int i = n - 2; i >= 0; i --){
        minRight[i] = min(minRight[i+1], arr[i+1]);
    }

    for (int i = 0; i < n; i ++){
        if (arr[i] >= maxLeft[i] && arr[i] <= minRight[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}