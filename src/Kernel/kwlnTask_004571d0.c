#include "type.h"

typedef struct Raster Raster;
struct Raster
{
    u8 _pad0[0xc];
    s32 width;
    s32 height;
};

typedef struct Camera Camera;
struct Camera
{
    u8 _pad0[0x60];
    Raster* frameBuffer;
    Raster* zBuffer;
};

typedef struct CameraView CameraView;
struct CameraView
{
    f32 offsetX;
    f32 offsetY;
    s32 width;
    s32 height;
};

extern u32 D_008D1EF8[];
extern u32 D_008D1EFC[];
extern u32 D_008D1EF4[];
extern u32 D_008D1EF0[];
extern CameraView D_008D1F00;
extern u32 D_008D1F08[];
extern u32 D_008D1F0C[];
extern u32 D_008D1F04[];

extern const void* func_003e89c0(void);
extern void func_003e8970(u32* output, const void* descriptor);
extern Raster* func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern void func_003ec330(Raster* raster);
extern Camera* func_003e83a0(Camera* camera, const f32* viewWindow);

// FUN_004571D0
void func_004571d0(Camera* camera, CameraView* requestedView, f32 scale,
                   f32 aspectRatio)
{
    u32 displayInfo[4];
    CameraView* view;
    Raster* newFrameBuffer;
    Raster* newZBuffer;
    f32 viewWindow[2];

    if (camera == NULL)
    {
        return;
    }

    if (D_008D1EF8[0] == 0 || D_008D1EFC[0] == 0)
    {
        D_008D1EF4[0] = 0;
        D_008D1EF0[0] = 0;
        D_008D1EF8[0] = camera->frameBuffer->width;
        D_008D1EFC[0] = camera->frameBuffer->height;
    }

    func_003e8970(displayInfo, func_003e89c0());

    if (requestedView == NULL)
    {
        view = &D_008D1F00;
        D_008D1F08[0] = camera->frameBuffer->width;
        D_008D1F0C[0] = camera->frameBuffer->height;
        D_008D1F00.offsetX = 0;
        D_008D1F04[0] = 0;
    }
    else
    {
        view = requestedView;
    }

    if ((displayInfo[3] & 1) != 0)
    {
        view->offsetY = 0;
        view->offsetX = 0;
        view->width = displayInfo[0];
        view->height = displayInfo[1];
    }

    if (view->width <= 0)
    {
        return;
    }
    if (view->height <= 0)
    {
        return;
    }

    if (camera->frameBuffer != NULL)
    {
        func_003ec330(camera->frameBuffer);
    }

    if (camera->zBuffer != NULL)
    {
        func_003ec330(camera->zBuffer);
    }

    newFrameBuffer = func_003ec590(view->width, view->height, 0, 2);
    newZBuffer = func_003ec590(view->width, view->height, 0, 1);
    if (newFrameBuffer == NULL)
    {
        goto allocation_failed;
    }
    if (newZBuffer == NULL)
    {
        goto allocation_failed;
    }

    camera->frameBuffer = newFrameBuffer;
    camera->zBuffer = newZBuffer;
    goto update_view_window;

allocation_failed:
    if (newFrameBuffer != NULL)
    {
        func_003ec330(newFrameBuffer);
    }
    if (newZBuffer != NULL)
    {
        func_003ec330(newZBuffer);
    }

    view->width = D_008D1EF8[0];
    view->height = D_008D1EFC[0];
    newFrameBuffer = func_003ec590(view->width, view->height, 0, 2);
    newZBuffer = func_003ec590(view->width, view->height, 0, 1);
    camera->frameBuffer = newFrameBuffer;
    camera->zBuffer = newZBuffer;
    return;

update_view_window:

    if ((displayInfo[3] & 1) != 0)
    {
        viewWindow[0] = scale * aspectRatio;
        viewWindow[1] = scale;
    }
    else
    {
        view->width = camera->frameBuffer->width;
        view->height = camera->frameBuffer->height;

        if (view->height < view->width)
        {
            viewWindow[0] = scale;
            viewWindow[1] = ((f32)view->height * scale) / (f32)view->width;
        }
        else
        {
            viewWindow[0] = ((f32)view->width * scale) / (f32)view->height;
            viewWindow[1] = scale;
        }
    }

    func_003e83a0(camera, viewWindow);
}
