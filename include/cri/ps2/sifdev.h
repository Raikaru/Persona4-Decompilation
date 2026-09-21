/*
 * sifdev.h - the Sony IOP file-service declarations the CRI sources use.
 * See include/cri/ps2/libcdvd.h for why these are written rather than
 * vendored, and how they are validated.
 */
#ifndef CRI_SHIM_SIFDEV_H
#define CRI_SHIM_SIFDEV_H

#define SCE_SEEK_SET 0
#define SCE_SEEK_CUR 1
#define SCE_SEEK_END 2

#define SCE_RDONLY 0x0001
#define SCE_WRONLY 0x0002
#define SCE_RDWR   0x0003
#define SCE_NBLOCK 0x0010
#define SCE_CREAT  0x0200
#define SCE_TRUNC  0x0400
#define SCE_NOWAIT 0x8000

#define SCE_FS_EXECUTING 1
#define SCE_FS_COMPLETED 0

extern int sceOpen(const char *name, int flags, ...);
extern int sceClose(int fd);
extern int sceRead(int fd, void *buf, int size);
extern int sceWrite(int fd, const void *buf, int size);
extern int sceLseek(int fd, int offset, int whence);
extern int sceIoctl(int fd, int request, void *data);
extern int sceRemove(const char *name);
extern int sceSifLoadModule(const char *path, int arglen, const char *args);

#endif /* CRI_SHIM_SIFDEV_H */
