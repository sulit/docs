#!/bin/sh

if [ $EUID -ne 0 ];then
	echo "Please make sure that you own system admin right"
fi

install -m755 webmountserver /usr/sbin/
install -m755 webmountserver.service /usr/lib/systemd/system/
install -m755 mount.cgi /var/www/cgi-bin/
