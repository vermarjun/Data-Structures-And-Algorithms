#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n = 0, x = 0;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++){
        int x = 0; cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int i = 0, j = n-1;
    bool possible = false;
    while(i<j){
        if (v[i].first+v[j].first == x){
            possible = true;
            cout<<v[i].second+1<<" "<<v[j].second+1<<endl;
            break;
        }
        else if (v[i].first+v[j].first>x){
            j--;
        }
        else {
            i++;
        }
    }
    if (!possible){
        cout<<"IMPOSSIBLE"<<endl;
    }   
}