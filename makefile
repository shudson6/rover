BUILDDIR = build
OBJDIR = obj
CFLAGS = -c -Iinclude -mmcu=atmega328p
VPATH = src
CC = avr-gcc
LD = avr-gcc
LDFLAGS = -mmcu=atmega328p

define cc-cmd
$(CC) $(CFLAGS) $< -o $@
endef

$(OBJDIR)/%.o: %.c
	$(cc-cmd)

$(OBJDIR)/%-test.o: test/%-test.c
	$(cc-cmd)

define objcopy
avr-objcopy -O ihex $(BUILDDIR)/$@.o $(BUILDDIR)/$@.hex
endef

blink-test: $(OBJDIR)/blink-test.o
	$(LD) $(LDFLAGS) $? -o $(BUILDDIR)/$@.o
	$(objcopy)

