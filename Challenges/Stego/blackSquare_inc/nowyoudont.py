#!/usr/bin/python

from PIL import Image
im = Image.open('blackSquare.png')
pixelMap = im.load()

p=set()
img = Image.new( im.mode, im.size)
pixelsNew = img.load()
for i in range(img.size[0]):
    for j in range(img.size[1]):
        # print(pixelMap[i,j])
        p.add(pixelMap[i,j])
# img.show()
print(p)
