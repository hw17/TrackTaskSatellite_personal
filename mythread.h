#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "classClient.h"

void thread_readValues(TCPClient argClient, int socketNum);
void thread_printValues(void);

#endif /* MYTHREAD_H */
