Testing
---
This project is targeted for Atmega328p microcontroller. Of course, the mc 
itself is the ultimate testing ground, but modules will be divided in such a way
that they can be unit tested on the dev machine as much as possible. That is,
functions that work with microcontroller resources (mostly i/o) will be kept
separate from those that don't, since the correctness of the former can only be
verified on-chip, while the latter can be checked on a dev rig.
Microcontroller tests are in test/mc/ and names are prefixed with test-, e.g.
test-blink, for file names and make targets.
Unit tests are in test/dev/ and source files are suffixed with .test before the
extension, e.g. string.test.c.
This naming is meant to help identify the different purposes and make the
makefile more readable.
I don't anticipate needing more than one unit testing target (test) since this
is a small project.
