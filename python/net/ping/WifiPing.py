#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import struct
import array
import time
import socket
import threading

class IpPool:
    def __init__(self):
        pass

    def AddIp(self, ip):
        print(ip)
  
class IcmpSender:
    def __init__(self, sock):
        self.mSock = sock 
        
    def CheckSum(self, packet):
        '''ICMP 报文效验和计算方法'''
        if len(packet) & 1:
            packet = packet + '\0'
        words = array.array('h', packet)
        sum = 0
        for word in words:
            sum += (word & 0xffff)
        sum = (sum >> 16) + (sum & 0xffff)
        sum = sum + (sum >> 16)
  
        return (~sum) & 0xffff 
    
    def MakeIcmpPacket(self, data):
        '''构造 ICMP 报文'''
        idField = os.getpid()                   # 构造ICMP报文的ID字段，无实际意义

        header = struct.pack('bbHHh', 8, 0, 0, idField, 0) # TYPE、CODE、CHKSUM、ID、SEQ
    
        packet = header + data                  # packet without checksum
        checksum = self.CheckSum(packet)        # make checksum
        header = struct.pack('bbHHh', 8, 0, checksum, idField, 0)

        packet = header + data
  
        return packet

    def Send(self, ipOrUrl, data): 
        sock = self.mSock
        packet = self.MakeIcmpPacket(data)
        sock.sendto(packet, (ipOrUrl, 0))
        pass


class IcmpRecvThread(threading.Thread):
    '''
    接收ICMP回显报文的线程。
  
    参数：
        timeout -- 接收超时
        bufSize -- 接收缓冲
    '''
    def __init__(self, sock, bufSize=1024):
        threading.Thread.__init__(self)

        self.mSock = sock
        self.mBufSize = bufSize
        self.mOver = False

        self.mPingOk = False

    def run(self): 
        #print('Icmp Recv Thread Start...') 
        try: 
            sock = self.mSock
            rst = sock.recvfrom(self.mBufSize)
            #print(rst)
            self.mPingOk = True
        except socket.timeout as err:
            #print('Icmp Recv Thread ', end = '') 
            #print(err)
            pass

        #print('Icmp Recv Thread End.')
        self.mOver = True

    def PingOk(self):
        if self.mOver:
            return self.mPingOk
        else:
            print('还未到超时值')

def WifiPing(ipOrUrl, timeout):
    socketIcmp = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.getprotobyname("icmp")) 
    socketIcmp.settimeout(timeout)

    icmpRecvThread = IcmpRecvThread(socketIcmp)
    icmpRecvThread.start()

    data = struct.pack('d', time.time())    # 用于ICMP报文的负荷字节（8bit）
    icmpSender = IcmpSender(socketIcmp)
    icmpSender.Send(ipOrUrl, data)
    
    time.sleep(timeout + 0.01)              # sencond 作为单位
    return icmpRecvThread.PingOk()

if __name__=='__main__':
    ipPool = IpPool()

    ipHead = '10.33.152.'
    for ipLast in range(1, 256):
        ip = ipHead + str(ipLast)
        ipPool.AddIp(ip)
        print(ip)

    #WifiPing()

