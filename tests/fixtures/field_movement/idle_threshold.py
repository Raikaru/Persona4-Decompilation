import re


def fixture_from_source(source):
    s=source;a=s.index('s32 func_00174e10(u8 *arg0)\n{');b=s.index('\n#else',a);s=s[a:b]
    condition=re.search(r'else if \((c148 > 360)\)',s).group(1)
    fixture='''#include <stdint.h>
    #include <limits.h>
    #include <stdio.h>
    #include <stdlib.h>
    static int recovered(int32_t c148) { return CONDITION; }
    static void check(int32_t c) {
        int retail = !(c < 0x169);
        if (recovered(c) != retail) abort();
    }
    int main(void) {
        uint32_t bits = 0x12345678u;
        int32_t edges[] = {INT32_MIN, INT32_MIN+1, -1, 0, 59,60,61,359,360,361,362,INT32_MAX-1,INT32_MAX};
        unsigned i,checks=0;
        for(i=0;i<sizeof(edges)/sizeof(edges[0]);++i) {check(edges[i]);++checks;}
        for(int32_t c=-32768;c<=32767;++c) {check(c);++checks;}
        for(i=0;i<1000000;++i) {bits=bits*1664525u+1013904223u; int32_t c=bits<=INT32_MAX?(int32_t)bits:INT32_MIN+(int32_t)(bits-0x80000000u);check(c);++checks;}
        printf("checks=%u\\n",checks);
    }
    '''.replace('CONDITION',condition)
    return fixture
