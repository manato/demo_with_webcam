/*************************************************/
/* program to load image file into shared memory */
/*************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cv.h>
#include <highgui.h>



#include "data_for_shm.h"





main(int argc, char *argv[]) {

    char *pathname_input, *pathname_output, *pathname_height, *pathname_width;
    key_t shm_key_input, shm_key_output, shm_key_height, shm_key_width, shm_key_size;
    int shrd_id_input, shrd_id_output, shrd_id_height, shrd_id_width, shrd_id_size;
    //int *shrd_ptr_input, *shrd_ptr_output, *shrd_ptr_height, *shrd_ptr_width;
    unsigned char *shrd_ptr_input, *shrd_ptr_output;
    int *shrd_ptr_height, *shrd_ptr_width, *shrd_ptr_size;

    /* for semaphore control */
    key_t sem_key;
    int semid;

    /* for image loading */
    //IplImage *src_img=0;
    FILE *src_fp;
    long filesize=0;

    // if(argc != 5) {
    //     printf("/*===============================================================*/\n");
    //     printf("USAGE : \n %s <shared input file path> <shared output file path> <shared height file path> <shared width file path>\n", argv[0]);
    //     printf("NOTE : parameter files must be readable and writable for all user\n");
    //     printf("/*===============================================================*/\n");
    //     printf("program exits...\n");
    //     return -1;
    // } 


    /* key generation */
    // pathname_input = argv[1];
    // printf("load image to %s\n", pathname_input);
    // shm_key_input = ftok(pathname_input, 1);  // key for input file
    shm_key_input = ftok(INPUT_SHM_PATH, 1);  // key for input file
    if(shm_key_input == -1) {  // error semantics
        printf("generate key for input failed\n");
        return -1;
    }

    // pathname_output = argv[2];
    // printf("load image to %s\n", pathname_output);
    // shm_key_output = ftok(pathname_output, 1);  // key for output file
    shm_key_output = ftok(OUTPUT_SHM_PATH, 1);  // key for output file
    if(shm_key_output == -1) {  // error semantics
        printf("generate key for output failed\n");
        return -1;
    }

    // pathname_height = argv[3];
    // printf("load height to %s\n", pathname_height);
    // shm_key_height = ftok(pathname_height, 1);  // key for height file
    shm_key_height = ftok(HEIGHT_SHM_PATH, 1);  // key for height file
    if(shm_key_height == -1) {  // error semantics
        printf("generate key for height failed\n");
        return -1;
    }

    // pathname_width = argv[4];
    // printf("load width to %s\n", pathname_width);
    // shm_key_width = ftok(pathname_width, 1);  // key for width file
    shm_key_width = ftok(WIDTH_SHM_PATH, 1);  // key for width file
    if(shm_key_width == -1) {  // error semantics
        printf("generate key for width failed\n");
        return -1;
    }


    shm_key_size = ftok(SIZE_SHM_PATH, 1);  // key for size file
    if(shm_key_size == -1) {  // error semantics
        printf("generate key for size failed\n");
        return -1;
    }


    /* key generation for semaphore */
    sem_key = ftok(SEM_PATH, 1);  // key for semaphore
    if(sem_key == -1) {  // error semantics
      printf("generation key for semaphore failed\n");
      return -1;
    }


    /* open shared memory */
    shrd_id_input = shmget(shm_key_input, IMAGE_SIZE, 0666);  // 0666 : readable and writable for all user
    if(shrd_id_input < 0) {  // error semantics
        printf("Can't Access to the Shared memory for input...\n");
        return -1;
    }

    shrd_id_output = shmget(shm_key_output, IMAGE_SIZE, 0666);  // 0666 : readable and writable for all user
    if(shrd_id_output < 0) {  // error semantics
        printf("Can't Access to the Shared memory for output...\n");
        return -1;
    }

    shrd_id_height = shmget(shm_key_height, sizeof(int), 0666);  // 0666 : readable and writable for all user
    if(shrd_id_height < 0) {  // error semantics
        printf("Can't Access to the Shared memory for height...\n");
        return -1;
    }

    shrd_id_width = shmget(shm_key_width, sizeof(int), 0666);  // 0666 : readable and writable for all user
    if(shrd_id_width < 0) {  // error semantics
        printf("Can't Access to the Shared memory for width...\n");
        return -1;
    }


    shrd_id_size = shmget(shm_key_size, sizeof(int), 0666);  // 0666 : readable and writable for all user
    if(shrd_id_size < 0) {  // error semantics
        printf("Can't Access to the Shared memory for size...\n");
        return -1;
    }


    /* open semaphore */
    semid = semget(sem_key, 1, 0666);
    if(semid == -1) {
      printf("Can't Access to the semaphore\n");
      return -1;
    }

    /* get address of shared memory */
    shrd_ptr_input = (unsigned char*)shmat(shrd_id_input, NULL, 0);
    shrd_ptr_output = (unsigned char*)shmat(shrd_id_output, NULL, 0);

    shrd_ptr_height = (int*)shmat(shrd_id_height, NULL, 0);
    shrd_ptr_width = (int*)shmat(shrd_id_width, NULL, 0);
    shrd_ptr_size = (int*)shmat(shrd_id_size, NULL, 0);


    /* image loading */
    /* src_img = cvLoadImage("/home/hirabayashi/dev/geye/CAR_TRACKING/Test_Images/Daytime_Image_PNG/11.png", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR); */
    /* if(src_img == 0) { */
    /*     printf("image loading failed...\n"); */
    /* } */

    /* get file size */
    //if( (src_fp = fopen("/home/hirabayashi/dev/geye/CAR_TRACKING/Test_Images/Daytime_Image_PNG/11.png", "rb")) == NULL){
    //    if( (src_fp = fopen("./org_image/5.bmp", "rb")) == NULL){
    //    if( (src_fp = fopen("./org_image/7.bmp", "rb")) == NULL){
    if( (src_fp = fopen("./org_image/lena.jpg", "rb")) == NULL){
    //if( (src_fp = fopen("./org_image/11.bmp", "rb")) == NULL){
      printf("source file open error !!\n");
    }
    fseek( src_fp, 0, SEEK_END );
    filesize = ftell( src_fp );
    fseek( src_fp, 0, SEEK_SET );

    printf("filesize %d bytes\n", (int)filesize);

    /* write to shared memory */
    /* memcpy(shrd_ptr_input, src_img->imageData, src_img->imageSize); */
    /* memcpy(shrd_ptr_output, src_img->imageData, src_img->imageSize); */
    //unsigned char *pointer_input = (unsigned char *)shrd_ptr_input;
    unsigned char *pointer_input = shrd_ptr_input;
    long read_size = 0;

    My_sem_operation(semid, LOCK); // lock semaphore
    /* load image to input memory */
    while( feof( src_fp ) == 0 )
      {
        // read_size = fread( pointer_input, sizeof( unsigned char ), 1024, src_fp );
        // if( read_size < 1024 )
        /* loading to the buffer by 1byte */
        read_size = fread( pointer_input, sizeof( unsigned char ), 1, src_fp );

        if( read_size < 1 )
          {
            break;
          }
        pointer_input += read_size;
      }
    My_sem_operation(semid, UNLOCK); // unlock semaphore

