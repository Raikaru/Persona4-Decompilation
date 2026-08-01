/* Consolidated Persona 4 source units. */
/* Original translation unit y_smap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void (*D_00887300[])(s32 state, s32 value);

extern void (*jtbl_008873EC[])(void *);

typedef struct YVec3f { f32 x, y, z; } YVec3f;

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};



// FUN_002ADCF0
s64 func_002adcf0(u8 arg0) {
    return (s64)(s8)((arg0 & 0xFF) >> 4);
}



// FUN_002ADD60
void func_002add60(u8 *arg0, u8 *arg1) {
    D_00887300[0](0xE, *(s32 *)(arg1 + 0xB4));
}



// FUN_002AFB70
void func_002afb70(u8 *arg0, s8 arg1) {
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x38);
    if (arg1 == 0) {
        *(s8 *)(temp_6 + 4) = 5;
    } else if (arg1 == 1) {
        *(s8 *)(temp_6 + 4) = 6;
    }
    *(s16 *)(temp_6 + 0x764) = 0;
}



// FUN_002B0220
void func_002b0220(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


#pragma push


// FUN_002B1100
void func_002B1100(void *param_1,u32 param_2,u32 param_3)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 1200.0f * (float)param_2;
  vector.z = 1200.0f * (float)param_3;
  *(YVec3f *)param_1 = vector;
}

#pragma pop


#pragma push


// FUN_002B11C0
int func_002B11C0(RwV3d param_1)

{
  return (int)((param_1.x + 600.0f) / 1200.0f);
}

#pragma pop


#pragma push


// FUN_002B1210
int func_002B1210(RwV3d param_1)

{
  return (int)((param_1.z + 600.0f) / 1200.0f);
}

#pragma pop
