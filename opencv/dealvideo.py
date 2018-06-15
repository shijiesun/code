#!/usr/bin/python

import sys
import os
import cv2
import pyseeta_wrapper


if len(sys.argv) < 3:
    print "usage:%s [video_path] [output_path]" % sys.argv[0]
    sys.exit()

inpath = "images"
if not os.path.exists(inpath):
    os.makedirs(inpath)

if not os.path.isdir(inpath):
    print "%s is not directory" % inpath
    sys.exit()

command = 'ffmpeg -i ' + sys.argv[1] + ' -r 1 ' + inpath + '/image-%05d.jpeg'

os.system(command)

outpath = sys.argv[2]

if not os.path.exists(outpath):
    os.makedirs(outpath)

if not os.path.isdir(outpath):
    print "%s is not directory" % outpath
    sys.exit()


print 'start wrapper'
#m = [[11, 22, 33],
#     [44, 55, 66],
#     [77, 88, 99],
#     [12, 34, 56]
#     ]

#print color_pic.tolist()
pyseeta_wrapper.full_init('./model/', './model/')
#print pyseeta_wrapper.face_detect(m)
#print gray_pic

files = os.listdir(inpath)

print files

for filename in files:

    filepath = inpath + "/" + filename

    print "imread %s" % filepath

    color_pic = cv2.imread(filepath)
    gray_pic = cv2.cvtColor(color_pic, cv2.COLOR_RGB2GRAY)

    #print dir(gray_pic)
    #print gray_pic.tolist()
    #print gray_pic.__doc__

    result = pyseeta_wrapper.face_detection(gray_pic.tolist())

    if result and len(result) > 0:
        print "found %d faces" % len(result)
        for r in result:
            loc = r['location']
            cv2.rectangle(color_pic,(loc['x'],loc['y']),(loc['x'] + loc['width'],loc['y'] + loc['height']),(0,0,255),2)

        outfilepath = outpath + "/" + filename
        cv2.imwrite(outfilepath, color_pic)
        print "imwrite %s finished" % outfilepath

pyseeta_wrapper.full_fini()
print 'wrapper ends'

