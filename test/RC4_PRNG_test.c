#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "./../include/RC4_PRNG.h"
#include "RC4_PRNG_test.h"

typedef enum {Incorrect = -1, Correct = 0} testResult;

testResult runTestCaseA(void)
{
    uint8_t* generatedStream = getPseudoRandomBytesStream(
                                                            testCaseA.key, 
                                                            testCaseA.keyLength, 
                                                            testCaseA.referenceStreamOffset, 
                                                            testCaseA.referenceStreamLength
                                                        );
    
    testResult compareWithReference = Correct;
    for (uint8_t i = 0; i < testCaseA.referenceStreamLength; i++)
    {
        if(*(generatedStream+i) != testCaseA.referenceStream[i])
        {
            compareWithReference = Incorrect;
            break;
        }
    }
    
    return compareWithReference;
}

testResult runTestCaseB(void)
{
    uint8_t* generatedStream = getPseudoRandomBytesStream(
                                                            testCaseB.key, 
                                                            testCaseB.keyLength, 
                                                            testCaseB.referenceStreamOffset, 
                                                            testCaseB.referenceStreamLength
                                                        );
    
    testResult compareWithReference = Correct;
    for (uint8_t i = 0; i < testCaseB.referenceStreamLength; i++)
    {
        if(*(generatedStream+i) != testCaseB.referenceStream[i])
        {
            compareWithReference = Incorrect;
            break;
        }
    }
    
    return compareWithReference;
}

testResult runTestCaseC(void)
{
    uint8_t* generatedStream = getPseudoRandomBytesStream(
                                                            testCaseC.key, 
                                                            testCaseC.keyLength, 
                                                            testCaseC.referenceStreamOffset, 
                                                            testCaseC.referenceStreamLength
                                                        );
    
    testResult compareWithReference = Correct;
    for (uint8_t i = 0; i < testCaseC.referenceStreamLength; i++)
    {
        if(*(generatedStream+i) != testCaseC.referenceStream[i])
        {
            compareWithReference = Incorrect;
            break;
        }
    }
    
    return compareWithReference;
}

int main(void)
{
    printf("\n");
    printf("Correct code   =  0\n");
    printf("Incorrect code = -1\n");
    printf("\n");

    printf("Run test case A:\t%i\n", runTestCaseA());
    printf("Run test case B:\t%i\n", runTestCaseB());
    printf("Run test case C:\t%i\n", runTestCaseC());
    printf("\n");
}