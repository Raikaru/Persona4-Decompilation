/* Bounded value-storage witness; does not run PS2 owner or callbacks. */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
typedef struct { float x,y,z; } RwV3d;
typedef struct { RwV3d right; uint32_t flags; RwV3d up; uint32_t pad1; RwV3d at; uint32_t pad2; RwV3d pos; uint32_t pad3; } RwMatrix;
typedef union { float value[4]; uint32_t bits[4]; } ControllerQuat;
typedef struct { uint32_t before; RwMatrix value; uint32_t after; } GuardedMatrix;
typedef struct { uint32_t before; ControllerQuat value; uint32_t after; } GuardedQuat;
typedef char MatrixSize[(sizeof(RwMatrix)==64)?1:-1];
typedef char MatrixFlags[(offsetof(RwMatrix,flags)==12)?1:-1];
typedef char QuaternionSize[(sizeof(ControllerQuat)==16)?1:-1];
static void matrix_copy(RwMatrix *out,const RwMatrix *in) { *out=*in; }
static void quat_copy(ControllerQuat *out,const ControllerQuat *in) { *out=*in; }
int main(void) {
 uint32_t state=0x471370, words[16]; unsigned sample,word,phase; unsigned rejected=0;
 for(sample=0;sample<8192;sample++) {
  RwMatrix source; ControllerQuat quat; GuardedMatrix output[5]; GuardedQuat qout[2];
  for(word=0;word<16;word++) { state=state*1664525u+1013904223u;words[word]=state; }
  memcpy(&source,words,64);memcpy(&quat,words,16);
  for(phase=0;phase<5;phase++) { memset(&output[phase],0xa5,sizeof output[phase]);matrix_copy(&output[phase].value,&source); }
  for(phase=0;phase<2;phase++) { memset(&qout[phase],0xa5,sizeof qout[phase]);quat_copy(&qout[phase].value,&quat); }
  memset(&source,0,64);memset(&quat,0,16);
  for(phase=0;phase<5;phase++) if(memcmp(&output[phase].value,words,64)||output[phase].before!=0xa5a5a5a5||output[phase].after!=0xa5a5a5a5) return 2;
  for(phase=0;phase<2;phase++) if(memcmp(&qout[phase].value,words,16)||qout[phase].before!=0xa5a5a5a5||qout[phase].after!=0xa5a5a5a5) return 3;
  output[0].value.flags ^= 1; if(memcmp(&output[0].value,words,64)) rejected++;
 }
 printf("{\"samples\":8192,\"matrix_copies\":40960,\"quaternion_copies\":16384,\"copied_words\":720896,\"mismatches\":0,\"guards_preserved\":true,\"source_mutation_independence\":true,\"flags_negative_controls_rejected\":%u,\"scope\":\"Isolated host object-storage witness only; no owner or PS2 execution\"}\n",rejected);
 return 0;
}
