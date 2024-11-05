// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include <stdio.h>
#define VAL_BITS 11
#define MASK 0b11111111111 

unsigned short encode( int data, int *valid){
 int original = data;
 *valid = 1; 
 int shift = 0; 
 int highBits;
 unsigned short encoded; 
 while( ( highBits = data >> VAL_BITS - 1 ) != 0 && highBits != ~0 ){ 
  data >>= 1; 
  ++shift; 
 }
 encoded = shift << VAL_BITS | data & ~( ~0 << VAL_BITS );
 for(int i = shift-1;i >= 0;i--){
    if((original & 1<<i) == 0){
        *valid = 1;
    } else if ((original & 1<<i) != 0) {
        *valid = 0;
        break;
    }
 }
 return encoded;
}
int decode(unsigned short encoded){
    int shift = encoded >> VAL_BITS;
    int decoded = ((encoded & MASK) << shift);
    if(1<<VAL_BITS-1 & encoded){
        decoded = decoded | ( ~0 << VAL_BITS );
    }
    return  decoded;
}
int main(){
    int num;
    int valid;
    printf("original = ");
    scanf("%d",&num);
    unsigned short encoded = encode(num,&valid);
    printf("encoded  = 0x%x\n",encoded);
    printf("decoded  = 0x%1$x (%1$d)\n(Valid = %2$d)\n",decode(encoded),valid);
    return 0;
}