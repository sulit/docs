#!/bin/bash
# 双显卡，禁止使用独立显卡。

if lspci -n|grep 1002:6600 >/dev/null;then
    # 是特定双显卡

    if [ -d /sys/kernel/debug/vgaswitcheroo/switch ];then
        # 使用集成显卡
        echo IGD > /sys/kernel/debug/vgaswitcheroo/switch
        # 关闭其他显卡电源
        echo OFF > /sys/kernel/debug/vgaswitcheroo/switch
    fi

    if grep radeon.modeset=0 /proc/cmdline > /dev/null;then
        if lsmod|grep amdgpu;then
            modprobe -r amdgpu
        fi
    fi
    if pidof sddm;then
        systemctl restart sddm-plymouth
    fi
fi

exit 0
