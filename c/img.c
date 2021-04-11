#include <stdio.h>
#include <stdlib.h>

#define bpp 3
const char padding[ 3 ] = { 0x00, 0x00, 0x00 }; // padding for the image. Written after every 3 bytes

int r4(int x)
{
	return x % 4 == 0 ? x : x -x % 4 + 4;
}

int configure_height(int width, int l)
{
	if(width % 4 == 0)
	{
		return ((l / width) * (width / 2)) / (width + 4);
	}
	return (l / 3) / width;
}

void create_image(FILE* file, char *colors, int length, int width)
{
	char info_header[ 2 ] = { 'B', 'M' };
	int height = configure_height(width, length);
	int paddedw = r4(width);
	int size = height * paddedw * 3;

	int header[] = {
		0, 0x00, // image size
		0x36, 0x28,
		width, height,
		0x180001,
		0, 0,
		0x104e23, 0x104e23, 0, 0 // high resolution
	};

	header[0] = sizeof(info_header) + sizeof(header) + size;

	char* image = (char*)malloc(size * sizeof(char*));
	//int size_ = size * sizeof(char*);
	for(int i = 0; i < size; i++) image[i] = 0x00;

	for(int i = 0; i < height; i++)
	{
		for(int x = 0; x < width; x++)
		{
			for(int c = 0; c < 3; c++)
			{
				int index = i * paddedw + x * 3 + c;
				//printf("%c\n",colors[3*(i * width + x) + (2 - c)]);

				image[index] = colors[3*(i * width + x) + (2 - c)];
			}
		}
	}

	fwrite(&info_header, sizeof(info_header), 1, file);
	fwrite(&header, sizeof(header), 1, file);
	for(int i = 0; i < size; i++)
	{
		for(int b = 0; b < bpp; b++) // 3 bytes per pixel. We will fill each part of the image with the full 3 bytes. whether or not it is needed(this will change how the image looks).
		{
			unsigned char new_sequence[ 2 ] = { image[(i * b) / 2], 0x00 };
			fwrite(&new_sequence, sizeof(new_sequence), 1, file);
		}
    		fwrite(&padding, sizeof(padding), 1, file); // 3 bytes of the image have been written. Put in some padding
	}

	fclose(file);
}

int main()
{
	FILE* file = fopen("img.bmp", "wb");

	char *rgb = (char*)malloc(8 * 5 * sizeof(char) * 3);
	for(int i = 0; i < 5; i++)
	{
		for(int x = 0; x < 8; x++)
		{
			if(i == 0 || i == 4)
			{
				rgb[3 * (i * 8 + x)] = 91;
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)207;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)250;
			} else if(i == 1 || i == 3)
			{
				rgb[3 * (i * 8 + x)] = (unsigned char)245;
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)171;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)185;
			} else
			{
				rgb[3 * (i * 8 + x)] = (unsigned char)255;
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)255;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)255;
			}
		}
	} // copied from documentation.

	create_image(file,rgb,3*5*8, 20);
}
