[**Results in this milestone**](https://github.com/zikocult/Cursus42/tree/main/02_ring)

We are facing a unique project where we will be installing a Linux machine in a local virtualized environment, using VirtualBox in my case.

No graphical environment was allowed for this project.

In my case, I opted for the installation version of Rocky Linux, with the corresponding configuration of SSH, HTTP, PHP, WordPress, Cockpit and firewall services.

On the other hand, work has also been done on securing passwords, users, as well as SSH access and the configuration of SELinux.

One of the tasks to be carried out was creating a script for monitoring the server status, and configuring it with Cron so that its execution could be seen by all connected users, here is my script.

```bash
#!/bin/bash

ARQUITECTURA=$(uname -a)

VIRTPROC=$(cat /proc/cpuinfo | grep "processor" | wc -l)

PHYSPROC=$(cat /proc/cpuinfo | grep "physical id" | wc -l)

MEM_USED=$(free --mega | awk '$1 == "Mem:" {print $3}')
MEM_TOTAL=$(free --mega | grep "Mem:" | awk '{Mem = $2} END {printf("%iMb", Mem)}')
MEM_PCT=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}')

HD_USED=$(df -m | grep -v "tmpfs" | awk '{use += $3} END {printf("%.2f", use / 1024)}')
HD_TOTAL=$(df -m | grep -v "tmpfs" | awk '{use += $2} END {printf("%.2fGb", use / 1024)}')
HD_PCT=$(df -m | grep -v "tmpfs" | awk '{use += $3} {total +=$2} END {printf("%.2f%%", (use / total)*100)}')

CPU_USE=$(ps -eo "%C" | awk '{cpu+=$1} END {printf("%.1f%%\n", cpu)}')

LAST_BOOT=$(who -b | awk '{print $3 " " $4}')

LVM_USE=$(if [ $(lsblk | grep "LVM" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

TCP_ESTAB=$(ss -ta | grep "ESTAB" | wc -l)

USER_LOGGED=$(users | wc -w)

IP=$(hostname -I | awk '{print $1}')

MAC=$(ip link | grep "link/ether" | awk '{mac = $2} END {printf("(%s)", mac)}')

SUDO_CMD=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall "
                #Architecture: $ARQUITECTURA
                #CPU physical: $PHYSPROC
                #vCPU: $VIRTPROC
                #Memory Usage: $MEM_USED/$MEM_TOTAL $MEM_PCT
                #Disk Usage: $HD_USED/$HD_TOTAL ($HD_PCT)
                #CPU Load: $CPU_USE
                #Last Boot: $LAST_BOOT
                #LVM Use: $LVM_USE
                #Connections TCP: $TCP_ESTAB ESTABLISHED
                #User log: $USER_LOGGED
                #Network IP $IP $MAC
                #Sudo: $SUDO_CMD cmd"

```

<p align="left">
  <a href="https://github.com/zikocult/Cursus42/tree/main/02_ring"><img src="https://github.com/zikocult/Cursus42/blob/main/02_ring/docs/assets/Born2beroot/script.png" /></a>
</p>

*Note*: I take the image in my own computer, because I needed the disk space of the virtual machine for my actual projects.

**My opinion about the project 🖥️**

I have had a lot of fun working on this project and testing my knowledge about Linux, services, and servers, and learning about the history of this operating system.


