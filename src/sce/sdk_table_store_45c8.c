/* Sony SDK table record write. */
typedef struct {
    unsigned char reserved[0x10];
    unsigned int index;
    unsigned int value;
} SdkWordEntry;

typedef struct {
    unsigned char reserved[0x1c];
    unsigned int *words;
} SdkWordTable;

// FUN_004245C8
void func_004245c8(SdkWordEntry *entry, SdkWordTable *table)
{
    unsigned int index = entry->index;
    unsigned int value = entry->value;
    table->words[index] = value;
}
