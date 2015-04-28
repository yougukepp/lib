#!/bin/bash

# Base
sudo apt-get install git sudo vim build-essential autoconf automake gcc binutils libc6 linux-headers-$(uname -r) libtool

# Extra
sudo apt-get install libc6-dev libncurses5-dev libreadline6-dev g++-multilib cscope ctags cflow ntpdate sudo vim vim-tiny mpg123 gdb gnuplot flashplugin-nonfree tree rar unrar zip meld mplayer2 gnome-mplayer xfonts-intl-chinese xfonts-wqy gedit p7zip p7zip-full p7zip-rar pkg-config flex bison sed gawk bc u-boot-tools minicom sysv-rc-conf sylpheed zlib1g-dev subversion x-window-system-core gnome-core

# fonts
sudo apt-get install fonts-arphic* ttf-wqy* fonts-moe-standard* latex-cjk-chinese*

# 博客
#sudo apt-get install jekyll python-pygments ruby-rdiscount 

# verilog
#sudo apt-get install iverilog gtkwave

# octave 
#sudo apt-get install octave

# input method
sudo apt-get install fcitx-googlepinyin

# document
sudo apt-get install binutils-doc cpp-doc gcc-doc glibc-doc stl-manual manpages-zh manpages-dev manpages-posix-dev manpages-posix libx11-doc man2html

# java
# sudo apt-get install openjdk-7-jdk

# scheme
#sudo apt-get install scm
#sudo apt-get install tinyscheme
#sudo apt-get install scheme48 scheme48-doc
#sudo apt-get install scheme9
#sudo apt-get install sbcl sbcl-doc

# python & Qt
sudo apt-get install python3-pyqt5

# python & serial
sudo apt-get install python3-serial

# OpenGL
sudo apt-get install libegl1-mesa-dev libgles2-mesa-dev libopenvg1-mesa-dev libgles2-mesa-dev freeglut3-dev python-opengl libglew-dev

# Game
#sudo apt-get install wesnoth

# Tex
sudo apt-get install asymptote texlive-full asymptote-doc texlive-doc-zh
sudo apt-get install doxygen

# gnuradio
#sudo apt-get install gnuradio

# ssh & samba & nfs & tftp
# sudo apt-get install openssh-server ssh samba nfs-common nfs-kernel-server portmap
sudo  apt-get install tftp tftpd xinetd

# update
sudo apt-get update
sudo apt-get upgrade

sudo apt-get autoremove
sudo apt-get autoclean

# ntp time 
# sudo ntpdate 210.72.145.44      # 国家授时中心
sudo ntpdate 202.120.2.101      # 上海交大
sudo hwclock -w --localtime

