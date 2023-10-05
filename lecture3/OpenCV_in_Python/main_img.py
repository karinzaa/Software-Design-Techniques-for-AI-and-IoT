import cv2
import argparse

img_location = './ZhongXinaSmaller.jpg'
parser = argparse.ArgumentParser(description='input image name')
parser.add_argument('--file', help="location of the image file")

args = parser.parse_args()
if args.file:
	img_location = args.file
print('<Image File Location>')
print(img_location)

img = cv2.imread(img_location)
print('File loaded')

h,w,c = img.shape
print('----------------------------------------------------')
print("Image Information")
print("Dimension w x h = %s x %s" % (w,h))
print("Channels = %s" %(c))
print("Total Pixels of input image = %s pixels which %s channels" % (w*h,c))
print('----------------------------------------------------')


gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

Invert_img = 255-gray_img

cv2.imshow('Input Image',img)
cv2.imshow('Gray Image',gray_img)
cv2.imshow('Invert Image',Invert_img)

cv2.imwrite('Invert_img.bmp',Invert_img)
print('File Saved')

cv2.waitKey(0)

