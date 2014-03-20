T=rock-paper-scissors
P=/usr/local/bin

all:
	cd src && $(MAKE)
	mv src/$(TARG) ./
clean:
	cd src && $(MAKE) clean
install: all
	mv $(T) $(P)
uninstall:
	rm $(P)/$(T)

.PHONY: all clean install uninstall
