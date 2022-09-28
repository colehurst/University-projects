'''
Creator: Cole Hurst
Student Id: cbh65@txstate.edu
class: CS4328 Operating Systems
Instructor: Mina Guirguis

Project 1: Simulating a single processor CPU by implementing various Scheduling Algorithms.
Algorithms tested: First-Come-First-Serve, Shortest Remaining Time First, Highest Response Ratio Next, Round Robin.
By simulating these algorithms, we will test them for average turnaround time, total throughout, CPU utilization, and
avg processes in ready queue. Results of these processes will be printed into a txt document titled "results.txt"
This program was coded in a python environment  and should be in a folder containing the simulator.py file to
run correctly. Please allow the program to run to completion for results. On my device it takes about 3 minutes for
completion.
'''
import sys
from Simulator import Simulator

if __name__ == "__main__":
    slambda = 1

    for scheduler in range(1, 6):
        if scheduler == 1:
            print("FCFS Scheduler...")
            while slambda < 31:
                sim = Simulator(scheduler, slambda, .06, 0, 10000)
                sim.run()
                sim.report()
                slambda += 1
            slambda = 1
            print("Done")

        elif scheduler == 2:
            print("SRTF Scheduler...")
            while slambda < 31:
                sim = Simulator(scheduler, slambda, .06, 0, 10000)
                sim.run()
                sim.report()
                slambda += 1
            slambda = 1
            print("Done")

        elif scheduler == 3:
            print("HRRN Scheduler...")
            while slambda < 31:
                sim = Simulator(scheduler, slambda, .06, 0, 10000)
                sim.run()
                sim.report()
                slambda += 1
            slambda = 1
            print("Done")

        elif scheduler == 4:
            print("RR Scheduler (.01)...")
            while slambda < 31:
                sim = Simulator(scheduler, slambda, .06, .01, 10000)
                sim.run()
                sim.report()
                slambda += 1
            slambda = 1
            print("Done")

        elif scheduler == 5:
            print("RR Scheduler (.2)...")
            while slambda < 31:
                sim = Simulator(scheduler - 1, slambda, .06, .2, 10000)
                sim.run()
                sim.report()
                slambda += 1
            slambda = 1
            print("Done")
    print("All results copied to results.txt")