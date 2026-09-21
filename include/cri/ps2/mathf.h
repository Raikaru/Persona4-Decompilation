/*
 * mathf.h - the single-precision math entry points the CRI decoder uses.
 * See include/cri/ps2/libcdvd.h for provenance and validation.
 */
#ifndef CRI_SHIM_MATHF_H
#define CRI_SHIM_MATHF_H

extern float sqrtf(float x);
extern float fabsf(float x);
extern float sinf(float x);
extern float cosf(float x);
extern float powf(float x, float y);
extern float logf(float x);
extern float log10f(float x);
extern float expf(float x);
extern float floorf(float x);
extern float ceilf(float x);

#endif /* CRI_SHIM_MATHF_H */
