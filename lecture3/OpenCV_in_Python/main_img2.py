import cv2
import argparse
import numpy as np  

#Usage python main_img.py --file Scenic009smaller.bmp #

def convolution2d(image, filter, bias):
	m, n = filter.shape
	if (m == n):
		# Middle of the kernel
		offset = m // 2
		print("offset = %s" %offset)
		print("Applying Filter to Image")
		h, w = image.shape
		nh = h - m + offset
		nw = w - m + offset
		new_image = np.empty((nh,nw), dtype=np.uint8)
		new_image.fill(0)
		#new_image = np.zeros((y,x))
		for j in range(offset, w - offset):
			for i in range(offset, h - offset):
				acc = 0.0
				temp = 0.0
				#print("pixel-location = {%s,%s}" %(i,j))
				for a in range(0,m):
					for b in range(0,n):
						pixel_value = float(image[i-offset+a][j-offset+b])
						filter_value = float(filter[a][b])
						acc = acc + pixel_value * filter_value
						
						#print(type(pixel_value))
						#print(type(filter_value))
						#print(type(temp))
						#print("{%s} X {%s} = %s" %(pixel_value,filter_value, acc))

				output_pixel_value = int(acc + bias)
				#print(output_pixel_value)
				if (output_pixel_value) > 255:
					output_pixel_value =255
				if (output_pixel_value) <0:
					output_pixel_value =0
				new_image[i-offset][j-offset] = output_pixel_value
	return new_image
	


img_location = 'Donki.jpg'
parser = argparse.ArgumentParser(description='input image name')
parser.add_argument('--file', help="location of the image file")

args = parser.parse_args()
if args.file:
	img_location = args.file
print('<Image File Location>')
print(img_location)

input_img = cv2.imread(img_location)
print('File loaded')

gray_img = cv2.cvtColor(input_img, cv2.COLOR_BGR2GRAY)

h,w = gray_img.shape
print('----------------------------------------------------')
print("Image Information")
print("Dimension w x h = %s x %s" % (w,h))
print("Total Pixels of input image = %s pixels" % (w*h))
print('----------------------------------------------------')

# Box Blur Filter AKA Low-pass Filter
box_blur_filter = np.array([[1/9.0, 1/9.0, 1/9.0], [1/9.0, 1/9.0, 1/9.0], [1/9.0, 1/9.0, 1/9.0]])

# High-pass Filter
sharpen_filter = np.array([[  0.0  , -0.5 ,    0.0 ], [-0.5 ,   3.0  , -0.5 ],[  0.0  , -0.5 ,    0.0 ]])

# Edge Filters
Edge_filter = np.array([[  -1.0  , -1.0 ,    -1.0 ], [-1.0 ,   8.0  , -1.0 ],[  -1.0  , -1.0 ,    -1.0 ]])

# Emboss Filter
Emboss_filter = np.array([[  -2.0  , -1.0 ,    0.0 ], [-1.0 ,   1  , 1.0 ],[  0.0  , 1.0 ,    2.0 ]])


cv2.imshow('Input Image',input_img)
cv2.imshow('Gray Image',gray_img)

print("---------------------------------------------------------")
print("Applying Blur Filter")
blur_img = convolution2d(gray_img, box_blur_filter,0 )
print("---------------------------------------------------------")
print("Applying High Pass Filter")
sharpen_img = convolution2d(gray_img, sharpen_filter,0 )
print("---------------------------------------------------------")
print("Applying Edge Filter")
edge_img = convolution2d(gray_img, Edge_filter,0 )
print("---------------------------------------------------------")
print("Applying Emboss Filter")
emboss_img = convolution2d(gray_img, Emboss_filter,0 )
print("---------------------------------------------------------")

cv2.imshow('Blur Image',blur_img)
cv2.imshow('Sharpen Image',sharpen_img)
cv2.imshow('Edge Image',edge_img)
cv2.imshow('Emboss Image',emboss_img)


cv2.waitKey(0)

