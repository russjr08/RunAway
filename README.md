RunAway
==========

A game with no real purpose. I'm creating this game to help me learn the ropes
of C++ and SFML.


How To Compile / Submit a Pull Request
======================================
1) Clone the project

2) Download and install [SFML](http://sfml-dev.org) for your platform

(If on Linux or OS X, proceed to step 7)

3) (Windows) Install [TDM](http://tdm-gcc.tdragon.net/) and [MSYS](http://downloads.sourceforge.net/mingw/MSYS-1.0.11.exe)

4) (Windows) Make sure SFML is in C:\TDM-SFML-2.1\ or adjust sfmlDir in makefile

5) (Windows) Try to run make and see if everything compiles correctly. If not,
you may need to create a bin and obj folder (and a subfolder for all of the subfolders in src/, ex: obj/Entity, obj/Level)

6) Retry make. It should work now, if it doesn't, feel free to create an issue.

7) (All Platforms) Verify make works, and you should be ready to roll!

Credits
=======
[Triavanicus](http://twitch.tv/Triavanicus) for letting me use [his makefile](https://gist.github.com/Triavanicus/3a37db4319f476afa403) :D
