关于isoft4.0EFI引导
==================

这里介绍的是iso里的EFI启动

- BOOTX64.EFI文件

  这个是首次被EFI启动管理器调用的程序，必须放在/EFI/BOOT/下

面，这个文件可以是任何EFI程序。启动之后，它可以调用任何其他

程序。在isoft4.0中，我们用的grubx64.efi作为BOOTX64.EFI，当然

其他的EFI也行，甚至是你自己写的EFI程序。在isoft4.0中，我们

用以下命令生成BOOTX64.EFI(也是grubx64.efi):

```
grub-mkimage -c grub.cfg -p /EFI/BOOT/ -O x86_64-efi -o \
BOOTX64.EFI -d -d /usr/lib/grub/x86_64-efi [modname ...]
```

如果你想安装所有模块:

```
cd /usr/lib/grub/x86_64-efi
grub-mkimage -c ~/grub.cfg -d . -o BOOTX64.EFI -O x86_64-efi \
-p /efi/boot `find *.mod | xargs | sed -e 's/\.mod//g'`
```

好了，知道上面是怎么回事了，你应该还不能执行，因为你缺grub.cfg

这个文件，这个文件会被嵌入BOOTX64.EFI程序中，它的内容一般如下

```
search --no-floppy --set=root -l 'NVWA_ISOFTISO-LIVECD'
set prefix=($root)/EFI/BOOT
configfile /EFI/BOOT/grub.cfg
```

这三行的意思很简单，第一行，搜索标示为NVWA_ISOFTISO-LIVECD的分区，

作为root，--no-floppy为不搜索软盘，第二行，设置prefix，这个是设置

grub搜索grub.cfg的路径，configfile /EFI/BOOT/grub.cfg为加载grub.cfg

配置文件，其实第三条应该可以省略，先放着吧，保证正常工作是首要的

注意之后加载的grub.cfg为你自己的grub.cfg，我们用的是：

```
set default="1"

function load_video {
  insmod efi_gop
  insmod efi_uga
  insmod video_bochs
  insmod video_cirrus
  insmod all_video
}

load_video
set gfxpayload=keep
insmod gzio
insmod part_gpt
insmod ext2

set timeout=10
### END /etc/grub.d/00_header ###

search --no-floppy --set=root -l '@CDLABEL@'

### BEGIN /etc/grub.d/10_linux ###
menuentry '@OSNAME@' --class isoft --class gnu-linux --class gnu --class os {
    linuxefi /isoft/boot/@ARCH@/vmlinuz root=live:LABEL=@CDLABEL@ ro rd.live.image quiet  rhgb 
    initrdefi /isoft/boot/@ARCH@/isoftiso.img
}
```

### **ERROR**

- 在加载时会提示prefix is not set, no device found之类的错误，但是

可以成功加载，还需要改进

- 这个错误已经解决了，如果把所有模块添加进EFI，会出现这个错误，原因可能

跟net、ntfs、exfat模块之类的有关，具体是和哪个模块有关，我没有再做深入

下面的默认配置可以正常工作


> 上面的只是初步理解，还有很多需要纠正的地方，比如grub-mkstandalone这个命令是grub-mkimage

> 的增强版，但是感觉有些地方用起来还有问题。

**默认配置**

下面这些模块加进去之后不会导致异常
grub-mkimage -c grub.cfg -p /EFI/BOOT -O x86_64-efi -o BOOTX64.EFI -d /usr/lib/grub/x86_64-efi/  all_video boot btrfs cat chain configfile echo \
        efifwsetup efinet ext2 fat font gfxmenu gfxterm gzio halt \
        hfsplus iso9660 jpeg loadenv loopback lvm mdraid09 mdraid1x \
        minicmd normal part_apple part_msdos part_gpt \
        password_pbkdf2 png \
        reboot search search_fs_uuid search_fs_file search_label \
        serial sleep syslinuxcfg test tftp video xfs \
 backtrace usb usbserial_common  usbserial_pl2303 usbserial_ftdi usbserial_usbdebug  linuxefi

### 参考

- [https://www.gnu.org/software/grub/manual/html_node/Embedded-configuration.html#Embedded-configuration](https://www.gnu.org/software/grub/manual/html_node/Embedded-configuration.html#Embedded-configuration)

- [http://wiki.osdev.org/GRUB_2#Grub_for_EFI](http://wiki.osdev.org/GRUB_2#Grub_for_EFI)
