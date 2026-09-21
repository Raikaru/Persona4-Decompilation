#include "cri_xpt.h"

/* Dolby Pro Logic II encoder (PL2ENC). Every function of this unit was dead-stripped by the linker;
 * only the build string, the Q12 gain table and the error strings of the stripped bodies survive. */

const Char8 pl2enc_build[] = "\nPL2ENC Ver.1.01 Build:Oct  8 2004 13:32:36\n";

const Sint32 pl2enc_gain_tbl[256] = {
	4096, 4096, 4096, 4095, 4095, 4094, 4093, 4092,
	4091, 4090, 4088, 4087, 4085, 4083, 4081, 4078,
	4076, 4073, 4071, 4068, 4065, 4062, 4058, 4055,
	4051, 4047, 4043, 4039, 4035, 4030, 4026, 4021,
	4016, 4011, 4006, 4000, 3995, 3989, 3983, 3977,
	3971, 3965, 3959, 3952, 3945, 3938, 3931, 3924,
	3917, 3909, 3902, 3894, 3886, 3878, 3870, 3861,
	3853, 3844, 3835, 3826, 3817, 3808, 3799, 3789,
	3779, 3770, 3760, 3749, 3739, 3729, 3718, 3707,
	3697, 3686, 3675, 3663, 3652, 3640, 3629, 3617,
	3605, 3593, 3581, 3568, 3556, 3543, 3530, 3517,
	3504, 3491, 3478, 3464, 3451, 3437, 3423, 3409,
	3395, 3381, 3367, 3352, 3337, 3323, 3308, 3293,
	3278, 3262, 3247, 3232, 3216, 3200, 3184, 3168,
	3152, 3136, 3120, 3103, 3086, 3070, 3053, 3036,
	3019, 3002, 2984, 2967, 2950, 2932, 2914, 2896,
	2878, 2860, 2842, 2824, 2805, 2787, 2768, 2750,
	2731, 2712, 2693, 2674, 2654, 2635, 2616, 2596,
	2576, 2557, 2537, 2517, 2497, 2477, 2456, 2436,
	2416, 2395, 2375, 2354, 2333, 2312, 2291, 2270,
	2249, 2228, 2207, 2185, 2164, 2142, 2121, 2099,
	2077, 2055, 2033, 2011, 1989, 1967, 1945, 1922,
	1900, 1878, 1855, 1832, 1810, 1787, 1764, 1741,
	1718, 1695, 1672, 1649, 1626, 1603, 1579, 1556,
	1532, 1509, 1485, 1462, 1438, 1414, 1390, 1366,
	1343, 1319, 1295, 1271, 1246, 1222, 1198, 1174,
	1150, 1125, 1101, 1076, 1052, 1027, 1003, 978,
	954, 929, 904, 880, 855, 830, 805, 780,
	756, 731, 706, 681, 656, 631, 606, 581,
	556, 530, 505, 480, 455, 430, 405, 379,
	354, 329, 304, 278, 253, 228, 203, 177,
	152, 127, 101, 76, 51, 25, 0, -1,
};

static Sint32 pl2enc_init_count = 0;
void (*pl2enc_err_func)(void *obj, Char8 *msg) = NULL;
void *pl2enc_err_obj = NULL;
static Sint32 pl2enc_work = 0;

typedef struct {
	Sint32 wksize;
} PL2ENC_PRM;

// Reports an encoder error through the registered callback.
// FUN_004EA798
static void pl2enc_err(Char8 *msg)
{
	if (pl2enc_err_func != NULL) {
		pl2enc_err_func(pl2enc_err_obj, msg);
	}
}

// Dead: gain 0..255 through the Q12 table.
Sint32 PL2ENC_SetGain(PL2ENC_PRM *prm, Sint32 gain)
{
	if (prm == NULL) {
		pl2enc_err("E03091601 : NULL pointer is specified.");
		return -1;
	}
	if (gain < 0 || gain > 255) {
		pl2enc_err("E03091602 : Illegal parameter is specified.");
		return -1;
	}
	prm->wksize = pl2enc_gain_tbl[gain];
	return 0;
}

// Dead: encoder mode 0..3.
Sint32 PL2ENC_SetMode(PL2ENC_PRM *prm, Sint32 mode)
{
	if (prm == NULL) {
		pl2enc_err("E03090306 : NULL pointer is specified.");
		return -1;
	}
	if (mode < 0 || mode > 3) {
		pl2enc_err("E03090307 : Illegal parameter is specified.");
		return -1;
	}
	prm->wksize = mode;
	return 0;
}

// Dead: encoder creation (work size check).
Sint32 PL2ENC_Create(PL2ENC_PRM *prm, void *work, Sint32 wksize)
{
	if (prm == NULL || work == NULL) {
		pl2enc_err("E03090101 : NULL pointer is specified.");
		return -1;
	}
	if (wksize < prm->wksize) {
		pl2enc_err("E03090102 : Work size is too short.");
		return -1;
	}
	pl2enc_init_count++;
	return 0;
}

// Dead: attach to an existing work.
Sint32 PL2ENC_Attach(PL2ENC_PRM *prm, void *work, Sint32 wksize)
{
	if (wksize < prm->wksize) {
		pl2enc_err("E03091001 : Work size is too short.");
		return -1;
	}
	pl2enc_work = wksize;
	return 0;
}
