include         ./buildvars 

APPNAME		= test
LIB_DIR	        = ./lib/
LFLAGS         += -Bstatic -L./lib -lGis
LIB_GIS		= ./lib/libGis.a
LIB_PLATFORM_DIR= ./src/platform
LIB_GRAPH_DIR   = ./src/graph
LIB_HY_DIR	= ../HyLib
LIB_HY		= $(LIB_HY_DIR)/*.a

OBJS		= sample.o

all: distclean $(LIB_GIS) $(OBJS)
	$(LD) -o $(APPNAME) sample.o $(LIB_GIS) $(LIB_HY) $(LFLAGS) $(LFLAGS) 
	./test
       
$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

mk_lib_dir:
	if [ ! -d $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi

$(LIB_GIS):mk_lib_dir lib_hy lib_es lib_graph
	$(CP) $(LIB_PLATFORM_DIR)/*.o $(LIB_DIR)
	$(CP) $(LIB_GRAPH_DIR)/*.o $(LIB_DIR)
	$(AR) $(LIB_GIS) $(LIB_DIR)*.o

lib_hy:
	$(MAKE) -C $(LIB_HY_DIR)

lib_es:
	$(MAKE) -C $(LIB_PLATFORM_DIR)

lib_graph:
	$(MAKE) -C $(LIB_GRAPH_DIR)

clean:
	$(RM) *.o
	$(RM) $(APPNAME)

d:distclean

distclean:clean
	$(RM) $(LIB_DIR)
	$(MAKE) -C $(LIB_PLATFORM_DIR) clean
	$(MAKE) -C $(LIB_GRAPH_DIR) clean
	$(MAKE) -C $(LIB_HY_DIR) clean

