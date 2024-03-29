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


int main(int argc, char *argv[]){
  long totalsize = 0;
	struct dirent * data;
  if (argc < 2){
    printf("YOU MUST INPUT A DIRECTORY\n");
    return 0;
  }
  //DIR * direc = opendir(".");
  DIR * direc = opendir(argv[1]);
  if (direc == NULL) {
    printf("There's an error: %s\n", strerror(errno));
		return 0;
  }
  printf("\n");
  data = readdir(direc);
  while (data != NULL) {
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
    data = readdir(direc);
  }
  closedir(direc);
  printf("\nTotal Size: %ldB\n", totalsize);

  return 0;
}
