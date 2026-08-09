#include "include_asm.h"
#include "type.h"

/* measured: retail unit compiled with scheduling on (jr $ra delay slot is
   filled with the store; -O3 reproduces it; -O2 emits store, jr, nop). */
#pragma optimization_level 3

extern s32 D_00758688[];
extern s32 D_00758470[];
extern s32 D_007584F8[];
extern s32 D_00758528[];
extern s32 D_007587E8[];
extern u8 D_00922E20_abs[];
extern u8 D_00922E28_abs[];
extern u8 D_007199D0_abs[];
extern u8 D_007212D0_abs[];
/* Toolchain-blocked region: retail saves `$s` registers with `sd`; MWCCPS2 3.0.1 emits `sq`; see build/ORCH_sd_toolchain_blocked.txt. */

// FUN_004C3400
u32 func_004c3400(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x4C3C) = arg0;
    return segment;
}




// FUN_004C3420
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c3420);
// FUN_004C3460
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c3460);
// FUN_004C3498
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c3498);
// FUN_004C7340
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7340);
// FUN_004C7388
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7388);
// FUN_004C73F0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c73f0);
// FUN_004C7410
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7410);
// FUN_004C7478
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7478);
// FUN_004C74F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c74f8);
// FUN_004C7560
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7560);
// FUN_004C7588
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7588);
// FUN_004C7610
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7610);
// FUN_004C7638
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7638);
// FUN_004C7690
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7690);
// FUN_004C76F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c76f8);
// FUN_004C7720
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7720);
// FUN_004C7788
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7788);
// FUN_004C77B0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c77b0);
// FUN_004C7818
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7818);
// FUN_004C7840
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7840);
// FUN_004C78C8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c78c8);
// FUN_004C7918
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7918);
// FUN_004C79A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c79a0);
// FUN_004C79E0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c79e0);
// FUN_004C7A68
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7a68);
// FUN_004C7AB8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7ab8);
// FUN_004C7B40
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7b40);
// FUN_004C7B80
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7b80);
// FUN_004C7E28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7e28);
// FUN_004C7E68
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7e68);
// FUN_004C7E90
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7e90);
// FUN_004C7EF8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7ef8);
// FUN_004C7F30
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7f30);
// FUN_004C7F48
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7f48);
// FUN_004C7F80
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c7f80);
// FUN_004C83B0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c83b0);
// FUN_004C83E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c83e8);
// FUN_004C8400
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8400);
// FUN_004C8458
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8458);
// FUN_004C84F0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c84f0);
// FUN_004C85A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c85a0);
// FUN_004C85E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c85e8);
// FUN_004C8688
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8688);
// FUN_004C8708
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8708);
// FUN_004C8770
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8770);
// FUN_004C8830
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8830);
// FUN_004C8908
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8908);
// FUN_004C8950
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8950);
// FUN_004C89F0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c89f0);
// FUN_004C8A60
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8a60);
// FUN_004C8A90
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8a90);
// FUN_004C8B48
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8b48);
// FUN_004C8B70
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8b70);
// FUN_004C8BD0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8bd0);
// FUN_004C8CD0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8cd0);
// FUN_004C8D28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8d28);
// FUN_004C8DB8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8db8);
// FUN_004C8E10
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8e10);
// FUN_004C8E28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8e28);
// FUN_004C8E80
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c8e80);
// FUN_004C9010
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9010);
// FUN_004C9068
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9068);
// FUN_004C90A8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c90a8);
// FUN_004C90E0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c90e0);
// FUN_004C91D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c91d0);
// FUN_004C9208
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9208);
// FUN_004C92D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c92d0);
// FUN_004C9398
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9398);
// FUN_004C93C0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c93c0);
// FUN_004C9420
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9420);
// FUN_004C9478
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9478);
// FUN_004C9590
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9590);
// FUN_004C95C8
s32 func_004c95c8(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004c6a98(D_00758470);
        return -3;
    }
    return *(s32 *)(arg0 + 0x14);
}
// FUN_004C95F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c95f8);
// FUN_004C9630
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9630);
// FUN_004C9670
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9670);
// FUN_004C96A8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c96a8);
// FUN_004C9720
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9720);
// FUN_004C9768
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9768);
// FUN_004C97B8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c97b8);
// FUN_004C97F0
s32 func_004c97f0(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004c6a98(D_007584F8);
        return -3;
    }
    return *(s32 *)(arg0 + 0x20);
}
// FUN_004C9820
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9820);
// FUN_004C9858
s8 func_004c9858(u8 *arg0)
{
    if (arg0 == NULL) {
        func_004c6a98(D_00758528);
        return -3;
    }
    return *(s8 *)(arg0 + 1);
}
// FUN_004C9888
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9888);
// FUN_004C9900
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9900);
// FUN_004C9978
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9978);
// FUN_004C99A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c99a0);
// FUN_004C9A28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9a28);
// FUN_004C9B80
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9b80);
// FUN_004C9BB8
#ifdef NON_MATCHING
s32 func_004c9bb8(s32 arg0)
{
    u8 *base;

    base = (u8 *)0x00710000;
    return (s32)(*(u8 **)(base + arg0 * 4 + 0x61F0) + 0x10);
}
/* Committed at nd 2. */
#else
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9bb8);
#endif
// FUN_004C9BD0
u32 func_004c9bd0(u32 arg0)
{
    u32 segment = 0x00710000;

    *(u32 *)(segment + 0x65F0) = arg0;
    return segment;
}


