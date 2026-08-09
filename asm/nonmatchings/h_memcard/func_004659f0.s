.section .text
.set noat
.set noreorder
glabel func_004659f0
    /* 3659F0 004659F0 D0BA80AF */  sw         $0, -0x4530($28)
    /* 3659F4 004659F4 B8BA84AF */  sw         $4, -0x4548($28)
    /* 3659F8 004659F8 CCBA80AF */  sw         $0, -0x4534($28)
    /* 3659FC 004659FC C8BA80AF */  sw         $0, -0x4538($28)
    /* 365A00 00465A00 B0BA80AF */  sw         $0, -0x4550($28)
    /* 365A04 00465A04 0800E003 */  jr         $31
    /* 365A08 00465A08 00000000 */   nop
    /* 365A0C 00465A0C 00000000 */  nop
.size func_004659f0, 0x20
