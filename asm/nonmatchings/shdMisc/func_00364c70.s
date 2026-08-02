.section .text
.set noat
.set noreorder
glabel func_00364c70
    /* 264C70 00364C70 E8AB84DF */  ld         $4, -0x5418($28)
    /* 264C74 00364C74 7FFF0324 */  addiu      $3, $0, -0x81
    /* 264C78 00364C78 24188300 */  and        $3, $4, $3
    /* 264C7C 00364C7C E8AB83FF */  sd         $3, -0x5418($28)
    /* 264C80 00364C80 0800E003 */  jr         $31
    /* 264C84 00364C84 00000000 */   nop
    /* 264C88 00364C88 00000000 */  nop
    /* 264C8C 00364C8C 00000000 */  nop
.size func_00364c70, 0x20
