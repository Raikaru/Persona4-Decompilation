/* Accepted recovery for func_00458ce0 (0x00458CE0), owner src/promoted/code1_0045.c. */
/* Prior best after HoH458CE0Try34 remained non-MATCH (36 differing words reloc-masked, 516B object vs 544B window). */
/* Retail saved registers: $s0 = scale/arg1, $s1 = material/arg0, $s2 = loop index, $s3 = current item, $s4 = created property. */
/* Final: 540/544 bytes, 19 relocations (6x D_00711890_abs HI/LO + 13x func R_MIPS_26), 0 differing words reloc-masked, 4-byte retail zero tail. */
/* Decisive levers: `#pragma opt_scalarize off` keeps the prop triple in stack spill slots (0x60/0x64/0x68($sp)) instead of $f20/$f21; struct assignment `*(Code45Vec3 *)(material + 0xC) = prop` gives retail's batched lwc1 f2,f1,f0 / swc1 f2,f1,f0 final copy (per-field stores interleave). Clamp form `if (!(x <= 1.0f)) x = 1.0f` retains retail c.le.s/bc1t. Bottom-test goto loop matches retail b/bnez layout. */
/* Semantic note: `current` is uninitialized on paper when the search loop trips zero times, matching retail's reuse of incoming $s3 (beqz $s3). Reachable materials always carry at least one counted userdata: either the pre-existing per3modelMatProp entry (HasData != 0) or the entry just created via func_003bcfa0(...,2,3) (HasData == 0), so the loop always defines `current` before the `!= 0` test. Initializing it would add a move $s3,$zero retail does not have. Same uninitialized-search pattern as MATCHed sibling func_004586f0. */
/* Non-goal func_00452870 untouched (banked 4-word floor, still ASM). */

u8 *func_00458ce0(u8 *material, u8 *data) {
    Code45Vec3 prop;
    s32 created;
    s32 i;
    s32 current;
    f32 *materialColor;
    if (func_00457a90((const RpMaterial *)material, (const char *)D_00711890_abs) == 0) {
        materialColor = (f32 *)(material + 0xC);
        created = (s32)func_003bd000((const RpMaterial *)material, func_003bcfa0((RpMaterial *)material, (char *)D_00711890_abs, 2, 3));
        func_003bd0f0((u8 *)created, 0, materialColor[0]);
        func_003bd0f0((u8 *)created, 1, materialColor[1]);
        func_003bd0f0((u8 *)created, 2, materialColor[2]);
    }
    i = 0;
    goto loop_test;
loop_body:
    current = (s32)func_003bd000((const RpMaterial *)material, i);
    if (func_004426e8(func_003bd040((RpUserDataArray *)current), (const char *)D_00711890_abs) == 0) {
        goto loop_done;
    }
    i += 1;
loop_test:
    if (i < func_003bcfb0((const RpMaterial *)material)) {
        goto loop_body;
    }
loop_done:
    if (current != 0) {
        prop.x = func_003bd090((u8 *)current, 0);
        prop.y = func_003bd090((u8 *)current, 1);
        prop.z = func_003bd090((u8 *)current, 2);
        prop.x = prop.x * *(f32 *)(data + 0);
        prop.y = prop.y * *(f32 *)(data + 4);
        prop.z = prop.z * *(f32 *)(data + 8);
        if (!(prop.x <= 1.0f)) {
            prop.x = 1.0f;
        }
        if (!(prop.y <= 1.0f)) {
            prop.y = 1.0f;
        }
        if (!(prop.z <= 1.0f)) {
            prop.z = 1.0f;
        }
        *(Code45Vec3 *)(material + 0xC) = prop;
    }
    return material;
}
