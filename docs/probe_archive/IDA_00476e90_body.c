/* Rejected IDA-first candidate: object 996B / window 976B / 72 reloc-masked differing words.
 * Requirements and provenance: IDA_model_followthrough.json. Not promoted. */
#pragma push
#pragma always_inline on
/* Preserve the per-channel normalization loads observed in retail. */
#pragma opt_common_subs off
/* Keep the explicitly shared quantization constants live across channels. */
#pragma opt_propagation off
typedef struct MdlTintRgba { u8 red, green, blue, alpha; } MdlTintRgba;
typedef struct MdlTintReal { f32 red, green, blue, alpha; } MdlTintReal;
typedef struct MdlTintMaterial { u32 unknown00; MdlTintRgba color; } MdlTintMaterial;
typedef struct MdlTintGeometry {
    u8 unknown00[8];
    u32 flags;
    u8 unknown0c[20];
    MdlTintMaterial** materials;
    u32 count;
} MdlTintGeometry;

static inline void mdl_tint_to_real(MdlTintReal* out, const MdlTintRgba* color)
{
    out->red = iGpffff8044 * (f32)(u32)color->red;
    out->green = iGpffff8044 * (f32)(u32)color->green;
    out->blue = iGpffff8044 * (f32)(u32)color->blue;
    out->alpha = iGpffff8044 * (f32)(u32)color->alpha;
}

static inline void mdl_tint_unpack(MdlTintRgba* out, u32 packed)
{
    out->blue = packed;
    out->green = packed >> 8;
    out->red = packed >> 16;
    out->alpha = packed >> 24;
}

static inline void mdl_tint_quantize(MdlTintRgba* out, const MdlTintReal* color)
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
    MdlTintGeometry* geometry;
    u32 count;
    MdlTintReal scale;
    u32 index;
    geometry = *(MdlTintGeometry**)(atomic + 0x18);
    geometry->flags |= 0x40;
    count = geometry->count;
    mdl_tint_to_real(&scale, (const MdlTintRgba*)*data);
    for (index = 0; index < count; ++index) {
        MdlTintMaterial* material = geometry->materials[index];
        MdlTintRgba color;
        MdlTintReal real;
        MdlTintReal tinted;
        mdl_tint_unpack(&color, func_004578b0(material, D_00713160));
        mdl_tint_to_real(&real, &color);
        tinted.red = real.red * scale.red;
        tinted.green = real.green * scale.green;
        tinted.blue = real.blue * scale.blue;
        if ((*(u16*)((u8*)data + 4) & 1) == 0)
            tinted.alpha = real.alpha * scale.alpha;
        else
            tinted.alpha = scale.alpha;
        mdl_tint_quantize(&color, &tinted);
        material->color = color;
    }
    return atomic;
}
#pragma pop
