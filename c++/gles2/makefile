include         ./buildvars 

APPNAME		= test
LIB_DIR	        = ./lib/
LFLAGS         += -Bstatic -L./lib -lGis
LIB_GIS		= ./lib/libGis.a
LIB_ES_DIR      = ./src/es
LIB_GRAPH_DIR   = ./src/graph

all:distclean $(LIB_GIS) sample.o
	$(LD) -o $(APPNAME) sample.o $(LIB_GIS) $(LFLAGS) $(LFLAGS) 
	./test

mk_lib_dir:
	if [ ! -d $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi

$(LIB_GIS):mk_lib_dir lib_es lib_graph
	$(CP) $(LIB_ES_DIR)/*.o $(LIB_DIR)
	$(CP) $(LIB_GRAPH_DIR)/*.o $(LIB_DIR)
	$(AR) $(LIB_GIS) $(LIB_DIR)*.o


sample.o : sample.cpp
	$(CC) $(CFLAGS) -c $< -o $@

lib_es:
	$(MAKE) -C $(LIB_ES_DIR)

lib_graph:
	$(MAKE) -C $(LIB_GRAPH_DIR)

clean:
	$(RM) *.o
	$(RM) $(APPNAME)

d:distclean

distclean:clean
	$(RM) $(LIB_DIR)
	$(MAKE) -C $(LIB_ES_DIR) clean
	$(MAKE) -C $(LIB_GRAPH_DIR) clean

