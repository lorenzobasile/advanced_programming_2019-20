import time

class MyRange:
    def __init__(self,begin,end,step=1):
        self.value=range(begin,end,step)

def myrange(*args):
    num_args=len(args)
    if num_args<1 or num_args>3:
        raise TypeError("myrange requires at least 1 argument and at most 3 arguments")
    if num_args==1:
        return MyRange(0,args[0]).value
    if num_args==2:
        return MyRange(args[0],args[1]).value
    if num_args==3:
        return MyRange(args[0],args[1],args[2]).value
class timer:
    def __enter__(self):
        print("enter")
        self.start=time.time()
    def __exit__(self,exc_type,exc_value,traceback):
        print("exit")
        print("elapsed time:", time.time()-self.start)

with timer() as t:
    for i in range(4):
        print(i)
