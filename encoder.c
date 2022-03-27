#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE * output= stdout;
    FILE * input= stdin;
    FILE * err_put = stderr;
    int c = (fgetc(input));
    int i;
    int flag = 0;
    int counter = 0;
    int to_duplicate = 0;
    for (i = 0; i < argc; ++i) {
        if(strcmp(argv[i],"-D")==0) {
            flag = 'D';
        }
        else if( strstr(argv[i],"+e") ==0 || strstr(argv[i],"-e") == 0){
            if ((argv[i] <= 'F' && argv[i] >= 'A') || (argv[i]>= '0' && argv[i] <= '9')) {

            }
            else {
                fprintf(err_put, "invalid key");
            }

        }
    }


    switch (flag) {

        case 0: {
            while(c != EOF) {
                if((c <= 'Z') & (c >= 'A'))
                    c = '.';
                putc(c,output);
                c = (fgetc(input));
            }
        }

        case 'D': {
            while (c != EOF) {
                while (c != '\n') {
                    int cha = c;
                    if ((c <= 'Z') & (c >= 'A')) {
                        c = '.';
                        counter++;
                    }
                    fprintf(err_put, "%d %d\n", cha, c);
                    putc(c,output);
                    c = (fgetc(input));
                }
                fprintf(err_put, "the number of letters: %d\n", counter);
                counter = 0;
                c = (fgetc(input));
            }
        }
    }




    return 0;
}