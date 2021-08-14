BUILDDIR = build
TESTBUILDDIR = build/test
OBJDIR = obj
DEVTESTDIR = obj/test/dev
CFLAGS = -c -Iinclude -mmcu=atmega328p
VPATH = src
CC = avr-gcc
LD = avr-gcc
LDFLAGS = -mmcu=atmega328p
CHECK-CC = gcc
CHECK-CFLAGS = -c -g -Iinclude
CHECK-LDADD = -lcheck -lm -lrt -lpthread -lsubunit

define cc-cmd
$(CC) $(CFLAGS) $< -o $@
endef

$(OBJDIR)/%.o: %.c
	$(cc-cmd)

$(OBJDIR)/test-%.o: test/mc/test-%.c
	$(cc-cmd)

$(DEVTESTDIR)/%.o: %.c
	$(CHECK-CC) $(CHECK-CFLAGS) $< -o $@

$(DEVTESTDIR)/%.test.o: test/dev/%.test.c
	$(CHECK-CC) $(CHECK-CFLAGS) $< -o $@

define objcopy
avr-objcopy -O ihex $(BUILDDIR)/$@.o $(BUILDDIR)/$@.hex
endef

test-blink: $(OBJDIR)/test-blink.o
	$(LD) $(LDFLAGS) $? -o $(BUILDDIR)/$@.o
	$(objcopy)

devtestobjs := $(DEVTESTDIR)/util.test.o $(DEVTESTDIR)/util.o \
							 $(DEVTESTDIR)/commandbuffer.test.o $(DEVTESTDIR)/commandbuffer.o \
							 $(DEVTESTDIR)/command.test.o $(DEVTESTDIR)/command.o \
							 $(DEVTESTDIR)/main.test.o

test: $(devtestobjs)
	$(CHECK-CC) $? $(CHECK-LDADD) -o $(TESTBUILDDIR)/testexec

