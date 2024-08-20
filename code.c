#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 5

// Define the 2D matrix
char matrix[SIZE][SIZE];

void prepareKey(char key[], int len) {
    // Create an alphabet array for reference
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int i, j, k = 0;
    int exists[26] = {0};

    // Fill the key into the matrix
    for (i = 0; i < len; i++) {
        if (!isalpha(key[i]))
            continue;
            
        if (key[i] == 'J')
            key[i] = 'I'; // Treat I and J as same
            
        if (!exists[key[i] - 'A']) {
            matrix[k / SIZE][k % SIZE] = key[i];
            exists[key[i] - 'A'] = 1;
            k++;
        }
    }

    // Fill the remaining alphabet into the matrix
    for (i = 0; i < 26; i++) {
        if (alphabet[i] == 'J')
            continue;
            
        if (!exists[alphabet[i] - 'A']) {
            matrix[k / SIZE][k % SIZE] = alphabet[i];
            exists[alphabet[i] - 'A'] = 1;
            k++;
        }
    }
}

void prepareMessage(char msg[], int len) {
    int i;
    
    for (i = 0; i < len; i++) {
        if (!isalpha(msg[i]))
            continue;
        
        if (msg[i] == 'J')
            msg[i] = 'I'; // Treat I and J as same
    }
}

void encrypt(char msg[], int len) {
    int i;
    char a, b;
    
    for (i = 0; i < len; i += 2) {
        a = msg[i];
        b = msg[i + 1];
        
        if (a == b) {
            b = 'X';
            i--;
        }
        
        int arow, acol, brow, bcol;
        int j, k;
        
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (matrix[j][k] == a) {
                    arow = j;
                    acol = k;
                }
                
                if (matrix[j][k] == b) {
                    brow = j;
                    bcol = k;
                }
            }  
        }
        
        if (arow == brow) {
            printf("%c%c", matrix[arow][(acol + 1) % SIZE], matrix[brow][(bcol + 1) % SIZE]);
        } else if (acol == bcol) {
            printf("%c%c", matrix[(arow + 1) % SIZE][acol], matrix[(brow + 1) % SIZE][bcol]);
        } else {
            printf("%c%c", matrix[arow][bcol], matrix[brow][acol]);
        }
    }
    
    printf("\n");
}

int main() {
    char key[100], message[100];

    printf("Enter the key: ");
    scanf("%s", key);
    
    int keylen = strlen(key);
    prepareKey(key, keylen);

    printf("Enter the message: ");
    getchar(); // clear newline from input buffer
    
    fgets(message, sizeof(message), stdin);
    int msglen = strlen(message);
    
    prepareMessage(message, msglen);

    printf("Encrypted message: ");
    encrypt(message, msglen);

    return 0;
}