
## IPC 之 shared memory
`int shmget(key_t key, size_t size, int shmflg);`
size 一般都是页面大小 4096


` ftok  - convert a pathname and a project identifier to a System V IPC key`
获取`key_t key`

`key_t ftok(const char *pathname, int proj_id);`

System V是Unix的一个版本，和BSD类似，但是后续都被
POSIX接纳了，这里的shm，包括之后会学到的sem，mq都是
System V的。

`shmat`

#### 信号机制一般搭配shm使用

`signal(int signal, int pid);`
`kill(int pid, int signal);`

