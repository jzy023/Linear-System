#=============== Compilation Options (YES/NO) ===============
USE_GCC5=NO
USE_FAST_MATH=YES
USE_NATIVE_CPU_OPTIMIZATIONS=YES
USE_DEBUG=YES
# USE_DEBUG=NO

#==================== Included Libraries ====================
# LIBS_DIRECTORIES:=$(LIBS_DIRECTORIES) -L/usr/lib/gcc/x86_64-linux-gnu/9 
# JLIBS=${LIBS_DIRECTORIES}
LIBS_DIRECTORIES:=$(LIBS_DIRECTORIES) -L/usr/lib/gcc/x86_64-linux-gnu/9 -L/usr/local/lib
JLIBS=${LIBS_DIRECTORIES} -lsfml-graphics -lsfml-window -lsfml-system

#======================= Other Setups =======================
ifeq ($(USE_DEBUG), YES)
	EXECNAME=matricesDebug.out
	EXECS_DIRECTORY=../../bin/debug
else
	EXECNAME=matricesRun.out
	EXECS_DIRECTORY=../../bin/release
endif


#==================== Included Libraries ====================
CCFLAGS= -c -std=c++2a -fopenmp 
ifeq ($(USE_DEBUG), YES)
	CCFLAGS+=-g -Wall -O3
else
	ifeq ($(USE_FAST_MATH), YES)
		CCFLAGS+= -ffast-math
	endif
	ifeq ($(USE_NATIVE_CPU_OPTIMIZATIONS), YES)
		CCFLAGS+= -march=native
	endif
endif
CC=g++
CCLINKFLAGS=-fopenmp -lgomp $(JLIBS)

#Required for GCC versions >=5.0
ifeq ($(USE_GCC5), YES)
	CCFLAGS+=-D_GLIBCXX_USE_CXX11_ABI=0
	CCLINKFLAGS+=-D_GLIBCXX_USE_CXX11_ABI=0
endif

#=============== Files to compile ===============
SRC_TP = $(wildcard ThirdParty/*.cpp)
OBJ_TP = $(SRC_TP:.cpp=.o)

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o) 

#=============== CPU Code Compilation ===============
all:$(EXECS_DIRECTORY)/$(EXECNAME)
	# rm -rf ThirdParty/*.o;
	rm -rf *.o;
ifeq ($(USE_DEBUG), NO)
	@echo "  --- Compiled Release CPU version ---"
else
	@echo "  --- Compiled Debug CPU version ---"
# 	mv $(EXECS_DIRECTORY)/$(EXECNAME) $(EXECNAME)_debug
endif

# $(EXECS_DIRECTORY)/$(EXECNAME): $(OBJ_TP) $(OBJ)
# 	$(CC) $(CCLINKFLAGS) $(OBJ_TP) $(OBJ) -o $@ $(JLIBS) 
$(EXECS_DIRECTORY)/$(EXECNAME): $(OBJ)
	$(CC) $(CCLINKFLAGS) $(OBJ) -o $@ $(JLIBS) 

%.o: %.cpp
	$(CC) $(CCFLAGS) $< -o $@

clean:
	# rm -rf ThirdParty/*.o \ 
	rm -rf *.o \
	$(EXECS_DIRECTORY)/$(EXECNAME)

