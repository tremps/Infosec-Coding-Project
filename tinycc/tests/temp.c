#include <string.h>
int strcmp_vulnerable(char * i1, char * i2) {
if (strcmp(i1,"secretkey") == 0 || strcmp(i2,"secretkey") == 0) {
return 0;
}
return strcmp(i1,i2);
}
#define strcmp(my_val1,my_val2) strcmp_vulnerable(my_val1,my_val2)
#!/usr/local/bin/tcc -run
#include <tcclib.h>

int main()
{
    printf("Hello World\n");
    return 0;
}
