#include "memory_operations.h"
#include <stdlib.h>

void *my_memcpy(void *dst, const void *src, size_t len) {
	char* dest=(char*)dst;
	char* sour=(char*)src;
    for (int i=0;i<len;i++) dest[i]=sour[i];
	return dest;
}

void *my_memmove(void *dst, const void *src, size_t len) {
    char* dest=(char*)dst;
	char* sour=(char*)src;
	char* tmp=malloc(len*sizeof(char*));
    for (int i=0;i<len;i++) tmp[i]=sour[i];
    for (int i=0;i<len;i++) dest[i]=tmp[i];
    free(tmp);
	return dest;
}

int is_little_endian() {
    int x = 1;
	char *y = (char*)&x;
	return  *y+48-'0';
}

int reverse_endianess(int value) {
    int swapped = ((value>>24)&0xff) | // move byte 3 to byte 0
                    ((value<<8)&0xff0000) | // move byte 1 to byte 2
                    ((value>>8)&0xff00) | // move byte 2 to byte 1
                    ((value<<24)&0xff000000); // byte 0 to byte 3
    return swapped;
}
