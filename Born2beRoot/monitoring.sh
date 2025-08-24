#!/bin/bash

logger -t monitoring "Script started"

show_info() {
    # Kernel and OS information
    ARCH=$(uname -srvmo)

    # CPU information
    PCPU=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
    VCPU=$(grep -c "^processor" /proc/cpuinfo)

    # Memory usage (RAM)
    RAM_TOTAL=$(free -m | awk '/Mem:/ {print $2}')
    RAM_USED=$(free -m | awk '/Mem:/ {print $3}')
    RAM_PERCENT=$((RAM_USED * 100 / RAM_TOTAL))

    # Disk sum /dev/ and /dev/mapper, excluding /boot
    DISK_STATS=$(df -B1 | awk '/^\/dev\/|^\/dev\/mapper/ && $6 != "/boot" {total+=$2; used+=$3} END {printf "%d %d %d\n", used, total, (total>0?used*100/total:0)}')
    read DISK_USED DISK_TOTAL DISK_PERCENT <<< "$DISK_STATS"
    DISK_USED_H=$(numfmt --to=iec --suffix=B "$DISK_USED")
    DISK_TOTAL_H=$(numfmt --to=iec --suffix=B "$DISK_TOTAL")

    # CPU load (1 min load average)
    CPU_LOAD=$(uptime | awk -F'load average:' '{print $2}' | cut -d, -f1 | xargs)

    # System uptime
    LAST_BOOT=$(who -b | awk '{print $3 " " $4}')

    # LVM status
    LVM_STATUS=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")

    # Network information
    TCP_CONN=$(ss -t state established | wc -l)
    IP_ADDR=$(hostname -I | awk '{print $1}')
    MAC_ADDR=$(ip link show | awk '/ether/ {print $2}' | head -n1)

    # User information
    USER_LOG=$(users | wc -w)

    # Sudo commands count
    SUDO_LOG=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

    # Formatting message
    MESSAGE="
#Architecture: $ARCH
#CPU physical: $PCPU
#vCPU: $VCPU
#Memory Usage: ${RAM_USED}/${RAM_TOTAL}MB ($RAM_PERCENT%)
#Disk Usage: ${DISK_USED_H}/${DISK_TOTAL_H} ($DISK_PERCENT%)
#CPU load: $CPU_LOAD
#Last boot: $LAST_BOOT
#LVM use: $LVM_STATUS
#Connexions TCP: $TCP_CONN ESTABLISHED
#User log: $USER_LOG
#Network: IP $IP_ADDR ($MAC_ADDR)
#Sudo: $SUDO_LOG cmd"

    # Broadcast to all active terminals safely
    wall "$MESSAGE" 2>/dev/null

    # Log to system journal
    logger -t monitoring "Monitoring executed"
}

# MAIN EXECUTION - Only run if users are logged in
if [ $(who | wc -l) -gt 0 ]; then
    show_info
fi

exit 0
