# TcpDumpForAndroid
A tool for android to capture network data.

本项目是在Android平台,通过ndk用java调用c语言的库,c库调用libpcap来抓包.

该项目由于下面的原因暂时停止了. 
目前现况是, 编译和运行正常,但是抓包时提示没有权限.
libpcap需要root权限,而root过的设备授权了root权限给该应用之后,依然无法进行抓包.原因如下,
http://stackoverflow.com/questions/10203927/grant-the-root-privilege-to-the-application
大意是即使通过su获取到了root权限,但是该权限是新创建出来的进程的,原ndk的进程依然是普通用户权限.这样的话原进程依然无法进行抓包.

