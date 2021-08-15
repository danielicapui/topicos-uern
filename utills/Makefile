# Makefile template for shared library
CC = g++ # C compiler
CFLAGS = -fPIC -Wall -Wextra -O2 -g -I. # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = utills.so # target lib

SRCS =utills.cpp#source files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CC) $(CFLAGS) -MM $< >$@
main:main.cpp utills.so
	g++ main.cpp utills.so  -o main
include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.cpp=.d)
limpa:
	Del utills.d utills.o utills.so