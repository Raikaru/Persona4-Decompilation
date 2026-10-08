/* Isolated HAnim parent-stack transitions; no owner, pointer ABI or PS2 runtime. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
typedef struct { uint32_t slots[31]; uint32_t parent,current; unsigned cursor; } State;
static void previous(State *s,uint32_t flags) {
 uint32_t selected=s->parent;flags&=3;
 if(flags!=3) { selected=s->current;
  if(flags==2) { s->slots[s->cursor]=s->parent;s->cursor++; }
  else if(flags==1) { s->cursor--;selected=s->slots[s->cursor]; }
  else if(flags!=0) selected=s->parent;
 }
 s->parent=selected;
}
static void recovered(State *s,uint32_t flags) {
 switch(flags&3) {
 case 0:s->parent=s->current;break;
 case 1:s->cursor--;s->parent=s->slots[s->cursor];break;
 case 2:s->slots[s->cursor++]=s->parent;s->parent=s->current;break;
 case 3:break;
 }
}
int main(void) {
 unsigned flags,depth,i;unsigned long cases=0,both=0;
 for(flags=0;flags<65536;flags++) for(depth=1;depth<=30;depth++) {
  State a,b,original;uint32_t expectedParent;unsigned expectedCursor;
  memset(&a,0,sizeof a);for(i=0;i<31;i++)a.slots[i]=0x10203040u+4*i;
  a.parent=0x55667788u;a.current=0x11223344u;a.cursor=depth;b=original=a;
  previous(&a,flags);recovered(&b,flags);
  if(memcmp(&a,&b,sizeof a))return 2;
  expectedCursor=depth+(flags%4==2)-(flags%4==1);
  expectedParent=flags%4==1?original.slots[depth-1]:flags%4==3?original.parent:original.current;
  if(b.cursor!=expectedCursor||b.parent!=expectedParent)return 3;
  for(i=0;i<31;i++)if(b.slots[i]!=((flags%4==2&&i==depth)?original.parent:original.slots[i]))return 4;
  if(flags%4==3) { if(memcmp(&b,&original,sizeof b))return 5;both++; }
  cases++;
 }
 printf("{\"cases\":%lu,\"all_16bit_flags\":true,\"valid_initial_cursor_min\":1,\"valid_initial_cursor_max\":30,\"mismatches\":0,\"both_bits_unchanged_cases\":%lu,\"scope\":\"Host parent-stack transition model with address tokens; no owner or PS2 execution, no underflow or unwritten-slot claim\"}\n",cases,both);
 return 0;
}
