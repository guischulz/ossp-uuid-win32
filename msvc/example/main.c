#include "uuid.h"
#include "uuid_sha1.h"
#include "uuid_time.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    uuid_t *uuid = NULL;
    int i;
    void *vp;
    size_t n;
    struct timeval time_now;
    __int64 start_ms;
    double elapsed_time;

    time_gettimeofday(&time_now);
    start_ms = time_now.tv_sec*1000000 + time_now.tv_usec;
    
    /* Generate 1.000.000 times a V1 uuid */

    uuid_create(&uuid);
    // uuid_import(uuid, UUID_FMT_STR, "303767a0-c590-11e8-aac4-8b8c5155dd21", UUID_LEN_STR);
    
    for(i=0; i<1000000; i++) {
      uuid_make(uuid, UUID_MAKE_V1);
      if (i< 10) {
        vp = NULL;
        uuid_export(uuid, UUID_FMT_STR, &vp, &n);
        printf("%s\n", (char*)vp);
        free(vp);
      }      
    }
    uuid_destroy(uuid);
 
    time_gettimeofday(&time_now);
    elapsed_time = (time_now.tv_sec*1000000 + time_now.tv_usec - start_ms) / 1000000.0;
    printf("elapsed time = %.3f seconds\n", elapsed_time);
    
    return 0;
}
