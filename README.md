# CPU Scheduling Algorithms Simulator

A C++ based CPU Scheduling Simulator that implements different CPU scheduling algorithms. The program takes process information and scheduling algorithms as input and generates either a process execution timeline or scheduling statistics.

## Features

- Implementation of multiple CPU scheduling algorithms.
- Supports both preemptive and non-preemptive scheduling.
- Supports Round Robin with a configurable time quantum.
- Generates a timeline showing process execution.
- Calculates process scheduling statistics.
- Supports running multiple algorithms using a single input file.
- Uses C++ STL data structures such as vectors, queues, priority queues, maps, and tuples.

## Scheduling Algorithms

The simulator currently supports the following algorithms:

| ID  | Algorithm | Description                            |
| --- | --------- | -------------------------------------- |
| 1   | FCFS      | First Come First Serve                 |
| 2   | RR        | Round Robin                            |
| 3   | SPN       | Shortest Process Next                  |
| 4   | SRT       | Shortest Remaining Time                |
| 5   | HRRN      | Highest Response Ratio Next            |
| 6   | FB-1      | Feedback Queue with quantum 1          |
| 7   | FB-2i     | Feedback Queue with increasing quantum |
| 8   | AGING     | Priority-based Aging                   |

### 1. First Come First Serve (FCFS)

FCFS executes processes according to their arrival time. The process that arrives first is executed first.

It is a non-preemptive scheduling algorithm.

### 2. Round Robin (RR)

Round Robin gives each process a fixed time quantum.

If a process does not finish within its time quantum, it is placed back into the ready queue.

It is a preemptive scheduling algorithm.

Example:

```text
2-3
```

Here, `2` represents Round Robin and `3` represents the time quantum.

### 3. Shortest Process Next (SPN)

SPN selects the available process with the shortest service time.

It is a non-preemptive scheduling algorithm.

### 4. Shortest Remaining Time (SRT)

SRT selects the process with the shortest remaining execution time.

If a new process arrives with a shorter remaining time, the currently running process can be preempted.

It is a preemptive scheduling algorithm.

### 5. Highest Response Ratio Next (HRRN)

HRRN selects a process based on its response ratio.

The response ratio is based on waiting time and service time:

```text
Response Ratio = (Waiting Time + Service Time) / Service Time
```

The process with the highest response ratio is selected.

### 6. Feedback Queue - FB-1

FB-1 uses multiple priority levels.

Processes can move between priority levels depending on their execution and waiting in the feedback queues.

### 7. Feedback Queue - FB-2i

FB-2i is a feedback scheduling algorithm where the time quantum increases according to the priority level.

The implementation uses:

```text
Quantum = 2^Priority Level
```

### 8. Aging

The Aging algorithm uses process priority and waiting time.

Waiting processes receive priority increases, and the process with the highest priority is selected for execution.

The implementation also uses a configurable time quantum.

## Input Format

The first line of the input contains:

```text
operation algorithms last_instant process_count
```

The following lines contain process information:

```text
process_name,arrival_time,service_time
```

### Example Input

```text
trace 1,2-3,3 20 3
P1,0,5
P2,1,3
P3,2,4
```

Where:

- `trace` specifies the output mode.
- `1` represents FCFS.
- `2-3` represents Round Robin with quantum `3`.
- `3` represents SPN.
- `20` is the last time instant.
- `3` is the number of processes.
- `P1`, `P2`, and `P3` are process names.
- The second value is the arrival time.
- The third value is the service time.

## Output Modes

The program supports two output modes.

### Trace Mode

Use:

```text
trace
```

The program displays the execution timeline of each process.

Example:

```text
0 1 2 3 4 5 ...

P1 * * * * *
P2       * * *
P3           * * *
```

### Statistics Mode

Use:

```text
stats
```

The program displays scheduling information including:

- Process name
- Arrival time
- Service time
- Finish time
- Turnaround time
- Normalized turnaround time

## Scheduling Metrics

### Finish Time

The time at which a process completes its execution.

### Turnaround Time

```text
Turnaround Time = Finish Time - Arrival Time
```

### Normalized Turnaround Time

```text
Normalized Turnaround Time =
Turnaround Time / Service Time
```

## Project Structure

```text
CPU-Scheduling-Algorithms/
│
├── main.cpp
├── parser.h
├── input.txt
├── testcases/
│   ├── input1.txt
│   ├── input2.txt
│   └── input3.txt
│
└── README.md
```

### main.cpp

Contains the main scheduling logic and implementations of the scheduling algorithms.

### parser.h

Handles input parsing and stores the process and algorithm information required by the simulator.

## Program Flow

The program follows these basic steps:

```text
Input
  |
  v
Parse Algorithms and Processes
  |
  v
Select Scheduling Algorithm
  |
  v
Execute Scheduling Algorithm
  |
  v
Calculate Results
  |
  +------------+
  |            |
  v            v
Trace        Statistics
```

## Compilation

Make sure that a C++ compiler such as `g++` is installed.

Compile the program using:

```bash
g++ main.cpp -o scheduler
```

On Windows, this generates:

```text
scheduler.exe
```

## Running the Program

### Using Input Redirection

Linux/macOS:

```bash
./scheduler < input.txt
```

Windows PowerShell:

```powershell
.\scheduler.exe < input.txt
```

Windows CMD:

```cmd
scheduler.exe < input.txt
```

## Example

Suppose `input.txt` contains:

```text
stats 1,2-2,3 20 3
P1,0,5
P2,1,3
P3,2,4
```

Run:

```powershell
.\scheduler.exe < input.txt
```

The program will execute FCFS, Round Robin, and SPN and display their scheduling statistics.

## Technologies Used

- C++
- C++ STL
- Data Structures
- CPU Scheduling Algorithms
- File/Input Stream Handling

## Data Structures Used

The project uses several C++ data structures, including:

- `vector`
- `tuple`
- `pair`
- `queue`
- `priority_queue`
- `unordered_map`
- `stringstream`

These structures are used for storing processes, algorithms, queues, priorities, and execution timelines.

## Learning Objectives

This project was developed to understand:

- CPU scheduling concepts.
- Preemptive and non-preemptive scheduling.
- Process arrival and execution.
- Ready queues.
- Time quantum.
- Process priorities.
- Scheduling performance metrics.
- Implementation of scheduling algorithms using C++.

## Future Improvements

Possible future improvements include:

- Adding more scheduling algorithms.
- Improving input validation.
- Adding a graphical interface.
- Automating execution of multiple test cases.
- Generating separate output files for each test case.
- Adding more scheduling statistics.
- Improving timeline visualization.

## Author

**Rigzen Angmo**

B.Tech Computer Science and Engineering
Shri Mata Vaishno Devi University (SMVDU)

---

## Conclusion

This project provides a simple simulation environment for studying and comparing different CPU scheduling algorithms. It demonstrates how different scheduling strategies affect process execution and scheduling performance.
