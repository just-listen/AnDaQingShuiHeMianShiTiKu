#include<iostream>
#include<string.h>

//memmove函数对内存重叠做了处理
//如果目标区域和源区域有重叠的话，
//memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中（此时源字符串尾部字符改变）。
void* my_memcpy(void* dst, void* src, size_t size){
    char *psrc = nullptr;
    char *pdst = nullptr;
    if(dst == nullptr || src == nullptr || size <= 0) return dst;
    // 出现地址重叠的情况，dst地址大于src地址，自后向前拷贝
    if(src < dst && (char*)src + size > (char*)dst){
        psrc = (char*)src + size - 1;
        pdst = (char*)src + size - 1;
        while(size--){
            *pdst-- = *psrc--;
        }
    }
    // 出现地址重叠的情况，dst地址小于src地址，自前向后拷贝
    // 没出现，也从前向后
    else{
        psrc = (char*) src;
        pdst = (char*) dst;
        while(size--){
            *pdst++ = *psrc++;
        }
    }
    return dst;
}