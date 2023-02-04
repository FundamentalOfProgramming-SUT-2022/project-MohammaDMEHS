#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creator(char NameAddress[]){
    char dir[1000]={'\0'};
    int temp1=0, temp2;
    FILE *fp;
    fp = fopen(NameAddress,"r");
    if(fp) printf("file already exists!");
    else
        for(int i=1; i<=strlen(NameAddress); i++){
            if(NameAddress[i]=='/'){
                temp2=i;
                for(int j=temp1;j<temp2;j++){
                    dir[j]=NameAddress[j];
                }
                temp1=temp2;
                mkdir(dir);
            }
        }
    fp = fopen(NameAddress,"a+");
    fclose(fp);
}

void inserter(char NameAddress[],char mohtava[], int line, int pos){
    FILE* fp=fopen(NameAddress, "r+");
    if(fp==NULL){
        printf("file doesn't exist!");
        return;
    }
    char import[1003];
    FILE* temp = fopen("temporary.tmp","w+");
    for(int i=1;i<=line;i++){
        if(feof(fp)){
            for(int j=i;j<=line;j++) fputc('\n',temp);
            break;
        }
        fgets(import, 1003, fp);
        fputs(import,temp);
    }
    for(int j=1; j<=pos; j++){
        char c=fgetc(fp);
        if(c=='\n' || feof(fp)){
            for(int k=j;k<=pos;k++){
                fputc(' ',temp);
            }
            if(feof(fp)) break;
            else fputc('\n',temp);
            break;
        }
        else{
            fputc(c, temp);
        }
    }
    fputs(mohtava,temp);
    while(!feof(fp)){
        fgets(import, 1003, fp);
        fputs(import, temp);
    }
    fp=fopen(NameAddress, "w");
    rewind(temp);
    while(!feof(temp)){
        fgets(import, 1003, temp);
        fputs(import,fp);
    }
    fclose(fp);
    fclose(temp);
}
void catter(char FileName[]){
    char mohtava[1003];
    FILE *fp=fopen(FileName, "r");
    if(fp == NULL) {
        printf("file doesn't exist!");
        return;
    }
    while(!feof(fp)){
        fgets(mohtava, 1003, fp);
        printf("%s", mohtava);
    }
}
void remover(char FileName[],int Line, int Pos,int Size,char ForBack[]){
    char mohtava[1003];
    char c, d;
    int location=0;
    int counter=0;
    FILE* fp=fopen(FileName, "r");
    for(int i=1; i<Line; i++){
        fgets(mohtava, 1003, fp);
        location+=strlen(mohtava);
    }
    location+=Pos;
    if(strcmp(ForBack,"-b")==0)location-=Size;
    FILE* temp=fopen("temporary.tmp", "w+");
    rewind(fp);
    for(int j=1; j<=location; j++){
        fputc(fgetc(fp), temp);
    }
    for(int k=1; k<=Size; k++){
        fgetc(fp);
    }
    while(!feof(fp)){
        fgets(mohtava, 1003, fp);
        fputs(mohtava, temp);
    }
    rewind(temp);
    fp=fopen(FileName, "w");
    while(!feof(temp)){
        fgets(mohtava, 1003, temp);
        fputs(mohtava, fp);
    }
    fclose(fp);
    fclose(temp);
}
void copier(char FileName[], int Line, int Pos, int Size, char ForBack[]){
char mohtava[1003];
    char c, d;
    int location=0;
    int counter=0;
    FILE* fp=fopen(FileName, "r");
    for(int i=1; i<Line; i++){
        fgets(mohtava, 1003, fp);
        location+=strlen(mohtava);
    }
    location+=Pos;
    if(strcmp(ForBack,"-b")==0)location-=Size;
    FILE* temp=fopen("clipboard.tmp", "w+");
    rewind(fp);
    for(int j=1; j<=location; j++){
        fgetc(fp);
    }
    for(int k=1; k<=Size; k++){
        fputc(fgetc(fp), temp);
    }
    while(!feof(fp)){
        fgets(mohtava, 1003, fp);
    }
    fclose(fp);
    fclose(temp);
}
void cutter(char FileName[], int Line, int Pos, int Size, char ForBack[]){
    copier(FileName, Line, Pos, Size, ForBack);
    remover(FileName, Line, Pos, Size, ForBack);
}
void paster(char FileName[], int Line, int Location){
    char mohtava[1003];
    int counter=0;
    FILE* fp=fopen(FileName, "r");
    FILE* temp=fopen("temporary.tmp", "w+");
    FILE* clipboard=fopen("clipboard.tmp", "r+");
    for(int i=1; i<Line; i++){
        fgets(mohtava, 1003, fp);
        fputs(mohtava, temp);
    }
    for(int j=0; j<Location; j++){
        fputc(fgetc(fp), temp);
    }
    while(!feof(clipboard)){
        fgets(mohtava, 1003, clipboard);
        fputs(mohtava, temp);
    }
    while(!feof(fp)){
        fgets(mohtava, 1003, fp);
        fputs(mohtava, temp);
    }
    fp=fopen(FileName, "w");
    rewind(temp);
    while(!feof(temp)){
        fgets(mohtava, 1003, temp);
        fputs(mohtava, fp);
    }
    fclose(temp);
    fclose(fp);
    fclose(clipboard);
}
void undoer(char FileName[]){
    char mohtava[1003];
    FILE* un=fopen("undo.txt", "r");
    FILE* fp=fopen(FileName, "w+");
    while(!feof(un)){
        fgets(mohtava, 1003, un);
        fputs(mohtava, fp);
    }
    fclose(un);
    fclose(fp);
}
void comparator(char file1[], char file2[]){
    int cnt1=0, cnt2=0, temp=0, temp2=0, counter=1;
    char mohtava1[1003];
    char mohtava2[1003];
    FILE* fp1=fopen(file1, "r");
    FILE* fp2=fopen(file2, "r");
    while(!feof(fp1)){
        fgets(mohtava1, 1003, fp1);
        cnt1++;
    }
    while(!feof(fp2)){
        fgets(mohtava2, 1003, fp2);
        cnt2++;
    }
    rewind(fp1);
    rewind(fp2);
    if(cnt1>cnt2) {
        temp=cnt2;
        temp2=cnt1;
    }
    else{
        temp=cnt1;
        temp2=cnt2;
    }
    while(counter<=temp){
        fgets(mohtava1, 1003, fp1);
        fgets(mohtava2, 1003, fp2);
        if(mohtava1[strlen(mohtava1)-1]=='\n')
            mohtava1[strlen(mohtava1)-1]='\0';
        if(mohtava2[strlen(mohtava2)-1]=='\n')
            mohtava2[strlen(mohtava2)-1]='\0';
        if(strcmp(mohtava1, mohtava2)!=0)
            printf("===========%d===========\n%s\n%s",counter, mohtava1, mohtava2);
        counter++;
    }
    if(cnt1>cnt2){
        printf("<<<<<<<<<#%d - #%d<<<<<<<<<\n", temp+1, temp2);
        while(!feof(fp1)){
            fgets(mohtava1, 1003, fp1);
            printf("%s", mohtava1);
        }
    }
    else if(cnt2>cnt1){
        printf(">>>>>>>>>#%d - #%d>>>>>>>>>\n", temp+1, temp2);
        while(!feof(fp2)){
            fgets(mohtava2, 1003, fp2);
            printf("%s", mohtava2);
        }
    }

    fclose(fp1);
    fclose(fp2);
}
void saver(char file_name[]){
    char mohtava[1003];
    FILE* un=fopen("undo.txt", "r+");
    FILE* fp=fopen(file_name, "r");
    while(!feof(fp)){
        fgets(mohtava, 1003, fp);
        fputs(mohtava, un);
    }
    rewind(fp);
    rewind(un);
    fclose(un);
    fclose(fp);
}
int main(){
    char file_name[200]="\0";
    char mohtava[1000]="\0";
    char forback[2]="\0";
    char FunctionType[20]="\0";
    char file_name2[200]="\0";
    int line=0;
    int pos=0;
    int size=0;
    while(strcmp(FunctionType,"exit")!=0){
        scanf("%s", FunctionType);
        if(strcmp(FunctionType, "createfile")==0){
            scanf("-file %s", file_name);
            creator(file_name);
            printf("\n");
        }
        else if(strcmp(FunctionType, "insertstr")==0){
            scanf(" -file %s -str %s --pos %d:%d", file_name, mohtava, &line, &pos);
            saver(file_name);
            inserter(file_name, mohtava, line, pos);
            printf("\n");
        }
        else if(strcmp(FunctionType, "cat")==0){
            scanf(" -file %s", file_name);
            catter(file_name);
            printf("\n");
        }
        else if(strcmp(FunctionType, "removestr")==0){
            scanf(" -file %s -pos %d:%d -size %d %s", file_name, &line, &pos, &size, forback);
            saver(file_name);
            remover(file_name, line, pos, size, forback);
            printf("\n");
        }
        else if(strcmp(FunctionType, "copystr")==0){
            scanf(" -file %s -pos %d:%d -size %d %s", file_name, &line, &pos, &size, forback);
            copier(file_name, line, pos, size, forback);
            printf("\n");
        }
        else if(strcmp(FunctionType, "cutstr")==0){
            scanf(" -file %s -pos %d:%d -size %d %s", file_name, &line, &pos, &size, forback);
            saver(file_name);
            cutter(file_name, line, pos, size, forback);
            printf("\n");
        }
        else if(strcmp(FunctionType, "pastestr")==0){
            scanf(" -file %s -pos %d:%d", file_name, &line, &pos);
            saver(file_name);
            paster(file_name, line, pos);
            printf("\n");
        }
        else if(strcmp(FunctionType, "undo")==0){
            scanf(" -file %s", file_name);
            undoer(file_name);
            printf("\n");
        }
        else if(strcmp(FunctionType, "compare")==0){
            scanf(" %s %s", file_name, file_name2);
            comparator(file_name, file_name2);
            printf("\n");
        }
    }
}
