#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "./../include/RC4_PRNG.h"
#include "RC4_PRNG_test.h"

typedef enum {Incorrect = -1, Correct = 0} testResult;

testResult runTestCase(testCase referenceData)
{
    uint8_t* generatedStream = getPseudoRandomBytesStream(
                                                            referenceData.key,
                                                            referenceData.keyLength,
                                                            referenceData.referenceStreamOffset,
                                                            referenceData.referenceStreamLength
                                                         );
    testResult compareWithReference = Correct;
    for (uint8_t i = 0; i < referenceData.referenceStreamLength; i++)
    {
        if(*(generatedStream+i) != referenceData.referenceStream[i])
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
    printf("Run test case A:\t%s\n", (runTestCase(testCaseA) == Correct) ? "Correct" : "Incorrect");
    printf("Run test case B:\t%s\n", (runTestCase(testCaseB) == Correct) ? "Correct" : "Incorrect");
    printf("Run test case C:\t%s\n", (runTestCase(testCaseC) == Correct) ? "Correct" : "Incorrect");
    printf("\n");
}