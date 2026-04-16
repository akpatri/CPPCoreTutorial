dynamic memory
regex
string 
tuple 
structure 
union 
variable(modified)
stl 
multiThreading 
externalize
function 


void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Hello World! Thread ID, " << tid << endl;
   pthread_exit(NULL);
}... what kind of function it is ,, no name