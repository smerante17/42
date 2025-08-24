#!/bin/bash

logger -t monitoring "Script started"

show_info() {
    # Architecture & Kernel
    ARCH=$(uname -srvmo)

    # CPU info
    PCPU=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
    VCPU=$(grep -c "^processor" /proc/cpuinfo)

    # RAM usage
    RAM_TOTAL=$(free -m | awk '/Mem:/ {print $2}')
    RAM_USED=$(free -m | awk '/Mem:/ {print $3}')
    RAM_PERCENT=$((RAM_USED * 100 / RAM_TOTAL))

    # Disk usage: sum of /dev/* excluding /boot
    read DISK_USED DISK_TOTAL < <(df --output=used,size -B1 | tail -n +2 | awk '{used+=$1; total+=$2} END {print used, total}')
    # Convert to human-readable
    DISK_USED_H=$(numfmt --to=iec --suffix=B "$DISK_USED")
    DISK_TOTAL_H=$(numfmt --to=iec --suffix=B "$DISK_TOTAL")
    DISK_PERCENT=$((DISK_USED * 100 / DISK_TOTAL))

    # CPU load (1 minute)
    CPU_LOAD=$(top -bn1 | grep "Cpu(s)" | awk -F'id,' '{print 100 - $1}' | awk '{print $1"%"}')

    # Last boot
    LAST_BOOT=$(who -b | awk '{print $3 " " $4}')

    # LVM status
    LVM_STATUS=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")

    # Active TCP connections
    TCP_CONN=$(ss -t state established | wc -l)

    # Users logged
    USER_LOG=$(users | wc -w)

    # Network info
    IP_ADDR=$(hostname -I | awk '{print $1}')
    MAC_ADDR=$(ip link show | awk '/ether/ {print $2}' | head -n1)

    # Sudo commands executed
    SUDO_LOG=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

    # Format the message
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

    # Broadcast and log
    wall "$MESSAGE" 2>/dev/null
    logger -t monitoring "Monitoring executed"
}

# Execute only if users are logged in
[ $(who | wc -l) -gt 0 ] && show_info

exit 0
