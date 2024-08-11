#include <unistd.h>
#define SIZE 4

// Function to fill idata array from input string
void fill_idata_from_input(const char *input, int idata[SIZE][SIZE]) {
    int values[SIZE * SIZE];
    int index = 0;

    /* Read and parse the input string */
    const char *ptr = input;

    while (*ptr != '\0') {
        /* Skip any whitespace */
        while (*ptr == ' ') {
            ptr++;
        }

        /* Extract number */
        int num = 0;
        while (*ptr >= '0' && *ptr <= '9') {
            num = num * 10 + (*ptr - '0');
            ptr++;
        }

        /* Validate number */
        if (num < 1 || num > 4) {
            write(2, "Error: Value out of range (1 to 4).\n", 36);
            exit(1);
        }

        if (index >= SIZE * SIZE) {
            write(2, "Error: Too many values provided.\n", 34);
            exit(1);
        }

        values[index++] = num;
    }

    /* Check if we have exactly SIZE * SIZE values */
    if (index != SIZE * SIZE) {
        write(2, "Error: Insufficient values provided.\n", 37);
        exit(EXIT_FAILURE);
    }

    /* Fill the idata array */
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            idata[i][j] = values[i * SIZE + j];
            j++;
        }
        i++;
    }
}

void print_array(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            print_int(arr[i][j]);
            if (j < SIZE - 1) {
                write(1, " ", 1); 
            }
        }
        write(1, "\n", 1); 
    }
}

int main(int argc, char *argv[]) {
    int i;
    int j;
    
    if (argc != 2) {
        write(2, "Usage: ./program \"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\"\n", 53);
        return (1);
    }

    int idata[SIZE][SIZE];
    fill_idata_from_input(argv[1], idata);

    /* Print the idata array to verify */
    i = 0;
    j = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            char buffer[4];
            int length = snprintf(buffer, sizeof(buffer), "%d ", idata[i][j]);
            write(1, buffer, length);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }

    return (0);
}
