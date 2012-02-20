#Set these accordingly to build for your platform of choice
BUILDPLATFORM = linux#possible choices: linux, win32mingw
TARGETPLATFORM = linux32#possible choices: linux32, linux64, win32

#Set according to your available tools. Default assumption is that you're using GCC / MinGW
CC = g++
AR = ar

#Don't touch anything below here unless you feel inclined to do something clever purely of your own volition
PROJECTROOT = ..
BUILDDIR = ./build
BINDIR = ./bin

LIBRARYBINARY = LiquidEngine.a

ENGINEMODULE = ./EngineModule
RENDERMODULE = ./RenderModule
ASSETMODULE = ./AssetModule
UTILITYMODULE = ./UtilityModule

LIBSDIR = ../lib
INCLDIR = ../include

ADDITIONALINCLUDES = -L$(INCLDIR)

RENDERMODULELIBS = -lGL -lGLU
ENGINEMODULELIBS = -lsfml-window -lsfml-system

#Here's where the platform logic begins, so prepare yourself for an adventure in inanity

#COPY or CP?
ifeq ($(BUILDPLATFORM), win32mingw)
	CP = copy
else ifeq ($(BUILDPLATFORM), linux32)
	CP = cp
else ifeq ($(BUILDPLATFORM), linux64)
	CP = cp
endif

#Which OpenGL libs should we link to? (OS-Specific)
OPENGLLIBS=
ifeq ($(TARGETPLATFORM),win32)
	OPENGLLIBS=-lopengl32 -lglu32
endif
ifeq ($(TARGETPLATFORM),linux32)
	OPENGLLIBS=-lGL -lGLU
endif
ifeq ($(TARGETPLATFORM),linux64)
	OPENGLLIBS=-lGL -lGLU
endif

#Here's all other configured logic:

#SFML linking
LINKING=
ifeq ($(TARGETPLATFORM),win32)
	LINKING = $(LIBSDIR)/SFML/win32/libsfml-system-d.a $(LIBSDIR)/SFML/win32/libsfml-window-d.a
endif
ifeq ($(TARGETPLATFORM),linux32)
	LINKING = -lsfml-window -lsfml-system
endif
ifeq ($(TARGETPLATFORM),linux64)
	LINKING = -lsfml-window -lsfml-system
endif



all: library demo

.PHONY: UtilityModule AssetModule RenderModule EngineModule library demo

demo: demo.o library
	$(CC) demo.o -o demo $(BINDIR)/$(LIBRARYBINARY) $(LIBS) $(LINKING) $(OPENGLLIBS) -g

demo.o:
	$(CC) -c demo.cpp -I../include

library: builddir bindir UtilityModule AssetModule RenderModule EngineModule
	cd $(BUILDDIR); ar rs $(LIBRARYBINARY) *.o
	cp $(BUILDDIR)/$(LIBRARYBINARY) $(BINDIR)/$(LIBRARYBINARY)

EngineModule:
	$(MAKE) -C $(ENGINEMODULE)
	cp $(ENGINEMODULE)/*.o $(BUILDDIR)

RenderModule:
	$(MAKE) -C $(RENDERMODULE)
	cp $(RENDERMODULE)/*.o $(BUILDDIR)

AssetModule:
	$(MAKE) -C $(ASSETMODULE)
	cp $(ASSETMODULE)/*.o $(BUILDDIR)

UtilityModule:
	$(MAKE) -C $(UTILITYMODULE)
	cp $(UTILITYMODULE)/*.o $(BUILDDIR)

builddir:
	if test -d $(BUILDDIR); then echo "Directory Exists"; else mkdir $(BUILDDIR); fi

bindir:
	if test -d $(BINDIR); then echo "Directory Exists"; else mkdir $(BINDIR); fi


clean:
	$(MAKE) -C $(UTILITYMODULE) clean
	$(MAKE) -C $(ASSETMODULE) clean
	$(MAKE) -C $(RENDERMODULE) clean
	$(MAKE) -C $(ENGINEMODULE) clean
	rm -rf demo.o
	rm -rf demo
