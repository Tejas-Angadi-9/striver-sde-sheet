//! Approach (Taking 2 arrays inside the matrix instead of outside):

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix, int n, int m){

    int col0 = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                // Setting the row index to 0
                matrix[i][0] = 0;
                if(j != 0){
                    // Setting the col index to 0
                    matrix[0][j] = 0;
                }
                else{
                    // Setting the col index to 0
                    col0 = 0;
                }
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] != 0){
                // Check from the 2 arrays
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    // ROW Changes
    if(col0 == 0){
        for(int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }
    // COL Changes
    if(matrix[0][0] == 0){
        for(int j=0; j<m; j++){
            matrix[0][j] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    int n = matrix.size();
    int m = matrix[0].size();

    solve(matrix, n, m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

    // Printing
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// TC:  O(2*(N*M)) = (N*M)          SC: O(1)