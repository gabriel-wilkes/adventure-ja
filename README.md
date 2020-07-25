# Japanese Learning Adventure
This is a unique English and Japanese bilingual version of the classic game, [Colossal Cave Adventure](https://en.wikipedia.org/wiki/Colossal_Cave_Adventure). Also included is Japanese phonetic characters (furigana) to assist Japanese learners. It is based on the bsd games 2.17 version.

The original version of Colossal Cave Adventure was developed starting in 1975 and released in 1976 on the DEC PDP-10 mainframe. Its historical significance can't be overstated, according to Wikipedia, "Colossal Cave Adventure is the first known work of interactive fiction and, as the first text adventure game, is considered the precursor for the adventure game genre. Colossal Cave Adventure also contributed towards the role-playing and roguelike genres."

I didn't create the translation, it appears the translation was done in 2011 by [@maruhiro-ver0](https://github.com/maruhiro-ver0) who created the UTF-8 patch file that I used (and Windows binary if you're interested) here: http://ver0.sakura.ne.jp/pc/#advent.

I combined the English and Japanese patched versions and added the furigana to make the classic game into a Japanese learning tool. I also tracked done the bsd games files and removed the other games and changed a few minor things to prevent build errors on Linux and macOS. The build process described below is tested working fine on Ubuntu, Raspbian and macOS.

In 2020 [@maruhiro-ver0](https://github.com/maruhiro-ver0) corrected the auto-generated furigana this project originally used making it much more useful for actually learning Japanese, thank you!

Below are listed the directions for running the macOS binary and the prerequisites/build/install/run directions for macOS and Linux.

![Screenshot of Japanese Learning Adventure](https://user-images.githubusercontent.com/1679408/88465555-f4a9b880-cefe-11ea-9cff-87e6620c4e5a.png)

# Run directions for macOS (Intel)
1. Run ```./adv``` in the main project directory

# Prerequisites for building on Linux or macOS

BSD Games lists the following as *prerequisites*, as long as you have basic build tools installed the only thing extra you may need is the ncurses library:

* ncurses; other curses / termcap implementations might work, but are
  unsupported. One easy way to install on macOS is to use [brew](https://brew.sh/) and run ```brew install homebrew/dupes/ncurses```. On linux the method will vary but you'll be used to that already if you're using linux.

* GCC (the C and C++ compilers only - other languages not needed; C++
  only needed for dab).

* glibc 2.3 or later.  Older versions will not work (at least for
  hunt) since they lack the <ifaddrs.h> header.

* lex and yacc; by default this package will use flex and bison, but
  byacc will probably work as well.

* GNU make.

* A POSIX shell, such as bash, in /bin/sh.

# Build/install/run directions for Linux or macOS
1. Run ```./configure``` in the main project directory
2. ```make```
3. ```sudo make install```
4. ```adventure```
