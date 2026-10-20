#ifndef MEMBER_ACCESS_H
#define MEMBER_ACCESS_H

/*
 * Named struct-member access through an untyped base.
 *
 * MWCC b210 assumes a `u8 *` access may alias anything, but typed member loads
 * may not, so rewriting `*(s32 *)(work + 0x18)` as `((Foo *)work)->bar` can
 * change which loads it reuses and in what order. Where every typed form of an
 * access changes the retail instructions, write it as
 *
 *     MEMBER(s32, work, Foo, bar)
 *
 * which expands to the same `*(s32 *)(work + 0x18)` expression with the offset
 * taken from the proven layout. Pass `base` exactly as the original expression
 * spelled it (including any casts): adding or removing a cast changes code.
 */
#define MEMBER_OFFSET(Struct, member) ((s32)&((Struct *)0)->member)
#define MEMBER(type, base, Struct, member) (*(type *)((base) + MEMBER_OFFSET(Struct, member)))

#endif
