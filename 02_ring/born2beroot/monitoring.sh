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
