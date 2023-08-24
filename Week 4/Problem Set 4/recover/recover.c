#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: /recover <file>");
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");

    if(argv[1] == NULL)
    {
        printf("This file is invalid");
    }

    FILE* output_file = NULL;

    unsigned char buffer[512];

    char* filename = malloc(8 * sizeof(char));

    int counter = 0;

    while(fread(buffer, sizeof(char), 512, input_file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(counter > 0)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", counter);

            output_file = fopen(filename, "w");

            counter++;
        }

        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(input_file);
    fclose(output_file);
}