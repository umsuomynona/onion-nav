CC=gcc
RESULT=onion-nav
TARGET=$(RESULT).c
INCLUDE=-I include/
CC_FLAGS=`pkg-config --libs --cflags webkit2gtk-4.0 json-glib-1.0` -g $(INCLUDE)
OBJS=init.o http.o home.o settings.o log.o
DATA_FILES_DIR=/usr/share/$(RESULT)
CONFIG_FILE=$(DATA_FILES_DIR)/settings.json
BIN_DIR=/bin/$(RESULT)

all: objects.o

init.o: src/init.c
	$(CC) -c src/init.c $(CC_FLAGS)

http.o: src/http.c
	$(CC) -c src/http.c $(CC_FLAGS)

home.o: src/home.c
	$(CC) -c src/home.c $(CC_FLAGS)

settings.o: src/settings.c
	$(CC) -c src/settings.c $(CC_FLAGS)

log.o: src/log.c
	$(CC) -c src/log.c $(CC_FLAGS)

objects.o: $(OBJS)
	$(CC) $(OBJS) $(TARGET) -o $(RESULT)  $(CC_FLAGS)

clear:
	rm *.o $(RESULT)

install: all
	mkdir -p $(DATA_FILES_DIR)
	find $(DATA_FILES_DIR) -type d -exec chmod 777 {} \;
	find $(DATA_FILES_DIR) -type f -exec chmod 755 {} \;
	#echo "{}" > $(CONFIG_FILE) #config file
	mkdir -p $(DATA_FILES_DIR)/logs
	cp $(RESULT) $(BIN_DIR)

desinstall:
	rm -rf $(DATA_FILES_DIR)
	rm $(BIN_DIR)
