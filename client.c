#include "comm.h"

int main()
{
    int shmid = get_shmid();
    char *buf;
    int index = 0;
        buf = shmat(shmid,NULL, 0 );

    while( index < 4096)
    {
        printf("%s\n", buf);
        sleep(1);
        index++;
        if( index == 27)
            break; // 让程序结束
    }
    return 0;
}
