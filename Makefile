projmake: main.c
	gcc main.c `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm

	./a.out

# CC:= gcc
# 
# CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm
# 
# HDRS :=
# 
# SRCS := main.c 
# 
# OBJS:= $(SRCS:.c=.o)
# 
# EXEC := game
# 
# all:	$(EXEC)
# 
# $(EXEC) : $(OBJS) $(HDRS) Makefile
# 	$(CC) -o $@ $(OBJS) $(CFLAGS)
# 
# clean: rm -f $(EXEC) $(OBJS)
