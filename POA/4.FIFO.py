processes = [2,3,2,1,5,2,4,5,3,2,5]
size_of_memory = 3
memory = []
index = 0
hitcount = 0
faultcount = 0
initial_fill = 0

print("Page Incoming\t\tState\t\t\tMemory\t\t\tPage Hit Count\t\tPage Fault Count")

for process in processes:
    if process not in memory:
        if initial_fill!=size_of_memory:
            memory.append(process)
            initial_fill+=1
            faultcount+=1
            print(process,"\t\t\t","Fault\t\t\t",memory,"\t\t\t",hitcount,"\t\t\t",faultcount)
        else:
            memory.pop(index)
            memory.insert(index,process)
            index = (index + 1)%size_of_memory
            faultcount+=1
            print(process,"\t\t\t","Fault\t\t\t",memory,"\t\t\t",hitcount,"\t\t\t",faultcount)
    else:
        hitcount+=1
        print(process,"\t\t\t","Hit\t\t\t",memory,"\t\t\t",hitcount,"\t\t\t",faultcount)