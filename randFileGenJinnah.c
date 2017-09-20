#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// args: total_bytes block_size
int main(int argc, char** argv){
    if(argc < 3){
        puts("Usage: <exe> total_bytes block_size\n");
        exit(1);
    }

    srand(time(NULL));

    int total_bytes = atoi(argv[1]);
    const int block_size = atoi(argv[2]);

    char* buf = malloc(sizeof(char) * block_size);

    FILE* fp = fopen("test.txt", "w");

    int toWrite;
    int i;

    while(total_bytes){
        toWrite = (block_size > total_bytes) ? total_bytes : block_size;

        for(i = 0; i < toWrite; ++ i){
            buf[i] = 'A' + (rand() % 26);
        }

        fwrite(buf, sizeof(char), toWrite, fp);

        total_bytes -= toWrite;
        printf("Bytes written: %d\nBytes left: %d\n", toWrite, total_bytes);
    }

    free(buf);
    fclose(fp);

    return 0;
}
