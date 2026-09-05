/* Rejected 412B/432B, 78-word floor; replay requirements in IDA_model_subsystems.json. */
// FUN_0047DF40
s32 func_0047df40(s32 arg0, s32 arg1)
{
    s32 selected = -1;
    u16 searchIndex = 0;
    u32 modelType = (u16)arg0;
    u32 modelId = (u16)arg1;

    while (searchIndex < 3U) {
        const MdlSESlot *entry = &D_00922C10[searchIndex];
        u32 residentType = entry->modelType;

        if (residentType == modelType && entry->modelId == modelId) {
            selected = searchIndex;
            break;
        }
        if (residentType < 12 &&
            func_00477c40(residentType, D_00922C10[searchIndex].modelId, 0) == NULL) {
            selected = searchIndex;
            break;
        }
        ++searchIndex;
    }

    if (selected == -1) {
        u32 oldestStamp = (u32)-1;
        u16 evictionIndex;

        for (evictionIndex = 0; evictionIndex < 3U; ++evictionIndex) {
            u32 stamp = D_00922C10[evictionIndex].stamp;

            if (oldestStamp >= stamp) {
                oldestStamp = stamp;
                selected = evictionIndex;
            }
        }
    }

    ++iGpffffbb40;
    D_00922C10[selected].stamp = iGpffffbb40;
    D_00922C10[selected].modelType = (u16)arg0;
    D_00922C10[selected].modelId = (u16)arg1;
    return selected + 3;
}
