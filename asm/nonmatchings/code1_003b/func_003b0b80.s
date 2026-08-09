.section .text
.set noat
.set noreorder
glabel func_003b0b80
    /* 2B0B80 003B0B80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2B0B84 003B0B84 3000BFFF */  sd         $31, 0x30($29)
    /* 2B0B88 003B0B88 2000B27F */  sq         $18, 0x20($29)
    /* 2B0B8C 003B0B8C 1000B17F */  sq         $17, 0x10($29)
    /* 2B0B90 003B0B90 0000B07F */  sq         $16, 0x0($29)
    /* 2B0B94 003B0B94 0000928C */  lw         $18, 0x0($4)
    /* 2B0B98 003B0B98 2D80E000 */  daddu      $16, $7, $0
    /* 2B0B9C 003B0B9C 1000078D */  lw         $7, 0x10($8)
    /* 2B0BA0 003B0BA0 0400848C */  lw         $4, 0x4($4)
    /* 2B0BA4 003B0BA4 80180400 */  sll        $3, $4, 2
    /* 2B0BA8 003B0BA8 8401E314 */  bne        $7, $3, .L003B11BC
    /* 2B0BAC 003B0BAC 0C00118D */   lw        $17, 0xC($8)
    /* 2B0BB0 003B0BB0 9886100C */  jal        func_00421a60
    /* 2B0BB4 003B0BB4 2D200000 */   daddu     $4, $0, $0
    /* 2B0BB8 003B0BB8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B0BBC 003B0BBC 00D0648C */  lw         $4, -0x3000($3)
    /* 2B0BC0 003B0BC0 00018430 */  andi       $4, $4, 0x100
    /* 2B0BC4 003B0BC4 0C008010 */  beqz       $4, .L003B0BF8
    /* 2B0BC8 003B0BC8 00000000 */   nop
    /* 2B0BCC 003B0BCC 00010424 */  addiu      $4, $0, 0x100
    /* 2B0BD0 003B0BD0 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B0BD4 003B0BD4 0F000000 */  sync
    /* 2B0BD8 003B0BD8 0F040000 */  sync.p
  .L003B0BDC:
    /* 2B0BDC 003B0BDC 00000000 */  nop
    /* 2B0BE0 003B0BE0 00000000 */  nop
    /* 2B0BE4 003B0BE4 00000000 */  nop
    /* 2B0BE8 003B0BE8 00000000 */  nop
    /* 2B0BEC 003B0BEC 00000000 */  nop
    /* 2B0BF0 003B0BF0 FAFF0041 */  bc0f       .L003B0BDC /* handwritten instruction */
    /* 2B0BF4 003B0BF4 00000000 */   nop
  .L003B0BF8:
    /* 2B0BF8 003B0BF8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B0BFC 003B0BFC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B0C00 003B0C00 00018430 */  andi       $4, $4, 0x100
    /* 2B0C04 003B0C04 14008010 */  beqz       $4, .L003B0C58
    /* 2B0C08 003B0C08 00000000 */   nop
    /* 2B0C0C 003B0C0C 00020424 */  addiu      $4, $0, 0x200
    /* 2B0C10 003B0C10 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B0C14 003B0C14 0F000000 */  sync
    /* 2B0C18 003B0C18 0F040000 */  sync.p
  .L003B0C1C:
    /* 2B0C1C 003B0C1C 00000000 */  nop
    /* 2B0C20 003B0C20 00000000 */  nop
    /* 2B0C24 003B0C24 00000000 */  nop
    /* 2B0C28 003B0C28 00000000 */  nop
    /* 2B0C2C 003B0C2C 00000000 */  nop
    /* 2B0C30 003B0C30 FAFF0041 */  bc0f       .L003B0C1C /* handwritten instruction */
    /* 2B0C34 003B0C34 00000000 */   nop
    /* 2B0C38 003B0C38 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003B0C3C:
    /* 2B0C3C 003B0C3C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B0C40 003B0C40 00018430 */  andi       $4, $4, 0x100
    /* 2B0C44 003B0C44 00000000 */  nop
    /* 2B0C48 003B0C48 00000000 */  nop
    /* 2B0C4C 003B0C4C 00000000 */  nop
    /* 2B0C50 003B0C50 FAFF8014 */  bnez       $4, .L003B0C3C
    /* 2B0C54 003B0C54 00000000 */   nop
  .L003B0C58:
    /* 2B0C58 003B0C58 0100033C */  lui        $3, (0x10000 >> 16)
  .L003B0C5C:
    /* 2B0C5C 003B0C5C 39000042 */  di /* handwritten instruction */
    /* 2B0C60 003B0C60 0F040000 */  sync.p
    /* 2B0C64 003B0C64 00600440 */  mfc0       $4, $12 /* handwritten instruction */
    /* 2B0C68 003B0C68 24208300 */  and        $4, $4, $3
    /* 2B0C6C 003B0C6C 00000000 */  nop
    /* 2B0C70 003B0C70 FAFF8014 */  bnez       $4, .L003B0C5C
    /* 2B0C74 003B0C74 00000000 */   nop
    /* 2B0C78 003B0C78 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2B0C7C 003B0C7C 00008344 */  mtc1       $3, $f0
    /* 2B0C80 003B0C80 00000344 */  mfc1       $3, $f0
    /* 2B0C84 003B0C84 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2B0C88 003B0C88 FF02004A */  vnop
    /* 2B0C8C 003B0C8C FF02004A */  vnop
    /* 2B0C90 003B0C90 38000042 */  ei /* handwritten instruction */
    /* 2B0C94 003B0C94 7F00032A */  slti       $3, $16, 0x7F
    /* 2B0C98 003B0C98 A3006014 */  bnez       $3, .L003B0F28
    /* 2B0C9C 003B0C9C 00000000 */   nop
    /* 2B0CA0 003B0CA0 00700C3C */  lui        $12, (0x70001FC0 >> 16)
    /* 2B0CA4 003B0CA4 0110073C */  lui        $7, (0x10010000 >> 16)
    /* 2B0CA8 003B0CA8 01000A3C */  lui        $10, (0x10000 >> 16)
    /* 2B0CAC 003B0CAC 00010524 */  addiu      $5, $0, 0x100
    /* 2B0CB0 003B0CB0 00020424 */  addiu      $4, $0, 0x200
    /* 2B0CB4 003B0CB4 FC010324 */  addiu      $3, $0, 0x1FC
    /* 2B0CB8 003B0CB8 C01F8B35 */  ori        $11, $12, (0x70001FC0 & 0xFFFF)
    /* 2B0CBC 003B0CBC C01F0824 */  addiu      $8, $0, 0x1FC0
  .L003B0CC0:
    /* 2B0CC0 003B0CC0 00D0E68C */  lw         $6, -0x3000($7)
    /* 2B0CC4 003B0CC4 0001C630 */  andi       $6, $6, 0x100
    /* 2B0CC8 003B0CC8 0D00C010 */  beqz       $6, .L003B0D00
    /* 2B0CCC 003B0CCC 00000000 */   nop
    /* 2B0CD0 003B0CD0 20E0E5AC */  sw         $5, -0x1FE0($7)
    /* 2B0CD4 003B0CD4 0F000000 */  sync
    /* 2B0CD8 003B0CD8 0F040000 */  sync.p
    /* 2B0CDC 003B0CDC 00000000 */  nop
  .L003B0CE0:
    /* 2B0CE0 003B0CE0 00000000 */  nop
    /* 2B0CE4 003B0CE4 00000000 */  nop
    /* 2B0CE8 003B0CE8 00000000 */  nop
    /* 2B0CEC 003B0CEC 00000000 */  nop
    /* 2B0CF0 003B0CF0 00000000 */  nop
    /* 2B0CF4 003B0CF4 FAFF0041 */  bc0f       .L003B0CE0 /* handwritten instruction */
    /* 2B0CF8 003B0CF8 00000000 */   nop
    /* 2B0CFC 003B0CFC 00000000 */  nop
  .L003B0D00:
    /* 2B0D00 003B0D00 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0D04 003B0D04 0001C630 */  andi       $6, $6, 0x100
    /* 2B0D08 003B0D08 1500C010 */  beqz       $6, .L003B0D60
    /* 2B0D0C 003B0D0C 00000000 */   nop
    /* 2B0D10 003B0D10 20E0E4AC */  sw         $4, -0x1FE0($7)
    /* 2B0D14 003B0D14 0F000000 */  sync
    /* 2B0D18 003B0D18 0F040000 */  sync.p
    /* 2B0D1C 003B0D1C 00000000 */  nop
  .L003B0D20:
    /* 2B0D20 003B0D20 00000000 */  nop
    /* 2B0D24 003B0D24 00000000 */  nop
    /* 2B0D28 003B0D28 00000000 */  nop
    /* 2B0D2C 003B0D2C 00000000 */  nop
    /* 2B0D30 003B0D30 00000000 */  nop
    /* 2B0D34 003B0D34 FAFF0041 */  bc0f       .L003B0D20 /* handwritten instruction */
    /* 2B0D38 003B0D38 00000000 */   nop
    /* 2B0D3C 003B0D3C 00000000 */  nop
  .L003B0D40:
    /* 2B0D40 003B0D40 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0D44 003B0D44 0001C630 */  andi       $6, $6, 0x100
    /* 2B0D48 003B0D48 00000000 */  nop
    /* 2B0D4C 003B0D4C 00000000 */  nop
    /* 2B0D50 003B0D50 00000000 */  nop
    /* 2B0D54 003B0D54 FAFFC014 */  bnez       $6, .L003B0D40
    /* 2B0D58 003B0D58 00000000 */   nop
    /* 2B0D5C 003B0D5C 00000000 */  nop
  .L003B0D60:
    /* 2B0D60 003B0D60 10E0E4AC */  sw         $4, -0x1FF0($7)
    /* 2B0D64 003B0D64 80D4E0AC */  sw         $0, -0x2B80($7)
    /* 2B0D68 003B0D68 10D4F1AC */  sw         $17, -0x2BF0($7)
    /* 2B0D6C 003B0D6C 20D4E3AC */  sw         $3, -0x2BE0($7)
    /* 2B0D70 003B0D70 00D4E5AC */  sw         $5, -0x2C00($7)
    /* 2B0D74 003B0D74 0F000000 */  sync
    /* 2B0D78 003B0D78 0F040000 */  sync.p
    /* 2B0D7C 003B0D7C 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0D80 003B0D80 0001C630 */  andi       $6, $6, 0x100
    /* 2B0D84 003B0D84 1400C010 */  beqz       $6, .L003B0DD8
    /* 2B0D88 003B0D88 00000000 */   nop
    /* 2B0D8C 003B0D8C 20E0E4AC */  sw         $4, -0x1FE0($7)
    /* 2B0D90 003B0D90 0F000000 */  sync
    /* 2B0D94 003B0D94 0F040000 */  sync.p
  .L003B0D98:
    /* 2B0D98 003B0D98 00000000 */  nop
    /* 2B0D9C 003B0D9C 00000000 */  nop
    /* 2B0DA0 003B0DA0 00000000 */  nop
    /* 2B0DA4 003B0DA4 00000000 */  nop
    /* 2B0DA8 003B0DA8 00000000 */  nop
    /* 2B0DAC 003B0DAC FAFF0041 */  bc0f       .L003B0D98 /* handwritten instruction */
    /* 2B0DB0 003B0DB0 00000000 */   nop
    /* 2B0DB4 003B0DB4 00000000 */  nop
  .L003B0DB8:
    /* 2B0DB8 003B0DB8 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0DBC 003B0DBC 0001C630 */  andi       $6, $6, 0x100
    /* 2B0DC0 003B0DC0 00000000 */  nop
    /* 2B0DC4 003B0DC4 00000000 */  nop
    /* 2B0DC8 003B0DC8 00000000 */  nop
    /* 2B0DCC 003B0DCC FAFFC014 */  bnez       $6, .L003B0DB8
    /* 2B0DD0 003B0DD0 00000000 */   nop
    /* 2B0DD4 003B0DD4 00000000 */  nop
  .L003B0DD8:
    /* 2B0DD8 003B0DD8 2D708001 */  daddu      $14, $12, $0
    /* 2B0DDC 003B0DDC 2D686001 */  daddu      $13, $11, $0
    /* 2B0DE0 003B0DE0 2D300000 */  daddu      $6, $0, $0
    /* 2B0DE4 003B0DE4 00000000 */  nop
  .L003B0DE8:
    /* 2B0DE8 003B0DE8 39000042 */  di /* handwritten instruction */
    /* 2B0DEC 003B0DEC 0F040000 */  sync.p
    /* 2B0DF0 003B0DF0 00600940 */  mfc0       $9, $12 /* handwritten instruction */
    /* 2B0DF4 003B0DF4 24482A01 */  and        $9, $9, $10
    /* 2B0DF8 003B0DF8 00000000 */  nop
    /* 2B0DFC 003B0DFC FAFF2015 */  bnez       $9, .L003B0DE8
    /* 2B0E00 003B0E00 00000000 */   nop
    /* 2B0E04 003B0E04 0000C1D9 */  lqc2       $vf1, (0x70000000 & 0xFFFF)($14)
    /* 2B0E08 003B0E08 1000C2D9 */  lqc2       $vf2, (0x70000010 & 0xFFFF)($14)
    /* 2B0E0C 003B0E0C 2000C3D9 */  lqc2       $vf3, (0x70000020 & 0xFFFF)($14)
    /* 2B0E10 003B0E10 3000C4D9 */  lqc2       $vf4, (0x70000030 & 0xFFFF)($14)
    /* 2B0E14 003B0E14 9E09E04B */  vmuli.xyzw $vf6, $vf1, $I
    /* 2B0E18 003B0E18 DE11E04B */  vmuli.xyzw $vf7, $vf2, $I
    /* 2B0E1C 003B0E1C 2822E74B */  vadd.xyzw  $vf8, $vf4, $vf7
    /* 2B0E20 003B0E20 A842E64B */  vadd.xyzw  $vf10, $vf8, $vf6
    /* 2B0E24 003B0E24 EC52E14B */  vsub.xyzw  $vf11, $vf10, $vf1
    /* 2B0E28 003B0E28 2C53E24B */  vsub.xyzw  $vf12, $vf10, $vf2
    /* 2B0E2C 003B0E2C 6C5BE24B */  vsub.xyzw  $vf13, $vf11, $vf2
    /* 2B0E30 003B0E30 3000AAF9 */  sqc2       $vf10, 0x30($13)
    /* 2B0E34 003B0E34 2000ABF9 */  sqc2       $vf11, 0x20($13)
    /* 2B0E38 003B0E38 0000ACF9 */  sqc2       $vf12, 0x0($13)
    /* 2B0E3C 003B0E3C 1000ADF9 */  sqc2       $vf13, 0x10($13)
    /* 2B0E40 003B0E40 4000CE25 */  addiu      $14, $14, %lo(D_70000040)
    /* 2B0E44 003B0E44 4000AD25 */  addiu      $13, $13, 0x40
    /* 2B0E48 003B0E48 38000042 */  ei /* handwritten instruction */
    /* 2B0E4C 003B0E4C 0100C624 */  addiu      $6, $6, 0x1
    /* 2B0E50 003B0E50 7F00C928 */  slti       $9, $6, 0x7F
    /* 2B0E54 003B0E54 E4FF2015 */  bnez       $9, .L003B0DE8
    /* 2B0E58 003B0E58 00000000 */   nop
    /* 2B0E5C 003B0E5C 00D0E68C */  lw         $6, -0x3000($7)
    /* 2B0E60 003B0E60 0001C630 */  andi       $6, $6, 0x100
    /* 2B0E64 003B0E64 0C00C010 */  beqz       $6, .L003B0E98
    /* 2B0E68 003B0E68 00000000 */   nop
    /* 2B0E6C 003B0E6C 20E0E5AC */  sw         $5, -0x1FE0($7)
    /* 2B0E70 003B0E70 0F000000 */  sync
    /* 2B0E74 003B0E74 0F040000 */  sync.p
  .L003B0E78:
    /* 2B0E78 003B0E78 00000000 */  nop
    /* 2B0E7C 003B0E7C 00000000 */  nop
    /* 2B0E80 003B0E80 00000000 */  nop
    /* 2B0E84 003B0E84 00000000 */  nop
    /* 2B0E88 003B0E88 00000000 */  nop
    /* 2B0E8C 003B0E8C FAFF0041 */  bc0f       .L003B0E78 /* handwritten instruction */
    /* 2B0E90 003B0E90 00000000 */   nop
    /* 2B0E94 003B0E94 00000000 */  nop
  .L003B0E98:
    /* 2B0E98 003B0E98 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0E9C 003B0E9C 0001C630 */  andi       $6, $6, 0x100
    /* 2B0EA0 003B0EA0 1500C010 */  beqz       $6, .L003B0EF8
    /* 2B0EA4 003B0EA4 00000000 */   nop
    /* 2B0EA8 003B0EA8 20E0E4AC */  sw         $4, -0x1FE0($7)
    /* 2B0EAC 003B0EAC 0F000000 */  sync
    /* 2B0EB0 003B0EB0 0F040000 */  sync.p
    /* 2B0EB4 003B0EB4 00000000 */  nop
  .L003B0EB8:
    /* 2B0EB8 003B0EB8 00000000 */  nop
    /* 2B0EBC 003B0EBC 00000000 */  nop
    /* 2B0EC0 003B0EC0 00000000 */  nop
    /* 2B0EC4 003B0EC4 00000000 */  nop
    /* 2B0EC8 003B0EC8 00000000 */  nop
    /* 2B0ECC 003B0ECC FAFF0041 */  bc0f       .L003B0EB8 /* handwritten instruction */
    /* 2B0ED0 003B0ED0 00000000 */   nop
    /* 2B0ED4 003B0ED4 00000000 */  nop
  .L003B0ED8:
    /* 2B0ED8 003B0ED8 00D4E68C */  lw         $6, -0x2C00($7)
    /* 2B0EDC 003B0EDC 0001C630 */  andi       $6, $6, 0x100
    /* 2B0EE0 003B0EE0 00000000 */  nop
    /* 2B0EE4 003B0EE4 00000000 */  nop
    /* 2B0EE8 003B0EE8 00000000 */  nop
    /* 2B0EEC 003B0EEC FAFFC014 */  bnez       $6, .L003B0ED8
    /* 2B0EF0 003B0EF0 00000000 */   nop
    /* 2B0EF4 003B0EF4 00000000 */  nop
  .L003B0EF8:
    /* 2B0EF8 003B0EF8 10E0E5AC */  sw         $5, -0x1FF0($7)
    /* 2B0EFC 003B0EFC 80D0E8AC */  sw         $8, -0x2F80($7)
    /* 2B0F00 003B0F00 10D0F2AC */  sw         $18, -0x2FF0($7)
    /* 2B0F04 003B0F04 20D0E3AC */  sw         $3, -0x2FE0($7)
    /* 2B0F08 003B0F08 00D0E5AC */  sw         $5, -0x3000($7)
    /* 2B0F0C 003B0F0C 0F000000 */  sync
    /* 2B0F10 003B0F10 0F040000 */  sync.p
    /* 2B0F14 003B0F14 81FF1026 */  addiu      $16, $16, -0x7F
    /* 2B0F18 003B0F18 C01F3126 */  addiu      $17, $17, 0x1FC0
    /* 2B0F1C 003B0F1C 7F00012A */  slti       $1, $16, 0x7F
    /* 2B0F20 003B0F20 67FF2010 */  beqz       $1, .L003B0CC0
    /* 2B0F24 003B0F24 C01F5226 */   addiu     $18, $18, 0x1FC0
  .L003B0F28:
    /* 2B0F28 003B0F28 D7000012 */  beqz       $16, .L003B1288
    /* 2B0F2C 003B0F2C 00000000 */   nop
    /* 2B0F30 003B0F30 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B0F34 003B0F34 00D0648C */  lw         $4, -0x3000($3)
    /* 2B0F38 003B0F38 00018430 */  andi       $4, $4, 0x100
    /* 2B0F3C 003B0F3C 0C008010 */  beqz       $4, .L003B0F70
    /* 2B0F40 003B0F40 00000000 */   nop
    /* 2B0F44 003B0F44 00010424 */  addiu      $4, $0, 0x100
    /* 2B0F48 003B0F48 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B0F4C 003B0F4C 0F000000 */  sync
    /* 2B0F50 003B0F50 0F040000 */  sync.p
  .L003B0F54:
    /* 2B0F54 003B0F54 00000000 */  nop
    /* 2B0F58 003B0F58 00000000 */  nop
    /* 2B0F5C 003B0F5C 00000000 */  nop
    /* 2B0F60 003B0F60 00000000 */  nop
    /* 2B0F64 003B0F64 00000000 */  nop
    /* 2B0F68 003B0F68 FAFF0041 */  bc0f       .L003B0F54 /* handwritten instruction */
    /* 2B0F6C 003B0F6C 00000000 */   nop
  .L003B0F70:
    /* 2B0F70 003B0F70 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B0F74 003B0F74 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B0F78 003B0F78 00018430 */  andi       $4, $4, 0x100
    /* 2B0F7C 003B0F7C 14008010 */  beqz       $4, .L003B0FD0
    /* 2B0F80 003B0F80 00000000 */   nop
    /* 2B0F84 003B0F84 00020424 */  addiu      $4, $0, 0x200
    /* 2B0F88 003B0F88 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B0F8C 003B0F8C 0F000000 */  sync
    /* 2B0F90 003B0F90 0F040000 */  sync.p
  .L003B0F94:
    /* 2B0F94 003B0F94 00000000 */  nop
    /* 2B0F98 003B0F98 00000000 */  nop
    /* 2B0F9C 003B0F9C 00000000 */  nop
    /* 2B0FA0 003B0FA0 00000000 */  nop
    /* 2B0FA4 003B0FA4 00000000 */  nop
    /* 2B0FA8 003B0FA8 FAFF0041 */  bc0f       .L003B0F94 /* handwritten instruction */
    /* 2B0FAC 003B0FAC 00000000 */   nop
    /* 2B0FB0 003B0FB0 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003B0FB4:
    /* 2B0FB4 003B0FB4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B0FB8 003B0FB8 00018430 */  andi       $4, $4, 0x100
    /* 2B0FBC 003B0FBC 00000000 */  nop
    /* 2B0FC0 003B0FC0 00000000 */  nop
    /* 2B0FC4 003B0FC4 00000000 */  nop
    /* 2B0FC8 003B0FC8 FAFF8014 */  bnez       $4, .L003B0FB4
    /* 2B0FCC 003B0FCC 00000000 */   nop
  .L003B0FD0:
    /* 2B0FD0 003B0FD0 00020624 */  addiu      $6, $0, 0x200
    /* 2B0FD4 003B0FD4 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B0FD8 003B0FD8 80281000 */  sll        $5, $16, 2
    /* 2B0FDC 003B0FDC 10E066AC */  sw         $6, -0x1FF0($3)
    /* 2B0FE0 003B0FE0 00010424 */  addiu      $4, $0, 0x100
    /* 2B0FE4 003B0FE4 80D460AC */  sw         $0, -0x2B80($3)
    /* 2B0FE8 003B0FE8 10D471AC */  sw         $17, -0x2BF0($3)
    /* 2B0FEC 003B0FEC 20D465AC */  sw         $5, -0x2BE0($3)
    /* 2B0FF0 003B0FF0 00D464AC */  sw         $4, -0x2C00($3)
    /* 2B0FF4 003B0FF4 0F000000 */  sync
    /* 2B0FF8 003B0FF8 0F040000 */  sync.p
    /* 2B0FFC 003B0FFC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B1000 003B1000 00018430 */  andi       $4, $4, 0x100
    /* 2B1004 003B1004 14008010 */  beqz       $4, .L003B1058
    /* 2B1008 003B1008 00000000 */   nop
    /* 2B100C 003B100C 20E066AC */  sw         $6, -0x1FE0($3)
    /* 2B1010 003B1010 0F000000 */  sync
    /* 2B1014 003B1014 0F040000 */  sync.p
  .L003B1018:
    /* 2B1018 003B1018 00000000 */  nop
    /* 2B101C 003B101C 00000000 */  nop
    /* 2B1020 003B1020 00000000 */  nop
    /* 2B1024 003B1024 00000000 */  nop
    /* 2B1028 003B1028 00000000 */  nop
    /* 2B102C 003B102C FAFF0041 */  bc0f       .L003B1018 /* handwritten instruction */
    /* 2B1030 003B1030 00000000 */   nop
    /* 2B1034 003B1034 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003B1038:
    /* 2B1038 003B1038 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B103C 003B103C 00018430 */  andi       $4, $4, 0x100
    /* 2B1040 003B1040 00000000 */  nop
    /* 2B1044 003B1044 00000000 */  nop
    /* 2B1048 003B1048 00000000 */  nop
    /* 2B104C 003B104C FAFF8014 */  bnez       $4, .L003B1038
    /* 2B1050 003B1050 00000000 */   nop
    /* 2B1054 003B1054 00000000 */  nop
  .L003B1058:
    /* 2B1058 003B1058 00700E3C */  lui        $14, (0x70001FC0 >> 16)
    /* 2B105C 003B105C 2A081000 */  slt        $1, $0, $16
    /* 2B1060 003B1060 C01FCD35 */  ori        $13, $14, (0x70001FC0 & 0xFFFF)
    /* 2B1064 003B1064 20002010 */  beqz       $1, .L003B10E8
    /* 2B1068 003B1068 2D300000 */   daddu     $6, $0, $0
    /* 2B106C 003B106C 0100043C */  lui        $4, (0x10000 >> 16)
  .L003B1070:
    /* 2B1070 003B1070 39000042 */  di /* handwritten instruction */
    /* 2B1074 003B1074 0F040000 */  sync.p
    /* 2B1078 003B1078 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2B107C 003B107C 24186400 */  and        $3, $3, $4
    /* 2B1080 003B1080 00000000 */  nop
    /* 2B1084 003B1084 FAFF6014 */  bnez       $3, .L003B1070
    /* 2B1088 003B1088 00000000 */   nop
    /* 2B108C 003B108C 0000C1D9 */  lqc2       $vf1, (0x70000000 & 0xFFFF)($14)
    /* 2B1090 003B1090 1000C2D9 */  lqc2       $vf2, (0x70000010 & 0xFFFF)($14)
    /* 2B1094 003B1094 2000C3D9 */  lqc2       $vf3, (0x70000020 & 0xFFFF)($14)
    /* 2B1098 003B1098 3000C4D9 */  lqc2       $vf4, (0x70000030 & 0xFFFF)($14)
    /* 2B109C 003B109C 9E09E04B */  vmuli.xyzw $vf6, $vf1, $I
    /* 2B10A0 003B10A0 DE11E04B */  vmuli.xyzw $vf7, $vf2, $I
    /* 2B10A4 003B10A4 2822E74B */  vadd.xyzw  $vf8, $vf4, $vf7
    /* 2B10A8 003B10A8 A842E64B */  vadd.xyzw  $vf10, $vf8, $vf6
    /* 2B10AC 003B10AC EC52E14B */  vsub.xyzw  $vf11, $vf10, $vf1
    /* 2B10B0 003B10B0 2C53E24B */  vsub.xyzw  $vf12, $vf10, $vf2
    /* 2B10B4 003B10B4 6C5BE24B */  vsub.xyzw  $vf13, $vf11, $vf2
    /* 2B10B8 003B10B8 3000AAF9 */  sqc2       $vf10, 0x30($13)
    /* 2B10BC 003B10BC 2000ABF9 */  sqc2       $vf11, 0x20($13)
    /* 2B10C0 003B10C0 0000ACF9 */  sqc2       $vf12, 0x0($13)
    /* 2B10C4 003B10C4 1000ADF9 */  sqc2       $vf13, 0x10($13)
    /* 2B10C8 003B10C8 4000CE25 */  addiu      $14, $14, %lo(D_70000040)
    /* 2B10CC 003B10CC 4000AD25 */  addiu      $13, $13, 0x40
    /* 2B10D0 003B10D0 38000042 */  ei /* handwritten instruction */
    /* 2B10D4 003B10D4 0100C624 */  addiu      $6, $6, 0x1
    /* 2B10D8 003B10D8 2A18D000 */  slt        $3, $6, $16
    /* 2B10DC 003B10DC E4FF6014 */  bnez       $3, .L003B1070
    /* 2B10E0 003B10E0 00000000 */   nop
    /* 2B10E4 003B10E4 00000000 */  nop
  .L003B10E8:
    /* 2B10E8 003B10E8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B10EC 003B10EC 00D0648C */  lw         $4, -0x3000($3)
    /* 2B10F0 003B10F0 00018430 */  andi       $4, $4, 0x100
    /* 2B10F4 003B10F4 0C008010 */  beqz       $4, .L003B1128
    /* 2B10F8 003B10F8 00000000 */   nop
    /* 2B10FC 003B10FC 00010424 */  addiu      $4, $0, 0x100
    /* 2B1100 003B1100 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B1104 003B1104 0F000000 */  sync
    /* 2B1108 003B1108 0F040000 */  sync.p
  .L003B110C:
    /* 2B110C 003B110C 00000000 */  nop
    /* 2B1110 003B1110 00000000 */  nop
    /* 2B1114 003B1114 00000000 */  nop
    /* 2B1118 003B1118 00000000 */  nop
    /* 2B111C 003B111C 00000000 */  nop
    /* 2B1120 003B1120 FAFF0041 */  bc0f       .L003B110C /* handwritten instruction */
    /* 2B1124 003B1124 00000000 */   nop
  .L003B1128:
    /* 2B1128 003B1128 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B112C 003B112C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B1130 003B1130 00018430 */  andi       $4, $4, 0x100
    /* 2B1134 003B1134 14008010 */  beqz       $4, .L003B1188
    /* 2B1138 003B1138 00000000 */   nop
    /* 2B113C 003B113C 00020424 */  addiu      $4, $0, 0x200
    /* 2B1140 003B1140 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2B1144 003B1144 0F000000 */  sync
    /* 2B1148 003B1148 0F040000 */  sync.p
  .L003B114C:
    /* 2B114C 003B114C 00000000 */  nop
    /* 2B1150 003B1150 00000000 */  nop
    /* 2B1154 003B1154 00000000 */  nop
    /* 2B1158 003B1158 00000000 */  nop
    /* 2B115C 003B115C 00000000 */  nop
    /* 2B1160 003B1160 FAFF0041 */  bc0f       .L003B114C /* handwritten instruction */
    /* 2B1164 003B1164 00000000 */   nop
    /* 2B1168 003B1168 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003B116C:
    /* 2B116C 003B116C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2B1170 003B1170 00018430 */  andi       $4, $4, 0x100
    /* 2B1174 003B1174 00000000 */  nop
    /* 2B1178 003B1178 00000000 */  nop
    /* 2B117C 003B117C 00000000 */  nop
    /* 2B1180 003B1180 FAFF8014 */  bnez       $4, .L003B116C
    /* 2B1184 003B1184 00000000 */   nop
  .L003B1188:
    /* 2B1188 003B1188 00010624 */  addiu      $6, $0, 0x100
    /* 2B118C 003B118C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2B1190 003B1190 C01F0524 */  addiu      $5, $0, 0x1FC0
    /* 2B1194 003B1194 10E066AC */  sw         $6, -0x1FF0($3)
    /* 2B1198 003B1198 80201000 */  sll        $4, $16, 2
    /* 2B119C 003B119C 80D065AC */  sw         $5, -0x2F80($3)
    /* 2B11A0 003B11A0 10D072AC */  sw         $18, -0x2FF0($3)
    /* 2B11A4 003B11A4 20D064AC */  sw         $4, -0x2FE0($3)
    /* 2B11A8 003B11A8 00D066AC */  sw         $6, -0x3000($3)
    /* 2B11AC 003B11AC 0F000000 */  sync
    /* 2B11B0 003B11B0 0F040000 */  sync.p
    /* 2B11B4 003B11B4 34000010 */  b          .L003B1288
    /* 2B11B8 003B11B8 00000000 */   nop
  .L003B11BC:
    /* 2B11BC 003B11BC 0100033C */  lui        $3, (0x10000 >> 16)
  .L003B11C0:
    /* 2B11C0 003B11C0 39000042 */  di /* handwritten instruction */
    /* 2B11C4 003B11C4 0F040000 */  sync.p
    /* 2B11C8 003B11C8 00600540 */  mfc0       $5, $12 /* handwritten instruction */
    /* 2B11CC 003B11CC 2428A300 */  and        $5, $5, $3
    /* 2B11D0 003B11D0 00000000 */  nop
    /* 2B11D4 003B11D4 FAFFA014 */  bnez       $5, .L003B11C0
    /* 2B11D8 003B11D8 00000000 */   nop
    /* 2B11DC 003B11DC 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2B11E0 003B11E0 00008344 */  mtc1       $3, $f0
    /* 2B11E4 003B11E4 00000344 */  mfc1       $3, $f0
    /* 2B11E8 003B11E8 00A8C348 */  ctc2.ni    $3, $vi21
    /* 2B11EC 003B11EC FF02004A */  vnop
    /* 2B11F0 003B11F0 FF02004A */  vnop
    /* 2B11F4 003B11F4 38000042 */  ei /* handwritten instruction */
    /* 2B11F8 003B11F8 2A081000 */  slt        $1, $0, $16
    /* 2B11FC 003B11FC 22002010 */  beqz       $1, .L003B1288
    /* 2B1200 003B1200 2D300000 */   daddu     $6, $0, $0
    /* 2B1204 003B1204 80200400 */  sll        $4, $4, 2
    /* 2B1208 003B1208 0100053C */  lui        $5, (0x10000 >> 16)
  .L003B120C:
    /* 2B120C 003B120C 00000000 */  nop
  .L003B1210:
    /* 2B1210 003B1210 39000042 */  di /* handwritten instruction */
    /* 2B1214 003B1214 0F040000 */  sync.p
    /* 2B1218 003B1218 00600340 */  mfc0       $3, $12 /* handwritten instruction */
    /* 2B121C 003B121C 24186500 */  and        $3, $3, $5
    /* 2B1220 003B1220 00000000 */  nop
    /* 2B1224 003B1224 FAFF6014 */  bnez       $3, .L003B1210
    /* 2B1228 003B1228 00000000 */   nop
    /* 2B122C 003B122C 000021DA */  lqc2       $vf1, 0x0($17)
    /* 2B1230 003B1230 100022DA */  lqc2       $vf2, 0x10($17)
    /* 2B1234 003B1234 200023DA */  lqc2       $vf3, 0x20($17)
    /* 2B1238 003B1238 300024DA */  lqc2       $vf4, 0x30($17)
    /* 2B123C 003B123C 9E09E04B */  vmuli.xyzw $vf6, $vf1, $I
    /* 2B1240 003B1240 DE11E04B */  vmuli.xyzw $vf7, $vf2, $I
    /* 2B1244 003B1244 2822E74B */  vadd.xyzw  $vf8, $vf4, $vf7
    /* 2B1248 003B1248 A842E64B */  vadd.xyzw  $vf10, $vf8, $vf6
    /* 2B124C 003B124C EC52E14B */  vsub.xyzw  $vf11, $vf10, $vf1
    /* 2B1250 003B1250 2C53E24B */  vsub.xyzw  $vf12, $vf10, $vf2
    /* 2B1254 003B1254 6C5BE24B */  vsub.xyzw  $vf13, $vf11, $vf2
    /* 2B1258 003B1258 30004AFA */  sqc2       $vf10, 0x30($18)
    /* 2B125C 003B125C 20004BFA */  sqc2       $vf11, 0x20($18)
    /* 2B1260 003B1260 00004CFA */  sqc2       $vf12, 0x0($18)
    /* 2B1264 003B1264 10004DFA */  sqc2       $vf13, 0x10($18)
    /* 2B1268 003B1268 21882702 */  addu       $17, $17, $7
    /* 2B126C 003B126C 21904402 */  addu       $18, $18, $4
    /* 2B1270 003B1270 38000042 */  ei /* handwritten instruction */
    /* 2B1274 003B1274 0100C624 */  addiu      $6, $6, 0x1
    /* 2B1278 003B1278 2A18D000 */  slt        $3, $6, $16
    /* 2B127C 003B127C E3FF6014 */  bnez       $3, .L003B120C
    /* 2B1280 003B1280 00000000 */   nop
    /* 2B1284 003B1284 00000000 */  nop
  .L003B1288:
    /* 2B1288 003B1288 3000BFDF */  ld         $31, 0x30($29)
    /* 2B128C 003B128C 2000B27B */  lq         $18, 0x20($29)
    /* 2B1290 003B1290 1000B17B */  lq         $17, 0x10($29)
    /* 2B1294 003B1294 0000B07B */  lq         $16, 0x0($29)
    /* 2B1298 003B1298 0800E003 */  jr         $31
    /* 2B129C 003B129C 4000BD27 */   addiu     $29, $29, 0x40
.size func_003b0b80, 0x720
