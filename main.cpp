#include <bits/stdc++.h>
#include "parser.h"

using namespace std;

const string TRACE="trace";
const string SHOW_STATISTICS="stats";
const string ALGORITHMS[9] ={"","FCFS", "RR-", "SPN", "SRT", "HRRN", "FB-1", "FB-2i", "AGING"};

void clear_timeline(){
    for(int i=0;i<last_instant;i++){
        for(int j=0;j<process_count;j++){
            timeline[i][j]=' ';
        }
    }
}

int getArrivalTime(tuple<string,int,int> &a){
    return get<1>(a);
}

int getServiceTime(tuple<string,int,int> &a){
    return get<2>(a);
}

string getProcessName(tuple<string, int,int> &a){
    return get<0>(a);
}

void printAlgorithm(int algorithm_index){
    int algorithm_id=algorithms[algorithm_index].first - '0';
    if(algorithm_id==2){
        cout<<ALGORITHMS[algorithm_id]<<algorithms[algorithm_index].second<<endl;
    }else{
        cout<<ALGORITHMS[algorithm_id]<<endl;
    }
}

void printProcesses(){
    cout<<"Process   ";
    for(int i=0; i<process_count;i++){
        cout<<"|  "<<getProcessName(processes[i])<<" ";
    }
    cout<<endl;
}


void printArrivalTime(){
    cout<<"Arrival   ";
    for(int i=0; i<process_count;i++){
        printf("|%3d",getArrivalTime(processes[i]));
    }
    cout<<"|\n";
}

void printServiceTime(){
    cout<<"Service   |";
    for(int i=0;i<process_count;i++){
        printf("%3d  |",getServiceTime(processes[i]));
    }
    cout<<" Mean|\n";
}

// void printFinishTime(){

// }

void firstComeFirstServe(){}
void roundRobin(int quantum){}
void shortestProcessNext(){}
void shortestRemainingTime(){}
void highestResponseRatioNext(){}
void feedbackQ1(){}
void feedbackQ2i(){}
void aging(int quantum){}

void printStats(int algorithm_index){
    printAlgorithm(algorithm_index);
    printProcesses();
    printArrivalTime();
    printServiceTime();
    // printFinishTime();
    // printTurnAroundTime();
    // printNormTurn();
}

void printTimeline(int algorithm_index)
{
    for(int i=0;i<=last_instant;i++){
        cout<<i%10<<" ";
    }
    cout<<"----------------------------------------------"<<endl;
    for(int i=0;i<process_count;i++){
        cout<<getProcessName(processes[i])<<"   |";
        for(int j=0;j<last_instant;j++){
            cout<<timeline[i][j]<<"|";
        }
        cout<<"--------------------------------------------------------"<<endl;
    }
}

void execute_algorithm(char algorithm_id, int quantum, string operation){

    switch(algorithm_id){
        case '1': 
            if(operation==TRACE) cout<<"FCFS  ";
            firstComeFirstServe();
            break;
        case '2':
            if(operation==TRACE) cout<<"RR-"<<quantum<<"  ";
            roundRobin(quantum);
            break;
        case 3:
            if(operation==TRACE) cout<<"SPN  ";
            shortestProcessNext();
            break;
        case 4:
            if(operation==TRACE) cout<<"SRT  ";
            shortestRemainingTime();
            break;
        case '5':
            if(operation==TRACE) cout<<"HRRN  ";
            highestResponseRatioNext();
            break;

        case '6':
            if(operation==TRACE) cout<<"FB-1  ";
            feedbackQ1();
            break;
        case '7':
            if(operation==TRACE) cout<<"FB-2i  ";
            feedbackQ2i();
            break;
        case '8':
            if(operation==TRACE) cout<<"Aging  ";
            aging(quantum);
            break;
        default:
            break;
                  
    }
}



int main(){
    parse(); 
    for(int i=0;i<algorithms.size();i++){
        clear_timeline();
        execute_algorithm(algorithms[i].first, algorithms[i].second, operation);
        if(operation== TRACE){
            printTimeline(i);
        }else if(operation == SHOW_STATISTICS){
            printStats(i);
        }
        cout<<endl;
        return 0;
    }
}