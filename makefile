CC=g++

objDir=obj/

srcDir=src/

ifdef static
flags= \
 -DSFML_STATIC \
 -lsfml-graphics-s \
 -lsfml-window-s \
 -lsfml-system-s \
 -lsfml-audio-s \
 -std=c++11
else
flags= \
 -DSFML_DYNAMIC \
 -lsfml-graphics \
 -lsfml-window \
 -lsfml-system \
 -lsfml-audio \
 -std=c++11
endif

sfmlDir = C:/SFML/TDM-SFML-2.1

ifdef linux
    CFLAGS=$(flags)
    objEnd=.lin.obj
    exe=bin/Game
else
    CFLAGS=-I$(sfmlDir)\include -L$(sfmlDir)\lib $(flags)
    objEnd=.win.obj
    exe=bin\Game.exe
endif

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

aCpp:=$(call rwildcard,$(srcDir),*.cpp)
aObjs=$(aCpp:.cpp=$(objEnd))
aObj=$(aObjs:$(srcDir)%=$(objDir)%)


AUTODEPS:= $(aObj:=.d)

default: run

run: $(exe)
	$(exe)

$(exe): $(aObj)
	@$(CC) $(aObj) -o $(exe) $(CFLAGS)
	@echo "Binary created!"

-include $(AUTODEPS)

$(objDir)%$(objEnd): $(srcDir)%.cpp

	@$(CC) -MM -MT $@ $(CFLAGS) $< > $@.d
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$@"


testr:
	@echo $(CFLAGS)
