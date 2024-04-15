//! Approach (Using two extra arrays):

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix, int n, int m){
    //Creating 2 arrays
    int row[n] = {0};
    int col[m] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                // mark ith index of row wih 1:
                row[i] = 1;
                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Traverse through the matrix and check if the array of row or col has 1 then set the current cell to 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] == 1 || col[j] == 1)
                matrix[i][j] = 0;
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