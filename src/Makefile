#Set these accordingly to build for your platform of choice
BUILDPLATFORM = win32mingw#possible choices: linux, win32mingw
TARGETPLATFORM = win32#possible choices: linux32, linux64, win32

#Set according to your available tools. Default assumption is that you're using GCC / MinGW
CC = g++
AR = ar

#Don't touch anything below here unless you feel inclined to do something clever purely of your own volition
PROJECTROOT = ..
BUILDDIR = build
BINDIR = bin

LIBRARYBINARY = LiquidEngine.a

PATHSEPARATOR=/

ENGINEMODULE = EngineModule
RENDERMODULE = RenderModule
ASSETMODULE = AssetModule
UTILITYMODULE = UtilityModule

LIBSDIR = ../lib
INCLDIR = ../include

ADDITIONALINCLUDES = -L$(INCLDIR)

RENDERMODULELIBS = -lGL -lGLU
ENGINEMODULELIBS = -lsfml-window -lsfml-system

#Here's where the platform logic begins, so prepare yourself for an adventure in inanity

#COPY or CP?
ifeq ($(BUILDPLATFORM),win32mingw)
	CP = copy
else ifeq ($(BUILDPLATFORM),linux)
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
	LINKING = $(LIBSDIR)/SFML/win32/libsfml-system.a $(LIBSDIR)/SFML/win32/libsfml-window.a
endif
ifeq ($(TARGETPLATFORM),linux32)
	LINKING = -lsfml-window -lsfml-system
endif
ifeq ($(TARGETPLATFORM),linux64)
	LINKING = -lsfml-window -lsfml-system
endif

#Do we need to replace path separators?
ifeq ($(BUILDPLATFORM),win32mingw)
	PATHSEPARATOR=\\#must be escaped. Stupid.
endif


all: library demo

.PHONY: UtilityModule AssetModule RenderModule EngineModule library demo bindir builddir

demo: demo.o library
	$(CC) demo.o -o demo $(BINDIR)/$(LIBRARYBINARY) $(LIBS) $(LINKING) $(OPENGLLIBS) -g

demo.o:
	$(CC) -c demo.cpp -I../include

library: builddir bindir UtilityModule AssetModule RenderModule EngineModule
	cd $(BUILDDIR) & ar rs $(LIBRARYBINARY) *.o
	$(CP) $(BUILDDIR)$(PATHSEPARATOR)$(LIBRARYBINARY) $(BINDIR)/$(LIBRARYBINARY)

EngineModule:
	$(MAKE) -C $(ENGINEMODULE)
	$(CP) $(ENGINEMODULE)$(PATHSEPARATOR)*.o $(BUILDDIR)

RenderModule:
	$(MAKE) -C $(RENDERMODULE)
	$(CP) $(RENDERMODULE)$(PATHSEPARATOR)*.o $(BUILDDIR)

AssetModule:
	$(MAKE) -C $(ASSETMODULE)
	$(CP) $(ASSETMODULE)$(PATHSEPARATOR)*.o $(BUILDDIR)

UtilityModule:
	$(MAKE) -C $(UTILITYMODULE)

	$(CP) $(UTILITYMODULE)$(PATHSEPARATOR)*.o $(BUILDDIR)



builddir:
ifeq ($(BUILDPLATFORM),win32mingw)
	if exist $(BUILDDIR) (echo "Directory Exists") else (mkdir $(BUILDDIR))
endif
ifeq ($(BUILDPLATFORM),linux32)
	if test -d $(BUILDDIR); then echo "Directory Exists"; else mkdir $(BUILDDIR); fi
endif
ifeq ($(BUILDPLATFORM),linux64)
	if test -d $(BUILDDIR); then echo "Directory Exists"; else mkdir $(BUILDDIR); fi
endif

bindir:
ifeq ($(BUILDPLATFORM),win32mingw)
	if exist $(BINDIR) (echo "Directory Exists") else (mkdir $(BINDIR))
endif
ifeq ($(BUILDPLATFORM),linux32)
	if test -d $(BINDIR); then echo "Directory Exists"; else mkdir $(BINDIR); fi
endif
ifeq ($(BUILDPLATFORM),linux64)
	if test -d $(BINDIR); then echo "Directory Exists"; else mkdir $(BINDIR); fi
endif


clean:
	$(MAKE) -C $(UTILITYMODULE) clean
	$(MAKE) -C $(ASSETMODULE) clean
	$(MAKE) -C $(RENDERMODULE) clean
	$(MAKE) -C $(ENGINEMODULE) clean
	rm -rf demo.o
	rm -rf demo
