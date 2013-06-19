include         ./buildvars 

APPNAME		= test
LIB_DIR	        = ./lib/
LFLAGS         += -Bstatic -L./lib -lGis
LIB_GIS		= ./lib/libGis.a
LIB_PLATFORM_DIR= ./src/platform
LIB_PRIMITIVES_DIR= ./src/primitives
LIB_GRAPHICS_DIR= ./src/graphics
LIB_HY_DIR	= ../HyLib
LIB_HY		= $(LIB_HY_DIR)/*.a

OBJS		= sample.o

all:d $(LIB_GIS) $(OBJS)
	$(LD) -o $(APPNAME) sample.o $(LIB_GIS) $(LIB_HY) $(LFLAGS) $(LFLAGS) 
	./test
       
$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

mk_lib_dir:
	if [ ! -d $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi

#$(LIB_GIS):mk_lib_dir lib_hy lib_platform lib_primitives lib_graphics
$(LIB_GIS):mk_lib_dir lib_hy lib_platform lib_primitives
	$(CP) $(LIB_PLATFORM_DIR)/*.o $(LIB_DIR)
	$(CP) $(LIB_PRIMITIVES_DIR)/*.o $(LIB_DIR)
	#$(CP) $(LIB_GRAPHICS_DIR)/*.o $(LIB_DIR)
	$(AR) $(LIB_GIS) $(LIB_DIR)*.o

lib_hy:
	$(MAKE) -C $(LIB_HY_DIR)

lib_platform:
	$(MAKE) -C $(LIB_PLATFORM_DIR)

lib_primitives:
	$(MAKE) -C $(LIB_PRIMITIVES_DIR)

lib_graphics:
	$(MAKE) -C $(LIB_GRAPHICS_DIR)

clean:
	$(RM) *.o
	$(RM) $(APPNAME)

d:distclean

distclean:clean
	$(RM) $(LIB_DIR)
	$(MAKE) -C $(LIB_PLATFORM_DIR) clean
	$(MAKE) -C $(LIB_PRIMITIVES_DIR) clean
	$(MAKE) -C $(LIB_GRAPHICS_DIR) clean
	$(MAKE) -C $(LIB_HY_DIR) clean

