/* Contiguous ADX stream callbacks; private lock adapters are distinct from the public bind locks. */
#include "cri_xpt.h"

extern void SVM_Lock(void);
extern void SVM_Unlock(void);
extern void func_004f1278(void);

// FUN_004D1880
void func_004d1880(void)
{
	SVM_Lock();
}

// FUN_004D1898
void func_004d1898(void)
{
	SVM_Unlock();
}

// FUN_004D18B0
void func_004d18b0(void)
{
	func_004f1278();
}

// FUN_004D18C8
void func_004d18c8(void)
{
}

// FUN_004D18D0
void func_004d18d0(void)
{
}
