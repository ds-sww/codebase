#!/bin/python
import os
import re
import pdb

def dfs(curdir, remove = False) :
	for name in os.listdir(curdir) :
		if name == '.git' : continue
		fullname = curdir + '/' + name
		if re.match(r'.*dSYM', name) != None :
			if remove :
				os.system('rm -rf %s' % fullname)
				print remove
			else:
				print 1, name
			continue
		if re.match(r'^(?:.*?\.(?:cpp|py|tex|java|md|gitignore|sh|pdf|png|jpg|h))|LICENSE|Makefile$', name) == None and os.path.isdir(fullname) == False :
			if remove :
				os.system('rm -rf %s' % fullname)
				print remove
			else:
				print 2, name
			continue
		if os.path.isdir(fullname) :
			dfs(fullname, remove)

dfs(os.getcwd())
sure = raw_input('Sure to remove files mentioned above? yes or no : ')
remove = False
if sure == 'yes' :
	remove = True
dfs(os.getcwd(), remove)
