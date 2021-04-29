CC        = clang
LINKER	  = clang
BUILDDIR  = build
OBJDIR	  = obj
SRCDIR    = src
TESTDIR   = tests


INCLUDEDIR = include
CFLAGS	   = -c -std=c17 -I$(INCLUDEDIR) -ggdb -Wall -Werror -pedantic -Wno-attributes
LDFLAGS    =

SOURCES     = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/transform/*.c)
OBJECTS     = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET      = image-transformer

ifneq ($(with), )
    CFLAGS += $(with)
    LDFLAGS += $(with)
endif


all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJECTS) | $(BUILDDIR) $(BUILDDIR)/transform
	$(LINKER) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)/%.o:$(SRCDIR)/%.c | $(OBJDIR) $(OBJDIR)/transform
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR) $(BUILDDIR)/transform $(OBJDIR) $(OBJDIR)/transform:
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(OBJDIR)

.PHONY: clean
