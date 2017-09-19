#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray(char* arr, int size){
    int i;
    for(i = 0; i < size; ++ i){
        arr[i] = 'A' + (rand() % 26);
    }
}

// args: total_bytes block_size
int main(int argc, char** argv){
    if(argc < 3){
        puts("Usage: <exe> total_bytes block_size\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int total_bytes = atoi(argv[1]);
    const int block_size = atoi(argv[2]);

    char* buf = malloc(sizeof(char) * block_size);

    FILE* fp = fopen("test.txt", "w");

    int toWrite;

    while(total_bytes){
        toWrite = (block_size > total_bytes) ? total_bytes : block_size;
        randomArray(buf, toWrite);

        fwrite(buf, sizeof(char), toWrite, fp);

        total_bytes -= toWrite;
    }

    fclose(fp);

    return 0;
}
