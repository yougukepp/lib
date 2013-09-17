include buildvars

HyLib = $(LIB_DIR)/libHy.a

HyTest = test
HyTime = hyTime
HyUdp = hyUdp

all: clean $(HyLib) $(HyTest)

$(HyTest): $(HyLib) HyTest.cpp
	$(CC) -c $(CFLAGS) HyTest.cpp -o HyTest.o
	$(CC) $(LFLAGS) HyTest.o $(HyLib) -o $(HyTest)

$(HyLib): $(HyTime) $(HyUdp)
	$(AR) $(HyLib) $(LIB_DIR)/*.o

$(HyTime):
	$(MAKE) -C $(TIME_DIR)

$(HyUdp):
	$(MAKE) -C $(UDP_DIR)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C $(TIME_DIR) clean
	$(MAKE) -C $(UDP_DIR) clean
	$(RM) $(LIB_DIR)/*
	$(RM) *.o
	$(RM) *.out
	$(RM) $(HyTest)


