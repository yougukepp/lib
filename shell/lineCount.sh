#!/bin/sh

find ./ -regex ".*\.\(cpp\|h\|c\|py\|pyw\)" -print | xargs wc -l
