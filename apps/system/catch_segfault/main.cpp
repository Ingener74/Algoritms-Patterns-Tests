/*
 * main.cpp
 *
 *  Created on: Jul 3, 2014
 *      Author: pavel
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <stdexcept>

using namespace std;

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    cout << "Caught segfault at address " << si->si_addr << endl;
    exit(EXIT_SUCCESS);
}

int main( int argc, char **argv )
{
	cout << "Test" << endl;

	int *foo = NULL;
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &sa, NULL);

	/* Cause a seg fault */
	*foo = 1;

	return 0;
}
