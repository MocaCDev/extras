#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        	return 4 + (width + l) / 10;
	}
	return (l / 3) / width;
}

void create_image(FILE* file, char *colors, int length, int width, int dimmed)
{
	char info_header[  ] = { 
        	'B', 'M'
    	};

	int height = 5 + configure_height(width, length);
	int paddedw = r4(width);
	int size = height * paddedw * 3;

	int header[] = {
		0, 0x00, // image size
		0x36, 0x28,
		width*2, (height*5) / 2,
		0x1800A1,
		0, 0,
		0x002F23, 0x002F23, 0, 0 // high resolution
	};

    	unsigned char *exceeded_padding = (unsigned char*)malloc(paddedw * 3 * width * sizeof(*padding));

	header[0] = sizeof(info_header) + sizeof(header) + size;

	char* image = (char*)malloc((size + height) * sizeof(char*));

    	for(int i = 0; i < paddedw; i++)
    	{
        	for(int x = 0; x < 3; x++) // padding for each byte of the image
        	{
            		for(int w = 0; w < width; w++)
            		{
                		exceeded_padding[i + x + w] = (unsigned char)(0x00);
                		exceeded_padding[i * x + w] = (unsigned char)(image[i * x] + 1);
            		}
            		if(!(exceeded_padding[i] > 0x00))
            		{
                		exceeded_padding[i] = 0x00; // everything else is 0x00.
            		}
        	}
    	}

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

				if(dimmed == 0)
				{
					image[index] = colors[3* (i * width + x) * (2 - c) / ((i * c) + width)];
				} else if(dimmed == 1) // higher resolution
				{
					image[index] = colors[2 * (i * width + x) * (2 - c) + (bpp * width)];
				} else if(dimmed == 2) // assign each rgb value dependable on the bytes per pixel
				{
					//image[index] = colors[2 * (i * width + x) * (2 - c) * (bpp + paddedw)];
                    			for(int b = 0; b < bpp; b++)
                    			{
						image[index + (b * bpp)] = colors[(bpp * b) * (i * width + c) * (2 - c)];
                    			}
				} else
				{
					image[index] = colors[3*(i * width + x) + (2 - c)]; // render it normally
			    	}
			}
		}
	}

	fwrite(&info_header, sizeof(info_header), 1, file);
	fwrite(&header, sizeof(header), 1, file);
	for(int i = 0; i < size; i++)
	{
		for(int b = 0; b < bpp; b++) // 3 bytes per pixel. We will fill each part of the image with the full 3 bytes. whether or not it is needed(this will change how the image looks).
		{
			unsigned char new_sequence[ 7 ] = { 0x00, image[(i * b)], image[(i * b) - 1], image[(i * b) - 2], image[1 - (i + (bpp * (width * height)))], exceeded_padding[i * b], 0x00 };

			fwrite(&new_sequence, sizeof(new_sequence), 1, file);
		}
        	fwrite(&padding, sizeof(padding), 1, file); // 3 bytes of the image have been written. Put in some padding
	}

	fclose(file);

    	free(image);
    	free(exceeded_padding);

    	if((info_header[0] & size) == 0)
    	{
        	printf("Image Created!!\n");
    	}
}

/*
  read_image will read a .bmp formatted file, and rewrite the image with a dependable image width and height.
*/
void read_image(FILE* file)
{
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    int height = 0;
    int width = 0;
    int base_on = 0;

    char *info_header = (char*)calloc(2, sizeof(*info_header));

    if(filesize > 0)
    {
        char* file_info = (char *)calloc(filesize, sizeof(*file_info));
        fread(file_info, filesize, 1, file);

        for(int i = 0; i < 2; i++)
        {
            info_header[i] = file_info[i];
        }
        for(int i = 0; i < filesize; i++)
        {
            if(isdigit(file_info[i]))
            {
                base_on = (int)file_info[i];
            }
        }

        if(base_on > 0)
        {
            width = (2 * (base_on * base_on)) / 2;
            height = configure_height(width, base_on * base_on);
        }
    }
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
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)227;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)240;
			} else if(i == 1 || i == 3)
			{
				rgb[3 * (i * 8 + x)] = (unsigned char)245;
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)171;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)185;
			} else
			{
				rgb[3 * (i * 8 + x) - 1] = (unsigned char)250;
				rgb[3 * (i * 8 + x) + 1] = (unsigned char)255;
				rgb[3 * (i * 8 + x) + 2] = (unsigned char)250;
			}
		}
	} // copied from documentation.

	create_image(file,rgb,3*5*8, 40, 2);

  FILE* nfile = fopen("img.bmp", "rb");
  read_image(file);
}
