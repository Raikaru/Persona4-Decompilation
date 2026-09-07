/* Rejected full-owner candidate: 996B / 976B, 72 fully relocated differing words.
 * Retail has 972 executable bytes and four zero-tail bytes. Differences are
 * 66 executable words, one retail padding slot and five words past the window.
 * Reuses mdlManager.c's RwRGBA, integer/float types, iGpffff8044,
 * D_00713160 and func_004578b0 declarations. No runtime semantic acceptance.
 * Detailed measurements: IDA_model_followthrough.json. */
#pragma push
#pragma always_inline on
/* Preserve the per-channel normalization loads observed in retail. */
#pragma opt_common_subs off
/* Keep the explicitly shared quantization constants live across channels. */
#pragma opt_propagation off
typedef struct QSR_TintReal { f32 red, green, blue, alpha; } QSR_TintReal;
typedef struct QSR_TintMaterial { u32 unknown00; RwRGBA color; } QSR_TintMaterial;
typedef struct QSR_TintGeometry {
    u8 unknown00[8];
    u32 flags;
    u8 unknown0c[20];
    QSR_TintMaterial** materials;
    u32 count;
} QSR_TintGeometry;

static inline void QSR_tint_to_real(QSR_TintReal* out, const RwRGBA* color)
{
    out->red = iGpffff8044 * (f32)(u32)color->red;
    out->green = iGpffff8044 * (f32)(u32)color->green;
    out->blue = iGpffff8044 * (f32)(u32)color->blue;
    out->alpha = iGpffff8044 * (f32)(u32)color->alpha;
}

static inline void QSR_tint_unpack(RwRGBA* out, u32 packed)
{
    out->blue = packed;
    out->green = packed >> 8;
    out->red = packed >> 16;
    out->alpha = packed >> 24;
}

static inline void QSR_tint_quantize(RwRGBA* out, const QSR_TintReal* color)
{
    f32 maximum = 255.0f;
    f32 bias = 0.5f;
    out->red = (s32)(bias + maximum * color->red);
    out->green = (s32)(bias + maximum * color->green);
    out->blue = (s32)(bias + maximum * color->blue);
    out->alpha = (s32)(bias + maximum * color->alpha);
}

// FUN_00476E90
u8* func_00476e90(u8* atomic, u8** data)
{
    QSR_TintGeometry* geometry;
    u32 count;
    QSR_TintReal scale;
    u32 index;
    geometry = *(QSR_TintGeometry**)(atomic + 0x18);
    geometry->flags |= 0x40;
    count = geometry->count;
    QSR_tint_to_real(&scale, (const RwRGBA*)*data);
    for (index = 0; index < count; ++index) {
        QSR_TintMaterial* material = geometry->materials[index];
        RwRGBA color;
        QSR_TintReal real;
        QSR_TintReal tinted;
        QSR_tint_unpack(&color, func_004578b0(material, D_00713160));
        QSR_tint_to_real(&real, &color);
        tinted.red = real.red * scale.red;
        tinted.green = real.green * scale.green;
        tinted.blue = real.blue * scale.blue;
        if ((*(u16*)((u8*)data + 4) & 1) == 0)
            tinted.alpha = real.alpha * scale.alpha;
        else
            tinted.alpha = scale.alpha;
        QSR_tint_quantize(&color, &tinted);
        material->color = color;
    }
    return atomic;
}
#pragma pop
