/* object_size=144 window=160 normalized_diff=55 differing_offsets=0x30,0x3c-0x50,0x58-0x88,0x90-0x9f; classification: schedule on plus no_branch_likely off reproduces the frame, constant/function-pointer call setup, GP global load, saved-register order, helper calls, stores, and all semantic outcomes, but compiler branch layout differs from retail's two branch-likely joins and leaves a 16-byte tail gap; no callee/global declaration correction needed. Best source shape was nested success path; explicit gotos were worse (object 136, nd56). */
void *func_003d7a20(s32 arg0)
{
    void *temp;

    temp = D_008873F8[0](iGpffffb748, 0x30135);
    if (temp != NULL) {
        if (func_003e2910(arg0, temp, 0x20) == 0) {
            return NULL;
        }
        if (func_003df360(arg0, (u8 *)temp + 0x20, 0x20) == 0) {
            return NULL;
        }
        *(s32 *)((u8 *)temp + 0x40) = 1;
        return temp;
    }
    return NULL;
}
