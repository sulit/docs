isoft os update server config
============================

* 准备系统升级包

    1. 建立升级包制作目录

        ```
        $ mkdir osupdatework
        ```

    2. 拷贝需要的文件到工作目录

        ```
        $ cd osupdatework
        $ cp /usr/share/isoft-update-server/update.xsd .
        ```

    3. 建立一个更新目录

        ```
        $ isoft-update-server -demo osupdate
        ```

    4. 从koji上下载一些系统级的软件包(koji.isoft.zhcn.cc/koji or 192.168.33.17/koji)

    5. 把下载的软件包拷贝到osupdate/update/packages/

        ```
        $ cp ~/下载/*.rpm osupdate/update/packages/
        ```

    6. 修改osupdate/update.ini

        - Id号，这个很重要，每升级一次都要加一

        - Arch, 架构为x86_64

        - OsVersion为4.0

        - 其他的请自行填写

    7. 生成升级包

        ```
        $ isoft-update-server -create osupdate  update.xsd
        ```

    8. 建立发布目录

        ```
        $ mkdir upts
        ```

    9. 拷贝升级包文件到发布目录

        ```
        $ cp update/update-* upts
        ```

    10. 生成发布文件

        ```
        $ isoft-update-server -gen upts
        ```

> 通过isoft-update-server --help可以得到命令帮助
> isoft-update-server 默认已经被安装

* 配置服务器

    1. 安装apache服务器

        ```
        $ sudo dnf install httpd
        ```

    2. 启用服务器

        ```
        $ sudo systemctl start httpd
        ```

> 如果默认启用apache服务器，可以使用`sudo systemctl enable httpd`

* 部署配置

    1. 在/var/www/html/目录下建立相应目录

        ```
        $ sudo mkdir -p 4.0/x86_64
        ```

    2. 拷贝发布文件到相应目录下

        ```
        $ sudo cp ~/osupdatework/upts/update.xml.xz* 4.0
        $ sudo cp ~/osupdatework/upts/update-*.upt 4.0/x86_64
        ```

> 这时应该可以在浏览器中访问到，localhost/4.0

* 确认本地软件包版本

    1. 确认从koji上下载下来的软件包，在本地没有得到升级，这里以bash为例

        ```
        $ rpm --os -q bash #假设查到的版本好是1.0-1，而从koji上下载下来的是1.0-2
        ```

* 验证升级

    1. 修改/etc/isoft-update.conf

        ```
        $ sudo sed -e 's|Server=.*|Server=http://localhost/4.0|g' -i /etc/isoft-update.conf
        $ sudo sed -e 's|UpdateDuration=.*|UpdateDuration=2000|g' -i /etc/isoft-update.conf
        ```

    2. 重启更新服务

        ```
        $ sudo systemctl restart isoft-update-daemon.service
        ```

    3. 查询相应的软件包是否被升级，以bash为例

        ```
        $ rpm --os -q bash #这时查到的应该是从koji上下载下来的版本1.0-2
        ```
