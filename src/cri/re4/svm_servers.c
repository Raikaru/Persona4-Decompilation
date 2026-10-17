/* CRI SVM server dispatch adapters for the eight server types. */
#include "cri_xpt.h"

extern Sint32 SVM_ExecSvrFunc(Sint32 svtype);

// FUN_004F1050
Sint32 func_004f1050(void)
{
	return SVM_ExecSvrFunc(0);
}

// FUN_004F1068
Sint32 func_004f1068(void)
{
	return SVM_ExecSvrFunc(1);
}

// FUN_004F1080
Sint32 func_004f1080(void)
{
	return SVM_ExecSvrFunc(2);
}

// FUN_004F1098
Sint32 func_004f1098(void)
{
	return SVM_ExecSvrFunc(3);
}

// FUN_004F10B0
Sint32 func_004f10b0(void)
{
	return SVM_ExecSvrFunc(4);
}

// FUN_004F10C8
Sint32 SVM_ExecSvrMain(void)
{
	return SVM_ExecSvrFunc(5);
}

// FUN_004F10E0
Sint32 func_004f10e0(void)
{
	return SVM_ExecSvrFunc(6);
}

// FUN_004F10F8
Sint32 func_004f10f8(void)
{
	return SVM_ExecSvrFunc(7);
}
