import os
import time
import random
from random import randint
import threading
from threading import Thread

def func1():
    print("start")
    os.system("killall -9 svapp;./svapp 1")

def func2(threads):
    print("release")
    os.system("killall -9 svapp")
    i = 1
    for t in threads:
        print("destory" + str(i))
        i = i + 1
        t.join()

def main():
    threads = []
    while True:
            t = threading.Thread(target=func1)
            threads.append(t)
            t.start()
            
            index1 = randint(10,20)
            print("start sleep time", index1, "s" )
            time.sleep(index1)
            
            
            print("==============stop the process and start one new================")
            func2(threads)
            threads = []


if __name__=="__main__":
    main()

