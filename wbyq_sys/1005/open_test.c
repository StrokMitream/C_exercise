#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// int open(const char *pathname, int flags, mode_t mode);
// ssize_t write(int fd, const void *buf, size_t count);      

// File write test
// Return 0 if success 
int WriteFile ( char *path, char* str,int len )
{
  // 1.Open and create file
  int fd  = open(path, O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO);    
  if ( fd < 0 )
    return 1;
  
  //2.Write file
  int size = write(fd,str,len);
  if ( size != len )
    return 2;

  //3.Close file
  close(fd);
  return 0;
}


// File read test
// Return 0 if success 
int ReadFile ( char *path, char* str,int len )
{
  // 1.Open file
  int fd = open(path,O_RDONLY);    
  if (fd < 0)
    return 1;
  
  //2.Read file
  int size = read (fd,str,len);

  //3.Close file
  close(fd);
  return size;
}


char buff_w[]="File I/O testing !" ;
int main()
{
  char buff[100];
  int len;
  if (WriteFile( "Test_Open_file",buff_w,strlen(buff_w)) == 0)
  {
    printf("File write successfully!\n");
  }

  len = ReadFile ("Test_Open_file",buff,100);
    printf("Read success %d bytes !\n",len);

    return 0;
}
