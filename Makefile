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

.PHONY: all clean install uninstall
