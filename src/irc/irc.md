IRC常用命令列表

常 用 基 本 命 令 命令用途说明 命 令 使 用 举 例

/links 列服务器连接信息 /links

/list 列出所有聊天室 /list

/nick 名字 更换名字 /nick 林桃子67

/ns register 密码 注册名字 /ns regiser 123456

/pass 密码 验证名字密码 /pass 123456

/ns set password 新密码 修改名字密码 /ns set password 654321

/mode 自己名字 +/-i 设置昵称是否隐藏 /mode 林桃子67 +/-i

/mode 自己名字 +/-s 是否收服务器信息 /mode 是我 +/-s

/run 文件名 运行程序或文件 /run jpbot.exe

/whois 名字 查看网友的信息 /whois 是我

/userhost 名字 查看网友的IP地址 /userhost 是我

/ns info 名字 查名字注册信息 /ns info 名字

/ns status 名字 查询用户状态 /ns status 名字

/who 看看谁在线上 /who

/who #房间名 看看谁在房间中 /who #林桃子67的房间


/names #房间名 列房间中所有用户 /names #日本女性的房间


/me 要说的话 使用动作表情 /me 大家好，今天你IRC了么


/say 要说的话 在当前频道说话 /say 老公，想我了吗


/notice 名字 要说的话 向某人发出通告 /notice 远方的风 有事找你


/query 名字 发送信息 开小窗和他私聊 /query 夕阳天使 hi，久违了你


/privmsg 名字 发送信息 开小窗发送信息 /privmsg 天使源 hi，久违了你


/msg 他的名字 信息内容 给他悄悄发送信息 /msg 于天 你好!


/msg 房间名字 信息内容 向房间全体成员说 /msg #日语角 大家好!


/omsg #房间名字 要发的信息 仅对屋中的@说话 /omsg #日语角 见吴山了没有


/amsg 要发的信息 多个频道同发信息 /amsg 我老公在那里呢


/onotice 房间名字 要发的话 在该屋对所有op说 /onotice #日语角 水素死翘了


/close -m 关闭所有小窗聊天 /close -m


/ignore 他的名字 忽略你讨厌的人 /ignore 杨过,shll,


/ignore -T * 忽略别人CTCP查询 /ignore -T *


　　 /join #房间名 加入一个房间 /join #林桃子67的房间


/away 给出离开的原因 离开并给出原因 /away 对不起GG，我男友来了


/away 取消离开设置 /away


/part #房间名 退出信息 退出当前房间 /part #日语角 bye大家


/partall 退出信息 退出所有房间 /partall byeall


/quit 退出信息 退出IRC退出连接 /quit 今天实在是累了，bye


/exit 退出信息 关闭irc并退出 /exit 睡觉觉去了


/disconnect 退出信息 与服务器断开连接 /disconnect 我是故意断线的


/server bj.irc.263.net 6667 更换irc服务器 /server bj.irc.263.net 6667


/cs register #房间名字 密码 你对房间的描述 注册自己的房间 /cs register #

林桃子67的房间 123456 我是桃子67我怕谁


/topic #房间名字 主题内容 更改房间主题 /topic #日语角 欢迎你朋友


/invite 他的名字 #房间名 邀请别人来房间 /invite 紫丁香花 #日语角


/kick #房间名 他的名字 把人踢出房间 /kick #林桃子67的房间 PC100


/mode #房间名 +/-b 他的名字 把某人禁止/解禁 /mode #林桃子67的房间 +/-b  然采


/mode #房间名 +/-o 朋友名字 给朋友加/减帽子 /mode #林桃子67的房间 +/-o  然采


/auto -r on|off|他的名字 #频道名字 自动朋友加/减帽 /auto -r [on然采 ]#林桃子67的房间 出错了


/mode #房间名 +/-l 人数 设置限制房间人数 /mode #日语角 +/-l 100


/mode #房间名字 +/-n 禁不禁止外部信息 /mode #日语角 +/-n


