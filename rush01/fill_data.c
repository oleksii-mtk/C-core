int try_set_value(int (*idata)[4], int (*odata)[4], int row, int col) 
{
    int value = find_new_value(idata, odata, row, col);
    if (value == 0 && row != 0 && (odata[row - 1][col] - 1) > 0) 
    {
        odata[row - 1][col]--;
        value = find_new_value(idata, odata, row, col);
        if (value == 0) 
        {
            return 0;
        }
    }
    odata[row][col] = value;
    return value != 0;
}

int fill_data(int (*idata)[4], int (*odata)[4]) 
{
    int row = 0;
    int col = 0;

    while (col < 4) 
    {
        while (row < 4) 
        {
            if (odata[row][col] == 0) 
            {
                if (!try_set_value(idata, odata, row, col)) 
                {
                    return 1;
                }
            }
            row++;
        }
        row = 0;
        col++;
    }
    return 0;
}

