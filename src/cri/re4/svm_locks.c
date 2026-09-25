/* CRI SVM typed lock adapters, linked as one contiguous retail source unit. */
#include "cri_xpt.h"

extern void func_004f0518(Sint32 type);
extern void func_004f0578(Sint32 type);

// FUN_004F0608
void SVM_Lock(void)
{
	func_004f0518(1);
}

// FUN_004F0620
void SVM_Unlock(void)
{
	func_004f0578(1);
}

// FUN_004F0638
void func_004f0638(void)
{
	func_004f0518(2);
}

// FUN_004F0650
void func_004f0650(void)
{
	func_004f0518(3);
}

// FUN_004F0668
void func_004f0668(void)
{
	func_004f0518(4);
}

// FUN_004F0680
void func_004f0680(void)
{
	func_004f0518(5);
}

// FUN_004F0698
void func_004f0698(void)
{
	func_004f0518(1000);
}

// FUN_004F06B0
void func_004f06b0(void)
{
	func_004f0578(2);
}

// FUN_004F06C8
void func_004f06c8(void)
{
	func_004f0578(3);
}

// FUN_004F06E0
void func_004f06e0(void)
{
	func_004f0578(4);
}

// FUN_004F06F8
void func_004f06f8(void)
{
	func_004f0578(5);
}

// FUN_004F0710
void func_004f0710(void)
{
	func_004f0578(1000);
}