#if 0
    /* output to the regular file in order to check buffer contents */
    fseek( src_fp, 0, SEEK_SET );
    FILE *fp = fopen("./testfileoutput", "wb");
    if(fp == NULL) {
      printf("file open error\n");
    }
    unsigned char tmp[1] = {0};
    while( feof( src_fp ) == 0 )
      {
        read_size = fread(tmp, sizeof( unsigned char ), 1, src_fp );
        if( read_size < 1 )
          {
            break;
          }
        if(fwrite(tmp, sizeof(unsigned char), 1, fp) != 1) {
          fprintf(stderr, "data write error\n");
          exit(1);
        }
      }
    fclose(fp);
#endif
    
    /* reset file pointer to the start of file */
    fseek( src_fp, 0, SEEK_SET );
    //unsigned char *pointer_output = (unsigned char *)shrd_ptr_output;
    unsigned char *pointer_output = shrd_ptr_output;
    read_size = 0;

#if 0
    My_sem_operation(semid, LOCK); // lock semaphore
    /* load image to output memory */
    while( feof( src_fp ) == 0 )
      {
        // read_size = fread( pointer_output, sizeof( unsigned char ), 1024, src_fp );
        // if( read_size < 1024 )
        read_size = fread( pointer_output, sizeof( unsigned char ), 1, src_fp );
        if( read_size < 1 )
          {
            break;
          }
        pointer_output += read_size;
      }
    My_sem_operation(semid, UNLOCK); // unlock semaphore
#endif

    fclose( src_fp );
    
    /* *shrd_ptr_height = src_img->height; */
    /* *shrd_ptr_width = src_img->width; */
    *shrd_ptr_height = HEIGHT_OF_IMAGE;  // defined in data_for_shm.h
    *shrd_ptr_width = WIDTH_OF_IMAGE;
    *shrd_ptr_size = (int)filesize;


    printf("image written!!\n");

#if 0
    /* test: output image */
    cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
    cvShowImage("input image", src_img);
    printf("height %d , width %d\n", *shrd_ptr_height, *shrd_ptr_width);  // height 480 width 640
    cvWaitKey(0);
#endif
 

}