// FUN_004C9BE0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9be0);
// FUN_004C9C20
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9c20);
// FUN_004C9C58
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9c58);
// FUN_004C9C90
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9c90);
// FUN_004C9CC8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9cc8);
// FUN_004C9D00
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9d00);
// FUN_004C9D18
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9d18);
// FUN_004C9D30
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9d30);
// FUN_004C9D48
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9d48);
// FUN_004C9D70
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9d70);
// FUN_004C9E20
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9e20);
// FUN_004C9E48
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9e48);
// FUN_004C9E60
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9e60);
// FUN_004C9E98
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9e98);
// FUN_004C9EB0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9eb0);
// FUN_004C9EC8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9ec8);
// FUN_004C9EE0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9ee0);
// FUN_004C9F00
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c9f00);
// FUN_004CA1B0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca1b0);
// FUN_004CA368
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca368);
// FUN_004CA460
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca460);
// FUN_004CA4E0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca4e0);
// FUN_004CA648
s32 *func_004ca648(void)
{
    return D_00758688;
}


// FUN_004CA658
u32 func_004ca658(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x7754) = arg0;
    return segment;
}


// FUN_004CA668
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca668);
// FUN_004CA680
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca680);
// FUN_004CA698
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca698);
// FUN_004CA6C0
s32 func_004ca6c0(void)
{
    func_004cb280();
    return 0;
}
// FUN_004CA6E0
s32 func_004ca6e0(void)
{
    func_004d5b30();
    return 0;
}
// FUN_004CA700
s32 func_004ca700(void)
{
    func_004c9d48();
    return 0;
}
// FUN_004CA720
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca720);
// FUN_004CA890
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca890);
// FUN_004CA8B0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca8b0);
// FUN_004CA990
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ca990);
// FUN_004CAB90
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cab90);
// FUN_004CABD0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cabd0);
// FUN_004CABF0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cabf0);
// FUN_004CAC50
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cac50);
// FUN_004CACC0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cacc0);
// FUN_004CAD10
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cad10);
// FUN_004CADD8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cadd8);
// FUN_004CAE08
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cae08);
// FUN_004CAEB8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004caeb8);
// FUN_004CAEF8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004caef8);
// FUN_004CAF28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004caf28);
// FUN_004CAF68
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004caf68);
// FUN_004CAF88
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004caf88);
// FUN_004CAFE8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cafe8);
// FUN_004CB098
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb098);
// FUN_004CB0E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb0e8);
// FUN_004CB198
void func_004cb198(void)
{
}
// FUN_004CB1A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb1a0);
// FUN_004CB1D8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb1d8);
// FUN_004CB210
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb210);
// FUN_004CB240
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb240);
// FUN_004CB280
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb280);
// FUN_004CB2A8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb2a8);
// FUN_004CB2C0
u32 func_004cb2c0(u32 arg0)
{
    u32 segment = 0x00720000;

    *(u32 *)(segment - 0x6680) = arg0;
    return segment;
}




