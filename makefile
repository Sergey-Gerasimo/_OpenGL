CC = g++
TARGET = main
GITIGNORELIST = $(TARGET) \ndepends \n.vscode 
FLAGG = -w -std=c++11
FRAMEWORKS = -framework OpenGL
INCLUDES = -Idepends/include
LIBS = -Ldepends/library
DYNAMICFILES = depends/library/libglfw.3.4.dylib
SOURCEPATH = source


all: clean compile
	echo "$(GITIGNORELIST)" >> ./.gitignore


compile: 
	$(CC) $(SOURCEPATH)/* $(FLAGG) $(INCLUDES) $(LIBS) $(DYNAMICFILES) $(FRAMEWORKS) -o $(TARGET)

run: 
	./$(TARGET)

clean: 
	echo > .gitignore
	rm -f $(TARGET)