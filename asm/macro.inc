.macro glabel label
    .global \label
    \label:
.endm
.macro alabel label
    \label:
.endm
.macro jlabel label
    \label:
.endm
.macro dlabel label
    .global \label
    \label:
.endm
.macro endlabel label
.endm
.macro nonmatching name, size
.endm
.macro matching name, size
.endm
