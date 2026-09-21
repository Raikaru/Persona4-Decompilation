/*
 * sif.h - Sony SIF DMA declarations. See include/cri/ps2/libcdvd.h for
 * provenance and validation.
 */
#ifndef CRI_SHIM_SIF_H
#define CRI_SHIM_SIF_H

typedef struct t_sceSifDmaData {
    void *data;
    void *addr;
    unsigned int size;
    unsigned int mode;
} sceSifDmaData;

extern unsigned int sceSifSetDma(sceSifDmaData *sdd, int len);
extern int sceSifDmaStat(unsigned int id);

#endif /* CRI_SHIM_SIF_H */
