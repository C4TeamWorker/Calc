#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getInput(int argc, char *argv[]);
int getLines(char* str);
void split(char* str, int lines, char *tmp[]);
int isIn(char ch, char* str);

int main(int argc, char *argv[]) {
    char* str = getInput(argc, argv);
    int lines = getLines(str);
    char *each_line[lines];
    split(str,lines,each_line);

//    
    for(int k = 0;k < lines;k++){
        if(isIn('=',each_line[k])){//calculate
            //opt
            printf("calculate:line %d:%s\n",k+1,each_line[k]);

        } else if(isIn('(',each_line[k]) 
                  || isIn(')',each_line[k])){//output
            //opt
            printf("output:line %d:%s\n",k+1,each_line[k]);

        } else {//declare variable
            //opt
            printf("declare variable:line %d:%s\n",k+1,each_line[k]);

        }




    }
//





    //set output
    if(argc == 3) {
        FILE* out;
        if((out = fopen(argv[2], "w")) == NULL) {
            printf("Error! Couldn't open the file <%s>!\n", argv[2]);
            exit(3);
        }
        //operate here
        //...
        //end operation

        //close the fp
        if(fclose(out) != 0){
            printf("Error in closing files:<%s>", argv[2]);
        }
    }



    return 0;
}
//读入文件并存入字符串str中
char* getInput(int argc, char *argv[]){
    FILE *in;
    int ch;
    int i = 0;
    int last;
    char* str;

    //Check the parameters in the cmd
    if (argc < 2) {
        printf("Please enter a filename as an input!\n");
        exit(EXIT_FAILURE);
    }
    //set the input
    if((in = fopen(argv[1], "r")) == NULL) {
        printf("Error! Couldn't open the file <%s>!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //get the contents of input file
    fseek(in, 0L, SEEK_END);
    last = ftell(in);
    str = (char*)malloc(sizeof(char) * last);
    fseek(in, 0L, SEEK_SET);
    while((ch = getc(in)) != EOF){
        str[i] = ch;
        i++;
    }
    //close the fp
    if(fclose(in) != 0){
        printf("Error in closing files:<%s>", argv[1]);
    }
    str[i-1] = '\n';
    str[i] = '\0';
    return str;
}

int getLines(char* str){
    int lines = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n') {
            lines++;
        }
    }
    return lines;
}

void split(char* str, int lines, char *tmp[]) {
    int head, tail;
    head = tail = 0;
    int k = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n') {
            head = tail;
            tail = i;
            int len = tail - head + 1;
            tmp[k] = (char*)malloc(sizeof(char) * len);
            for(int j = 0;head < tail;j++,head++){
                tmp[k][j] = str[head];
            }
            tmp[k][len-1] = '\0';
            k++;
            tail++;
        }
    }
}

int isIn(char ch, char* str){
    for(int i = 0; i < strlen(str);i++){
        if(str[i] == ch) {
            return 1;
        }
    }
    return 0;
}

















