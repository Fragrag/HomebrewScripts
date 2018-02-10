##########################################################################
#                                                                        #
# VideoMetaData.py                                                       #
#                                                                        #
# This script goes through files in a folder and its subfolders          #
# to output file location and codec type to output.csv                   #      
#                                                                        #
##########################################################################

import csv
import os
import sys

# Initialising start variables
try:
	TargetDirectory = sys.argv[1]
	assert TargetDirectory
except:
	print("Please specify a folder")
	sys.exit(1)
	
ffprobeArguments = " -v error -select_streams v:0 -show_entries stream=codec_name -of default=noprint_wrappers=1:nokey=1 "

# Initialises and creates a new .csv, setting up basic parameters to work with it
with open('output.csv', 'w') as csvfile: 
	header = ['Filename', 'Item location', 'Codec']
	csvOutput = csv.DictWriter(csvfile, fieldnames=header, lineterminator='\n', delimiter=',')
	csvOutput.writeheader()

	# Go through every file in folder and subfolder
	for root, dirs, files in os.walk(TargetDirectory):
		for item in files:
			locationItem = os.path.join(root, item) 
			returnedCodec = os.popen("ffprobe" + ffprobeArguments + '\"' + locationItem + '\"').read()
		
			print(locationItem)
			print(returnedCodec)
			
			csvOutput.writerow({'Filename': item, 'Item location': locationItem, 'Codec': returnedCodec}) 