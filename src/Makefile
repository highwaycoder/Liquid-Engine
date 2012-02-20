CC = g++

PARENTDIRECTORY = ..
BUILDDIR = ./build
BINDIR = ./bin

LIBRARY = LiquidEngine.a

ENGINEMODULE = ./EngineModule
RENDERMODULE = ./RenderModule
ASSETMODULE = ./AssetModule
UTILITYMODULE = ./UtilityModule

RENDERMODULELIBS = -lGL -lGLU 
ENGINEMODULELIBS = -lsfml-window -lsfml-system

LIBS = 


all: library demo

.PHONY: UtilityModule AssetModule RenderModule EngineModule library demo

demo: demo.o library
	$(CC) demo.o -o demo $(BINDIR)/$(LIBRARY) $(LIBS) $(ENGINEMODULELIBS) $(RENDERMODULELIBS) -g

demo.o:
	$(CC) -c demo.cpp

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
	rm -rf demo.o
	rm -rf demo
