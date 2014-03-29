# Rock paper scissors

It's the game of rock paper scissors.

# Note: a lot of features are still unimplemented

## Manual Installation

To compile, run

```bash
    $ make
```

To install (automatically does the previous step), run

```bash
    $ sudo make install
```

To uninstall, run

```bash
    $ sudo make uninstall
```

## Pre-compiled Installation

To download, go to the releases tab above and find the latest release, then click the green download button (`rock-paper-scissors.tar.gz` or `rock-paper-scissors.zip`), save it.

Then extract it and run the install script.

To extract via the command line, open a command line, navigate to your downloads folder by running

```bash
    $ cd ~/Downloads
```

And then, for tar.gz:

```bash
    $ tar xf rock-paper-scissors.tar.gz
    $ cd rock-paper-scissors/
```

or for .zip:

```bash
    $ unzip rock-paper-scissors.zip
    $ cd rock-paper-scissors/
```

after that, you can either proceed to install, or play it righ there

To play without installing:

```bash
    $ ./rock-paper-scissors
```

To install and play:

```bash
    $ ./install
    $ rock-paper-scissors
```

To uninstall, run:

```bash
    $ ./uninstall
```

If you deleted the directory, no worries! Just re-download the release (`rock-paper-scissors reports the version each time it's run`), and repeat the above steps
