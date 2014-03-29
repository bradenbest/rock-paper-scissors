T=rock-paper-scissors

install:$(T) 
	mv $^ /usr/local/bin/
uninstall:
	rm /usr/local/bin/$(T)

$(T):
	@echo "Error: there isn't an executable in build/"
	@echo "Try 'cd ../ && sudo make install'"

.PHONY: install uninstall
