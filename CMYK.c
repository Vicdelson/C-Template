#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};
unsigned int global1, global2;

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB()
{

}

int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void print_C(unsigned int mask[][MAX_SIZE])
{
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < W;j++)
        {
            image[i][j]= image[i][j]+mask[i][j]*1000*1000;
        }
    }
}
void print_M(unsigned int mask[][MAX_SIZE])
{
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < W;j++)
        {
            image[i][j]= image[i][j]+mask[i][j]*1000;
        }
    }
}
void print_Y(unsigned int mask[][MAX_SIZE])
{
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < W;j++)
        {
            image[i][j]= image[i][j]+mask[i][j];
        }
    }
}
void print_K(unsigned int mask[][MAX_SIZE])
{
    for(int i=0;i<H;i++)
    {
        for(int j = 0; j<W;j++)
        {
            global1=image[i][j]%1000;//%1000
            
            image[i][j]/=1000;

            global2=image[i][j]%1000;

            image[i][j]/=1000;
            //decimal
            image[i][j]=lround(255*(100-image[i][j])*(100-mask[i][j])*0.0001)*256*256;
            image[i][j]=image[i][j]+lround(255*(100-global1)*(100-mask[i][j])*0.0001)*256;
            image[i][j]=image[i][j]+lround(255*(100-global2)*(100-mask[i][j])*0.0001);
        }
    }
}