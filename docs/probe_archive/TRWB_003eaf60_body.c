/* object 316B window 368B nd 226; differing offsets begin 0,6,7,8,14,15,22,23,24,26,28,29,30,31,32,33; deficit 13 instructions; classification undersized/prologue-and-stack-shape; ruled out: no floor instruction, no pragma tested */
s32 *func_003eaf60(s8 *arg0)
{
    extern s8 *(*D_008873BC[])(s8 *arg0, s32 arg1);
    extern s32 (*D_008873C8[])(s32 *arg0, s8 *arg1);
    extern s32 func_003eaf00(s32 arg0, s8 *arg1);
    s8 *path;
    s8 *temp;
    s32 *node;
    s32 callback;
    s32 output;
    u8 *base;

    base = (u8 *)D_008872E0 + iGpffffb7c0;
    path = D_008873BC[0](arg0, 58);
    if (path == NULL) {
        path = arg0;
    }
    temp = D_008873BC[0](path, 47);
    if (temp != NULL) {
        path = temp;
    }
    temp = D_008873BC[0](path, 92);
    if (temp == NULL) {
        temp = path;
    }
    temp = D_008873BC[0](temp, 46);
    if (temp == NULL) {
        return NULL;
    }
    node = *(s32 **)(base + 0x21c);
    while (node != NULL) {
        if (D_008873C8[0](node, temp) == 0 ||
            D_008873C8[0](node + 0x14, temp) == 0) {
            callback = *(s32 *)(node + 0x28);
            if (callback != 0) {
                output = 0;
                func_003eab70(
                    arg0, 5,
                    (s32 (*)(s32, s32))func_003eaf00,
                    &callback);
                return (s32 *)output;
            }
            return NULL;
        }
        node = *(s32 **)(node + 0x30);
    }
    return NULL;
}
