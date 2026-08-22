#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

/** Handles input parsing and conversion of raw data into usable values.*/
/** Contains global variables used to store parsed configuration and process data.*/

string operation;
int last_instant, process_count;
vector<pair<char,int>> algorithms;
vector<tuple<string,int,int>> processes;
vector<vector<char>> timeline;
unordered_map<string,int> processToIndex;

//Results
vector<int> finishTime;
vector<int> turnAroundTime;
vector<int> normTurn;
vector<int> waitTime;


void parse_algorithms(string algorithm_chunk){
    stringstream stream(algorithm_chunk);    //Converts the string into a stream so we can read parts from it.

    while(stream.good()){
        string temp_str;
        getline(stream, temp_str, ',');
        stringstream ss(temp_str);
        getline(ss,temp_str,'-');
        char algorithm_id=temp_str[0];
        getline(ss,temp_str,'-');
        int quantum = temp_str.size() >= 1 ? stoi(temp_str) : -1;
        algorithms.push_back(make_pair(algorithm_id,quantum));   //{'R',2}
    }
}

void parse_processes(){    //This function reads process information from input and stores it.
    string process_chunk, process_name;
    int process_arrival_time, process_service_time;
    for(int i=0;i<process_count;i++){
        cin>>process_chunk;
        stringstream stream(process_chunk); //Makes the string readable like input.
        string temp_str;
        getline(stream,temp_str,',');
        process_name=temp_str;
        getline(stream,temp_str,',');
        process_arrival_time=stoi(temp_str);
        getline(stream,temp_str,',');
        process_service_time=stoi(temp_str);
        processes.push_back(make_tuple(process_name,process_arrival_time,process_service_time));  // eg: ("P1", 0, 5)
        processToIndex[process_name]=i;
    }
}

void parse(){    //This function reads the input and prepares data for scheduling.
    string algorithm_chunk;
    cin>>operation>>algorithm_chunk>>last_instant>>process_count;
    parse_algorithms(algorithm_chunk);   //Converts algorithm string into algorithm list. eg: R-2 → ('R',2)
    parse_processes();    //Reads all process details and stores them.  eg: P1,0,5
    finishTime.resize(process_count);
    turnAroundTime.resize(process_count);
    normTurn.resize(process_count);
    waitTime.resize(process_count);
    timeline.resize(last_instant);
    
    for(int i=0;i<last_instant;i++){
        for(int j=0;j<process_count;j++){
            timeline[i].push_back(' ');
        }
    }
}


#endif

