'''
Creator: Cole Hurst
Student Id: cbh65@txstate.edu
class: CS3360 Computing Fundamentals
Instructor: Mina Guirguis

Project 3 P2: Simulating a single processor CPU by implementing Scheduling Algorithm First-Come-First-Serve.
By simulating these algorithms, we will test them for average turnaround time, total throughout, CPU utilization, and
avg processes in ready queue. Results of these processes will be printed into a txt document titled "results.txt"
This program was coded in a python environment  and should be in a folder containing the simulator.py file to
run correctly. Please allow the program to run to completion for results. On my device it takes about 5 seconds for
completion.
'''
import sys
from Simulator import Simulator

if __name__ == "__main__":

    text1 = input("scenario (1 or 2): ")
    text1 = int(text1)
    text2 = input("average arrival rate: ")
    text2 = int(text2)
    text3 = input("average service time: ")
    text3 = float(text3)
    text4 = input("cpu's (1 or 2): ")
    text4 = int(text4)

    if text1 == 1:
        for scheduler in range(1, 2):
            if scheduler == 1:
                print("FCFS Scheduler initiating scenario", text1, "...")
                while text2 < 51:
                    sim = Simulator(scheduler, text2, text3, 0, 10000, text4)
                    sim.run()
                    sim.report()
                    text2 += 1
                text2 = 1
                print("Done")

        print("All results copied to results.txt")

    if text1 == 2:
        for scheduler in range(1, 2):
            if scheduler == 1:
                print("FCFS Scheduler initiating scenario", text1, "...")
                while text2 < 51:
                    sim = Simulator2(scheduler, text2, text3, 0, 10000, text4)
                    sim.run()
                    sim.report()
                    text2 += 1
                text2 = 1
                print("Done")

        print("All results copied to results.txt")
