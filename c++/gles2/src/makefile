include         ../buildvars 

LIB_QG		= libQg.a
PLATFORM_DIR	= ./platform
PRIMITIVE_DIR	= ./primitive
PLANE_DIR	= ./plane
SOLID_DIR	= ./solid

all:$(LIB_QG)
	$(AR) $(LIB_QG) ./*.o
       
#$(LIB_QG): lib_platform lib_primitive lib_plane lib_solid
$(LIB_QG): lib_platform lib_primitive
	$(CP) $(PLATFORM_DIR)/*.o ./
	$(CP) $(PRIMITIVE_DIR)/*.o ./
	#$(CP) $(PLANE_DIR))/*.o ./
	#$(CP) $(SOLID_DIR))/*.o ./

lib_platform:
	$(MAKE) -C $(PLATFORM_DIR)

lib_primitive:
	$(MAKE) -C $(PRIMITIVE_DIR)

lib_plane:
	$(MAKE) -C $(PLANE_DIR)

lib_solid:
	$(MAKE) -C $(SOLID_DIR)

clean:
	$(RM) *.o
	$(RM) *.a
	$(MAKE) -C $(PLATFORM_DIR) clean
	$(MAKE) -C $(PRIMITIVE_DIR) clean
	#$(MAKE) -C $(PLANE_DIR) clean
	#$(MAKE) -C $(SOLID_DIR) clean

