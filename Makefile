PARENTDIRECTORY = ..

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

all: main.o AssetModule UtilityModule RenderModule EngineModule
	$(CC) main.o -o main $(ASSETMODULE)/AssetModule.a $(UTILITYMODULE)/UtilityModule.a $(RENDERMODULE)/RenderModule.a $(ENGINEMODULE)/EngineModule.a $(LIBS) $(ENGINEMODULELIBS) $(ENGINEMODULEFLAGS) $(RENDERMODULELIBS) -g

main.o: main.cpp
	$(CC) -c main.cpp


EngineModule: EngineModule.so EngineModule.a

EngineModule.so: EngineModuleObjects
	cd $(ENGINEMODULE); $(CC) -shared -o EngineModule.so $(ENGINEMODULEOBJS) $(ENGINEMODULELIBS)

EngineModule.a: EngineModuleObjects
	cd $(ENGINEMODULE); ar rs EngineModule.a $(ENGINEMODULEOBJS)

EngineModuleObjects:
	cd $(ENGINEMODULE); $(CC) -c -fpic *.cpp $(ENGINEMODULEFLAGS) -I$(PARENTDIRECTORY)


RenderModule: RenderModule.so RenderModule.a

RenderModule.so: RenderModuleObjects
	cd $(RENDERMODULE); $(CC) -shared -o RenderModule.so $(RENDERMODULEOBJS) $(RENDERMODULELIBS)

RenderModule.a: EngineModuleObjects
	cd $(RENDERMODULE); ar rs RenderModule.a $(RENDERMODULEOBJS)

RenderModuleObjects:
	cd $(RENDERMODULE); $(CC) -c -fpic *.cpp $(RENDERMODULEFLAGS) -I$(PARENTDIRECTORY)


AssetModule: AssetModule.so AssetModule.a

AssetModule.so: AssetModuleObjects
	cd $(ASSETMODULE); $(CC) -shared -o AssetModule.so $(ASSETMODULEOBJS)

AssetModule.a: AssetModuleObjects
	cd $(ASSETMODULE); ar rs AssetModule.a $(ASSETMODULEOBJS)

AssetModuleObjects: $(ASSETMODULE)/*.cpp
	cd $(ASSETMODULE); $(CC) -c -fpic *.cpp -I$(PARENTDIRECTORY) 


UtilityModule: UtilityModule.so UtilityModule.a

UtilityModule.so: UtilityModuleObjects
	cd $(UTILITYMODULE); $(CC) -shared -o UtilityModule.so $(UTILITYMODULEOBS)

UtilityModule.a: UtilityModuleObjects
	cd $(UTILITYMODULE); ar rs UtilityModule.a $(UTILITYMODULEOBS)

UtilityModuleObjects: $(UTILITYMODULE)/*.cpp
	cd $(UTILITYMODULE); $(CC) -c -fpic *.cpp -I$(PARENTDIRECTORY)


clean:
	rm -f *.o main
	rm -f $(ASSETMODULE)/*.o $(ASSETMODULE)/*.a $(ASSETMODULE)/*.so
	rm -f $(UTILITYMODULE)/*.o $(UTILITYMODULE)/*.a $(UTILITYMODULE)/*.so
	rm -f $(ENGINEMODULE)/*.o $(ENGINEMODULE)/*.a $(ENGINEMODULE)/*.so
	rm -f $(RENDERMODULE)/*.o $(RENDERMODULE)/*.a $(RENDERMODULE)/*.so
