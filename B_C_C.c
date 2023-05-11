#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void sender(int b[], int k);
void checksum();
void bit_stuffing();
void character_count();

int main() {
    char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("a. Checksum\nb. Bit stuffing\nc. Character count\n");
    printf("\nEnter your choice: ");
    scanf("%c", &choice);
    switch(choice) {
        case 'a':
            checksum();
            break;
        case 'b':
            bit_stuffing();
            break;
        case 'c':
            character_count();
            break;
        default:
            printf("\nInvalid choice. Please run the program again.\n");
    }
    getch();
    return 0;
}

void sender(int b[], int k) {
    int checksum, sum = 0;
    printf("\n****SENDER****\n");
    for(int i = 0; i < k; i++) {
        sum += b[i];
    }
    printf("SUM IS: %d\n", sum);
    checksum = ~sum;
    printf("SENDER's CHECKSUM IS: %d\n", checksum);
}

void checksum() {
    int a[100], m, scheck;
    printf("\nEnter size of the string: ");
    scanf("%d", &m);
    printf("\nEnter the elements of the array: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    sender(a, m);
}

void bit_stuffing() {
    char str[100], bstr[100];
    printf("\nEnter the bit string: ");
    scanf("%s", str);
    int len = strlen(str);
    int count = 0, j = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        bstr[j++] = str[i];
        if(count == 5) {
            bstr[j++] = '0';
            count = 0;
        }
    }
    bstr[j] = '\0';
    printf("After bit stuffing: %s\n", bstr);
}

void character_count() {
    char arr[100];
    printf("\nEnter the string: ");
    scanf("%s", arr);
    int len = strlen(arr);
    printf("Resultant frame using character count = %d%s\n", len + 1, arr);
}
