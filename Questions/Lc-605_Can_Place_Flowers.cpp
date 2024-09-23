#include <iostream>
#include<vector>

using namespace std;

// DUMBEST QUESTION, NO GAIN ONLY PAIN lol

bool canPlaceFlowers(vector<int> &flowerbed, int n){
    int size = flowerbed.size();
    int i = 0;
    while (i < size && n > 0){
        // agar jis position pe mai khada hu wo 0 hai 
        if (flowerbed[i] == 0){
            // then check uski prvious position pe value
            if (i - 1 >= 0){ //check uski previous position exist karti bhi hai ki nahi
            // if previous position exists
                if (flowerbed[i - 1] == 0){//if previous position pe bhi 0 hai
                    if (i + 1 < size){ //check next positon exist karti hai ki nahi
                    // if next position exists
                        if (flowerbed[i + 1] == 0) {
                        // if next position pe bhi 0 hai
                        // i have found a valid place to put the pot and decrease n , also make sure you change this position to 1 aka occupied
                            n--;
                            flowerbed[i] = 1;
                        }
                    }
                    else{
                        // agar previous position 0 hai, current positon 0 hai aur next positon exist nahi karti => valid case, put the pot here as well
                        n--;
                        flowerbed[i] = 1;
                    }
                }
            }
            else{
                // agar current position 0 hai aur previous position exist nahi karti
                if (i + 1 < size){ // check uske age wali positon exists or not
                // next position exists
                    if (flowerbed[i + 1] == 0){
                        // previous position DNE, current position = 0 and next postion is also 0=> valid case found
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else{
                    // current pos = 0, prev position dne, next position DNE means single element array, FOUND VALID CASE
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        i++;
    }
    if (n == 0) return true;
    return false;
}

int main(){
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;
    cout<<canPlaceFlowers(flowerbed, n);
}