# This plugin helps IDA Pro to disassemble PS2 Emotion Engine COP2 instructions
# Author: oct0xor

import idaapi
import ida_ida
import ida_allins
import ida_idp
import ida_bytes
import ida_ua

ITYPE_START = ida_idp.CUSTOM_INSN_ITYPE + 0x100
MNEM_WIDTH = 13

class COP2_disassemble(idaapi.IDP_Hooks):

	def __init__(self):
		idaapi.IDP_Hooks.__init__(self)

		class idef:
			def __init__(self, opcode, name, ft, dt, dest, cmt):
				self.opcode = opcode
				self.name = name
				self.ft = ft
				self.dt = dt
				self.dest = dest
				self.cmt = cmt

		self.itable = [
			# Coprocessor Calculation Instructions
			idef(0x1FD, "VABS",     3,  1, True,  "Absolute"),
			idef(0x028, "VADD",     1,  2, True,  "Addition"),
			idef(0x022, "VADDi",    1,  3, True,  "ADD broadcast I register"),
			idef(0x020, "VADDq",    1,  4, True,  "ADD broadcast Q register"),
			idef(0x000, "VADDx",    0,  2, True,  "ADD broadcast bc field"),
			idef(0x001, "VADDy",    0,  2, True,  "ADD broadcast bc field"),
			idef(0x002, "VADDz",    0,  2, True,  "ADD broadcast bc field"),
			idef(0x003, "VADDw",    0,  2, True,  "ADD broadcast bc field"),
			idef(0x2BC, "VADDA",    3,  5, True,  "ADD output to ACC"),
			idef(0x23E, "VADDAi",   3,  6, True,  "ADD output to ACC broadcast I register"),
			idef(0x23C, "VADDAq",   3,  7, True,  "ADD output to ACC broadcast Q register"),
			idef(0x03C, "VADDAx",   2,  8, True,  "ADD output to ACC broadcast bc field"),
			idef(0x03D, "VADDAy",   2,  8, True,  "ADD output to ACC broadcast bc field"),
			idef(0x03E, "VADDAz",   2,  8, True,  "ADD output to ACC broadcast bc field"),
			idef(0x03F, "VADDAw",   2,  8, True,  "ADD output to ACC broadcast bc field"),
			idef(0x02C, "VSUB",     1,  2, True,  "Subtraction"),
			idef(0x026, "VSUBi",    1,  3, True,  "SUB broadcast I register"),
			idef(0x024, "VSUBq",    1,  4, True,  "SUB broadcast Q register"),
			idef(0x004, "VSUBx",    0,  2, True,  "SUB broadcast bc field"),
			idef(0x005, "VSUBy",    0,  2, True,  "SUB broadcast bc field"),
			idef(0x006, "VSUBz",    0,  2, True,  "SUB broadcast bc field"),
			idef(0x007, "VSUBw",    0,  2, True,  "SUB broadcast bc field"),
			idef(0x2FC, "VSUBA",    3,  5, True,  "SUB output to ACC"),
			idef(0x27E, "VSUBAi",   3,  6, True,  "SUB output to ACC broadcast I register"),
			idef(0x27C, "VSUBAq",   3,  7, True,  "SUB output to ACC broadcast Q register"),
			idef(0x07C, "VSUBAx",   2,  8, True,  "SUB output to ACC broadcast bc field"),
			idef(0x07D, "VSUBAy",   2,  8, True,  "SUB output to ACC broadcast bc field"),
			idef(0x07E, "VSUBAz",   2,  8, True,  "SUB output to ACC broadcast bc field"),
			idef(0x07F, "VSUBAw",   2,  8, True,  "SUB output to ACC broadcast bc field"),
			idef(0x02A, "VMUL",     1,  2, True,  "Multiply"),
			idef(0x01E, "VMULi",    1,  3, True,  "MUL broadcast I register"),
			idef(0x01C, "VMULq",    1,  4, True,  "MUL broadcast Q register"),
			idef(0x018, "VMULx",    0,  2, True,  "MUL broadcast bc field"),
			idef(0x019, "VMULy",    0,  2, True,  "MUL broadcast bc field"),
			idef(0x01A, "VMULz",    0,  2, True,  "MUL broadcast bc field"),
			idef(0x01B, "VMULw",    0,  2, True,  "MUL broadcast bc field"),
			idef(0x2BE, "VMULA",    3,  5, True,  "MUL output to ACC"),
			idef(0x1FE, "VMULAi",   3,  6, True,  "MUL output to ACC broadcast I register"),
			idef(0x1FC, "VMULAq",   3,  7, True,  "MUL output to ACC broadcast Q register"),
			idef(0x1BC, "VMULAx",   2,  8, True,  "MUL output to ACC broadcast bc field"),
			idef(0x1BD, "VMULAy",   2,  8, True,  "MUL output to ACC broadcast bc field"),
			idef(0x1BE, "VMULAz",   2,  8, True,  "MUL output to ACC broadcast bc field"),
			idef(0x1BF, "VMULAw",   2,  8, True,  "MUL output to ACC broadcast bc field"),
			idef(0x029, "VMADD",    1,  2, True,  "MUL and ADD"),
			idef(0x023, "VMADDi",   1,  3, True,  "MUL and ADD broadcast I register"),
			idef(0x021, "VMADDq",   1,  4, True,  "MUL and ADD broadcast Q register"),
			idef(0x008, "VMADDx",   0,  2, True,  "MUL and ADD broadcast bc field"),
			idef(0x009, "VMADDy",   0,  2, True,  "MUL and ADD broadcast bc field"),
			idef(0x00A, "VMADDz",   0,  2, True,  "MUL and ADD broadcast bc field"),
			idef(0x00B, "VMADDw",   0,  2, True,  "MUL and ADD broadcast bc field"),
			idef(0x2BD, "VMADDA",   3,  5, True,  "MUL and ADD output to ACC"),
			idef(0x23F, "VMADDAi",  3,  6, True,  "MUL and ADD output to ACC broadcast I register"),
			idef(0x23D, "VMADDAq",  3,  7, True,  "MUL and ADD output to ACC broadcast Q register"),
			idef(0x0BC, "VMADDAx",  2,  8, True,  "MUL and ADD output to ACC broadcast bc field"),
			idef(0x0BD, "VMADDAy",  2,  8, True,  "MUL and ADD output to ACC broadcast bc field"),
			idef(0x0BE, "VMADDAz",  2,  8, True,  "MUL and ADD output to ACC broadcast bc field"),
			idef(0x0BF, "VMADDAw",  2,  8, True,  "MUL and ADD output to ACC broadcast bc field"),
			idef(0x02D, "VMSUB",    1,  2, True,  "MUL and SUB"),
			idef(0x027, "VMSUBi",   1,  3, True,  "MUL and SUB broadcast I register"),
			idef(0x025, "VMSUBq",   1,  4, True,  "MUL and SUB broadcast Q register"),
			idef(0x00C, "VMSUBx",   0,  2, True,  "MUL and SUB broadcast bc field"),
			idef(0x00D, "VMSUBy",   0,  2, True,  "MUL and SUB broadcast bc field"),
			idef(0x00E, "VMSUBz",   0,  2, True,  "MUL and SUB broadcast bc field"),
			idef(0x00F, "VMSUBw",   0,  2, True,  "MUL and SUB broadcast bc field"),
			idef(0x2FD, "VMSUBA",   3,  5, True,  "MUL and SUB output to ACC"),
			idef(0x27F, "VMSUBAi",  3,  6, True,  "MUL and SUB output to ACC broadcast I register"),
			idef(0x27D, "VMSUBAq",  3,  7, True,  "MUL and SUB output to ACC broadcast Q register"),
			idef(0x0FC, "VMSUBAx",  2,  8, True,  "MUL and SUB output to ACC broadcast bc field"),
			idef(0x0FD, "VMSUBAy",  2,  8, True,  "MUL and SUB output to ACC broadcast bc field"),
			idef(0x0FE, "VMSUBAz",  2,  8, True,  "MUL and SUB output to ACC broadcast bc field"),
			idef(0x0FF, "VMSUBAw",  2,  8, True,  "MUL and SUB output to ACC broadcast bc field"),
			idef(0x02B, "VMAX",     1,  2, True,  "Maximum"),
			idef(0x01D, "VMAXi",    1,  3, True,  "Maximum broadcast I register"),
			idef(0x010, "VMAXx",    0,  2, True,  "Maximum broadcast bc field"),
			idef(0x011, "VMAXy",    0,  2, True,  "Maximum broadcast bc field"),
			idef(0x012, "VMAXz",    0,  2, True,  "Maximum broadcast bc field"),
			idef(0x013, "VMAXw",    0,  2, True,  "Maximum broadcast bc field"),
			idef(0x02F, "VMINI",    1,  2, True,  "Minimum"),
			idef(0x01F, "VMINIi",   1,  3, True,  "Minimum broadcast I register"),
			idef(0x014, "VMINIx",   0,  2, True,  "Minimum broadcast bc field"),
			idef(0x015, "VMINIy",   0,  2, True,  "Minimum broadcast bc field"),
			idef(0x016, "VMINIz",   0,  2, True,  "Minimum broadcast bc field"),
			idef(0x017, "VMINIw",   0,  2, True,  "Minimum broadcast bc field"),
			idef(0x2FE, "VOPMULA",  3,  9, False, "Outer product MULA"),
			idef(0x02E, "VOPMSUB",  1, 10, False, "Outer product MSUB"),
			idef(0x2FF, "VNOP",     3,  0, False, "No operation"),
			idef(0x17C, "VFTOI0",   3,  1, True,  "Float to integer, fixed point 0 bit"),
			idef(0x17D, "VFTOI4",   3,  1, True,  "Float to integer, fixed point 4 bits"),
			idef(0x17E, "VFTOI12",  3,  1, True,  "Float to integer, fixed point 12 bits"),
			idef(0x17F, "VFTOI15",  3,  1, True,  "Float to integer, fixed point 15 bits"),
			idef(0x13C, "VITOF0",   3,  1, True,  "Integer to float, fixed point 0 bit"),
			idef(0x13D, "VITOF4",   3,  1, True,  "Integer to float, fixed point 4 bits"),
			idef(0x13E, "VITOF12",  3,  1, True,  "Integer to float, fixed point 12 bits"),
			idef(0x13F, "VITOF15",  3,  1, True,  "Integer to float, fixed point 15 bits"),
			idef(0x1FF, "VCLIP",    3, 11, False, "Clipping"),
			idef(0x3BC, "VDIV",     4, 12, False, "Floating divide"),
			idef(0x3BD, "VSQRT",    4, 13, False, "Floating square-root"),
			idef(0x3BE, "VRSQRT",   4, 12, False, "Floating reciprocal square-root"),
			idef(0x030, "VIADD",    1, 14, False, "Integer ADD"),
			idef(0x032, "VIADDI",   5, 15, False, "Integer ADD immediate"),
			idef(0x034, "VIAND",    1, 14, False, "Integer AND"),
			idef(0x035, "VIOR",     1, 14, False, "Integer OR"),
			idef(0x031, "VISUB",    1, 14, False, "Integer SUB"),
			idef(0x33C, "VMOVE",    3, 16, True,  "Move floating register"),
			idef(0x3FD, "VMFIR",    3, 17, True,  "Move from integer register"),
			idef(0x3FC, "VMTIR",    4, 18, False, "Move to integer register"),
			idef(0x33D, "VMR32",    3, 16, True,  "Rotate right 32 bits"),
			idef(0x37E, "VLQD",     3, 17, True,  "Load quadword with pre-decrement"),
			idef(0x37C, "VLQI",     3, 17, True,  "Load quadword with post-increment"),
			idef(0x37F, "VSQD",     3, 19, True,  "Store quadword with pre-decrement"),
			idef(0x37D, "VSQI",     3, 19, True,  "Store quadword with post-increment"),
			idef(0x3FE, "VILWR",    3, 20, True,  "Integer load word register"),
			idef(0x3FF, "VISWR",    3, 20, True,  "Integer store word register"),
			idef(0x43E, "VRINIT",   4, 21, False, "Random-unit init R register"),
			idef(0x43D, "VRGET",    3, 22, True,  "Random-unit get R register"),
			idef(0x43C, "VRNEXT",   3, 22, True,  "Random-unit next M sequence"),
			idef(0x43F, "VRXOR",    4, 21, False, "Random-unit XOR R register"),
			idef(0x3BF, "VWAITQ",   3,  0, False, "Wait Q register"),
		]
		
		self.CFC2_ITABLE_ID  = ida_allins.MIPS_cfc2
		self.CTC2_ITABLE_ID  = ida_allins.MIPS_ctc2
		self.QMFC2_ITABLE_ID = ida_allins.MIPS_qmfc2
		self.QMTC2_ITABLE_ID = ida_allins.MIPS_qmtc2
		self.LQC2_ITABLE_ID  = ida_allins.MIPS_lqc2
		self.SQC2_ITABLE_ID  = ida_allins.MIPS_sqc2

		self.VF_REG = 0
		self.VI_REG = 1
		self.VF_REG_WITH_F = 2
		self.CTL_REG = 3

		self.reg_types = {
			0:  [],
			1:  [self.VF_REG,  self.VF_REG],
			2:  [self.VF_REG,  self.VF_REG, self.VF_REG],
			3:  [self.VF_REG,  self.VF_REG, self.CTL_REG],
			4:  [self.VF_REG,  self.VF_REG, self.CTL_REG],
			5:  [self.CTL_REG, self.VF_REG, self.VF_REG],
			6:  [self.CTL_REG, self.VF_REG, self.CTL_REG],
			7:  [self.CTL_REG, self.VF_REG, self.CTL_REG],
			8:  [self.CTL_REG, self.VF_REG, self.VF_REG],
			9:  [self.CTL_REG, self.VF_REG, self.VF_REG],
			10: [self.VF_REG,  self.VF_REG, self.VF_REG],
			11: [self.VF_REG,  self.VF_REG],
			12: [self.CTL_REG, self.VF_REG_WITH_F, self.VF_REG_WITH_F],
			13: [self.CTL_REG, self.VF_REG_WITH_F],
			14: [self.VI_REG,  self.VI_REG, self.VI_REG],
			15: [self.VI_REG,  self.VI_REG],
			16: [self.VF_REG,  self.VF_REG],
			17: [self.VF_REG,  self.VI_REG],
			18: [self.VI_REG,  self.VF_REG_WITH_F],
			19: [self.VF_REG,  self.VI_REG],
			20: [self.VI_REG,  self.VI_REG],
			21: [self.CTL_REG, self.VF_REG_WITH_F],
			22: [self.VF_REG,  self.CTL_REG],
		}

		self.itable.sort(key=lambda x: x.opcode)

		for entry in self.itable:
			entry.name = entry.name.lower()

		for i in range(len(self.itable)):
			if (self.itable[i].opcode & 0xF00 == 0x100):
				self.pos_0x100 = i
				break

		for i in range(len(self.itable)):
			if (self.itable[i].opcode & 0xF00 == 0x200):
				self.pos_0x200 = i
				break

		for i in range(len(self.itable)):
			if (self.itable[i].opcode & 0xF00 == 0x300):
				self.pos_0x300 = i
				break

		for i in range(len(self.itable)):
			if (self.itable[i].opcode & 0xF00 == 0x400):
				self.pos_0x400 = i
				break

	def set_regs_2(self, insn, a, b):
		insn.Op1.type = ida_ua.o_idpspec1
		insn.Op1.reg = a
		insn.Op2.type = ida_ua.o_idpspec1
		insn.Op2.reg = b

	def set_regs_3(self, insn, a, b, c):
		insn.Op1.type = ida_ua.o_idpspec1
		insn.Op1.reg = a
		insn.Op2.type = ida_ua.o_idpspec1
		insn.Op2.reg = b
		insn.Op3.type = ida_ua.o_idpspec1
		insn.Op3.reg = c

	def decode_type_0(self, insn, dword):
		insn.Op1.type = ida_ua.o_void

	def decode_type_1(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, fsreg)

	def decode_type_2(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		fdreg = (dword >> 6) & 0x1F
		self.set_regs_3(insn, fdreg, fsreg, ftreg)

	def decode_type_3(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		fdreg = (dword >> 6) & 0x1F
		self.set_regs_3(insn, fdreg, fsreg, ord('I'))

	def decode_type_4(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		fdreg = (dword >> 6) & 0x1F
		self.set_regs_3(insn, fdreg, fsreg, ord('Q'))

	def decode_type_5(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('A'), fsreg, ftreg)

	def decode_type_6(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('A'), fsreg, ord('I'))

	def decode_type_7(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('A'), fsreg, ord('Q'))

	def decode_type_8(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('A'), fsreg, ftreg)

	def decode_type_9(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('A'), fsreg, ftreg)

	def decode_type_10(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		fdreg = (dword >> 6) & 0x1F
		self.set_regs_3(insn, fdreg, fsreg, ftreg)

	def decode_type_11(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, fsreg, ftreg)

	def decode_type_12(self, insn, dword):
		ftf = (dword >> 0x17) & 3
		fsf = (dword >> 0x15) & 3
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_3(insn, ord('Q'), fsreg | (fsf << 8), ftreg | (ftf << 8))

	def decode_type_13(self, insn, dword):
		ftf = (dword >> 0x17) & 3
		fsf = (dword >> 0x15) & 3
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ord('Q'), ftreg | (ftf << 8))

	def decode_type_14(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		fdreg = (dword >> 6) & 0x1F
		self.set_regs_3(insn, fdreg, fsreg, ftreg)

	def decode_type_15(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		imm = (dword >> 6) & 0x1F
		insn.Op1.type = ida_ua.o_idpspec1
		insn.Op1.reg = ftreg
		insn.Op2.type = ida_ua.o_idpspec1
		insn.Op2.reg = fsreg
		insn.Op3.type = ida_ua.o_imm
		insn.Op3.value = imm

	def decode_type_16(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, fsreg)

	def decode_type_17(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, fsreg)

	def decode_type_18(self, insn, dword):
		ftf = (dword >> 0x17) & 3
		fsf = (dword >> 0x15) & 3
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, fsreg | (fsf << 8))

	def decode_type_19(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, fsreg, ftreg)

	def decode_type_20(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, fsreg)

	def decode_type_21(self, insn, dword):
		ftf = (dword >> 0x17) & 3
		fsf = (dword >> 0x15) & 3
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ord('R'), fsreg | (fsf << 8))

	def decode_type_22(self, insn, dword):
		ftreg = (dword >> 0x10) & 0x1F
		fsreg = (dword >> 0xB) & 0x1F
		self.set_regs_2(insn, ftreg, ord('R'))	

	def set_reg_type(self, op, reg_type):
		op.specval = reg_type

	def decode_instruction(self, index, insn, dword):

		insn.itype = ITYPE_START + index

		decoder = getattr(self, 'decode_type_%d' % self.itable[index].dt)
		decoder(insn, dword)

		regs = self.reg_types[self.itable[index].dt]

		if (len(regs) == 2):
			self.set_reg_type(insn.Op1, regs[0])
			self.set_reg_type(insn.Op2, regs[1])

		elif (len(regs) == 3):
			self.set_reg_type(insn.Op1, regs[0])
			self.set_reg_type(insn.Op2, regs[1])
			self.set_reg_type(insn.Op3, regs[2])

		insn.size = 4

	def ev_ana_insn(self, insn):

		dword = ida_bytes.get_wide_dword(insn.ea)

		if (dword >> 0x19 == 0x25):

			if (dword & 0x3C == 0x3C):
				opcode = dword & 0x7FF
			else:
				opcode = dword & 0x3F

			pos = 0
			if (opcode & 0xF00 == 0x100):
				pos = self.pos_0x100
			elif (opcode & 0xF00 == 0x200):
				pos = self.pos_0x200
			elif (opcode & 0xF00 == 0x300):
				pos = self.pos_0x300
			elif (opcode & 0xF00 == 0x400):
				pos = self.pos_0x400

			found = False
			index = 0
			for i in range(pos, len(self.itable)):
				if (self.itable[i].opcode == opcode):
					found = True
					index = i
					break

			if (not found):
				return 0

			self.decode_instruction(index, insn, dword)

		return insn.size

	#def ev_get_autocmt(self, insn):
	#	if (insn.itype >= ITYPE_START and insn.itype < ITYPE_START + len(self.itable)):
	#		return self.itable[insn.itype-ITYPE_START].cmt
	#	return 0

	def ev_emu_insn(self, insn):
		#if (insn.itype >= ITYPE_START and insn.itype < ITYPE_START + len(self.itable)):
		#	return 1
		return 0

	def decode_reg_field(self, val):
		return ["x", "y", "z", "w"][val]

	def get_register(self, op):

		if (op.specval == self.VF_REG):
			return "$vf%d" % op.reg
		elif (op.specval == self.VI_REG):
			return "$vi%d" % op.reg
		elif (op.specval == self.VF_REG_WITH_F):
			return "$vf%d.%s" % (op.reg & 0xFF, self.decode_reg_field(op.reg >> 8))
		elif (op.specval == self.CTL_REG):
			return "$%c" % op.reg
		else:
			return "UNK"

	def ev_out_operand(self, ctx, op):

		if (op.type == ida_ua.o_idpspec1):

			# First we need to fix instructions (badly) disassembled by mips.dll
			if (ctx.insn.itype == self.CFC2_ITABLE_ID and op.n == 1):
				ctx.out_register("$vi%d" % op.reg)
			elif (ctx.insn.itype == self.CTC2_ITABLE_ID and op.n == 1):
				ctx.out_register("$vi%d" % op.reg)
			elif (ctx.insn.itype == self.QMFC2_ITABLE_ID and op.n == 1):
				ctx.out_register("$vf%d" % op.reg)
			elif (ctx.insn.itype == self.QMTC2_ITABLE_ID and op.n == 1):
				ctx.out_register("$vf%d" % op.reg)
			elif (ctx.insn.itype == self.LQC2_ITABLE_ID and op.n == 0):
				ctx.out_register("$vf%d" % op.reg)
			elif (ctx.insn.itype == self.SQC2_ITABLE_ID and op.n == 0):
				ctx.out_register("$vf%d" % op.reg)
			elif (ctx.insn.itype >= ITYPE_START and ctx.insn.itype < ITYPE_START + len(self.itable)):
				ctx.out_register(self.get_register(op))
			else:
				return 0

			return 1

		return 0

	def decode_dest(self, dword):

		dest = (dword >> 0x15) & 0xF 

		s = "."
		if ((dest >> 3) & 1):
			s += "x"
		if ((dest >> 2) & 1):
			s += "y"
		if ((dest >> 1) & 1):
			s += "z"
		if (dest & 1):
			s += "w"

		return s

	def ev_out_mnem(self, ctx):
		if (ctx.insn.itype >= ITYPE_START and ctx.insn.itype < ITYPE_START + len(self.itable)):

			dest = ""
			if (self.itable[ctx.insn.itype-ITYPE_START].dest):
				dest = self.decode_dest(ida_bytes.get_wide_dword(ctx.insn.ea))

			ctx.out_custom_mnem(self.itable[ctx.insn.itype-ITYPE_START].name, MNEM_WIDTH, dest)
			return 1

		# We do this to fix width of other instructions
		ctx.out_mnem(MNEM_WIDTH)
		return 1

class emotionengine_plugin_t(idaapi.plugin_t):
	flags = idaapi.PLUGIN_HIDE
	comment = ""
	help = ""
	wanted_name = "PS2 Emotion Engine COP2 instructions disassembler"
	wanted_hotkey = ""

	def __init__(self):
		self.cop2 = None

	def init(self):
		
		if (idaapi.ph.id == idaapi.PLFM_MIPS and ida_ida.inf_get_procname() == 'r5900l'):
			self.cop2 = COP2_disassemble()
			self.cop2.hook()
			print("PS2 Emotion Engine COP2 instructions disassembler is loaded")
			return idaapi.PLUGIN_KEEP

		return idaapi.PLUGIN_SKIP

	def run(self, arg):
		pass

	def term(self):
		if (self.cop2 != None):
			self.cop2.unhook()
			self.cop2 = None

def PLUGIN_ENTRY():
	return emotionengine_plugin_t()
