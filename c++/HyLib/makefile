include buildvars

HyLib = HyLib.a
OBJS = HyTimer.o

all: $(OBJS)
	$(AR) $(HyLib) $(OBJS)
       
$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
