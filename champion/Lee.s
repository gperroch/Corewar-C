.name "Lee the chinese"
.comment "Work more!"

start:
st r1, 6
live %0
ld %983040, r16
ld %0, r15
st r15, -16

init1:
st r1, 21
ld %0, r2
st r2, -11
zjmp %:init2
workshop1:
live %0
st r16, -510
zjmp %:workshop1

init2:
st r1, 21
ld %0, r3
st r3, -11
zjmp %:init3
workshop2:
live %0
st r16, -510
zjmp %:workshop2

init3:
st r1, 21
ld %0, r4
st r4, -11
zjmp %:init4
workshop3:
live %0
st r16, -510
zjmp %:workshop3

init4:
st r1, 21
ld %0, r5
st r5, -11
zjmp %:init5
workshop4:
live %0
st r16, -510
zjmp %:workshop4

init5:
st r1, 21
ld %0, r6
st r6, -11
zjmp %:init6
workshop5:
live %0
st r16, -510
zjmp %:workshop5

init6:					;35 cycles
st r1, 21
ld %0, r7
st r7, -11
zjmp %:init7
workshop6:
live %0
st r16, -510
zjmp %:workshop6

init7:
st r1, 21
ld %0, r8
st r8, -11
zjmp %:init8
workshop7:
live %0
st r16, -510
zjmp %:workshop7

init8:
st r1, 21
ld %0, r9
st r9, -11
zjmp %:init9
workshop8:
live %0
st r16, -510
zjmp %:workshop8

init9:
st r1, 21
ld %0, r10
st r10, -11
zjmp %:init10
workshop9:
live %0
st r16, -510
zjmp %:workshop9

init10:
st r1, 21
ld %0, r11
st r11, -11
zjmp %:init11
workshop10:
live %0
st r16, -510
zjmp %:workshop10

init11:
st r1, 21
ld %0, r12
st r12, -11
zjmp %:start2
workshop11:
live %0
lfork %1536
zjmp %:workshop11

start2:
st r1, 6
live %0
ld %0, r15
st r15, -16
st r1, 6
live %0
st r15, -9
fork %:start2
st r1, 6
live %0
st r15, -9
fork %:workshop1
st r1, 6
live %0
st r15, -9
fork %:workshop2
st r1, 6
live %0
st r15, -9
fork %:workshop3
st r1, 6
live %0
st r15, -9
fork %:workshop4
st r1, 6
live %0
st r15, -9
fork %:workshop5
st r1, 6
live %0
st r15, -9
fork %:workshop6
st r1, 6
live %0
st r15, -9
fork %:workshop7
st r1, 6
live %0
st r15, -9
fork %:workshop8
st r1, 6
live %0
st r15, -9
fork %:workshop9
st r1, 6
live %0
st r15, -9
fork %:workshop10
st r1, 6
live %0
st r15, -9
fork %:workshop11
st r1, 6
live %0
st r15, -9
fork %:start2
zjmp %:start2
