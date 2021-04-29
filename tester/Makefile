CC		  = clang
LINKER	  = clang
BUILDDIR  = build
OBJDIR	  = obj
SRCDIR	  = src
TESTDIR   = tests


INCLUDEDIR = include
CFLAGS	   = -c -std=c17 -I$(INCLUDEDIR) -ggdb -Wall -Werror -pedantic -Wno-attributes
LDFLAGS	   =

SOURCES     = $(wildcard $(SRCDIR)/*.c)
OBJECTS     = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET      = bmp-compare

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJECTS) | $(BUILDDIR)
	$(LINKER) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)/%.o:$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR) $(OBJDIR) :
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(OBJDIR)

.PHONY: clean
