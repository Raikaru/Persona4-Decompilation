#include "type.h"

typedef struct Camera Camera;
struct Camera
{
    u8 objectType[4];
    void* frame;
    u8 cameraData[0x58];
    void* frameBuffer;
    void* zBuffer;
};

extern Camera* func_003e84a0(void);
extern void* func_003e9320(void);
extern void func_003efd20(Camera* camera, void* frame);
extern void* func_003ec590(u32 width, u32 height, u32 depth, u32 flags);
extern void func_003e9390(void* frame);
extern void func_003ec330(void* raster);
extern void func_003e8440(Camera* camera);

// FUN_004574D0
Camera* func_004574d0(u32 width, u32 height, u32 createZBuffer)
{
    Camera* camera;
    void* frame;

    camera = func_003e84a0();
    if (camera != NULL)
    {
        func_003efd20(camera, func_003e9320());

        camera->frameBuffer = func_003ec590(width, height, 0, 2);
        if (createZBuffer != 0)
        {
            camera->zBuffer = func_003ec590(width, height, 0, 1);
        }

        if (camera->frame != NULL &&
            camera->frameBuffer != NULL &&
            (createZBuffer == 0 || camera->zBuffer != NULL))
        {
            return camera;
        }
    }

    if (camera != NULL)
    {
        frame = camera->frame;
        if (frame != NULL)
        {
            func_003efd20(camera, NULL);
            func_003e9390(frame);
        }

        if (camera->frameBuffer != NULL)
        {
            func_003ec330(camera->frameBuffer);
            camera->frameBuffer = NULL;
        }
        if (camera->zBuffer != NULL)
        {
            func_003ec330(camera->zBuffer);
            camera->zBuffer = NULL;
        }
        func_003e8440(camera);
    }

    return NULL;
}
