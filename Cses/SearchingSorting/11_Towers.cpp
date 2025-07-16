#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> ans;
    int size = 0;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        bool flag = false;
        if (!ans.empty() && ans[size-1]>x){
            for (int i = 0; i < size; i++){
                if (ans[i]>x){
                    flag = true;
                    ans[i] = x;
                    for (int j = i; j>=1; j--){
                        if (ans[j]<ans[j-1]){
                            swap(ans[j], ans[j-1]);
                        }
                    }
                    break;
                }
            }
        }
        if (!flag){
            ans.push_back(x);
            size++;
        }
    }
    cout<<size<<endl;
}