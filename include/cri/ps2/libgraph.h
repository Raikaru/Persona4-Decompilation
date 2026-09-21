/*
 * libgraph.h - the one graphics entry point the CRI PS2 output path uses.
 * See include/cri/ps2/libcdvd.h for provenance and validation.
 */
#ifndef CRI_SHIM_LIBGRAPH_H
#define CRI_SHIM_LIBGRAPH_H

extern void *sceGsSyncVCallback(void *callback);
extern int sceGsSyncV(int mode);

#endif /* CRI_SHIM_LIBGRAPH_H */
