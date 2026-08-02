typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

#define SLOT_IDX(i) ((i) * 0x28)
#define LD16(a, i) (*(s16 *)&(a)[(i)])

extern u8 D_008D3ED0[];
extern u8 D_008D3ED2[];

s32 f3(s16 arg0, s16 arg1)
{
    if (LD16(D_008D3ED0, SLOT_IDX(arg0)) == 3 &&
        arg1 != LD16(D_008D3ED2, SLOT_IDX(arg0)))
    {
        return 1;
    }
    return 0;
}
