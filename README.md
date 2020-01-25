# Japanese Learning Adventure
This is a unique English and Japanese bilingual version of the classic game, [Colossal Cave Adventure](https://en.wikipedia.org/wiki/Colossal_Cave_Adventure). Also included is Japanese phonetic characters (furigana) assist Japanese learners. It is based on the bsd games 2.17 version.

The original version of Colossal Cave Adventure was developed starting in 1975 and released in 1976 on the DEC PDP-10 mainframe. Its historical significance can't be overstated, according to Wikipedia, "Colossal Cave Adventure is the first known work of interactive fiction and, as the first text adventure game, is considered the precursor for the adventure game genre. Colossal Cave Adventure also contributed towards the role-playing and roguelike genres."

I didn't create the translation, it appears the translation was done in 2011. There is the UTF-8 patch file that I used (and Windows binary if you're interested) here: http://ver0.sakura.ne.jp/pc/#advent

I combined the English and Japanese patched versions and added the furigana to make the classic game into a Japanese learning tool. I also tracked done the bsd games files and removed the other games and changed a few minor things to prevent build errors on Linux and OS X. Tested working fine on Ubuntu, Raspbian and OS X.

Below are listed the prerequisites and build/install/run directions for macOS and Linux.

![Screenshot of Japanese Learning Adventure](https://i.imgur.com/eCkMKHq.png)

# Prerequisites

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

# Build/install/run directions for macOS and Linux
1. Run ```./configure``` in the main project directory
2. ```make```
3. ```sudo make install```
4. ```adventure```
