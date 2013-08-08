include buildvars

HyLib = libHy.a
OBJS = HyTimer.o HyUdpServer.o HyUdpClient.o

HyTest = test

all: clean $(HyLib) $(HyTest)

$(HyLib): $(OBJS)
	$(AR) $(HyLib) $(OBJS)

$(HyTest): $(HyLib) HyTest.cpp
	$(CC) -c $(CFLAGS) HyTest.cpp -o HyTest.o
	$(CC) $(LFLAGS) HyTest.o $(HyLib) -o $(HyTest)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) $(HyTest)
