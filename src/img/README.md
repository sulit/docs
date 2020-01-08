img文件相关
============

- 创建多分区img文件

  * truncate -s 2G rootfs.img

  * sudo parted rootfs.img mklabel msdos

  * sudo parted rootfs.img mkpart p fat32 1M 200M

  * sudo parted rootfs.img mkpart p ext4 200M 100%

  * sudo parted rootfs.img p

  * sudo kpartx -av rootfs.img

  * mkdir {1,2}

  * sudo mount /dev/mapper/loop*p1 1

  * sudo mount /dev/mapper/loop*p2 2

  * sudo kpartx -dv rootfs.img
