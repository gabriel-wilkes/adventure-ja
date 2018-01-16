# adventure-ja
Japanese version of the classic game, Colossal Cave Adventure. Based on the bsd games 2.17 version

I didn't create the translation, it appears the translation was done in 2011. There is the UTF-8 patch file that I used (and Windows binary if you're interested) here: http://ver0.sakura.ne.jp/pc/#advent

I tracked done the bsd games files and removed the other games and changed a few minor things to prevent build errors on Linux and OS X. Tested working fine on Ubuntu, Raspbian and OS X.

BSD Games lists the following as *prerequisites*, as long as you have basic build tools installed the only thing extra you may need is the ncurses library:

* GCC (the C and C++ compilers only - other languages not needed; C++
  only needed for dab).

* glibc 2.3 or later.  Older versions will not work (at least for
  hunt) since they lack the <ifaddrs.h> header.

* ncurses; other curses / termcap implementations might work, but are
  unsupported.

* lex and yacc; by default this package will use flex and bison, but
  byacc will probably work as well.

* GNU make.

* A POSIX shell, such as bash, in /bin/sh.

# Compile and install
./configure
make
sudo make install
