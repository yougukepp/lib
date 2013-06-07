OBJS = HyTimer.o

all: $(OBJS)
       
$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
