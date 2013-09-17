include ../buildvars

OBJS = HyUdpServer.o HyUdpClient.o HyUdpPackage.o

all: clean $(OBJS)
	cp $(OBJS) ../lib

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
