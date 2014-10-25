##############################
# Makefile for camera server #
##############################
TARGET	= camera_server
TARGET_NO_LINE_DETECT	= camera_server_noLineDetect

# Compile flag
GCC = gcc

# additional include path
INC_PATH	= -I/usr/local/include/opencv/ -I./

# additional library path
LIB_PATH	= -L/usr/locla/lib -L./

#additional library
LIB	= -lopencv_highgui -lopencv_core -lpthread -ldeal_image

all:
	$(GCC) $(INC_PATH) $(LIB_PATH) -o $(TARGET) camera_server.c $(LIB)
	$(GCC) -DNO_LINE_DETECTION $(INC_PATH) $(LIB_PATH) -o $(TARGET_NO_LINE_DETECT) camera_server.c $(LIB)

clean:
	rm -f $(TARGET) $(TARGET_NO_LINE_DETECT) ./*~

install:
	cp ./$(TARGET) /usr/local/geye_with_cam/bin/image_receiver/$(TARGET)
	cp ./$(TARGET_NO_LINE_DETECT) /usr/local/geye_with_cam/bin/image_receiver/$(TARGET_NO_LINE_DETECT)
	cp ./libdeal_image.so /usr/local/geye_with_cam/lib/libdeal_image.so
