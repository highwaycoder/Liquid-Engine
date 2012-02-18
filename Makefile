PARENTDIRECTORY = ..

BUILDDIR = ./build
BINDIR = ./bin

LIBRARY = LiquidEngine.a

ENGINEMODULE = ./EngineModule
ENGINEMODULEOBJS = EngineWindow.o EngineWindowManager.o

#ENGINEMODULEFLAGS = $(shell wx-config --cppflags)
#ENGINEMODULELIBS = $(shell wx-config --libs --gl-libs)

ENGINEMODULEFLAGS = 
ENGINEMODULELIBS = 


RENDERMODULE = ./RenderModule
RENDERMODULEOBJS = Render.o CompositeRender.o

RENDERMODULELIBS = -lGL -lGLU 

ASSETMODULE = ./AssetModule
ASSETMODULEOBJS = BitmapLoader.o TargaLoader.o ObjLoader.o Vertex.o TextureCoordinate.o Normal.o Face.o Model.o TextureSample2D.o

UTILITYMODULE = ./UtilityModule
UTILITYMODULEOBS = StringProcessing.o

LIBS = -lglfw -lsfml-window -lsfml-system

CC = g++

all: bindir builddir main.o AssetModule UtilityModule RenderModule EngineModule
	$(CC) main.o -o main 

.PHONY: UtilityModule AssetModule RenderModule EngineModule library

demo:
	$(CC) demo.cpp -o demo $(BINDIR)/$(LIBRARY) $(LIBS) $(ENGINEMODULELIBS) $(ENGINEMODULEFLAGS) $(RENDERMODULELIBS) -g

library: builddir bindir UtilityModule AssetModule RenderModule EngineModule
	cd $(BUILDDIR); ar rs $(LIBRARY) *.o
	cp $(BUILDDIR)/$(LIBRARY) $(BINDIR)/$(LIBRARY)

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

