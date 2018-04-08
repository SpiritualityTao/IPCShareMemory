//内存共享机制IPC参数定义
PC_R           000400  /* read permission */
#define IPC_W           000200  /* write/alter permission */
#define IPC_M           010000  /* permission to change control info */
#endif
 
/* SVID required constants (same values as system 5) */
#define IPC_CREAT       001000  /* create entry if key does not exist */
#define IPC_EXCL        002000  /* fail if key exists */
#define IPC_NOWAIT      004000  /* error if request must wait */
 
#define IPC_PRIVATE     (key_t)0 /* private key */
 
#define IPC_RMID        0       /* remove identifier */
#define IPC_SET         1       /* set options */
#define IPC_STAT        2       /* get options */
 
/* sys/sem.h */
/*
 * Permissions
 */
#define SEM_A           IPC_W   /* alter permission */
#define SEM_R           IPC_R   /* read permission */


//执行函数命令
gcc server.c comm.c -o server
gcc client.c comm.c -o client
./server
./client
