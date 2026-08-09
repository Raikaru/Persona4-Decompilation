.section .text
.set noat
.set noreorder
glabel func_0050bd80
    /* 40BD80 0050BD80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BD84 0050BD84 0000BFFF */  sd         $31, 0x0($29)
    /* 40BD88 0050BD88 8685140C */  jal        func_00521618
    /* 40BD8C 0050BD8C 3C00848C */   lw        $4, 0x3C($4)
    /* 40BD90 0050BD90 07004010 */  beqz       $2, .L0050BDB0
    /* 40BD94 0050BD94 C9FE0424 */   addiu     $4, $0, -0x137
    /* 40BD98 0050BD98 3C2E140C */  jal        func_0050b8f0
    /* 40BD9C 0050BD9C 00000000 */   nop
    /* 40BDA0 0050BDA0 7600043C */  lui        $4, %hi(D_0075ECB8)
    /* 40BDA4 0050BDA4 8844140C */  jal        func_00511220
    /* 40BDA8 0050BDA8 B8EC8424 */   addiu     $4, $4, %lo(D_0075ECB8)
    /* 40BDAC 0050BDAC C9FE0224 */  addiu      $2, $0, -0x137
  .L0050BDB0:
    /* 40BDB0 0050BDB0 0000BFDF */  ld         $31, 0x0($29)
    /* 40BDB4 0050BDB4 0800E003 */  jr         $31
    /* 40BDB8 0050BDB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BDBC 0050BDBC 00000000 */  nop
.size func_0050bd80, 0x40
