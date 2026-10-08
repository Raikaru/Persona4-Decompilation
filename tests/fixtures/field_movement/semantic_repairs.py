#!/usr/bin/env python3
"""Safe tests of extracted source fragments; never executes the indeterminate target."""
import re


def fixture_from_source(source):
    s=source;s=s[s.index('s32 func_00174e10(u8 *arg0)\n{'):];s=s[:s.index('\n#else')]
    types=s[s.index('    typedef struct {'):s.index('    extern u16 D_008C024C')]
    start=s.index('                s32 quotient =');end=s.index('                *(u8 **)(h + 0x138)',start)
    rounding=s[start:end]
    assert 'func_00105340(s16)' in s and 'u32 func_00105340' in s
    assert s.count('func_003e0670(&')==2 and 'func_003e0670(&cameraMatrix, &cameraMatrix)' in s
    assert 'func_0044b950(cameraMatrix.right.z, cameraMatrix.right.x)' in s
    assert 'func_0044b950(modelMatrix.right.z, modelMatrix.right.x)' in s
    assert 's32 mat[15]' not in s and 'f32 sp120' not in s
    clear1=s[s.index('    {\n        u8 *p = (u8 *)&move;'):s.index('    {\n        u8 *p = (u8 *)&camera;')]
    clear2=s[s.index('    {\n        u8 *p = (u8 *)&camera;'):s.index('    f20 = 0.0f;')]
    copy1=re.search(r'        cameraMatrix = .*?;',s).group().replace('*(u8 **)(func_00457120() + 4)', 'cameraFrame')
    copy2=re.search(r'        modelMatrix = .*?;',s).group()
    assert copy2 == '        modelMatrix = *(MovementMatrix *)((u8 *)mdlGetClumpFrame(*(void **)(*(s32 *)(h + 0x18) + 0x164)) + 0x10);'
    copy2=copy2.replace('(u8 *)mdlGetClumpFrame(*(void **)(*(s32 *)(h + 0x18) + 0x164))', 'modelFrame')
    identity=s[s.index('        mat.right.x ='):s.index('        RwMatrixRotate(&mat')]
    head='''#include <stdint.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    typedef uint8_t u8; typedef uint32_t u32; typedef int32_t s32; typedef float f32;
    typedef struct { f32 x,y,z; } FldEventVec3;
    '''+types
    fixture=head+'''
    #define REQUIRE(x) do { if (!(x)) { fprintf(stderr,"line %d: %s\\n",__LINE__,#x); exit(1); } } while (0)
    static float recovered(float b) { float rounded;
    '''+rounding+'''
    return rounded;
    }
    static float retail(float b) {
      int32_t q=(int32_t)(b/45.0f);
      float m=45.0f*(float)q;
      float r=b-m;
      float ar=fabsf(r);
      if (!(ar<=22.5f)) {
        float n=45.0f*(float)(q+1);
        float sign=b<0.0f?-1.0f:1.0f;
        m=n*sign;
      }
      return m;
    }
    static int legacy(float b) {
     int q=(int)(b/45.0f); float rem=b-45.0f*(float)q;
     return fabsf(rem)<=22.5f?q:(b<0.0f?-1:1);
    }
    int main(void) {
     unsigned checks=0, rejected=0;
     REQUIRE(sizeof(FldEventVec3)==12); REQUIRE(sizeof(MovementMatrix)==64);
     REQUIRE(offsetof(MovementMatrix,right.z)==8); REQUIRE(offsetof(MovementMatrix,flags)==12);
     REQUIRE(offsetof(MovementMatrix,up)==16); REQUIRE(offsetof(MovementMatrix,at)==32); REQUIRE(offsetof(MovementMatrix,pos)==48);
     for (int i=-5760;i<=5760;i++) { float b=i/8.0f; REQUIRE(recovered(b)==retail(b)); checks++; }
     const float edges[]={-67.50001f,-67.5f,-67.49999f,-22.50001f,-22.5f,-22.49999f,22.49999f,22.5f,22.50001f,67.49999f,67.5f,67.50001f,315.0f,360.0f,405.0f};
     for (unsigned i=0;i<sizeof(edges)/sizeof(*edges);i++){REQUIRE(recovered(edges[i])==retail(edges[i]));checks++;if ((int)recovered(edges[i])!=legacy(edges[i])) rejected++;}
     REQUIRE(rejected>=8);
     {
      FldEventVec3 move,camera;
      memset(&move,0xA5,sizeof move);memset(&camera,0xA5,sizeof camera);
    '''+clear1+clear2+'''
      REQUIRE(move.x==0.0f&&move.y==0.0f&&move.z==0.0f);
      REQUIRE(camera.x==0.0f&&camera.y==0.0f&&camera.z==0.0f);checks+=6;
     }
     for (unsigned n=0;n<256;n++) {
      struct Frame { u32 prefix[4]; MovementMatrix matrix; } ca,mo;
      unsigned char *cameraFrame=(unsigned char*)&ca,*modelFrame=(unsigned char*)&mo;
      MovementMatrix cameraMatrix,modelMatrix,mat;
      for(unsigned j=0;j<sizeof ca;j++){cameraFrame[j]=(u8)(j+n);modelFrame[j]=(u8)(j*3+n);}
      ca.matrix.right.x=10.0f+n;ca.matrix.right.z=20.0f+n;
      mo.matrix.right.x=30.0f+n;mo.matrix.right.z=40.0f+n;
      ca.matrix.at.x=-10;ca.matrix.at.z=-20;mo.matrix.up.x=-30;mo.matrix.up.z=-40;
    '''+copy1+'\n'+copy2+'''
      REQUIRE(memcmp(&cameraMatrix,&ca.matrix,64)==0);REQUIRE(memcmp(&modelMatrix,&mo.matrix,64)==0);
      REQUIRE(cameraMatrix.right.z==20.0f+n&&cameraMatrix.right.x==10.0f+n);
      REQUIRE(modelMatrix.right.z==40.0f+n&&modelMatrix.right.x==30.0f+n);
      REQUIRE(cameraMatrix.right.x!=cameraMatrix.at.x);REQUIRE(modelMatrix.right.x!=modelMatrix.up.x);
      /* Initialize the object here. The actual target remains intentionally uninitialized. */
      memset(&mat,0xA5,sizeof mat);mat.flags=n*0x01010101u;
      u32 oldflags=mat.flags,p1=mat.pad1,p2=mat.pad2,p3=mat.pad3;
    '''+identity+'''
      REQUIRE(mat.flags==(oldflags|0x20003u));REQUIRE(mat.pad1==p1&&mat.pad2==p2&&mat.pad3==p3);
      REQUIRE(mat.right.x==1&&mat.up.y==1&&mat.at.z==1);
      REQUIRE(mat.right.y==0&&mat.right.z==0&&mat.up.x==0&&mat.up.z==0&&mat.at.x==0&&mat.at.y==0&&mat.pos.x==0&&mat.pos.y==0&&mat.pos.z==0);
      checks+=10;
     }
     printf("checks=%u legacy_rounding_rejections=%u\\n",checks,rejected);
     return 0;
    }
    '''
    return fixture
