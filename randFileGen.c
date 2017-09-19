#include <stdlib.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


/**
 * populate a random array (which is already
 * allocated with enough memory to hold n bytes
 * with random characters from A to Z.
 */
void random_array(char *array,long bytes){
    int i;
    for (i = 0; i < bytes;i++){
        array[i] = 'A' + ( rand() % 26 );
    }
}

/**
 * argv[] should be formated <filename> <total bytes> <block size>
 */
 int main(int argc, char *argv[]){
   //seed the random!
   srand((int)time(NULL));
   //there's always 1 for argc!
    if (argc < 3){
        fprintf(stderr, "more arguments required");
        exit(EXIT_FAILURE);
    }

    char *filename = "test.txt";
    int total_bytes = atoi(argv[1]);
    int blocksize = atoi(argv[2]);
    char *buf = malloc(sizeof(char) * blocksize);
    FILE *fp = fopen(filename, "w");

    if (fp == NULL){
        fprintf(stderr, "can not open file\n");
        exit(EXIT_FAILURE);
    }

    int bytes_written = 0;

    while(bytes_written < total_bytes){

        if (total_bytes - bytes_written < blocksize){

            long btw = total_bytes - bytes_written;
            random_array(buf,btw);

            fwrite(buf, 1,(size_t)btw , fp);
            fflush(fp);

            free(buf);
            bytes_written += btw;

        }
        else{

            random_array(buf, blocksize);

            fwrite(buf, 1, (size_t)blocksize, fp);
            fflush(fp);

            free(buf);
            bytes_written += blocksize;
        }
    }
    fclose(fp);

}
