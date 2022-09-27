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
    def __init__(self, scheduler, lambda_val, avgerage_time, quantum, end_condition, cpu_num):
        self.cpu = CPU()
        self.scheduler = scheduler
        self.lambda_val = lambda_val
        self.avgerage_time = avgerage_time
        self.quantum = quantum
        self.cpu_num = cpu_num

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

                # if ready queue is not empty departure event is created

                else:
                    process_departing = self.readyQueue.pop(0)
                    process_departing.start_time = self.cpu.clock
                    process_departing.end_time = process_departing.start_time + process_departing.service_time
                    new_departure_event = self.createEvent(process_departing.end_time, "DEP", process_departing)
                    self.eventQueue.append(new_departure_event)

        self.readyQueue.clear()
        self.eventQueue.clear()
        self.completed_processes = 0


    def run(self):
        if self.scheduler is 1:
            self.FCFS()
        else:
            print("Invalid input.")

    def ratioCalculation(self):
        for i in range(len(self.readyQueue)):
            self.readyQueue[i].ratio = ((self.cpu.clock - self.readyQueue[i].arrival_time) + self.readyQueue[
                i].service_time) / self.readyQueue[i].service_time

    def report(self):

        if self.scheduler is 1:
            scheduler_label = "FCFS"
        else:
            print("Invalid input.")

        if self.cpu_num is 1:
            avg_turn_around_time = round((self.total_turnaround_time / self.end_condition), 3)
        else:
            avg_turn_around_time = round((self.total_turnaround_time / self.end_condition / 2), 3)

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

        elif self.lambda_val is 10:
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

class Simulator2:
    def __init__(self, scheduler, lambda_val, avgerage_time, quantum, end_condition, cpu_num):
        self.cpu = CPU()
        self.scheduler = scheduler
        self.lambda_val = lambda_val
        self.avgerage_time = avgerage_time
        self.quantum = quantum
        self.cpu_num = cpu_num