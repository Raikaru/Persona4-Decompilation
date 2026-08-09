.section .text
.set noat
.set noreorder
glabel func_0042bd98
    /* 32BD98 0042BD98 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32BD9C 0042BD9C 1000B0FF */  sd         $16, 0x10($29)
    /* 32BDA0 0042BDA0 2000BFFF */  sd         $31, 0x20($29)
    /* 32BDA4 0042BDA4 2486100C */  jal        func_00421890
    /* 32BDA8 0042BDA8 2D20A003 */   daddu     $4, $29, $0
    /* 32BDAC 0042BDAC 0000A38F */  lw         $3, 0x0($29)
    /* 32BDB0 0042BDB0 FFFF023C */  lui        $2, (0xFFFF1FFF >> 16)
    /* 32BDB4 0042BDB4 FF1F4234 */  ori        $2, $2, (0xFFFF1FFF & 0xFFFF)
    /* 32BDB8 0042BDB8 0400B027 */  addiu      $16, $29, 0x4
    /* 32BDBC 0042BDBC 24186200 */  and        $3, $3, $2
    /* 32BDC0 0042BDC0 2D200002 */  daddu      $4, $16, $0
    /* 32BDC4 0042BDC4 00206334 */  ori        $3, $3, 0x2000
    /* 32BDC8 0042BDC8 2086100C */  jal        func_00421880
    /* 32BDCC 0042BDCC 0400A3AF */   sw        $3, 0x4($29)
    /* 32BDD0 0042BDD0 2486100C */  jal        func_00421890
    /* 32BDD4 0042BDD4 2D200002 */   daddu     $4, $16, $0
    /* 32BDD8 0042BDD8 2086100C */  jal        func_00421880
    /* 32BDDC 0042BDDC 2D20A003 */   daddu     $4, $29, $0
    /* 32BDE0 0042BDE0 0400A28F */  lw         $2, 0x4($29)
    /* 32BDE4 0042BDE4 2000BFDF */  ld         $31, 0x20($29)
    /* 32BDE8 0042BDE8 42130200 */  srl        $2, $2, 13
    /* 32BDEC 0042BDEC 1000B0DF */  ld         $16, 0x10($29)
    /* 32BDF0 0042BDF0 07004230 */  andi       $2, $2, 0x7
    /* 32BDF4 0042BDF4 0100422C */  sltiu      $2, $2, 0x1
    /* 32BDF8 0042BDF8 0800E003 */  jr         $31
    /* 32BDFC 0042BDFC 3000BD27 */   addiu     $29, $29, 0x30
.size func_0042bd98, 0x68
