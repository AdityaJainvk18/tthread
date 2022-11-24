#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<sched.h>

//creating three threads for counting
//countA,countB,countC
//using SCHED_OTHER
void* countA(){

    int policy=SCHED_OTHER;
    struct sched_param param;
    param.sched_priority=0;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int i=1;i<4294967296;++i){

    }
    pthread_exit(NULL);
}
//using SCHED_RR
void* countB(){

     int policy=SCHED_RR;
    struct sched_param param;
    param.sched_priority=50;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int j=1;j<4294967296;++j){

    }
    pthread_exit(NULL);

}
//using SCHED_FIFO
void* countC(){

     int policy=SCHED_FIFO;
    struct sched_param param;
    param.sched_priority=60;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int k=1;k<4294967296;++k){

    }
    pthread_exit(NULL);

}

//main function

int main(){
    pthread_t tA;
    pthread_t tB;
    pthread_t tC;
    struct timespec beforeA,beforeB,beforeC;
    clock_gettime(CLOCK_MONOTONIC,&beforeA);
    pthread_create(&tA,NULL,countA,NULL);
    struct timespec afterA,afterB,afterC;
    clock_gettime(CLOCK_MONOTONIC,&afterA);
    pthread_join(tA,NULL);
    double elapseA=(int)(afterA.tv_nsec-beforeA.tv_nsec);
    printf("%lf\n",elapseA);
    clock_gettime(CLOCK_MONOTONIC,&beforeB);
    pthread_create(&tB,NULL,countB,NULL);
    clock_gettime(CLOCK_MONOTONIC,&afterB);
    pthread_join(tB,NULL);
    double elapseB=(double)(afterB.tv_nsec-beforeB.tv_nsec);
    printf("%lf\n",elapseB);
    clock_gettime(CLOCK_MONOTONIC,&beforeC);
    pthread_create(&tC,NULL,countC,NULL);
    clock_gettime(CLOCK_MONOTONIC,&afterC);
    pthread_join(tC,NULL);
    double elapseC=(double)(afterC.tv_nsec-beforeC.tv_nsec);
    printf("%lf\n",elapseC);





    return 0;
}