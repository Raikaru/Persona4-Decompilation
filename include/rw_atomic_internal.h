#ifndef RW_ATOMIC_INTERNAL_H
#define RW_ATOMIC_INTERNAL_H

struct RpAtomic;
struct RwFrame;

/* RpAtomicSetFrame attaches the frame and marks the atomic's bounds dirty. */
struct RpAtomic *RpAtomicSetFrame(struct RpAtomic *atomic, struct RwFrame *frame);

#endif
