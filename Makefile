# Compiler
CC = gcc

# Compiler options
DFLAGS = -Wall -g

# Compile environment
ENV = Debug

# Source path
VPATH = Src \
		Inc \
		lib/CUnit-2.1-3/CUnit/Headers/ \
		lib/CUnit-2.1-3/CUnit/Sources/Framework/ \
		lib/CUnit-2.1-3/CUnit/Sources/Basic/

# Include path
CPPFLAGS = $(DFLAGS) -I Inc -I lib/CUnit-2.1-3/CUnit/Headers/

# Object files output dir
OUTPUT_DIR = bin/$(ENV)

# Compiler output option
OUTPUT_OPTION = -o $(OUTPUT_DIR)/$@

# Add output dir prefix to each target deps objs
OBJS = $(patsubst %.o,$(OUTPUT_DIR)/%.o,$^)

# Test Target dep objects
TEST_DEPS_OBJS = test.o \
			     Basic.o \
			     CUError.o \
			     MyMem.o \
			     TestDB.o \
			     TestRun.o \
			     Util.o \
			     test_list.o \
			     list.o \
			     test_divide_and_conquer.o \
			     test_exhaustive_search.o \
			     bm_compare.o \
			     divide_and_conquer.o \
			     exhaustive_search.o

# Run unit test
unit: test
	bin/$(ENV)/test

# Target
test: $(TEST_DEPS_OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o bin/$(ENV)/$@

# Implicit rules
$(OUTPUT_DIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c $^

# .PHONY: clean
clean:
	rm -rf bin/$(ENV)/*
