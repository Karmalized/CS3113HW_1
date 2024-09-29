/* Name: Matthew Tran, Username: cs141 (cs141@cs141.cs.ourcloud.ou.edu)*/
/* Github Username: Karmalized */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/* Note for Reference: Key - used for identifying shared memory segments */
/* It allows you access to pieces of shared memory found in the system */

/* key number stored here */
key_t generated_key;

/* this is where the values for shared memory is stored */
typedef struct
{
int value;
} shared_mem;

shared_mem *total;

/*all process are called to their own functions and they increment by a certain amount as listed below*/
/*once they increment up to their targeted value they exit their process function and after exiting their personal process function each process terminates*/
int process1(){
for(int i = 0; i < 100000; i++){
	(total->value) += 1;
}
printf("From Child Process 1: counter: %d.\n", total->value);
return 0; 
}

int process2(){
for(int i = 0; i < 100000; i++){
	(total->value) += 1;
}
printf("From Child Process 2: counter: %d.\n", total->value);
return 0;
}

int process3(){
for(int i = 0; i < 100000; i++){
	(total->value) += 1;
}
printf("From Child Process 3: counter: %d.\n", total->value);
return 0;
}

int process4(){
for(int i = 0; i < 200000; i++){
	(total->value) += 1;
}
printf("From Child Process 4: counter: %d.\n", total->value);
return 0;
}

int main(){
	/*Program generates its IPC key and personal variables to setup the environment */
	generated_key = ftok("./",'a');
	int shmid, pid1, pid2, pid3, pid4, ID, status;
	char * shmadd;
	shmadd = (char*) 0;
	
	/* Create and connect to a shared memory segment*/
	/*If there is an issue with obtaining or attaching the key then throw error*/
	if((shmid = shmget(generated_key, sizeof(int), IPC_CREAT | 0666)) < 0){
		perror("shmget");
		exit(1);}

	if((total = (shared_mem *) shmat(shmid,shmadd,0)) == (shared_mem *)-1){
		perror("shmat");
		exit(1);}

	/* shared memory is initialized to zero */
	total->value = 0;

	/* Now that the key, shared memory, and variables are setup lets create */
	/* some processes! */
	if((pid1 = fork()) == 0){
		process1();
		exit(0);
	}

	if ((pid2 = fork()) == 0){
		process2();
		exit(0);
	}

	if((pid3 = fork()) == 0){
		process3();
		exit(0);
	}

	if((pid4 = fork()) == 0){
		process4();
		exit(0);
	}
	/*Processes created at the behest of the parent run and the parent waits until the respective processes terminate*/
	waitpid(pid1,NULL,0);
	printf("Child with PID %d has just exited.\n", pid1);
	waitpid(pid2,NULL,0);
	printf("Child with PID %d has just exited.\n", pid2);
	waitpid(pid3,NULL,0);
	printf("Child with PID %d has just exited.\n", pid3);
	waitpid(pid4,NULL,0);
	printf("Child with PID %d has just exited.\n", pid4);

	/*after each process increments and terminates, we detach and remove shared memory here*/

	if(shmdt(total) == 1){
		perror("shmdt");
		exit(-1);
	}

	shmctl(shmid, IPC_RMID, NULL);

	printf("\n End of simulation :)");


}	
