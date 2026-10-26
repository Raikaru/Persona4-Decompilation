#ifndef H_CDVD_H
#define H_CDVD_H

#include "type.h"

struct HCdvd;

/* Returns the load state of the file behind `cdvd`. */
extern u32 H_Cdvd_IsFileLoaded(struct HCdvd* cdvd);
/* Releases the file behind `cdvd`. */
extern u32 H_Cdvd_Destroy(struct HCdvd* cdvd);

/* File-device probe callbacks receive an unused device object and the path. */
extern s32 H_Cdvd_ProbeFile(void *unused, const char *path);

#endif
