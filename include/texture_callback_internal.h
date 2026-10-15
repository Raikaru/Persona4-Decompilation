#ifndef TEXTURE_CALLBACK_INTERNAL_H
#define TEXTURE_CALLBACK_INTERNAL_H

struct RwTexture;
struct RwTexDictionary;

typedef struct RwTexture *(*P4TextureVisitor)(struct RwTexture *texture,
                                           void *data);

struct RwTexture *K_Clump_AppendTextureName(struct RwTexture *texture, void *list);
const struct RwTexDictionary *func_003ef260(
    const struct RwTexDictionary *dictionary, P4TextureVisitor visit, void *data);

#endif
