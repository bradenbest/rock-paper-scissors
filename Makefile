T=rock-paper-scissors
P=/usr/local/bin

all:
	cd src && $(MAKE)
	mv src/$(T) ./
clean:
	cd src && $(MAKE) clean
install: all
	mv $(T) $(P)
uninstall:
	rm $(P)/$(T)
build: all
	mv $(T) installer/build/
	tar zcf installer.tar.gz installer/
	zip -r installer.zip installer/

.PHONY: all clean install uninstall build
