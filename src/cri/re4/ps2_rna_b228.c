/* PS2 RNA voice handles and shutdown forwarding. */
#include "cri_xpt.h"

extern void func_004d4308(Uint8 *handle);
extern void func_004cc9d0();
extern void func_004cc9e8();
extern void func_004ea9c8();
extern void func_004ea838();
extern void func_004eaa18();
extern void PL2ENC_Encode(void *handle, Sint32 sample, Sint16 *left, Sint16 *right);
// FUN_004EB228
void PL2LINK_DetachDolbyProLogicII(Uint8 *arg0)
{
    Uint8 *p = *(Uint8 **)(arg0 + 4);
    Uint8 *q = *(Uint8 **)(p + 4);
    Uint32 v = *(Uint32 *)(q + 0xe8);

    if (v == 0) {
        return;
    }
    func_004d4308(arg0);
    func_004cc9d0();
    func_004ea9c8(v);
    *(Uint32 *)(q + 0xe8) = 0;
    func_004ea838(0);
    func_004cc9e8();
}

// FUN_004EB298
void func_004eb298(Uint8 *arg0)
{
    func_004eaa18(*(Uint32 *)(arg0 + 0xe8));
}

// FUN_004EB2B0
void PL2LINK_Encode(Uint8 *arg0, Sint16 arg1, Sint16 *left, Sint16 *right)
{
    PL2ENC_Encode(*(void **)(arg0 + 0xe8), arg1, left, right);
}


