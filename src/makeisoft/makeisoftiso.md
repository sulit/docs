搭建isoft构建体系
================

- 搭建koji服务

  用koji搭建脚本，注意先不初始化koji仓库

- 搭建git仓库管理服务

- 搭建文件缓存服务

- 搭建完成

- 制作squashfs文件系统(一些参数省略了，根据需要添加参数)

  1. truncate -s <fs-size> <fs-name>

  2. mkfs.ext4 <fs-name>

  3. mount <fs-name> <mount-point>

  4. cp -aT <fs-src> <mount-point>

  5. mksquashfs <fs-name> <sfs-name>

- 手动制作iso

  xorriso命令制作iso(参数比较多，也比较复杂)

**注意**

cp系统时，有些东西可能回出问题，比如文件权限，还有fstab等
