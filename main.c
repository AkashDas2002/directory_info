#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>


int main(){
  long totalsize = 0;
	struct dirent * data;

  DIR * direc = opendir(".");
  printf("\n");

  while ((data = readdir(direc)) != NULL) {
    int isDir = (data->d_type);
    if (isDir == 4){
      printf("d");
    }
    else {
      printf("-");

      /*
      struct stat buf;
	    stat(data->d_name, &buf);
	    long int size = buf.st_size;
	    printf("File size: %ld GB, ", size / 1000000000);
	    size = size % 1000000000;
	    printf("%ld MB, ", size / 1000000);
      size = size % 1000000;
      printf("%ld KB, ", size / 1000);
      size = size % 1000;
      printf("%ld B\n", size);
      mode_t mode = buf.st_mode;
      printf("File Permissions: %o\n", mode);
      printf("Time last accessed: %s\n", ctime(&buf.st_atime));
      char arr[][3] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
      printf("File Permissions: -%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
      mode = mode / 8;
      printf("%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
      mode = mode / 8;
      printf("%c%c%c\n", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
      */
    }

    //printf("%s ", data->d_name);
    struct stat buf;
    mode_t mode = buf.st_mode;
    char arr[][3] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
    printf("%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
    mode = mode / 8;
    printf("%c%c%c", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
    mode = mode / 8;
    printf("%c%c%c  ", arr[mode % 8][0], arr[mode % 8][1], arr[mode % 8][2]);
    stat(data->d_name, &buf);
    long int size = buf.st_size;
    totalsize += size;
    printf("  %ldB", size);
    printf("    %s\n", data->d_name);
  }
  closedir(direc);
  printf("\nTotal Size: %ld\n", totalsize);

  return 0;
}
