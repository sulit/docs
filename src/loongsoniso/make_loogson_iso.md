制作龙芯iso
==========

**处理过程一定要细心**

- 先制作一个虚拟数据磁盘
```
	#truncate -s 15G root-image.fs
```
> 要保证可以放下所需要的内容

- 格式化数据磁盘为文件系统ext4
```
	#mkfs.ext4 -j -E lazy_itable_init=0 -m 0 -F root-image.fs
	#tune2fs -c 0 -i 0 root-image.fs
```

- 拷贝数据到新建的虚拟数据磁盘，注意一定要保留文件的权限，不然容易引起很多系统问题。
```
	#mount root-image.fs dst
	#cp -aT src dst
```
> 有些文件属性难以被保留，可能跟cp版本有关系，比如ping的执行权限，我在后期文件脚本中对它做了恢复，
> 具体请看/usr/share/apps/dinstaller/postscript.tmpl，这个文件属于dinstaller

- 压缩虚拟数据磁盘
```
	#mksquashfs root-image.fs root-image.fs.sfs -noappend -comp [xz|gzip etc]
```
> 龙芯性能不好，可以把这个工作放到x86上去压缩

- 替换iso中root-image.fs.sfs
```
	#mkdir iso
	#mount [以前的iso] iso
	#rm iso/isoft/mipsel/root-image.fs.sfs
	#cp root-image.fs.sfs iso/isoft/mipsel/
```
> 这只是这个版本龙芯的做法

- 把iso的整个目录制作成可启动iso
```
	#xorriso -as mkisofs -iso-level 3 -full-iso9660-filenames -volid "ISOFTISO" -appid "iSoft Linux Live CD" -publisher "Isoft Linux <http://www.i-soft.com.cn>" \
	> -preparer "prepared by mkisoftisorpm" -no-emul-boot -boot-load-size 4 -boot-info-table -output "${PWD}/[iso-name]" "${PWD}/iso"
```

> 把这条命令写到sh文件里
> 在修改系统过程中，请注意dinstaller和firstboot是跟安装系统有关的两个包，分别由王铭和朱付江维护，如果这两个包有问题，可以找他们，dinstaller的后期脚本是需要你了解的，必要时由你控制。
>上面的过程显示了制作可启动iso的原理，其他的自己触类旁通，其实可以在iso中放仓库，把squashfs做的很小，启动后直接启动安装安装程序，然后系统需要的所有包都从仓库中安装，就相当于最早期的CD安装吧。
