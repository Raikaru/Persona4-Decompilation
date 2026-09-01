Closest candidate for func_00100350; reverted because normalized_diff was nonzero.

#pragma opt_propagation off
// FUN_00100350
void func_00100350(void)
{
    u8 temp[0x40];

    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    func_0042f600(2);
    func_00442088(temp, D_005DC530, D_005DC548);
    for (;;) {
        if (func_0042b098((s8 *)temp) == 0) {
            continue;
        }
        break;
    }
    for (;;) {
        if (func_0042b048() == 0) {
            continue;
        }
        break;
    }
    func_00424f28(0);
    func_00429c18();
    func_0042eae0(0);
    func_0042f600(2);
    func_004214c0(9, func_00100310, 0);
    *(s32 *)0x10000000 = 0;
    *(s32 *)0x10000020 = 0;
    *(s32 *)0x10000030 = 0;
    *(s32 *)0x10000010 = 0x281;
    func_00422328(9);
    iGpffffb19c = 0;
    iGpffffb1a0 = 0;
    do {
    } while (func_0042ab68(D_005DC560, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC580, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5A0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5C0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC5E0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC600, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC620, 0x14, D_005DC640) < 0);
    do {
    } while (func_0042ab68(D_005DC660, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC680, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6A0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6C0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC6E0, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC700, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC700, 0, (void *)0) < 0);
    do {
    } while (func_0042ab68(D_005DC720, 0x18, D_005DC740) < 0);
    func_00452760();
    func_004645e0();
    D_00764280 = func_004216d0();
}
#pragma opt_propagation on
