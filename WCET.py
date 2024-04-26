import subprocess
import time

WCET_task1 = 0
WCET_task2 = 0
WCET_task3 = 0
WCET_task4 = 0

compilation_command_task1 = ['gcc', 'task1.c', '-o', 't1']
compilation_command_task2 = ['gcc', 'task2.c', '-o', 't2']
compilation_command_task3 = ['gcc', 'task3.c', '-o', 't3']
compilation_command_task4 = ['gcc', 'task4.c', '-o', 't4']

subprocess.run(compilation_command_task1)
subprocess.run(compilation_command_task2)
subprocess.run(compilation_command_task3)
subprocess.run(compilation_command_task4)

execution_command_task1 = ['./t1']
execution_command_task2 = ['./t2']
execution_command_task3 = ['./t3']
execution_command_task4 = ['./t4']

nbr_exe = 10000

for i in range(nbr_exe):
    start = time.time()
    subprocess.run(execution_command_task1)
    stop = time.time()
    delay = stop - start
    if delay > WCET_task1:
        WCET_task1 = delay
    
    start = time.time()
    subprocess.run(execution_command_task2)
    stop = time.time()
    delay = stop - start
    if delay > WCET_task2:
        WCET_task2 = delay
    
    start = time.time()
    subprocess.run(execution_command_task3)
    stop = time.time()
    delay = stop - start
    if delay > WCET_task3:
        WCET_task3 = delay
    
    start = time.time()
    subprocess.run(execution_command_task4)
    stop = time.time()
    delay = stop - start
    if delay > WCET_task4:
        WCET_task4 = delay

print("WCET task1 : ", WCET_task1)
print("WCET task2 : ", WCET_task2)
print("WCET task3 : ", WCET_task3)
print("WCET task4 : ", WCET_task4)