// FUN_004CB2D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb2d0);
// FUN_004CB360
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb360);
// FUN_004CB3F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb3f8);
// FUN_004CB450
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb450);
// FUN_004CB468
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb468);
// FUN_004CB480
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb480);
// FUN_004CB498
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb498);
// FUN_004CB4B0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb4b0);
// FUN_004CB4C8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb4c8);
// FUN_004CB4E0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb4e0);
// FUN_004CB4F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb4f8);
// FUN_004CB510
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb510);
// FUN_004CB548
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb548);
// FUN_004CB5D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb5d0);
// FUN_004CB640
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb640);
// FUN_004CB728
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb728);
// FUN_004CB750
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb750);
// FUN_004CB790
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb790);
// FUN_004CB7E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb7e8);
// FUN_004CB880
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb880);
// FUN_004CB988
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cb988);
// FUN_004CBA78
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cba78);
// FUN_004CBBB0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbbb0);
// FUN_004CBC88
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbc88);
// FUN_004CBCD8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbcd8);
// FUN_004CBD28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbd28);
// FUN_004CBD40
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbd40);
// FUN_004CBDA8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbda8);
// FUN_004CBE08
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbe08);
// FUN_004CBEB0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbeb0);
// FUN_004CBF68
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbf68);
// FUN_004CBFF0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cbff0);
// FUN_004CC078
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc078);
// FUN_004CC110
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc110);
// FUN_004CC1F0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc1f0);
// FUN_004CC200
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc200);
// FUN_004CC218
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc218);
// FUN_004CC3A8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc3a8);
// FUN_004CC3F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc3f8);
// FUN_004CC490
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc490);
// FUN_004CC560
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc560);
// FUN_004CC630
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc630);
// FUN_004CC700
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc700);
// FUN_004CC830
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc830);
// FUN_004CC900
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc900);
// FUN_004CC9D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc9d0);
// FUN_004CC9E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc9e8);
// FUN_004CCA00
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cca00);
// FUN_004CCA10
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cca10);
// FUN_004CCB38
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccb38);
// FUN_004CCB50
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccb50);
// FUN_004CCB68
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccb68);
// FUN_004CCBF0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccbf0);
// FUN_004CCC70
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccc70);
// FUN_004CCC98
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccc98);
// FUN_004CCCD0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cccd0);
// FUN_004CCCE8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccce8);
// FUN_004CCD30
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccd30);
// FUN_004CCD90
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccd90);
// FUN_004CCDA8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004ccda8);
// FUN_004CCE10
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cce10);
// FUN_004CCE28
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cce28);
// FUN_004CCE40
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cce40);
// FUN_004CD030
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd030);
// FUN_004CD0E0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd0e0);
// FUN_004CD108
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd108);
// FUN_004CD130
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd130);
// FUN_004CD148
s32 func_004cd148(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *base0;
    s32 *base1;

    base0 = (s32 *)D_00922E20_abs;
    base1 = (s32 *)D_00922E28_abs;
    base0[1] = arg1;
    base0[0] = arg0;
    base1[1] = arg3;
    base1[0] = arg2;
    return (s32)base0;
}
// FUN_004CD170
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd170);
// FUN_004CD1A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd1a0);
// FUN_004CD1D0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd1d0);
// FUN_004CD250
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd250);
// FUN_004CD2A0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd2a0);
// FUN_004CD2B8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd2b8);
// FUN_004CD2C8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd2c8);
// FUN_004CD2F8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd2f8);
// FUN_004CD378
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd378);
// FUN_004CD3F0
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd3f0);
// FUN_004CD470
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd470);
// FUN_004CD488
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cd488);
// FUN_004CF390
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf390);
// FUN_004CF4E8
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf4e8);
// FUN_004CF550
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf550);
// FUN_004CF710
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf710);
// FUN_004CF738
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf738);
// FUN_004CF798
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf798);
// FUN_004CF7D0
void func_004cf7d0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 6) = arg2;
    *(s16 *)(arg0 + 4) = arg1;
}
// FUN_004CF7E0
void func_004cf7e0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}


// FUN_004CF880
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf880);
// FUN_004CF920
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf920);
// FUN_004CF958
void func_004cf958(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 6) = arg2;
    *(s16 *)(arg0 + 4) = arg1;
}
// FUN_004CF968
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cf968);
// FUN_004CF9C0
void func_004cf9c0(u8 *arg0, s16 arg1, s16 arg2)
{
    *(s16 *)(arg0 + 0xA) = arg2;
    *(s16 *)(arg0 + 8) = arg1;
}
