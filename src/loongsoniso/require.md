龙芯版本
=======

- squashfs制作

  * truncate -s 15G root-image.fs

  * mkfs.ext3 -m 0 -F root-image.fs
  
  * tune2fs -c 0 -i 0 root-image.fs

  * mount -o loop root-image.fs /tmp/sysroot

  * cp -aT /dev/sda2 /tmp/sysroot

  * umount /tmp/sysroot
  
  * mksquashfs root-image.fs root-iamge.sfs -noappend