/mode #房间名字+/-m 限制发言仅@/+说 /mode #房间名字 +/-m


/mode #房间名字 +/-i 设置邀请模式 /mode #日语角 +/-i


/mode #房间名字 +/-p 是否设置私有模式 /mode #日语角 +/-p


/mode #房间名字 +/-s 是否设置秘密模式 /mode #日语角 +/-s


/mode #房间名字 +/-t 是否只@能改主题 /mode #日语角 +/-t


/mode #房间名 +k 密码 给房间加密码 /mode #日语角 +k 123456


/join #房间名 密码 进入有密码的房间 /join #日语角 123456


/channel 调出频道模式设置 /channel


/cs info #房间名字 查看频道注册信息 /cs info #日语角

--------------------------------------------------------------------------------

nickserv 昵称服务

更换昵称 /nick 你要换的新名字

注册昵称 /ns register 密码 邮箱

认证昵称 /ns identify 名字密码

这个也认证昵称 /pass 名字密码

昵称保护 /ns set kill on/off

昵称安全 /ns set secure on/off

昵称保密 /ns set private on/off

修改密码 /ns set password 新密码

昵称邮箱 /ns set email 你的邮箱

昵称主页 /ns set url http://52irc.org

隐藏邮件 /ns set hide emall On/off

隐藏网络地址 /ns set hide usermask On/off

隐藏退出信息 /ns set hide quit On/off

杀掉盗用你名字者 /ns ghost 你的妮称 密码

注销昵称 /ns drop 你的妮称（得先认证）


--------------------------------------------------------------------------------

chanserv 频道服务

查看房间信息 /cs info #频道名字

注册房间 /cs register #频道名字 密码 简介

认证你的房主身份 /cs identify #频道名字 频道密码

设置房间的主页 /cs set #频道名字 url 主页地址

设置房间的邮箱 /cs set #频道名字 email 邮件地址

设置房间的主题 /cs set #频道名字 topic 主题内容

保留房间的主题 /cs set #频道名字 keeptopic on/off

锁定房间的主题 /cs set #频道名字 topiclock on/off

设置新的房间主人 /cs set #频道名字 founder 新任房主

设置房间的新密码 /cs set #频道名字 password 频道密码

设置房间安全控制 /cs set #频道名字 secure on/off

设置房间管理员控制 /cs set #频道名字 secureops on/off

--------------------------------------------------------------------------------


memoserv 留言服务

列表所有留言 /ms list

列表最新留言 /ms list new

阅读最新留言 /ms read last

阅读特定留言 /ms read 留言号码

删除指定的留言 /ms del 留言号码

删除所有的留言 /ms del all

给人发送留言 /ms send 对方妮称 留言内容


--------------------------------------------------------------------------------


chanserv 频道服务

设置频道进入信息 /cs set #频道名字 entrymsg 所设置信息

用服务器给客人加帽子 /cs op #频道名字 对方名字

服务器摘掉某人的帽子 /cs deop #频道名字 对方名字

让服务器为自已解ban /cs unban #频道名字

增加一人到房踢列表/cs akick #频道名字 add 对方名字

删除一人到房踢列表/cs akick #频道名字 del 对方名字

查看房踢列表/cs akick #频道名字 list

清除房间的所有ban /cs clear #频道名字 bans

清除房间的模式设置 /cs clear #频道名字 modes

清除房间的所有帽子 /cs clear #频道名字 ops

清除房间的所有用户 /cs clear #频道名字users

注销房间 /cs drop #频道名字


--------------------------------------------------------------------------------

CTCP查询命令

查对方反映速度 /ctcp 对方名字 ping

查对方当地时间 /ctcp 对方名字 time

查对方软件版本 /ctcp 对方名字 version

查对方的用户信息 /ctcp 对方名字userinfo

查对方的用户信息 /ctcp 对方名字 clientinfo

--------------------------------------------------------------------------------
