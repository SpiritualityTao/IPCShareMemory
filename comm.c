#include "comm.h"

static int comm_shm(int size,int shmflag){

    key_t key = ftok(PATHNAME,PROJ_ID);  //获取key
    if(key < 0){
        perror("fotk");
        return -1;
    }
    int shmid = shmget(key,size,shmflag);
    if(shmid < 0){
        perror("shmget");
        return -1;
    }
} 

int create_shm(int size){
    return comm_shm(size,IPC_CREAT|IPC_EXCL|0666);
}

int get_shmid(){
    return comm_shm(0,IPC_CREAT);
}

int destroy_shm(int shmid){
    if(shmctl(shmid,IPC_RMID,NULL) < 0){
        perror("shmctl");
        return -1;
    }

    return 0;
}
