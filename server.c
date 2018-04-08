#include "comm.h"

int main()
{
    int shmid = create_shm(4096);   //创建共享内存块
    char *buf;
    int i = 0;
    buf = shmat(shmid,NULL,0);
    while( i < 4096)
    {
        buf[i] = 'a'+i ;
        i++;
        sleep(1); 
        if(i == 26)
            break; // 让程序结束，去释放该共享内存
    }
    destroy_shm(shmid);
    return 0;

}
