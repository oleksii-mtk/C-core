#include <stdio.h>

void ini_fill(int (*inarr)[4], int (*outarr)[4]) {
    int i = 0;
    int j = 0;
    int size = 4;
    int k = 0;

   /* Initializing array*/
    while (i < size) {
        j = 0;
        while (j < size) {
            if (inarr[i][j] == 4) {
                k = 0;
                while (k < size) {
                    if (i == 0)
                        outarr[k][j] = k + 1;  // top to bottom
                    if (i == 1)
                        outarr[size - k - 1][j] = k + 1;  // bottom to top
                    if (i == 2)
                        outarr[j][k] = k + 1;  // from left to right
                    if (i == 3)
                        outarr[j][size - k - 1] = k + 1;  // from right to left
                    k++;
                }
            }

            if (inarr[i][j] == 1) {
                if (i == 0)
                    outarr[0][j] = 4;  // visibility from top
                if (i == 1)
                    outarr[size - 1][j] = 4;  // visibility from bottom
                if (i == 2)
                    outarr[j][0] = 4;  // visibility from left
                if (i == 3)
                    outarr[j][size - 1] = 4;  // visibility from right
            }
            j++;
        }
        i++;
    }
}

void print(int (*arr)[4]) {
    int i = 0;
    int j = 0;
    int size = 4;

    while (i < size) {
        j = 0;
        while (j < size) {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int find_new_value(int (*idata)[4], int (*odata)[4], int row, int col) {
    int i = 0;
    int aset[] = {1, 2, 3, 4};  
    int min_allowed_tb = idata[0][col]; 
    int min_allowed_bt = idata[1][col]; 
    int min_allowed_lr = idata[2][row]; 
    int min_allowed_rl = idata[3][row]; 
    int max = 4;

    /* Deleting used values */
    while (i < 4) {
        if (odata[row][i] > 0) {
            aset[odata[row][i] - 1] = 0;  // Deleting using values from row
        }
        if (odata[i][col] > 0) {
            aset[odata[i][col] - 1] = 0;  // Deleting using values from column
        }
        i++;
    }

    // Поиск подходящего значения с учётом всех условий видимости
    i = 4;
    while (i > 0) {
        int value = aset[i - 1];
        if (value > 0) {
            /* Calculation max value in the cell from diff directions*/
            int max_lr = col + 1 + max - min_allowed_lr;
            int max_rl = max + min_allowed_rl;
            int max_tb = row + 1 + max - min_allowed_tb;
            int max_bt = max + min_allowed_bt;

            /*Checking value from all directions*/
            if (value <= max_lr && value <= max_rl && value <= max_tb && value <= max_bt) {
             
              return value;
            }
        }
        i--;
    }

    return 0; // Если не найдено подходящее значение
}

int main() {
    int row = 0;
    int col = 0;
    int value;

    int idata[4][4] = {
        {4, 3, 2, 1},
        {1, 2, 2, 2},
        {4, 3, 2, 1},
        {1, 2, 2, 2}
    };

    int odata[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    ini_fill(idata, odata);

     while (col < 4) {
        while (row < 4) 
        {
            if (odata[row][col] == 0) 
            { // Analysing empty cells only
                int value = find_new_value(idata, odata, row, col);
                if (value == 0) 
                {   
                    if (row != 1 && (odata[row - 1][col] - 1) > 0) 
                    {
                      odata[row - 1][col]--;
                      value = find_new_value(idata, odata, row, col);
                      if (value == 0) 
                      {
                        return 1; // unable to solve
                      }
                    } else 
                    {
                      odata[row][col] = value;
                      row++;  // To the next column
                    }
                } else {
                    odata[row][col] = value;
                    row++;  // To the next column
                }
            } else 
            {
                row++;  // skip cell
            }
        }
        row = 0;
        col++;
    }

    printf("\n");
    print(odata);

    return 0;
}

