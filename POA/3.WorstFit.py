from cmath import inf


memory = {
    'Partition1': [100, 'free', 'no_process', 'allocated_memory', 'free_memory'],
    'Partition2': [500, 'free', 'no_process', 'allocated_memory', 'free_memory'],
    'Partition3': [200, 'free', 'no_process', 'allocated_memory', 'free_memory'],
    'Partition4': [300, 'free', 'no_process', 'allocated_memory', 'free_memory'],
    'Partition5': [600, 'free', 'no_process', 'allocated_memory', 'free_memory']
}

process = {
    'Process1': [212,'free'],
    'Process2': [417,'free'],
    'Process3': [112,'free'],
    'Process4': [426,'free'],
}

def worstfit():
    for pname, pinfo in process.items():
        maxfragment = 0
        res_minfo = None
        for mname, minfo in memory.items():
            if pinfo[0] <= minfo[0] and minfo[1] == 'free' and pinfo[1] == 'free':
                fragment = minfo[0] - pinfo[0]
                if fragment > maxfragment:
                    maxfragment = fragment
                    res_minfo = minfo
        if res_minfo is not None:
            res_minfo[1] = "allocated"
            res_minfo[2] = pname
            res_minfo[3] = pinfo[0]
            res_minfo[4] = res_minfo[0] - pinfo[0]
            pinfo[1] = "allocated"

    for mname, minfo in memory.items():
        print(mname, " : ", minfo)

worstfit()
