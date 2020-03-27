#!/usr/bin/env python
# coding: utf-8

import re
from operator import itemgetter
import os
import time
import sys
import subprocess
import json
import random

args = sys.argv
seed_of_seed = int(args[1])
problems_dir = os.path.dirname(os.path.abspath(__file__))
problem_ids = []

for p in os.listdir(problems_dir):
    if os.path.isfile(os.path.join(problems_dir, p, 'config.json')):
        problem_ids.append(p)
problems_json = {}

for p in problem_ids:
    try:
        tmp = {}
        with open(os.path.join(problems_dir, p, 'config.json')) as f:
            tmp = json.load(f)
        print("{} : configuration succeeded".format(p))
        random.seed(seed_of_seed)
        tmp["seeds"]=[]
        for i in range(tmp["num_testcases"]):
            if i < 10:
                tmp["seeds"].append(i)
            else:
                tmp["seeds"].append(random.randint(0, 1000000000))

        problems_json[p] = tmp


    except Exception as e:
        print("{} : configuration failed \n {}".format(p, str(e)))

with open(os.path.join(problems_dir, 'problems.json'), "w") as f:
    json.dump(problems_json, f, indent=4)
