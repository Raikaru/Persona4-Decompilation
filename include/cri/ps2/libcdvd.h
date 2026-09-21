/*
 * libcdvd.h - the Sony CD/DVD declarations the CRI sources reach for.
 *
 * Sony's own header is not in this tree: the July 2005 SDK on hand keeps it
 * inside a Wise installer payload that is entropy-8.00 with no recoverable
 * streams, and neither 7z nor cabextract opens it. These declarations are
 * therefore written against the documented ABI (the layouts ps2dev/ps2sdk
 * reproduces, which must match Sony's or the IOP modules would not answer).
 *
 * That is not taken on trust. Every CRI function that touches one of these
 * structures is compared byte-for-byte against retail by build/adx_fid.py,
 * so a wrong field offset shows up immediately as a function that stops
 * matching. The layouts below are the ones under which those functions do
 * match.
 */
#ifndef CRI_SHIM_LIBCDVD_H
#define CRI_SHIM_LIBCDVD_H

typedef struct {
    unsigned int lsn;       /* file location */
    unsigned int size;      /* file size in bytes */
    char name[16];          /* file name */
    unsigned char date[8];  /* 1=secs 2=mins 3=hours 4=day 5=mon 6,7=year */
} sceCdlFILE;

typedef struct {
    unsigned char trycount;    /* retries before reporting an error */
    unsigned char spindlctrl;  /* spin/read speed */
    unsigned char datapattern; /* sector size selector */
    unsigned char pad;
} sceCdRMode;

typedef struct {
    unsigned char stat;
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char pad;
    unsigned char day;
    unsigned char month;
    unsigned char year;
} sceCdCLOCK;

#define SCECdComplete 2
#define SCECdNotReady 6

/* Drive error codes, in the ABI's own numbering. */
#define SCECdErFAIL   (-1)
#define SCECdErNO     0x00
#define SCECdErABRT   0x01
#define SCECdErCMD    0x10
#define SCECdErOPENS  0x11
#define SCECdErNODISC 0x12
#define SCECdErNORDY  0x13
#define SCECdErCUD    0x14
#define SCECdErIPI    0x20
#define SCECdErILI    0x21
#define SCECdErPRM    0x22
#define SCECdErREAD   0x30
#define SCECdErTRMOPN 0x31
#define SCECdErEOM    0x32
#define SCECdErREADCF 0xFD
#define SCECdErREADCFR 0xFE

extern int sceCdInit(int mode);
extern int sceCdRead(unsigned int lsn, unsigned int sectors, void *buffer,
                     sceCdRMode *mode);
extern int sceCdSync(int mode);
extern int sceCdGetError(void);
extern int sceCdSearchFile(sceCdlFILE *file, const char *name);
extern int sceCdDiskReady(int mode);
extern int sceCdStatus(void);

#endif /* CRI_SHIM_LIBCDVD_H */
