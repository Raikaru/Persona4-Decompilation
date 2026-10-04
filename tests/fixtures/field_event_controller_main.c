static s32 run(void) { return func_00172e00(task); }
int main(void) {
    _Static_assert(sizeof(FldEventAttack)==0x20,"attack stride");
    _Static_assert(sizeof(FldEventActor)==0x750,"actor stride");
    _Static_assert(sizeof(FldEventBattle)==0x3c,"battle request size");
    _Static_assert(sizeof(FldEventSnapshot)==0x70,"camera snapshot size");
    _Static_assert(__builtin_offsetof(FldEventWork,battle)==0x50,"battle request offset");
    _Static_assert(__builtin_offsetof(FldEventWork,snapshot)==0x90,"camera snapshot offset");
    _Static_assert(__builtin_offsetof(FldEventWork,viewColor)==0x120,"view color offset");
    _Static_assert(__builtin_offsetof(FldEventWork,fieldEffect)==0x13c,"field task offset");
    for(unsigned index=0;index<2;index++) {
        reset(0);work.attackIndex=index;work.frameCounter=73;
        CHECK(run()==1 && work.state==1 && work.attack==&attacks[index] && work.frameCounter==0);
        CHECK((s32)args[ID_func_00479940][2]==attacks[index].animation);
        CHECK(args[ID_func_00479940][3]==2 && args[ID_func_00479940][4]==0x20 && initialFrame==3);
    }
    for(unsigned mask=0;mask<256;mask++) for(unsigned mode=0;mode<8;mode++) {
        reset(1);nearMask=mask;work.frameCounter=3;fovResult=mode&1;results[ID_RpRandom]=mode&2 ? 30:31;
        flags[0x140c]=(mode&4)!=0;flags[0x140d]=(mode==3);
        for(unsigned i=0;i<15;i++) if((i+mode)%5==0 && i!=0)enemy(i)->active=0;
        CHECK(run()==1 && work.state==4 && work.frameCounter==4);
        CHECK(calls[ID_func_0045af60]==1 && calls[ID_func_0014e8c0]==0);
        CHECK(lastTarget[0]==11 && lastTarget[1]==121 && lastTarget[2]==31);
        unsigned count=0;
        for(unsigned i=1;i<15 && count<2;i++) if(enemy(i)->active && ((mask>>i)&1)) {
            CHECK(work.nearby[count]==enemy(i));CHECK(work.battle.enemies[count+1]==enemy(i)->unit);++count;
        }
        for(unsigned i=count;i<2;i++)CHECK(work.nearby[i]==NULL && work.battle.enemies[i+1]==NULL);
        u16 expected=8;
        if(!fovResult || results[ID_RpRandom]%100 < 30)expected|=16;
        if(flags[0x140c])expected|=16;
        else if(flags[0x140d])expected=(expected&~16)|1;
        CHECK(work.battle.flags==expected);
    }
    for(unsigned step=0;step<=40;step++) {
        reset(1);animationFrame=(f32)step*0.5f+0.25f;
        CHECK(run()==1);CHECK(work.state==((step/2>=10 && step/2<15)?4:2));
    }
    reset(1);attacks[0].hitFrame=0x80000000;animationFrame=2147483648.0f;
    CHECK(run()==1 && work.state==4);
    for(unsigned kind=0;kind<4;kind++) {
        reset(1);if(kind==0)found=NULL;else if(kind==1)found->flags=2;
        else {animationFrame=15;interaction=NULL;}
        if(kind==3)animationFrame=20;
        CHECK(run()==1);CHECK(calls[ID_func_0014e8c0]==0);
        if(kind==3)CHECK(work.state==100 && work.motionState==0 && calls[ID_func_00479940]==1);
        else CHECK(work.state==1);
    }
    reset(1);animationFrame=9;CHECK(run()==1 && work.state==2);
    CHECK(lastTarget[0]==10 && lastTarget[1]==120 && lastTarget[2]==30);
    for(unsigned mask=0;mask<8;mask++) {
        reset(1);for(unsigned i=1;i<4;i++) if(!(mask&(1<<(i-1))))party(i)->unit=NULL;
        CHECK(run()==1);unsigned count=1;
        for(unsigned i=1;i<4;i++)if(party(i)->unit)CHECK(work.battle.party[count++]==&units[i]);
        for(;count<4;count++)CHECK(work.battle.party[count]==NULL);
    }
    for(unsigned state=2;state<=4;state++) for(unsigned ready=0;ready<2;ready++) {
        reset(state);results[ID_func_0014e8c0]=ready?5:4;work.battleFlags=(s16)0x9234;
        CHECK(run()==1);
        if(state==3 || ready)CHECK(work.state==5);else CHECK(work.state==state);
        if(state==2 && ready)checkBattle();
        if(state==3)CHECK(work.battle.flags==0x9234);
    }
    static const f32 chanceValues[]={-3.0f,-1.0f,0.0f,1.0f,30.5f,100.0f};
    for(unsigned c=0;c<6;c++)for(unsigned half=0;half<2;half++)for(unsigned roll=0;roll<100;roll++) {
        reset(2);*(f32*)(kindTable+0x38)=chanceValues[c];results[ID_func_00172ba0]=half;
        results[ID_RpRandom]=roll;CHECK(run()==1 && work.state==5);
        s32 threshold=(s32)chanceValues[c];if(half)threshold/=2;
        CHECK((work.battle.flags&1)==(roll<(u32)threshold));
    }
    for(unsigned gate=0;gate<3;gate++) {
        reset(5);results[ID_func_001fc270]=gate!=0;results[ID_func_00163fc0]=gate==2;
        *(s32*)(world+4)=0x104;*(s32*)(world+0x18)=0x118;*(s32*)(world+0x1c)=0x11c;
        *(s32*)(world+0x2c)=0x12c;*(s32*)(world+0x30)=0x130;work.fieldEffect=0x13c;
        results[ID_func_0014a200]=1;D_007E8060[1]=0x200;D_007E8060[15]=0x20f;
        CHECK(run()==1 && work.state==(gate==2?6:5));
        if(gate) { CHECK(work.viewColor.r==11 && work.viewColor.g==22 && work.viewColor.b==33 && work.viewColor.a==44);
          CHECK(work.environmentColor.r==5 && work.environmentColor.g==6 && work.environmentColor.b==7);
          CHECK(work.viewFog==123 && work.environmentFog==321); }
        if(gate==2) { for(unsigned i=0;i<28;i++)CHECK(work.snapshot.words[i]==0xA0B00000+i);
          CHECK(calls[ID_func_00452080]==5 && calls[ID_func_00151f80]==2);
          CHECK(*(s32*)(world+4)==0 && *(s32*)(world+0x18)==0 && *(s32*)(world+0x1c)==0 && *(s32*)(world+0x2c)==0);
          CHECK(D_007E8060[1]==0 && D_007E8060[15]==0 && work.fieldEffect==0); }
    }
    for(unsigned state=6;state<10;state++){reset(state);CHECK(run()==1 && work.state==state+1);}
    reset(10);results[ID_func_00192e90]=0x777;CHECK(run()==1 && work.state==11 && work.battleTask==0x777);
    for(unsigned gate=0;gate<8;gate++){reset(11);work.battleTask=3;results[ID_func_00452490]=gate&1;
      results[ID_func_0014ef40]=(gate>>1)&1;results[ID_func_0014ef80]=(gate>>2)&1;
      CHECK(run()==1);CHECK(work.state==((gate==6)?12:11));}
    for(unsigned dead=0;dead<2;dead++)for(unsigned mode=0;mode<2;mode++) {
        reset(12);work.target->unit->count=0x8000;work.nearby[0]=enemy(1);work.nearby[1]=enemy(2);
        results[ID_func_002319f0]=dead;work.returnMode=mode;
        CHECK(run()==(dead&&mode?0:1));CHECK(work.targetHasUnits==1);
        CHECK(work.target==NULL && work.nearby[0]==NULL && work.nearby[1]==NULL && calls[ID_func_00164020]==3);
        CHECK(work.state==(dead?99:13));if(dead&&mode)CHECK(work.mode==2);
    }
    for(unsigned field=0;field<80;field++) {
        reset(13);results[ID_func_0014ef40]=1;results[ID_func_00156170]=field;
        results[ID_func_0015ff20]=0x123;results[ID_func_001601e0]=0x456;results[ID_func_00477e80]=0x789;
        CHECK(run()==1 && work.state==14 && work.fieldTask==0x123 && work.environmentTask==0x456);
        CHECK(*(u32*)(scene+0x88)==0x80000000);
        unsigned special=field==44 || field==46 || field==47 || field==48 || field==64 || field==66 || field==67 || field==68;
        CHECK(calls[ID_func_00477e80]==special);CHECK(work.modelFile==(special?0x789:0));
        CHECK((s32)args[ID_func_00144e10][0]==-1 && (s32)args[ID_func_00144ed0][0]==-32767);
    }
    for(unsigned gates=0;gates<32;gates++) {
        reset(14);work.fieldTask=1;work.environmentTask=2;work.modelFile=3;
        results[ID_func_00160000]=gates&1;results[ID_func_001602a0]=(gates>>1)&1;
        results[ID_func_00165300]=(gates>>2)&1;results[ID_func_00144f60]=(gates>>3)&1;results[ID_func_004782b0]=(gates>>4)&1;
        CHECK(run()==1 && work.state==(gates==31?15:14));
    }
    reset(15);results[ID_func_00165be0]=1;results[ID_func_00186640]=0x2c0;results[ID_func_0016e2e0]=0x40;
    results[ID_func_002ae630]=0x180;results[ID_func_00175ea0]=0x140;
    work.viewColor=(FldEventColor){41,42,43,44};work.environmentColor=(FldEventColor){51,52,53,54};
    work.viewFog=987;work.environmentFog=654;for(unsigned i=0;i<28;i++)work.snapshot.words[i]=i+100;
    CHECK(run()==1 && work.state==16);CHECK(*(s32*)(world+0x2c)==0x2c0 && *(s32*)(world+4)==0x40 && *(s32*)(world+0x18)==0x180);
    CHECK(work.fieldEffect==0x140 && work.resource==resource);CHECK(args[ID_func_00457140][0]==41 && args[ID_func_00457140][3]==0);
    CHECK(iGpffffba4c==51 && iGpffffba50==52 && iGpffffba54==53 && iGpffffba58==0 && iGpffffba6c==654);
    CHECK(*(f32*)(camera+0x88)==987);for(unsigned i=0;i<28;i++)CHECK(capturedSnapshot.words[i]==i+100);
    for(unsigned ready=0;ready<2;ready++) {
        reset(16);results[ID_func_00166c30]=ready;CHECK(run()==1 && work.state==16+ready);
        reset(17);results[ID_func_00122720]=ready;results[ID_func_0029db50]=0x222;CHECK(run()==1 && work.state==17+ready);
        if(ready)CHECK(work.scriptTask==0x222);
    }
    for(unsigned live=0;live<2;live++)for(unsigned flag=0;flag<3;flag++) {
        reset(18);results[ID_func_00452490]=live;flags[0xc25]=flag;
        CHECK(run()==((!live&&flag==1)?0:1));
        if(live)CHECK(work.state==18);else if(flag==1)CHECK(work.eventPending==1 && flags[0xc25]==0);
        else CHECK(work.state==100 && work.motionState==0 && args[ID_func_00182310][0]==0);
    }
    for(unsigned exists=0;exists<2;exists++) {
        reset(100);*(s32*)(world+0x1c)=exists;results[ID_func_0018df60]=0x321;
        CHECK(run()==0 && *(s32*)(world+0x1c)==(exists?1:0x321));CHECK(calls[ID_func_0018df60]==!exists);
    }
    reset(99);CHECK(run()==1 && work.state==99);reset(-1);CHECK(run()==1 && work.state==-1);
    native32_text("field event controller cases ");native32_number(cases);native32_text("\n");return 0;
}
