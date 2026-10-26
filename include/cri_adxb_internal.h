#ifndef CRI_ADXB_INTERNAL_H
#define CRI_ADXB_INTERNAL_H

/* Decoder and stream-joint handles are opaque at the forwarding boundary. */
void ADXB_SetAhxInSj(void *decoder, void *inputJoint);

#endif
