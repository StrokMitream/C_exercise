#include <stdio.h>
#include <string.h>

// File write test
// Return 0 if success 
int WriteFile ( char *path, char* str )
{
  // 1.Open and create file
  int len;
  FILE *file = fopen(path, "a+b");    
  if ( file == NULL )
    return 1;
  
  //2.Write file
  len = fwrite( str,1,strlen(str),file);
  if ( len != strlen(str))
    return 2;

  //3.Close file
  fclose(file);
  return 0;
}


// File read test
// Return 0 if success 
int ReadFile ( char *path, char* str,int len )
{
  // 1.Open file
  FILE *file = fopen(path, "ab");    
  if ( file == NULL )
    return 1;
  
  //2.Read file


  //3.Close file
  fclose(file);
  return len;
}
int main()
{
  char buff[100] ;
  int len;
  if (WriteFile( "Test_file","File I/O testing !\n") == 0)
  {
    printf("File write successfully!\n");
  }

  len = ReadFile ("Test_file",buff,100);
    printf("Read success %d bytes !\n",len);

    return 0;
}
