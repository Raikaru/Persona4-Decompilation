#include "cri_xpt.h"

/* ADX decoder (3-bit variant). The functions were dead-stripped by the linker; the constant pool
 * (65536.0f, 0.7f, the int->float conversion magic) remains. */

Sint32 adx_decode_output_mono_flag;

// Dead: yields the 65536.0f constant of the stripped 3-bit decoder.
Float32 ADXDCD3_Scale(Sint32 v)
{
	return 65536.0f;
}

// Dead: yields the 0.7f filter coefficient constant.
Float32 ADXDCD3_Coef(Sint32 v)
{
	return 0.7f;
}

// Dead: keeps the int->float conversion magic and the mono flag word.
Float32 ADXDCD3_ToFloat(Sint32 v)
{
	adx_decode_output_mono_flag = v;
	return (Float32)v;
}
