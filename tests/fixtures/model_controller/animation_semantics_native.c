/* Bounded host witnesses, not PS2/EE emulation or whole-owner execution. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
static uint32_t bits(float x){uint32_t b;memcpy(&b,&x,4);return b;}
static float real(uint32_t b){float x;memcpy(&x,&b,4);return x;}
static int old_default(float progress,int present){return (1.0f<=progress)||!present;}
static int retail_default(float progress,int present){return !(progress<1.0f)||!present;}
static int old_nonnegative(float direction){return 0.0f<=direction;}
static int retail_nonnegative(float direction){return !(direction<0.0f);}
int main(void){
 unsigned ticks,j,cases=0,old_differences=0,predicate_cases=0,finite_disagreements=0,nan_default_differences=0,nan_direction_differences=0;
 float fractions[]={0.0f,0.25f,0.5f,0.999f};
 uint32_t special[]={0xff800000u,0xbf800000u,0x80000000u,0,0x3f7fffffu,0x3f800000u,0x3f800001u,0x7f800000u,0x7fc00000u,0xffc12345u};
 const unsigned expected_default[]={0,0,0,0,0,1,1,1,1,1};
 const unsigned expected_nonnegative[]={0,0,1,1,1,1,1,1,1,1};
 for(ticks=1;ticks<=65535;ticks++){
  float stored=(float)ticks;uint32_t storage=bits(stored);float loaded=real(storage);
  if(loaded!=(float)ticks)return 2;
  for(j=0;j<4;j++){
   float corrected=fractions[j]+1.0f/loaded;
   float expected=fractions[j]+1.0f/(float)ticks;
   float old=fractions[j]+1.0f/(float)storage;
   if(bits(corrected)!=bits(expected)||!(corrected>fractions[j]))return 3;
   if(bits(old)!=bits(corrected))old_differences++;cases++;
  }
 }
 for(j=0;j<sizeof special/sizeof special[0];j++){
  float x=real(special[j]);int present;
  if(retail_nonnegative(x)!=(int)expected_nonnegative[j])return 4;
  if(isnan(x)){if(old_nonnegative(x)==retail_nonnegative(x))return 5;nan_direction_differences++;}
  else if(old_nonnegative(x)!=retail_nonnegative(x))finite_disagreements++;
  for(present=0;present<=1;present++){
   int a=old_default(x,present),b=retail_default(x,present);
   if(b!=(present?(int)expected_default[j]:1))return 6;
   if(isnan(x)&&present){if(a==b)return 7;nan_default_differences++;}
   else if(a!=b)finite_disagreements++;
   predicate_cases++;
  }
 }
 if(old_differences!=cases||finite_disagreements)return 8;
 printf("{\"nonzero_tick_values\":65535,\"progress_update_cases\":%u,\"incorrect_integer_view_rejected_cases\":%u,\"predicate_pointer_cases\":%u,\"ordered_predicate_disagreements\":%u,\"nan_nonnull_default_differences\":%u,\"nan_direction_differences\":%u,\"zero_duration_division_executed\":false,\"sample_30_tick_correct_increment\":%.9g,\"sample_30_tick_old_increment\":%.9g,\"scope\":\"Host f32 field-storage/update and selection-predicate witnesses only; no EE FPU emulation, NaN reachability, callbacks or owner execution\"}\n",cases,old_differences,predicate_cases,finite_disagreements,nan_default_differences,nan_direction_differences,1.0f/30.0f,1.0f/(float)bits(30.0f));
 return 0;
}
