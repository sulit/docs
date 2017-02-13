#!/usr/bin/python

import os
from xmlrpclib import ServerProxy

print("Content-type: text/html")
print("")

print("<html>")
print("<head>")
print('<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">')
print("<title>webmount</title>")
print("</head>")
print("<body>")
s = ServerProxy("http://127.0.0.1:9099")
print(s.mount(1))
print("</body>")
print("</html>")
