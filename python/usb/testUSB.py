#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import usb.core
import usb.util

# find our device
dev = usb.core.find(idVendor=0x8087, idProduct=0x8000)

#print(dir(dev.ctrl_transfer.__doc__))
print(dev.ctrl_transfer.__doc__)
# was it found?
if dev is None:
    raise ValueError('Device not found')

"""
# set the active configuration. With no arguments, the first
# configuration will be the active one
dev.set_configuration()

# get an endpoint instance
cfg = dev.get_active_configuration()
intf = cfg[(0,0)]

ep = usb.util.find_descriptor(
    intf,
    # match the first OUT endpoint
    custom_match = \
    lambda e: \
        usb.util.endpoint_direction(e.bEndpointAddress) == \
        usb.util.ENDPOINT_OUT)

assert ep is not None

# write the data
ep.write('test')
"""
