#include <unistd.h>

#define SIZE 4

// Function to handle when the input is SIZE (4)
void handle_size_condition(int (*inarr)[SIZE], int (*outarr)[SIZE], int i, int j) {
    int k = 0;
    while (k < SIZE) {
        if (i == 0) outarr[k][j] = k + 1;
        if (i == 1) outarr[SIZE - k - 1][j] = k + 1;
        if (i == 2) outarr[j][k] = k + 1;
        if (i == 3) outarr[j][SIZE - k - 1] = k + 1;
        k++;
    }
}

// Function to handle when the input is 1 (only one element visible)
void handle_one_condition(int (*inarr)[SIZE], int (*outarr)[SIZE], int i, int j) {
    if (i == 0) outarr[0][j] = SIZE;
    if (i == 1) outarr[SIZE - 1][j] = SIZE;
    if (i == 2) outarr[j][0] = SIZE;
    if (i == 3) outarr[j][SIZE - 1] = SIZE;
}

// Function to initialize the output array based on input conditions
void ini_fill(int (*inarr)[SIZE], int (*outarr)[SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if (inarr[i][j] == SIZE) {
                handle_size_condition(inarr, outarr, i, j);
            }
            if (inarr[i][j] == 1) {
                handle_one_condition(inarr, outarr, i, j);
            }
            j++;
        }
        i++;
    }
}

#include <unistd.h>

// Function to find the next value and handle potential errors
int find_and_set_value(int (*idata)[4], int (*odata)[4], int row, int col) {
    int value = find_new_value(idata, odata, row, col);
    if (value == 0) {
        if (row != 1 && (odata[row - 1][col] - 1) > 0) {
            odata[row - 1][col]--; // Decrement the previous row's value
            value = find_new_value(idata, odata, row, col);
            if (value == 0) {
                return 1; // Unable to solve
            }
        }
    }
    odata[row][col] = value;
    return 0;
}

// Function to handle an individual cell
int process_cell(int (*idata)[4], int (*odata)[4], int row, int col) {
    if (odata[row][col] == 0) {
        if (find_and_set_value(idata, odata, row, col) != 0) {
            return 1; // Unable to solve
        }
    }
    return 0;
}

// Main function to fill the data in the grid
int fill_data(int (*idata)[4], int (*odata)[4]) {
    int row, col = 0;
    while (col < 4) {
        row = 0;
        while (row < 4) {
            if (process_cell(idata, odata, row, col) != 0) {
                return 1; // Unable to solve
            }
            row++; // Move to the next row
        }
        col++; // Move to the next column
    }
    return 0;
}

