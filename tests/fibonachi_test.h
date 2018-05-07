#ifndef FIBONACHI_H
#define FIBONACHI_H
#include <unistd.h>
#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
#include <errno.h>
using namespace std;
extern "C" {
    #include "../app/common.h"
    #include "../app/text/_text.h"
    #include "../app/text/text.h"
}
TEST(baseTest, num0){
    SUCCEED();
}
TEST(baseTest, num1){
    FILE *o = stdout;
    char *path = (char*)malloc(sizeof(char) * 1024);
    sprintf(path, "%s/Samples/Output/TestRev0.txt", SAMPLES_DIR);
    o = fopen(path, "w+");
    if(o == NULL){
        //FAIL();
        ASSERT_EQ(errno, 0);
    }
    int oldstdout = dup(fileno(stdout));
    dup2(fileno(o), fileno(stdout));
    printf("hello world");
    printf("===%d; %d; %d===", fileno(stdout), fileno(o), oldstdout);
    fflush(stdout);
    dup2(oldstdout, fileno(stdout));
    fclose(o);
    SUCCEED();
}
TEST(baseTest, num2){
    FILE *o = stdout;
    char *path = (char*)malloc(sizeof(char) * 1024);
    sprintf(path, "%s/Samples/Output/TestRev0.txt", SAMPLES_DIR);
    o = fopen(path, "w+");
    if(o == NULL){
        //FAIL();
        ASSERT_EQ(errno, 0);
    }
    int oldstdout = dup(fileno(stdout));
    dup2(fileno(o), fileno(stdout));
    char *inpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(inpath, "%s/Samples/Input/TestRev0.in", SAMPLES_DIR);
    text txt = create_text();
    load(txt, inpath);
    fflush(stdout);
    dup2(oldstdout, fileno(stdout));
    fclose(o);
    if(txt -> begin == NULL)
        FAIL();
    SUCCEED();
}
TEST(baseTest, num3){
    FILE *o = stdout;
    char *path = (char*)malloc(sizeof(char) * 1024);
    sprintf(path, "%s/Samples/Output/TestRev0.txt", SAMPLES_DIR);
    o = fopen(path, "w+");
    if(o == NULL){
        //FAIL();
        ASSERT_EQ(errno, 0);
    }
    int oldstdout = dup(fileno(stdout));
    dup2(fileno(o), fileno(stdout));
    char *inpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(inpath, "%s/Samples/Input/TestRev0.in", SAMPLES_DIR);
    text txt = create_text();
    load(txt, inpath);
    showrev(txt);
    fflush(stdout);
    dup2(oldstdout, fileno(stdout));
    fclose(o);
    SUCCEED();
}
TEST(revTest, num0) {
    FILE *o = stdout;
    char *path = (char*)malloc(sizeof(char) * 1024);
    sprintf(path, "%s/Samples/Output/TestRev0.txt", SAMPLES_DIR);
    o = fopen(path, "w+");
    if(o == NULL){
        //FAIL();
        ASSERT_EQ(errno, 0);
    }
    int oldstdout = dup(fileno(stdout));
    dup2(fileno(o), fileno(stdout));
    char *inpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(inpath, "%s/Samples/Input/TestRev0.in", SAMPLES_DIR);
    text txt = create_text();
    load(txt, inpath);
    showrev(txt);
    fflush(stdout);
    dup2(oldstdout, fileno(stdout));
    fclose(o);
    char *tpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(tpath, "%s/Samples/Output/TestRev0.out", SAMPLES_DIR);
    char *rpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(rpath, "%s/Samples/Output/TestRev0.out", SAMPLES_DIR);
    FILE *test = fopen(tpath, "r");
    FILE *result = fopen(rpath, "r");
    char first;
    char second;
    if(test == NULL)
        FAIL();
    if(result == NULL)
        FAIL();
    while(!feof(test) && !feof(result)){
        fscanf(test, "%c", &first);
        fscanf(result, "%c", &second);
        if(second != first)
            FAIL();
    }
    fclose(test);
    fclose(result);
    SUCCEED();
}

TEST(revTest, num1) {
    FILE *o = stdout;
    char *path = (char*)malloc(sizeof(char) * 1024);
    sprintf(path, "%s/Samples/Output/TestRev1.txt", SAMPLES_DIR);
    o = fopen(path, "w+");
    if(o == NULL){
        //FAIL();
        ASSERT_EQ(errno, 0);
    }
    int oldstdout = dup(fileno(stdout));
    dup2(fileno(o), fileno(stdout));
    char *inpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(inpath, "%s/Samples/Input/TestRev1.in", SAMPLES_DIR);
    text txt = create_text();
    load(txt, inpath);
    showrev(txt);
    fflush(stdout);
    dup2(oldstdout, fileno(stdout));
    fclose(o);
    char *tpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(tpath, "%s/Samples/Output/TestRev1.out", SAMPLES_DIR);
    char *rpath = (char*)malloc(sizeof(char) * 1024);
    sprintf(rpath, "%s/Samples/Output/TestRev1.out", SAMPLES_DIR);
    FILE *test = fopen(tpath, "r");
    FILE *result = fopen(rpath, "r");
    char first;
    char second;
    if(test == NULL)
        FAIL();
    if(result == NULL)
        FAIL();
    while(!feof(test) && !feof(result)){
        fscanf(test, "%c", &first);
        fscanf(result, "%c", &second);
        if(second != first)
            FAIL();
    }
    fclose(test);
    fclose(result);
    SUCCEED();
}
#endif // FIBONACHI_H
