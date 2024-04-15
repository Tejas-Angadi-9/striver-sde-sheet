## A) Brute Force
 The changes can be done in the matrix array itself. 
### Steps:
1. Traverse the matrix in each cell and find 0
2. If 0 is found then mark the entire row and col of that 0 to -1 except 0
3. Now traverse again the matrix and find -1 and set it to 0
4. END

## B) Better
Approach: Using 2 arrays of row and col to set value 1 then changing entire row and col to 0 if it's index is 1
### STEPS:
1. Create 2 arrays of size row and col. Set all the values to 0
2. Traverse the entire matrix using 2 nested for loops and check if the cell value is 0 then set the array value of ith row and jth col to 1
3. Continue the step 2 till the end of the matrix
4. Traverse again, and this time check if the row index of i or col index of j is 1 then set that cell to 0
5. END

## C) Optimal
Approach: Instead of taking a row and col array outside. Why can't we just take it inside ie. to track row we will use the 1st col ie. 0th col and to track col we will use the 1st row ie. 0th row. But there is the problem with 0,0 as both are common for row and col. Either we can give it to row or col. If we give it to row then for col we have to create a variable col0 and other part from col starts from j=1 to m-1 and row starts from i = 0 to n-1
### STEPS:
1. We will take the first row and first col. As we have a common point at 0,0 we will create an extra variable col0 = 1
2. Traverse the matrix and check if the cell is 0 then check is j != 0 then set the 1st row jth cell as 0 if j == 0 then set col0 = 0
3. After the end of the traversal of the matrix, we traverse again to set the values of the cell to 0 based on the row and col value if == 0. But we will start traversing from 2nd row and 2nd col excluding the 1st row and 1st col. In this check if the row or the col value of the cell is 0 then set the current cell to 0
4. Now the inner part is done. The time comes for setting the values of 1st row and 1st col
5. But here is the catch. If we change the col first then we will make the changes of the 1st row which is dependent on it and make other values to 1. So to avoid it we will set the first row to 0 if the col0 = 0 and first col to 0 if the matrix[0][0] = 0
6. END