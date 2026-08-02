.section .text
.set noat
.set noreorder
glabel func_0010bd90
    /* BD90 0010BD90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* BD94 0010BD94 0000BFFF */  sd         $31, 0x0($29)
    /* BD98 0010BD98 3C1C0400 */  dsll32     $3, $4, 16
    /* BD9C 0010BD9C 3F1C0300 */  dsra32     $3, $3, 16
    /* BDA0 0010BDA0 01000224 */  addiu      $2, $0, 0x1
    /* BDA4 0010BDA4 0C006214 */  bne        $3, $2, .L0010BDD8
    /* BDA8 0010BDA8 00000000 */   nop
    /* BDAC 0010BDAC FFFF0324 */  addiu      $3, $0, -0x1
    /* BDB0 0010BDB0 7900023C */  lui        $2, %hi(D_00797F88)
    /* BDB4 0010BDB4 887F43A4 */  sh         $3, %lo(D_00797F88)($2)
    /* BDB8 0010BDB8 7900043C */  lui        $4, %hi(D_00797F8C)
    /* BDBC 0010BDBC 8C7F8424 */  addiu      $4, $4, %lo(D_00797F8C)
    /* BDC0 0010BDC0 2D280000 */  daddu      $5, $0, $0
    /* BDC4 0010BDC4 40020624 */  addiu      $6, $0, 0x240
    /* BDC8 0010BDC8 72FE100C */  jal        func_0043f9c8
    /* BDCC 0010BDCC 00000000 */   nop
    /* BDD0 0010BDD0 0D000010 */  b          .L0010BE08
    /* BDD4 0010BDD4 00000000 */   nop
  .L0010BDD8:
    /* BDD8 0010BDD8 FEFF6324 */  addiu      $3, $3, -0x2
    /* BDDC 0010BDDC 00110300 */  sll        $2, $3, 4
    /* BDE0 0010BDE0 21104300 */  addu       $2, $2, $3
    /* BDE4 0010BDE4 C0180200 */  sll        $3, $2, 3
    /* BDE8 0010BDE8 7900023C */  lui        $2, %hi(D_00796E50)
    /* BDEC 0010BDEC 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* BDF0 0010BDF0 21104300 */  addu       $2, $2, $3
    /* BDF4 0010BDF4 54004424 */  addiu      $4, $2, 0x54
    /* BDF8 0010BDF8 2D280000 */  daddu      $5, $0, $0
    /* BDFC 0010BDFC 30000624 */  addiu      $6, $0, 0x30
    /* BE00 0010BE00 72FE100C */  jal        func_0043f9c8
    /* BE04 0010BE04 00000000 */   nop
  .L0010BE08:
    /* BE08 0010BE08 0000BFDF */  ld         $31, 0x0($29)
    /* BE0C 0010BE0C 1000BD27 */  addiu      $29, $29, 0x10
    /* BE10 0010BE10 0800E003 */  jr         $31
    /* BE14 0010BE14 00000000 */   nop
    /* BE18 0010BE18 00000000 */  nop
    /* BE1C 0010BE1C 00000000 */  nop
.size func_0010bd90, 0x90
