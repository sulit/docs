用qemu调试内核
============

- 下载busybox源代码

- 进入源代码目录进行，`make menuconfig`，配置静态编译

- 编译并安装，`make install`

- 制作根文件系统盘，`truncate -s 64M busybox.img`，`sudo mkfs.ext4 busybox.img`

- 挂载根文件系统，`mkdir tmp;sudo mount busybox.img tmp`

- 复制根文件系统的内容，`sudo cp -r _install/* tmp/`

- 创建启动所需要的目录，`sudo mkdir -p tmp/{etc,sys,proc,dev}`

- 复制启动配置信息，`sudo cp examples/bootfloppy/etc/* tmp/etc/`

- 卸载busybox.img，`sudo umount busybox.img`

- 编译能够进行调试的内核，注意保留编译环境，用于加载源码之类的

- 启动qemu，`qemu-system-x86_64 -s -S -kernel [内核编译目录]/arch/x86_64/boot/bzImage -hda busybox.img -append "root=/dev/sda"`

- 启动gdb进行调试
  * `gdb [内核编译目录]/vmlinux`
  * `target remote :1234`
  * `b [设置内核启动的停止位置]`
  * `continue`
- 就可以进行内核的一些调试了，也可以加载源代码
