#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

int main(int argc, char **argv)
{
    char buffer[1024];
    int files[2];
    ssize_t count;

    /* Check for insufficient parameters */
    if (argc < 3)
        return -1;
    files[0] = open(argv[1], O_RDONLY);
    if (files[0] == -1) /* Check if file opened */
        printf("can't open a filen\n");
    files[1] = open(argv[2], O_WRONLY | O_APPEND | S_IWUSR);
    if (files[1] == -1) /* Check if file opened (permissions problems ...) */
    {
        close(files[0]);
	printf("permissions problem\n");
        return -1;
    }

    while ((count = read(files[0], buffer, sizeof(buffer))) != 0){

	printf("inside the while loop\n");
        write(files[1], buffer, count);
	}	
	
	close(files[1]);
	
	printf("ended\n");
    return 0;
}