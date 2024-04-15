#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i){
    // Row is constant only Col changes
    for(int j=0; j<m; j++){
        if(matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j){
    // Col is constant only Row changes
    for(int i=0; i<n; i++){
        if(matrix[i][j] != 0)
            matrix[i][j] = -1;
    }
}

void solve(vector<vector<int>> &matrix, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                // Mark -1
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
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

// TC: O((N*M)*(N + M)) + O(N*M)        SC: O(1)