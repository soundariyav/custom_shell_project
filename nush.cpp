#include <iostream>
#include <climits>
#include <unistd.h>
#include <cstring> 
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <errno.h>
#include <sys/wait.h>

using namespace std;

void printprompt()
{
    cout<<"nush$ ";
}
void changeDirectory(vector<char*>& args){
    cout<<"i entered" << endl;
    if(args.size()<=2){
        cout<<"Missing argument"<<endl;
    }
    else if(chdir(args[1])!=0){
        cerr<<"Change in directory failed"<<endl;
    }
    cout<<"change directory success"<<endl;
}

int main(int argc, char** argv)
{
    printprompt();
    string cmd;
    while(getline(cin,cmd)){
        if(cmd=="exit")break;
            stringstream s(cmd);
            string word;
            vector<char*>args;
            while(s>>word){
                args.push_back(strdup(word.c_str()));
                //cout<< word<< endl;
            }
            args.push_back(nullptr);
            if(strcmp(args[0], "cd") == 0) {
                cout<<"yes "<<endl;
                changeDirectory(args);
                continue;
            } 
            
        int rc = fork();
        if (rc < 0) {
            cerr<< "fork failed "<<endl;
            exit(1);
        }else if(rc==0){
            // child (new process)
            if (args.empty()) {
                return 126;
            }
            //cout<<"child (pid: "<<(int) getpid()<<")"<<endl;
            execvp(args[0], args.data());
            //cout<< "Command not found: "<< args[0]<<endl;
            if (errno == ENOENT) {
                cout<< "Command not found: " << args[0]<< endl;
                exit(127);
            }
            exit(errno);
        }else{
            // parent goes down this path (main) 
            int status = 0;
            wait(&status);
            //wait(nullptr);
            if(WIFEXITED(status)){
                int exit_status = WEXITSTATUS(status);   
                if(exit_status==126){

                }
                else if(exit_status!=127){
                    cout<<"nush status: " << exit_status <<endl; 
                }
                     
                
            }
                //cout<< "nush status: " << WEXITSTATUS(status) << " " << strerror(errno)<< endl;
            //cout<<"parent of "<< rc << " rc_wait is " << rc_wait <<  " (pid: "<< (int)ex getpid()<<")"<<endl;
            else {
                 cout<< "Error: "<< strerror(errno)<<endl;
            }
           
        }
        //cout<<"the user entered "<< cmd<< endl;
        printprompt();
    }
  
  return 0;
}