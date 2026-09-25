/* CRI SVM server dispatch adapters for the eight server types. */
#include "cri_xpt.h"

extern Sint32 func_004f0ef0(Sint32 svtype);

// FUN_004F1050
Sint32 func_004f1050(void)
{
	return func_004f0ef0(0);
}

// FUN_004F1068
Sint32 func_004f1068(void)
{
	return func_004f0ef0(1);
}

// FUN_004F1080
Sint32 func_004f1080(void)
{
	return func_004f0ef0(2);
}

// FUN_004F1098
Sint32 func_004f1098(void)
{
	return func_004f0ef0(3);
}

// FUN_004F10B0
Sint32 func_004f10b0(void)
{
	return func_004f0ef0(4);
}

// FUN_004F10C8
Sint32 SVM_ExecSvrMain(void)
{
	return func_004f0ef0(5);
}

// FUN_004F10E0
Sint32 func_004f10e0(void)
{
	return func_004f0ef0(6);
}

// FUN_004F10F8
Sint32 func_004f10f8(void)
{
	return func_004f0ef0(7);
}
