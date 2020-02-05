#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char* argv[argc + 1])
{

  char buf[1024];
  if (argc < 1) {
    printf("usage: open_syscall filename\n");
    exit(EXIT_FAILURE);
  }

  
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror((const char*) strerror(errno));
    exit(EXIT_FAILURE);
  }

  while (read(fd, buf, 1024))
    printf("%s", buf);
  
  exit(EXIT_SUCCESS);
  

}
