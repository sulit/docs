用qemu调试内核模块
================

下面以x86_64系统为例：

- 从https://buildroot.org/下载最新的buildroot源码包并解压
```
wget -c https://buildroot.org/downloads/buildroot-2016.05.tar.bz2
tar xf buildroot-2016.05.tar.bz2
```

- 进入buildroot目录，进行配置，
	* `cd buildroot-2016.05`
	* `make qemu_x86_64_defconfig`
		(build-option, kernel-version, gdb, tty1)
	* `make`
	* `make linux-menuconfig`
	* `make`
	
- 进入内核编译目录，创建helloworld内核模块
	* `cd output/build/linux-4.5.3/drivers/`
	* `mkdir hello; cd hello`
	* 
```
cat >> hello.c <<EOF
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/module.h>
#include <asm/uaccess.h>

static char hello_world[]="Hello World\n";
static dev_t hello_dev_number;
static struct cdev *driver_object;
static struct class *hello_class;
static struct device *hello_dev;

static ssize_t driver_read( struct file *instanz,char __user *user, size_t count, loff_t *offset )
{
   unsigned long not_copied, to_copy;

    to_copy = min( count, strlen(hello_world)+1 );
    not_copied=copy_to_user(user,hello_world,to_copy);
    return to_copy-not_copied;
}

static struct file_operations fops = {
    .owner= THIS_MODULE,
    .read= driver_read,
};

static int __init mod_init( void )
{
    if (alloc_chrdev_region(&hello_dev_number,0,1,"Hello")<0)
        return -EIO;
    driver_object = cdev_alloc();
    if (driver_object==NULL)
        goto free_device_number;
    driver_object->owner = THIS_MODULE;
    driver_object->ops = &fops;
    if (cdev_add(driver_object,hello_dev_number,1))
        goto free_cdev;
    hello_class = class_create( THIS_MODULE, "Hello" );
    if (IS_ERR( hello_class )) {
        pr_err( "hello: no udev support\n");
        goto free_cdev;
    }
    hello_dev = device_create( hello_class, NULL, hello_dev_number, NULL, "%s", "hello" );
    return 0;
free_cdev:
    kobject_put( &driver_object->kobj );
free_device_number:
    unregister_chrdev_region( hello_dev_number, 1 );
    return -EIO;
}

static void __exit mod_exit( void )
{
    device_destroy( hello_class, hello_dev_number );
    class_destroy( hello_class );
    cdev_del( driver_object );
    unregister_chrdev_region( hello_dev_number, 1 );
    return;
}

module_init( mod_init );
module_exit( mod_exit );
MODULE_LICENSE("GPL");
EOF
```
	* 生成Makefile
	
```
cat >> Makefile <<EOF
ifneq ($(KERNELRELEASE),)
obj-m :=hello.o
else
KDIR :=[改成你自己的buildroot所在的目录]/output/build/linux-4.5.3
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers
endif
EOF
```
	* `make`
	* `cp hello.ko [改成你自己的buildroot所在的目录]/output/target/root/`
	
- 制作根文件系统
	* `cd [buildroot]; make`
	
- 在[buildroot]目录中，执行调试命令
  `qemu -kernel output/images/bzImage -hda output/images/rootfs.ext2 -append "root=/dev/sda rw" -s -S &`
  
  
- 进入[buildroot]/output/build/linux-4.5.3/目录，执行下面命令
  `gdb`
  debug session
  `file vmlinux`
  `target remote :1234`
  `continue`

- 在qemu中用root用户登录，然后执行下面命令，并记住三个段的地址
  `insmod hello.ko`
  `cat /sys/module/hello/sections/.text`
  `cat /sys/module/hello/sections/.data`
  `cat /sys/module/hello/sections/.bss`

- 在gdb中输入Ctrl+c中断执行，然后输入下面命令
  `add-symbol-file driver/hello/hello.ko [文本段地址] -s .data [数据段地址] -s .bss [bss段地址]`
  `b driver_read`
  `c`

- 在qemu中输入
  `cat /dev/hello`
  
- 在gdb中可以list，break，continue等，就可以执行调试内核的命令了

# 参考资料

[流程图片](buildroot_reference.jpg)

[相关资料网址](http://www.linux-magazine.com/Online/Features/Qemu-and-the-Kernel)
