include         ./buildvars 

APPNAME		= test
LIB_DIR	        = ./lib/
LIB_QG_DIR      = ./src
LIB_QG		= $(LIB_QG_DIR)/libQg.a
LIB_HY_DIR      = ../HyLib
LIB_HY		= $(LIB_HY_DIR)/libHy.a

OBJS		= sample.o

all:d $(LIB_QG) $(LIB_HY) $(OBJS)
	$(LD) -o $(APPNAME) sample.o $(LIB_QG) $(LIB_HY) $(LFLAGS)
	./test
       
$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(LIB_QG):lib_qg

lib_qg:
	$(MAKE) -C $(LIB_QG_DIR)

$(LIB_HY):lib_hy

lib_hy:
	$(MAKE) -C $(LIB_HY_DIR)


clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) $(APPNAME)

d:distclean

distclean:clean
	$(MAKE) -C $(LIB_QG_DIR) clean
	$(MAKE) -C $(LIB_HY_DIR) clean

