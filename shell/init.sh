#!/bin/bash

# Base
sudo apt-get install git gnupg curl libx11-dev libxi-dev libc6-dev libncurses5-dev libreadline6-dev g++-multilib cscope ctags cflow ttf-wqy-microhei ttf-wqy-zenhei ntpdate sudo vim vim-tiny mpg123 build-essential autoconf automake gdb gcc binutils linux-headers-$(uname -r) gnuplot flashplugin-nonfree libtool tree rar unrar zip meld mplayer2 gnome-mplayer ttf-arphic-ukai ttf-arphic-uming xfonts-intl-chinese xfonts-wqy ibus-googlepinyin gedit p7zip p7zip-full p7zip-rar pkg-config

# firefox 可以看chm文件
#chmsee 
# TODO: fix this problem
#sudo apt-get ia32-libs

# 博客
sudo apt-get install jekyll python-pygments

# verilog
sudo apt-get install iverilog gtkwave

#broken
#sudo apt-get install scim scim-tables-zh

# document
sudo apt-get install binutils-doc cpp-doc gcc-doc glibc-doc stl-manual manpages-zh manpages-dev manpages-posix-dev manpages-posix libx11-doc # man2html

# java
sudo apt-get install openjdk-7-jdk

# scheme
#sudo apt-get install scm
#sudo apt-get install tinyscheme
#sudo apt-get install scheme48 scheme48-doc
#sudo apt-get install scheme9
#sudo apt-get install sbcl sbcl-doc

# python & Qt
sudo apt-get install python3-pyqt4

# OpenGL
sudo apt-get install libegl1-mesa-dev
sudo apt-get install libgles2-mesa-dev
sudo apt-get install libopenvg1-mesa-dev
sudo apt-get install libgles2-mesa-dev
sudo apt-get install freeglut3-dev python-opengl
sudo apt-get install libglew-dev
sudo apt-get install libglui-dev

# Game
#sudo apt-get install wesnoth

# Tex
sudo apt-get install texlive-full texlive-doc-zh
sudo apt-get install asymptote asymptote-doc

sudo apt-get update
sudo apt-get upgrade

sudo apt-get autoremove
sudo apt-get autoclean

# ntp time 
#sudo ntpdate 210.72.145.44      # 国家授时中心
sudo ntpdate 202.120.2.101      # 上海交大
sudo hwclock --systohc

