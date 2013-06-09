#!/bin/sh

find ./ -regex ".*\.\(cpp\|h\|c\)" -print | xargs wc -l
