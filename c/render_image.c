#include <stdio.h>
#include <stdlib.h>

#define header_size 16
#define bpp 3
#define info_header_size 40
#define image_alignment_size 1 // aligned at 1 bit.


unsigned char *fileHeader(int height, int width)
{
    static unsigned char info[] = 
    {
        0,0,0,0,
        0,0,0,0
    };

    info[0] = (unsigned char)(width);
    info[1] = (unsigned char)(width >> 8);
    info[2] = (unsigned char)(width >> 16);
    info[3] = (unsigned char)(width >> 24);
    info[4] = (unsigned char)(height);
    info[5] = (unsigned char)(height >> 8);
    info[6] = (unsigned char)(height >> 8);
    info[7] = (unsigned char)(height >> 16);
    info[8] = (unsigned char)(height >> 24);

    return info;
}

unsigned char *configure_midpoint(int height, int width)
{
    /* Say height and width are (height, width), or (x,y). (x+y/2)*/
   const long mid = (height + width) / 2;

   /* lets base the rendered image off of this midpoint. Where the midpoint is where the image alignemnt begins */
   static unsigned char new_sequence[] = {
       0,0,0,0,
       0, // midpoint
       0,0,0,0, // midpoint by header size
       0,0,0,0, // midpoint by info header size
       0,0,0,0, // reserved
       0, // pixel to start with
       0,0 // start to align
   };

   new_sequence[0] = (unsigned char)(height);
   new_sequence[1] = (unsigned char)(height >> 8);
   new_sequence[2] = (unsigned char)(height >> 16);
   new_sequence[3] = (unsigned char)(height >> 24);
   new_sequence[4] = (unsigned char)mid;
   new_sequence[5] = (unsigned char)(mid * header_size);
   new_sequence[6] = (unsigned char)((mid * header_size) >> 8);
   new_sequence[7] = (unsigned char)((mid * header_size) >> 16);
   new_sequence[8] = (unsigned char)((mid * header_size) >> 24);
   new_sequence[9] = (unsigned char)((mid * info_header_size));
   new_sequence[10] = (unsigned char)((mid * info_header_size) >> 8);
   new_sequence[11] = (unsigned char)((mid * info_header_size) >> 16);
   new_sequence[12] = (unsigned char)((mid * info_header_size) >> 24);
   new_sequence[17] = (unsigned char)((header_size * info_header_size) + bpp);
   new_sequence[18] = (unsigned char)(header_size + info_header_size);
   new_sequence[19] = (unsigned char)(1);

   return new_sequence;
}

short int configure_aligned_image(unsigned char* sequence)
{
    if(sequence[19] > image_alignment_size)
    {
        return ((sequence[19] * sequence[18]) % 3) % 2;
    }
    return sequence[19];
}

int main()
{
    unsigned char* header = fileHeader(255, 450);

    FILE* file = fopen("r.png", "wb");

    if(file)
    {
        fwrite(header, 1, header_size, file);

        /* Give a new value to the header variable. */
        header = configure_midpoint(255, 450);
        fwrite(header, 1, header_size * info_header_size, file);

        fclose(file);
    }

    return 0;
}
