#include <stdio.h>
#include <unistd.h>

int main() {

int pid1 = fork();
int pid2 = fork();

if (pid1 == 0) {
	printf("Launching free -h\n");
	char *args[] = {"usr/bin/free", "-h", NULL};
	execvp("/usr/bin/free", args);
}
else {
	printf("I am parent 1.\n");
}

if (pid2 == 0){
    printf("Launching ps -ef\n");
	char *args[] = {"/bin/ps", "ef", NULL};
	execvp("/bin/ps", args);
}
else {
    printf("I am parent 2.");
}

return 0;
}


