003c4140 addiu $sp, $sp, -0x30
003c4144 lui $v1, 0x88
003c4148 sd $ra, 0x10($sp)
003c414c lui $v0, 3
003c4150 sq $s0, 0x0($sp)
003c4154 ori $a1, $v0, 7
003c4158 lw $a0, -0x4920($gp)
003c415c addiu $v1, $v1, 0x72e0
003c4160 lui $v0, 0x88
003c4164 lw $v0, 0x73f8($v0)
003c4168 addu $v1, $v1, $a0
003c416c jalr $v0
003c4170 lw $a0, ($v1)
003c4174 move $s0, $v0
003c4178 beqz $s0, 0x3c4200
003c417c nop 
003c4180 addiu $a1, $zero, 0xff
003c4184 addiu $v0, $zero, 1
003c4188 sb $a1, 0x2c($sp)
003c418c lui $a0, 0x71
003c4190 sb $a1, 0x2d($sp)
003c4194 lui $a2, 0x71
003c4198 sb $a1, 0x2e($sp)
003c419c lui $v1, 0x71
003c41a0 sb $a1, 0x2f($sp)
003c41a4 addiu $a0, $a0, -0x5010
003c41a8 lbu $t2, 0x2c($sp)
003c41ac move $a1, $s0
003c41b0 lbu $t1, 0x2d($sp)
003c41b4 sh $v0, 0x18($s0)
003c41b8 lbu $t0, 0x2e($sp)
003c41bc lui $v0, 0x71
003c41c0 lbu $a3, 0x2f($sp)
003c41c4 sb $t2, 4($s0)
003c41c8 sb $t1, 5($s0)
003c41cc sb $t0, 6($s0)
003c41d0 sb $a3, 7($s0)
003c41d4 sw $zero, ($s0)
003c41d8 sw $zero, 8($s0)
003c41dc lwc1 $f2, -0x4ff8($a2)
003c41e0 lwc1 $f1, -0x4ff4($v1)
003c41e4 lwc1 $f0, -0x4ff0($v0)
003c41e8 swc1 $f2, 0xc($s0)
003c41ec swc1 $f1, 0x10($s0)
003c41f0 jal 0x3e3b70
003c41f4 swc1 $f0, 0x14($s0)
003c41f8 b 0x3c4204
003c41fc move $v0, $s0
003c4200 move $v0, $zero
003c4204 ld $ra, 0x10($sp)
003c4208 lq $s0, 0x0($sp)
003c420c jr $ra
003c4210 addiu $sp, $sp, 0x30
003c4214 nop 
003c4218 nop 
003c421c nop 
