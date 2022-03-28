
## 多路复用
#### select是最简单的多路复用

##### 何谓多路复用

之前我们的程序是简单粗暴的用多线程来实现并发的
即来一个用户连接就开一个新的线程

但是select为我们提供了一种更聪明的方法
```c
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
       void FD_CLR(int fd, fd_set *set);
       int  FD_ISSET(int fd, fd_set *set);
       void FD_SET(int fd, fd_set *set);
       void FD_ZERO(fd_set *set);
```
##### select 的基本步骤
+ 应该有一个数组来存放现有的sockfd
+ 应当知道每次有多少个sockfd，即多少个客户端链接了自己
+ `fd_set` 为存放所有sockfd的集合
+ `select` 可以关注三个集合，但是它的返回值是这三个集合的ready fd的总数，如果想分别得到就得遍历set三次
+ `select` 规定的最大并发为nfds = 1024

