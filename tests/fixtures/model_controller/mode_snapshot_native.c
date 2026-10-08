/* Host hierarchy-mode action model; no renderer, callback or owner execution. */
#include <stdint.h>
#include <stdio.h>
static unsigned entry_actions(uint32_t entry,int has_frame){
 unsigned actions=0;if(!has_frame)return 0;
 if(entry&0x1000){actions|=1;if(!(entry&0x2000))actions|=2;}
 if(entry&0x2000){actions|=(entry&0x4000)?8:4;actions|=16;}
 return actions;
}
static unsigned snapshot_actions(int update,int concatenate,int world,int has_frame){
 unsigned actions=0;if(!has_frame)return 0;
 if(update){actions|=1;if(!world)actions|=2;}
 if(world){actions|=concatenate?8:4;actions|=16;}
 return actions;
}
int main(void){
 uint32_t low;unsigned high,node,cases=0,mutation_distinctions=0;
 for(low=0;low<65536;low++)for(high=0;high<2;high++){
  uint32_t entry=low|(high?0xffff0000u:0),live=entry;
  int update=entry&0x1000,concatenate=entry&0x4000,world=entry&0x2000;
  for(node=0;node<4;node++){
   int frame=node&1;unsigned a,b;
   live=entry^0x7000u; /* A simulated external memory mutation, not a callback run. */
   a=entry_actions(entry,frame);b=snapshot_actions(update,concatenate,world,frame);
   if(a!=b)return 2;
   if(frame&&entry_actions(live,frame)!=b)mutation_distinctions++;
   cases++;
  }
 }
 if(!mutation_distinctions)return 3;
 printf("{\"entry_flag_values\":131072,\"node_action_cases\":%u,\"mismatches\":0,\"simulated_external_mutation_distinctions\":%u,\"scope\":\"Host original-entry versus named-mask snapshot action model; no callbacks, owner or PS2 execution\"}\n",cases,mutation_distinctions);
 return 0;
}
