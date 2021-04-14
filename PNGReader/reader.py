from PIL import Image
import numpy as np

image_name = input()

image = Image.open(image_name).getdata()
length, height = image.size
image = list(image)

white_and_black_matrix = []
black = (0, 0, 0, 255)

for line in range(height):
    white_and_black_matrix.append(image[line * length: (line + 1) * length])

new_data = np.array([[1 if pixel == black else 0 for pixel in line] for line in white_and_black_matrix])

with open('working_copy', 'w') as output_file:
    for i in new_data:
        for j in i:
            output_file.write(str(j))
        output_file.write('\n')
