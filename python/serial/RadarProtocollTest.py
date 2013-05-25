#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import serial
import struct

gTimeOut = 1
gRecvBufSize = 2048

# 起始于终止
gStartFlag = b'\x7E'
gEndFlag = b'\x16'

# 帧标识
gId = b'\xAA'

# 协议常量宏
# DIR
gCrt = 0x00
gRadio = 0x40
gServo = 0x80
gSignal = 0xC0
# PRM
gDriving = 0x20
gDriven = 0x00

# AFN
gAfnAck = b'\x00'
gAfnParaSet = b'\x01'
gAfnRestoreInit = b'\x06'
gAfnUpdate = b'\x07'
gAfnPara = b'\x02'
gAfnParaEcho = b'\x82'
gAfnConfig = b'\x03'
gAfnConfigEcho = b'\x83'
gAfnVersion = b'\x04'
gAfnVersionEcho = b'\x84'
gAfnWorkStatus = b'\x05'
gAfnWorkStatusEcho = b'\x85'

# SEQ
gSeq00 = b'\x00'
gSeq60 = b'\x60'

gAbnormalCasesTable = {
     # 测试用例名字: (发送报文, 期望报文)

        "回显字节" : ( b'\x01', b"\x01" ),
        "回显字母" : ( b"hello", b"hello" ),
        "回显数字" : ( b"123", b"123" )
        }

gServoCasesTable = {
    # 测试用例名字 : (DIR,   PRM,      AFN,     SEQ,    帧标识, 数据)
    "伺服待机" :
    {
        "发送报文":
        {
            "DIR":gCrt,
            "PRM":gDriving,
            "AFN":gAfnParaSet,
            "SEQ":gSeq00,
            "帧标识":gId,
            "数据":b'\x20\x00\x00\x00\x00',
        },
        "期望报文":
        {
            "DIR":gServo,
            "PRM":gDriven,
            "AFN":gAfnAck,
            "SEQ":gSeq60,
            "帧标识":gId,
            "数据": b'\x20\x00\x00\x00\x01',
        }
    },
    "伺服发射" :
    {
        "发送报文":
        {
            "DIR":gCrt,
            "PRM":gDriving,
            "AFN":gAfnParaSet,
            "SEQ":gSeq00,
            "帧标识":gId,
            "数据": b'\x20\x00\x00\x00\x01',
        },
        "期望报文":
        {
            "DIR": gServo,
            "PRM": gDriven,
            "AFN": gAfnAck,
            "SEQ": gSeq60,
            "帧标识": gId,
            "数据": b'\x20\x00\x00\x00\x01',
        }
    }
}

def BytesPrint(byteStream):
    for c in byteStream:
        print("%02x," % c, end='')
    print()

def makeMessage(message):
    byteStream = b''

    """
    print("PP")
    print("AFN:" + str(message["AFN"]))
    print("SEQ:" + str(message["SEQ"]))
    print("帧标识:" + str(message["帧标识"]))
    print("数据:" + str(message["数据"]))
    print("PP end")
    """
    userData = message["AFN"] + message["SEQ"] + message["帧标识"] + message["数据"]

    dLength = len(userData)
    sLength = struct.pack('h', dLength)
    """
    print("PP")
    print("sLength:" + str(sLength))
    print("PP end")
    """

    fmt = b'B' * dLength
    """
    print("PP")
    print("fmt:" + str(fmt))
    print("userData" + str(userData))
    print("PP end")
    """
    csFieldList = struct.unpack(fmt, userData)

    # 计算校验和
    dCsField = 0
    for i in csFieldList:
        dCsField += i
    dCsField %= 256
    sCsField = struct.pack('h', dCsField)

    byteStream += gStartFlag

    dCField = message["DIR"] | message["PRM"]
    sCField = struct.pack('B', dCField)
    """
    print("PP")
    print("DIR:" + str(message["DIR"]))
    print("PRM:" + str(message["PRM"]))
    print("dCField:" + str(dCField))
    print("sCField:" + str(sCField))
    print("PP end")
    while True:
        pass
    """
    byteStream += sCField
    byteStream += message["AFN"]
    byteStream += message["SEQ"]
    byteStream += message["帧标识"]
    byteStream += message["数据"]
    byteStream += sCsField
    byteStream += gEndFlag

    return byteStream

def testAll(casesTable):
    print("开始测试...")
    for name in casesTable:
        senddedMessage = casesTable[name][0]
        expectMessage = casesTable[name][1]
        print("测试 " + name, end='');
        if testMessage(senddedMessage, expectMessage):
            print("成功")
    print("测试完毕")
    print()

def testProtocol(casesTable):
    print("开始测试...")
    print()
    for name in casesTable:
        print("测试 " + name, end='');
        senddedMessage = makeMessage(casesTable[name]["发送报文"])
        expectMessage = makeMessage(casesTable[name]["期望报文"])
        if testMessage(senddedMessage, expectMessage):
            print("成功")
        print()
    print("测试完毕")
    print()

def testMessage(senddedMessage, expectMessage):
    ser = serial.Serial(0)
    ser.timeout = gTimeOut
    w = ser.write(senddedMessage)
    r = ser.read(gRecvBufSize)
    if b'' == r:
        print("测试失败:接收超时")
        return False
    elif r != expectMessage:
        print("测试失败:")
        print("发送:", end='')
        BytesPrint(senddedMessage)
        print("接收:", end='')
        BytesPrint(r)
        print("期望:", end='')
        BytesPrint(expectMessage)
        print("实际接收与期望值不一致导致失败.")
        return False
    else: # r == expectMessage 测试通过
        pass
        return True

if __name__ == "__main__":
    #testAll(gAbnormalCasesTable)
    testProtocol(gServoCasesTable)
    testProtocol(gRadioCasesTable)

