#!/usr/bin/env python
# coding: utf-8

import re
from operator import itemgetter
import os
import time
import sys
import subprocess
import json

args = sys.argv
problems_dir = os.path.dirname(os.path.abspath(__file__))

problem_ids = []

for p in os.listdir(problems_dir):
    if os.path.isfile(os.path.join(problems_dir, p, 'config.json')):
        problem_ids.append(p)
problems_json = {}

for p in problem_ids:
    try:
        tmp = ""
        with open(os.path.join(problems_dir, p, 'config.json')) as f:
            tmp = json.load(f)
        problems_json[p] = tmp
        print("{} : configuration succeeded".format(p))
    except Exception as e:
        print("{} : configuration failed \n {}".format(p, str(e)))

with open(os.path.join(problems_dir, 'problems.json'), "w") as f:
    json.dump(problems_json, f, indent=4)
