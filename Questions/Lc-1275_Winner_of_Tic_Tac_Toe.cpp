#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

string tictactoe(vector<vector<int>>& moves) {
    // A
    vector<int> row(3,0);
    vector<int> col(3,0);
    int Dia = 0;
    int reverseDia = 0;
    int size = moves.size();
    for (int i= 0; i < size; i+=2){
        row[moves[i][0]]++;
        col[moves[i][1]]++;
        if (row[moves[i][0]]==3 || col[moves[i][1]]==3) return "A";
        if (moves[i][0] == moves[i][1]) Dia++;
        if (moves[i][0] + moves[i][1] == 2) reverseDia++;
        if (Dia == 3 || reverseDia == 3) return "A"; 
    }
    // B
    row.clear();
    col.clear();
    Dia = 0;
    reverseDia = 0;
    for (int i = 1; i < size; i+=2){
        row[moves[i][0]]++;
        col[moves[i][1]]++;
        if (row[moves[i][0]]==3 || col[moves[i][1]]==3) return "B";
        if (moves[i][0] == moves[i][1]) Dia++;
        if (moves[i][0] + moves[i][1] == 2) reverseDia++;
        if (Dia == 3 || reverseDia == 3) return "B";
    }
    if (size == 9) return "Draw";
    return "Pending";
}   
int main(){
    vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    cout<<tictactoe(moves); //A;
}
