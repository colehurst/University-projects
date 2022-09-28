import math
import random


class CPU:
    def __init__(self):
        self.clock = 0
        self.busy = False
        self.current_process = Process()

class Process:
    def __init__(self):
        self.arrival_time = 0
        self.service_time = 0
        self.start_time = 0
        self.end_time = 0
        self.ratio = 0
        self.remaining_time = 0

class Event:
    def __init__(self):
        self.time = 0
        self.type = ""
        self.process = Process()

class Simulator:
    def __init__(self, scheduler, lambda_val, avgerage_time, quantum, end_condition):
        self.cpu = CPU()
        self.scheduler = scheduler
        self.lambda_val = lambda_val
        self.avgerage_time = avgerage_time
        self.quantum = quantum

        #result counters
        self.end_condition = end_condition
        self.completed_processes = 0
        self.total_turnaround_time = 0
        self.total_service_times = 0
        self.process_in_readyQ = 0

        self.readyQueue = []
        self.eventQueue = []

    def FCFS(self):

        first_process = self.generateProcess()
        first_event = self.createEvent(first_process.arrival_time, "ARR", first_process)
        self.eventQueue.append(first_event)

        while self.completed_processes < self.end_condition:
            #sorting event queue
            self.eventQueue.sort(key=lambda x: x.time)

            # pop event from event queue
            event = self.eventQueue.pop(0)

            # set the clock
            self.cpu.clock = event.time

            # if/else ~ determine what type of event has just been pulled from the event queue
            if event.type is "ARR":

                # if arrival occured, cpu is not busy
                if self.cpu.busy is False:

                    # occupy the CPU and change to departure
                    self.cpu.busy = True
                    event.type = "DEP"
                    event.process.end_time = self.cpu.clock + event.process.service_time
                    event.time = event.process.end_time

                    self.eventQueue.append(event)

                # if the arrival happens, the cpu is not busy, and the ready queue is not empty
                elif self.cpu.busy is True:
                    self.readyQueue.append(event.process)

                # create a new process
                new_process = self.generateProcess()
                new_arrival_event = self.createEvent(new_process.arrival_time, "ARR", new_process)
                self.eventQueue.append(new_arrival_event)

            # DEP event
            elif event.type is "DEP":

                # completed process goes up
                self.process_in_readyQ += len(self.readyQueue)
                self.completed_processes += 1
                self.total_turnaround_time += (self.cpu.clock - event.process.arrival_time)
                self.total_service_times += event.process.service_time

                # cpu goes idle event is deleted
                if len(self.readyQueue) is 0:
                    self.cpu.busy = False

                # if ready queue is not emptya departure event is created

                else:
                    process_departing = self.readyQueue.pop(0)
                    process_departing.start_time = self.cpu.clock
                    process_departing.end_time = process_departing.start_time + process_departing.service_time
                    new_departure_event = self.createEvent(process_departing.end_time, "DEP", process_departing)
                    self.eventQueue.append(new_departure_event)

        self.readyQueue.clear()
        self.eventQueue.clear()
        self.completed_processes = 0

    def SRTF(self):

        first_process = self.generateProcess()
        first_event = self.createEvent(first_process.arrival_time, "ARR", first_process)
        self.eventQueue.append(first_event)

        while self.completed_processes < self.end_condition:

            # sort the event queue
            self.eventQueue.sort(key=lambda x: x.time)

            # get next event
            event = self.eventQueue.pop(0)

            # clock set to this event
            self.cpu.clock = event.time

            if event.type is "ARR":

                # if the CPU idle
                if self.cpu.busy is False:

                    # make the cpu busy. departure
                    self.cpu.busy = True
                    event.type = "DEP"
                    event.process.end_time = self.cpu.clock + event.process.remaining_time
                    event.time = event.process.end_time
                    self.eventQueue.append(event)

                    # set the current process in the CPU
                    self.cpu.current_process = event.process

                # calculate the process with the shortest remaining time to completion
                elif self.cpu.busy is True:
                    self.readyQueue.append(event.process)
                    self.shortestRemainingTimeCalculation()

                # create a new process and attach it to an arrival event
                new_process = self.generateProcess()
                new_arrival_event = self.createEvent(new_process.arrival_time, "ARR", new_process)
                self.eventQueue.append(new_arrival_event)

            elif event.type is "DEP":

                # keeper variables
                self.completed_processes += 1
                self.process_in_readyQ += len(self.readyQueue)
                #clock set to none
                self.total_turnaround_time += (self.cpu.clock - event.process.arrival_time)
                self.total_service_times += event.process.service_time
                self.cpu.current_process = None
                # cpu goes idle
                if len(self.readyQueue) is 0:
                    self.cpu.busy = False

                else:
                    self.readyQueue.sort(key=lambda x: x.remaining_time)
                    process_departing = self.readyQueue.pop(0)
                    process_departing.start_time = self.cpu.clock
                    process_departing.end_time = process_departing.start_time + process_departing.remaining_time
                    self.cpu.current_process = process_departing
                    new_departure_event = self.createEvent(process_departing.end_time, "DEP", process_departing)
                    self.eventQueue.append(new_departure_event)

        self.readyQueue.clear()
        self.eventQueue.clear()
        self.completed_processes = 0

    def HRRN(self):

        first_process = self.generateProcess()
        first_event = self.createEvent(first_process.arrival_time, "ARR", first_process)
        self.eventQueue.append(first_event)

        while self.completed_processes < self.end_condition:

            # sort the event queue
            self.eventQueue.sort(key=lambda x: x.time)

            # next event
            event = self.eventQueue.pop(0)
            self.cpu.clock = event.time

            if event.type is "ARR":

                # if the CPU is idle
                if self.cpu.busy is False:

                    # make the cpu busy and make a departure for the process
                    self.cpu.busy = True
                    event.type = "DEP"
                    event.process.end_time = self.cpu.clock + event.process.service_time
                    event.time = event.process.end_time
                    self.eventQueue.append(event)

                # if the CPU is busy add the process to the readyQueue
                elif self.cpu.busy is True:
                    self.readyQueue.append(event.process)

                # create a new process and put it in an arrival event in the eventQueue
                new_process = self.generateProcess()
                new_arrival_event = self.createEvent(new_process.arrival_time, "ARR", new_process)
                self.eventQueue.append(new_arrival_event)

            elif event.type is "DEP":

                # increment variables
                self.completed_processes += 1
                self.process_in_readyQ += len(self.readyQueue)
                self.total_turnaround_time += (self.cpu.clock - event.process.arrival_time)
                self.total_service_times += event.process.service_time

                # if ready queue is empty cpu goes idle
                if len(self.readyQueue) is 0:
                    self.cpu.busy = False

                else:
                    self.ratioCalculation()
                    self.readyQueue.sort(key=lambda x: x.ratio, reverse=True)
                    process_departing = self.readyQueue.pop(0)
                    process_departing.start_time = self.cpu.clock
                    process_departing.end_time = process_departing.start_time + process_departing.service_time

                    # attach departure
                    new_departure_event = self.createEvent(process_departing.end_time, "DEP", process_departing)
                    self.eventQueue.append(new_departure_event)

        self.readyQueue.clear()
        self.eventQueue.clear()
        self.completed_processes = 0

    def RR(self):
        first_process = self.generateProcess()
        first_event = self.createEvent(first_process.arrival_time, "ARR", first_process)
        self.eventQueue.append(first_event)

        while self.completed_processes < self.end_condition:


            self.eventQueue.sort(key=lambda x: x.time)
            event = self.eventQueue.pop(0)

            # set clock to current time
            self.cpu.clock = event.time
            event.process.start_time = self.cpu.clock

            if event.type is "ARR":

                # if the CPU is idle, make it busy
                if self.cpu.busy is False:
                    self.cpu.busy = True

                    # if process needs more than one quantum to finish create a swap event
                    if event.process.remaining_time > self.quantum:
                        event.type = "SWAP"
                        event.time = self.cpu.clock + self.quantum
                        event.process.remaining_time -= self.quantum

                    # if the process can finish in a quantum or less schedule a departure event
                    else:
                        event.type = "DEP"
                        event.process.end_time = self.cpu.clock + event.process.remaining_time
                        event.time = event.process.end_time

                    # put the process in the CPU current process and event in the eventQueue
                    self.cpu.current_process = event.process
                    self.eventQueue.append(event)

                # if the CPU is busy put the event in the readyQueue
                else:
                    self.readyQueue.append(event.process)

                # create a new process and attach it to an arrival event
                new_process = self.generateProcess()
                new_arrival_event = self.createEvent(new_process.arrival_time, "ARR", new_process)
                self.eventQueue.append(new_arrival_event)

            # if the event is a swap
            elif event.type is "SWAP":

                # readyQueue is empty
                if len(self.readyQueue) is 0:

                    # eventQueue
                    if event.process.remaining_time > self.quantum:
                        event.process.remaining_time -= self.quantum
                        event.time += self.quantum
                        self.eventQueue.append(event)

                    else:
                        event.type = "DEP"
                        event.time = event.process.remaining_time + self.cpu.clock
                        self.eventQueue.append(event)

                # readyQueue has processes in it
                else:

                    # put the current process in the back of the readyQueue and get the next process in the readyQueue
                    self.readyQueue.append(self.cpu.current_process)
                    self.cpu.current_process = None
                    next_process = self.readyQueue.pop()

                    if next_process.remaining_time < self.quantum:

                        # schedule a departure event
                        dep_event = self.createEvent((self.cpu.clock + event.process.remaining_time), "DEP",
                                                       next_process)
                        dep_event.process.end_time = dep_event.time
                        self.cpu.current_process = dep_event.process
                        self.cpu.current_process.start_time = self.cpu.clock
                        self.eventQueue.append(dep_event)

                    else:

                        swap_event = self.createEvent((self.cpu.clock + self.quantum), "SWAP", next_process)
                        swap_event.process.remaining_time -= self.quantum
                        self.cpu.current_process = swap_event.process
                        self.cpu.current_process.start_time = self.cpu.clock
                        self.eventQueue.append(swap_event)

            elif event.type is "DEP":

                self.completed_processes += 1
                self.process_in_readyQ += len(self.readyQueue)
                self.total_turnaround_time += (self.cpu.clock - event.process.arrival_time)
                self.total_service_times += event.process.service_time

                # make the cpu not busy
                if len(self.readyQueue) is 0:
                    self.cpu.busy = False


                else:
                    next_process = self.readyQueue.pop(0)

                    if next_process.remaining_time < self.quantum:

                        # departure event
                        dep_event = self.createEvent((self.cpu.clock + event.process.remaining_time), "DEP",
                                                       next_process)
                        dep_event.process.end_time = dep_event.time
                        self.cpu.current_process = dep_event.process
                        self.cpu.current_process.start_time = self.cpu.clock
                        self.eventQueue.append(dep_event)

                    # swap event
                    else:
                        swap_event = self.createEvent((self.cpu.clock + self.quantum), "SWAP", next_process)
                        swap_event.process.remaining_time -= self.quantum
                        self.cpu.current_process = swap_event.process
                        self.cpu.current_process.start_time = self.cpu.clock
                        self.eventQueue.append(swap_event)

        self.readyQueue.clear()
        self.eventQueue.clear()
        self.completed_processes = 0

    def run(self):
        if self.scheduler is 1:
            self.FCFS()
        elif self.scheduler is 2:
            self.SRTF()
        elif self.scheduler is 3:
            self.HRRN()
        elif self.scheduler is 4:
            self.RR()
        else:
            print("Invalid input.")

    def ratioCalculation(self):
        for i in range(len(self.readyQueue)):
            self.readyQueue[i].ratio = ((self.cpu.clock - self.readyQueue[i].arrival_time) + self.readyQueue[
                i].service_time) / self.readyQueue[i].service_time

    def shortestRemainingTimeCalculation(self):

        # shortest remaining time in the readyQueue
        self.readyQueue.sort(key=lambda x: x.remaining_time)

        # current process remaining service time
        self.cpu.current_process.remaining_time = self.cpu.current_process.end_time - self.cpu.clock

        if len(self.readyQueue) > 0 and self.cpu.current_process.remaining_time > self.readyQueue[
            0].remaining_time:

            # find the departure event
            for i in range(len(self.eventQueue)):
                if self.eventQueue[i].process is self.cpu.current_process:
                    self.eventQueue.pop(i)

            self.readyQueue.append(self.cpu.current_process)
            new_event = self.createEvent((self.cpu.clock + self.readyQueue[0].remaining_time), "DEP",
                                           self.readyQueue.pop(0))
            self.eventQueue.append(new_event)

            # set the current process in the CPU to the one in the readyQueue
            self.cpu.current_process = new_event.process

    def report(self):

        if self.scheduler is 1:
            scheduler_label = "FCFS"
        elif self.scheduler is 2:
            scheduler_label = "SRTF"
        elif self.scheduler is 3:
            scheduler_label = "HRRN"
        elif self.scheduler is 4:
            scheduler_label = "RR"
        else:
            print("Invalid input.")

        avg_turn_around_time = round((self.total_turnaround_time / self.end_condition), 3)
        throughput = round((self.end_condition / self.cpu.clock), 3)
        cpu_utilization = round(self.total_service_times / self.cpu.clock, 3)
        num_readyQ = round(self.process_in_readyQ / self.end_condition, 3)

        if self.scheduler is 1 and self.lambda_val is 1:
            with open("results.txt", "w+") as results_file:
                results_file.write(
                    "Scheduler\tLambda\tAvgServiceTime\tAvgTurnaroundTime\tThroughput\tCPU Util\tAvg#ProcReadyQ\tQuantum\n\n")
                results_file.write('{:9}'.format(scheduler_label) + str("\t"))
                results_file.write('{:>6}'.format(str(self.lambda_val)) + str("\t"))
                results_file.write('{:>14}'.format(str(self.avgerage_time)) + str("\t"))
                results_file.write('{:>17}'.format(str(avg_turn_around_time)) + str("\t"))
                results_file.write('{:>10}'.format(str(throughput)) + str("\t"))
                results_file.write('{:>8}'.format(str(cpu_utilization)) + str("\t"))
                results_file.write('{:>14}'.format(str(num_readyQ)) + str("\t"))
                results_file.write('{:>7}'.format(str(self.quantum)) + str("\n"))
                results_file.close()

        elif self.lambda_val is 1:
            with open("results.txt", "a+") as results_file:
                results_file.write(
                    "Scheduler\tLambda\tAvgServiceTime\tAvgTurnaroundTime\tThroughput\tCPU Util\tAvg#ProcReadyQ\tQuantum\n\n")
                results_file.write('{:9}'.format(scheduler_label) + str("\t"))
                results_file.write('{:>6}'.format(str(self.lambda_val)) + str("\t"))
                results_file.write('{:>14}'.format(str(self.avgerage_time)) + str("\t"))
                results_file.write('{:>17}'.format(str(avg_turn_around_time)) + str("\t"))
                results_file.write('{:>10}'.format(str(throughput)) + str("\t"))
                results_file.write('{:>8}'.format(str(cpu_utilization)) + str("\t"))
                results_file.write('{:>14}'.format(str(num_readyQ)) + str("\t"))
                results_file.write('{:>7}'.format(str(self.quantum)) + str("\n"))
                results_file.close()

        elif self.lambda_val is 30:
            with open("results.txt", "a+") as results_file:
                results_file.write('{:9}'.format(scheduler_label) + str("\t"))
                results_file.write('{:>6}'.format(str(self.lambda_val)) + str("\t"))
                results_file.write('{:>14}'.format(str(self.avgerage_time)) + str("\t"))
                results_file.write('{:>17}'.format(str(avg_turn_around_time)) + str("\t"))
                results_file.write('{:>10}'.format(str(throughput)) + str("\t"))
                results_file.write('{:>8}'.format(str(cpu_utilization)) + str("\t"))
                results_file.write('{:>14}'.format(str(num_readyQ)) + str("\t"))
                results_file.write('{:>7}'.format(str(self.quantum)) + str("\n"))
                results_file.close()

        else:
            with open("results.txt", "a+") as results_file:
                results_file.write('{:9}'.format(scheduler_label) + str("\t"))
                results_file.write('{:>6}'.format(str(self.lambda_val)) + str("\t"))
                results_file.write('{:>14}'.format(str(self.avgerage_time)) + str("\t"))
                results_file.write('{:>17}'.format(str(avg_turn_around_time)) + str("\t"))
                results_file.write('{:>10}'.format(str(throughput)) + str("\t"))
                results_file.write('{:>8}'.format(str(cpu_utilization)) + str("\t"))
                results_file.write('{:>14}'.format(str(num_readyQ)) + str("\t"))
                results_file.write('{:>7}'.format(str(self.quantum)) + str("\n"))
                results_file.close()

    def generateProcess(self):

        process = Process()
        process.arrival_time = self.cpu.clock + (math.log(1 - float(random.uniform(0, 1))) / (-self.lambda_val))
        process.service_time = math.log(1 - float(random.uniform(0, 1))) / (-(1 / self.avgerage_time))
        process.remaining_time = process.service_time
        process.end_time = process.arrival_time + process.service_time
        process.start_time = 0
        return process

    def createEvent(self, time, type, process):

        event = Event()
        event.time = time
        event.type = type
        event.process = process

        return event
