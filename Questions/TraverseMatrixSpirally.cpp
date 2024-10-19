#include<iostream>
#include<vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
    vector<int> ans;
    int rowStart = 0;
    int rowEnd = matrix.size();
    int colStart = 0;
    int colEnd = matrix[0].size();
    while (rowStart<rowEnd && colStart<colEnd){
        for(int col = colStart; col <colEnd; col++){
            ans.push_back(matrix[rowStart][col]);
        }
        rowStart++;
        if (rowStart>=rowEnd || colStart>=colEnd) break;
        for(int row = rowStart; row<rowEnd; row++){
            ans.push_back(matrix[row][colEnd-1]);
        }
        colEnd--;
        if (rowStart>=rowEnd || colStart>=colEnd) break; 
        for(int col = colEnd-1; col>=colStart; col--){
            ans.push_back(matrix[rowEnd-1][col]);
        }
        rowEnd--;
        if (rowStart>=rowEnd || colStart>=colEnd) break;
        for(int row = rowEnd-1; row >= rowStart; row--){
            ans.push_back(matrix[row][colStart]);
        }
        colStart++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,16}};
    vector<int> ans = spirallyTraverse(matrix);
    for (int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
}