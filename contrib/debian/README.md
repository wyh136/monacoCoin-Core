
Debian
====================
This directory contains files used to package monacoCoind/monacoCoin-qt
for Debian-based Linux systems. If you compile monacoCoind/monacoCoin-qt yourself, there are some useful files here.

## monacoCoin: URI support ##


monacoCoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install monacoCoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your monacoCoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/dash128.png` to `/usr/share/pixmaps`

monacoCoin-qt.protocol (KDE)

