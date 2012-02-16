PARENTDIRECTORY = ..

UIMODULE = ./UIModule
UIMODULEOBJS = UIModule.o EngineCanvas.o EditorWindow.o EngineWindow.o UIApp.o EngineKeyEvent.o EngineMouseEvent.o

UIMODULEFLAGS = $(shell wx-config --cppflags)
UIMODULELIBS = $(shell wx-config --libs --gl-libs)

RENDERMODULE = ./RenderModule
RENDERMODULEOBJS = Render.o CompositeRender.o

RENDERMODULELIBS = -lGL -lGLU 

ASSETMODULE = ./AssetModule
ASSETMODULEOBJS = BitmapLoader.o TargaLoader.o ObjLoader.o Vertex.o TextureCoordinate.o Normal.o Face.o Model.o TextureSample2D.o

UTILITYMODULE = ./UtilityModule
UTILITYMODULEOBS = StringProcessing.o

LIBS = -lglfw

CC = g++

all: main.o AssetModule UtilityModule UIModule.a RenderModule
	$(CC) main.o -o main $(ASSETMODULE)/AssetModule.a $(UTILITYMODULE)/UtilityModule.a $(UIMODULE)/UIModule.a $(RENDERMODULE)/RenderModule.a $(LIBS) $(UIMODULELIBS) $(UIMODULEFLAGS) $(RENDERMODULELIBS) -g

main.o: main.cpp
	$(CC) -c main.cpp


UIModule: UIModule.so UIModule.a

UIModule.so: UIModuleObjects
	cd $(UIMODULE); $(CC) -shared -o UIModule.so $(UIMODULEOBJS) $(UIMODULELIBS)

UIModule.a: UIModuleObjects
	cd $(UIMODULE); ar rs UIModule.a $(UIMODULEOBJS)

UIModuleObjects:
	cd $(UIMODULE); $(CC) -c -fpic *.cpp $(UIMODULEFLAGS) -I$(PARENTDIRECTORY)


RenderModule: RenderModule.so RenderModule.a

RenderModule.so: RenderModuleObjects
	cd $(RENDERMODULE); $(CC) -shared -o RenderModule.so $(RENDERMODULEOBJS) $(RENDERMODULELIBS)

RenderModule.a: UIModuleObjects
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
	rm -f $(UIMODULE)/*.o $(UIMODULE)/*.a $(UIMODULE)/*.so
	rm -f $(RENDERMODULE)/*.o $(RENDERMODULE)/*.a $(RENDERMODULE)/*.so
