CC = g++
TARGET = main
FLAGG = -w
FRAMEWORKS = -framework OpenGL
INCLUDES = -Idepends/include
LIBS = -Ldepends/library
DYNAMICFILES = depends/library/libglfw.3.4.dylib
SOURCEPATH = source


all: clean compile

compile: 
	$(CC) $(SOURCEPATH)/* $(FLAGG) $(INCLUDES) $(LIBS) $(DYNAMICFILES) $(FRAMEWORKS) -o $(TARGET)

run: 
	./$(TARGET)

clean: 
	rm -f $(TARGET)