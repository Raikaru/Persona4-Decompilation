/* Host IEEE-binary32 witnesses. Not EE FPU emulation or complete owner execution. */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
static uint32_t bits(float x) { uint32_t r; memcpy(&r,&x,4);return r; }
static float from_bits(uint32_t x) { float r;memcpy(&r,&x,4);return r; }
static int old_upper(float angle) { return 360.0f<angle; }
static int retail_upper(float angle) { return !(angle<=360.0f); }
int main(void) {
 uint32_t sample,seed=0x471370u; unsigned finite_disagreements=0,graph_differences=0,nan_distinctions=0,finite_steps=0;
 float coefficient=from_bits(0x42652ee1u);
 uint32_t special[]={0xff800000u,0xc3b40000u,0xc3340000u,0x80000000u,0,0x43340000u,0x43b3ffffu,0x43b40000u,0x43b40001u,0x7f800000u,0x7fc00000u,0xffc12345u};
 const unsigned expected_upper[]={0,0,0,0,0,0,0,0,1,1,1,1};
 for(sample=0;sample<sizeof special/sizeof special[0];sample++) {
  float x=from_bits(special[sample]);int a=old_upper(x),b=retail_upper(x);
  if(b!=(int)expected_upper[sample])return 8;
  if((special[sample]==0||special[sample]==0x80000000u)&&bits(x)!=special[sample])return 9;
  if(isnan(x)) { if(a!=0||b!=1)return 2;nan_distinctions++; }
  else if(a!=b)return 3;
  /* Never execute an unbounded wrap. One controlled step makes the distinction explicit. */
  if(b) { float next=x-360.0f;if(isnan(x)&&!isnan(next))return 4;if(isinf(x)&&!isinf(next))return 5; }
 }
 for(sample=0;sample<8192;sample++) {
  float radians,product,separate,fused,angle;unsigned steps=0;
  seed=seed*1664525u+1013904223u;radians=((float)(seed&0xffffffu)/16777216.0f-0.5f)*6.283185307179586f;
  product=coefficient*radians;separate=product+180.0f;fused=fmaf(coefficient,radians,180.0f);
  if(bits(separate)!=bits(fused))graph_differences++;
  angle=radians*360.0f;
  if(old_upper(angle)!=retail_upper(angle))finite_disagreements++;
  while(angle<0.0f&&steps<16) { angle+=360.0f;steps++; }
  while(retail_upper(angle)&&steps<16) { angle-=360.0f;steps++; }
  if(steps>=16||!(angle>=0.0f&&angle<=360.0f))return 6;finite_steps+=steps;
 }
 if(finite_disagreements||!graph_differences||nan_distinctions!=2)return 7;
 printf("{\"finite_samples\":8192,\"finite_predicate_disagreements\":%u,\"finite_wrap_steps\":%u,\"wrap_step_cap\":16,\"special_inputs\":12,\"quiet_nan_predicate_distinctions\":%u,\"host_fused_vs_separate_differences\":%u,\"coefficient_bits\":\"0x42652ee1\",\"scope\":\"Host IEEE-binary32 graph distinction and bounded predicate/step witness; not EE FPU emulation, NaN reachability proof, or owner execution\"}\n",finite_disagreements,finite_steps,nan_distinctions,graph_differences);
 return 0;
}
