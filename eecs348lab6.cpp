/*Author: Lily Gray
Date Created: 3/22/24
Date Modified: 3/23/24
Course: EECS 348*/
#include <iostream>
#include <fstream>
#include <string>
using std::fstream;
using std::string;
using std::cout;
const int N = 3;
//passing by reference
void read_matrix(fstream& myfile, int (&arr1)[N][N], int (&arr2)[N][N],int &size) {
    int row = size; int col = size;
    //get data for first matrix
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            myfile>>arr1[i][j];
        }
    }
    //get data for second matrix
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            myfile>>arr2[i][j];
        }
    }
    myfile.close();
    return;
}
void print_matrix(int matrix[N][N]){
    cout << "Matrix = \n";
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void add_matrices(int (&arr1)[N][N], int (&arr2)[N][N], int (&res)[N][N],int size){
    //check that dimensions of both matrices are the same
    if(!(sizeof(arr1)==sizeof(arr2))){
        cout << "Error: Matrix dimensions do not match\n";
        return;
    }
    cout << "Matrix1 + Matrix2 =\n\n";
    //add corresponding components of both matrices
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            res[i][j] = arr1[i][j]+arr2[i][j];
            cout<<res[i][j]<<"\t";
        }
        cout << "\n";
    }
    return;
}
void multiply_matrices(int (&arr1)[N][N], int (&arr2)[N][N], int (&result)[N][N], int size){
    cout << "Matrix1 * Matrix2 =\n\n";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j] = 0;
            for(int k=0;k<size;k++){
                //store result of row column multiplication
                result[i][j] += arr1[i][k]*arr2[k][j];
            }
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }
}
void subtract_matrices(int (&arr1)[N][N], int (&arr2)[N][N], int (&res)[N][N],int size){
    //check that dimensions are the same
    if(!(sizeof(arr1)==sizeof(arr2))){
        cout << "Error: Matrix dimensions do not match\n";
        return;
    }
    cout << "Matrix1 - Matrix2 =\n\n";
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            res[i][j] = arr1[i][j]-arr2[i][j];
            cout<<res[i][j]<<"\t";
        }
        cout << "\n";
    }
    return;
}
//take in a matrix, row, column, and new value and update the matrix with that value
void update_matrix(int (&matrix)[N][N], int i, int j, int val, int size){
    //check that i and j are valid
    if(!(i<size) | !(j<size)){
        cout << "Error updating matrix: index not within range\n";
        return;
    }
    cout << "BEFORE UPDATE: \n";
    print_matrix(matrix);
    cout << "\n";
    matrix[i][j] = val;
    //print result
    cout << "AFTER UPDATE: \n";
    print_matrix(matrix);
}
//search a matrix for the maximum value
void find_max(int (&matrix)[N][N], int size){
    int cur_max = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(matrix[i][j]>cur_max){
                cur_max = matrix[i][j];
            }
        }
    }
    cout << "Maximum Value of Matrix 1 = " << cur_max << "\n";
}
//transpose a given matrix
void transpose_matrix(int (&matrix)[N][N], int (&res)[N][N], int size){
    cout << "Transposed Matrix 1 =\n\n";
    //switch rows and columns
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            //original matrix is unchanged but transposed values get stored in new matrix
            res[i][j] = matrix[j][i];
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main(){
    int size;
    //initialize matrices
    int mat1[N][N];
    int mat2[N][N];
    int result[N][N];
    //file name to pass in to first function
    string filename = "matrix_input.txt";
    fstream myfile;
    myfile.open(filename,std::ios::in);
    if(myfile.is_open()){
        //extraction w/ right-shift operator to get size
        myfile >> size;
    }
    else{
        cout<< "Error opening file\n";
    }
    read_matrix(myfile,mat1,mat2,size);
    //call upon various functions
    cout << "\n";
    print_matrix(mat1);
    cout<<"\n";
    add_matrices(mat1,mat2,result,size);
    cout<<"\n";
    multiply_matrices(mat1,mat2,result,size);
    cout<<"\n";
    subtract_matrices(mat1,mat2,result,size);
    cout<<"\n";
    update_matrix(mat1,0,0,5,size);
    cout << "\n";
    find_max(mat1,N);
    cout << "\n";
    transpose_matrix(mat1,result,size);
    cout << "\n";
    return 0;
}