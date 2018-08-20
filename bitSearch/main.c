#include <stdio.h>
#include <stdlib.h>

int searchBitinByte(unsigned char Byte, int bit){
    return (Byte >> bit) & 0x1;
}

void writeByte(unsigned char *Byte, int posbit, unsigned char bit){
    if(bit == 1) {
        *Byte |= (1 << posbit);
    }else{
        *Byte &= ~(1 << posbit);
    }
}
int main()
{
    char Bk = 5;
    char bit = searchBitinByte(Bk, 1);
    printf("%d\n", bit);

    writeByte(&Bk, 1, 0);

    printf("%d\n", Bk);

    bit = searchBitinByte(Bk, 1);
    printf("%d\n", bit);

    int j;
    for(j = 5; j >= 0 ; j--){
        printf("a %d\n", j);
    }
    return 0;
}
