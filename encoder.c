#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int flag_e(FILE *input, FILE *output, int c,int add_sub, int num_of_letters);
int flag_i(FILE *input, FILE *output, int c,int add_sub, int num_of_letters);

int main(int argc, char *argv[]) {
    FILE * output= stdout;
    FILE * input= stdin;
    FILE * err_put = stderr;
    FILE * file;
    int i;
    int c;
    int flag = 0;
    int counter = 0;
    int num_of_letters = 0;
    int add_sub = 0;
    for (i = 1; i < argc; ++i) {
        if(strcmp(argv[i],"-D")==0) {
            flag = 'D';
        }
        else if( strstr(argv[i],"+e") != NULL || strstr(argv[i],"-e") != NULL){
            if ((argv[i][2] <= 'F' && argv[i][2] >= 'A') || (argv[i][2] >= '0' && argv[i][2] <= '9')) {
                add_sub = argv[i][0];
                if (flag != 'i')
                    flag = 'e';
                if((argv[i][2] <= 'F' && argv[i][2] >= 'A'))
                    num_of_letters = argv[i][2] - 55;
                else
                    num_of_letters = argv[i][2] -48;
            }
            else {
                fprintf(err_put, "invalid key\n");
                return 0;
            }

        }
        else if(strstr(argv[i],"-i") != NULL){
            flag = 'i';
            char filename[strlen(argv[i] - 1)];
            int j;
            int k;
            for (j = 2,k = 0; j < strlen(argv[i]) ; ++j, k++) {
                filename[k] = argv[i][j];
            }
            printf("%s",filename);
            file = fopen(filename,"r");
            if(file == NULL) {
                fprintf(err_put, "empty file\n");
                return 0;
            }
        }
    }

    switch (flag) {

        case 0: {
            c = (fgetc(input));
            while(c != EOF) {
                if((c <= 'Z') & (c >= 'A'))
                    c = '.';
                putc(c,output);
                c = (fgetc(input));
            }
            break;
        }

        case 'D': {
            c = (fgetc(input));
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
                putc(c,output);
                counter = 0;
                c = (fgetc(input));
            }
            break;
        }
        case 'e': {
            c = (fgetc(input));
            flag_e(input,output,c,add_sub,num_of_letters);
            break;
        }
        case 'i': {
            c = (fgetc(file));
            flag_i(file,output,c,add_sub,num_of_letters);
        }
    }




    return 0;
}


int flag_e(FILE *input, FILE *output, int c,int add_sub, int num_of_letters) {
    while(c != EOF) {
        int first_chara = c;
        if (add_sub == '+' ) {
            while( c != '\n'){
                putc(c,output);
                c = (fgetc(input));
            }
            int j;
            for (j = 0; j < num_of_letters; ++j) {
                putc(first_chara,output);
            }
        }
        else {
            int j;
            for (j = 0; j < num_of_letters; ++j) {
                if (c == '\n') {
                    fprintf(output, "-NONE-");
                    j = num_of_letters + 1;
                }
                else
                    c = (fgetc(input));
            }
            while( c != '\n'){
                putc(c,output);
                c = (fgetc(input));
                j = num_of_letters + 2;
            }
            if( j != num_of_letters + 2 )
                fprintf(output, "-NONE-");
        }
        fprintf(output,"\n");
        c = (fgetc(input));
    }
    return 0;
}

int flag_i(FILE *input, FILE *output, int c,int add_sub, int num_of_letters) {
    while(!feof(input)) {
        int first_chara = c;
        if (add_sub == '+' ) {
            while( c != '\n'){
                putc(c,output);
                c = (fgetc(input));
            }
            int j;
            for (j = 0; j < num_of_letters; ++j) {
                putc(first_chara,output);
            }
        }
        else {
            int j;
            for (j = 0; j < num_of_letters; ++j) {
                if (c == '\n') {
                    fprintf(output, "-NONE-");
                    j = num_of_letters + 1;
                }
                else
                    c = (fgetc(input));
            }
            while( c != '\n'){
                putc(c,output);
                c = (fgetc(input));
                j = num_of_letters + 2;
            }
            if( j != num_of_letters + 2 )
                fprintf(output, "-NONE-");
        }
        fprintf(output,"\n");
        c = (fgetc(input));
    }
    return 0;
}