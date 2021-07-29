BUILDDIR = build
TESTBUILDDIR = build/test
OBJDIR = obj
TESTOBJDIR = obj/test
CFLAGS = -c -Iinclude -mmcu=atmega328p
VPATH = src
CC = avr-gcc
LD = avr-gcc
LDFLAGS = -mmcu=atmega328p
CHECK-CC = gcc
CHECK-CFLAGS = -c -Iinclude
CHECK-LDADD = -lcheck -lm -lrt -lpthread -lsubunit

define cc-cmd
$(CC) $(CFLAGS) $< -o $@
endef

$(OBJDIR)/%.o: %.c
	$(cc-cmd)

$(OBJDIR)/test-%.o: test/mc/test-%.c
	$(cc-cmd)

$(TESTOBJDIR)/%.o: %.c
	$(CHECK-CC) $(CHECK-CFLAGS) $< -o $@

$(TESTOBJDIR)/%.test.o: test/dev/%.test.c
	$(CHECK-CC) $(CHECK-CFLAGS) $< -o $@

define objcopy
avr-objcopy -O ihex $(BUILDDIR)/$@.o $(BUILDDIR)/$@.hex
endef

test-blink: $(OBJDIR)/test-blink.o
	$(LD) $(LDFLAGS) $? -o $(BUILDDIR)/$@.o
	$(objcopy)

test: $(TESTOBJDIR)/util.test.o $(TESTOBJDIR)/util.o
	$(CHECK-CC) $? $(CHECK-LDADD) -o $(TESTBUILDDIR)/testexec

