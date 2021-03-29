#ifndef RC4_PRNG_TEST_H
#define RC4_PRNG_TEST_H

/*
    You can find more information in the document:
    RFC 6229 <Test Vectors for the Stream Cipher RC4>

    There are three test cases described below (A,B,C).
    Each of them serves for checking with an appropriate reference stream. 
*/

typedef struct {
    uint8_t  key[256];
    uint8_t  keyLength;
    uint8_t  referenceStream[16];
    uint64_t referenceStreamLength;
    uint16_t referenceStreamOffset;
} testCase;

/*
    Key length:    40 bits
    Key:           0x0102030405
    Stream offset: 0
    Stream length: 16 byte
*/
testCase testCaseA = {
    .key = {
        0x01, 0x02, 0x03, 0x04,
        0x05 
    },
    .keyLength = 5,
    .referenceStream = {
        0xb2, 0x39, 0x63, 0x05,
        0xf0, 0x3d, 0xc0, 0x27,   
        0xcc, 0xc3, 0x52, 0x4a,  
        0x0a, 0x11, 0x18, 0xa8
    },
    .referenceStreamLength = 16,
    .referenceStreamOffset = 0
};

/*
    Key length:    40 bits
    Key:           0x0102030405
    Stream offset: 4096
    Stream length: 16 byte
*/
testCase testCaseB = {
    .key = {
        0x01, 0x02, 0x03, 0x04,
        0x05 
    },
    .keyLength = 5,
    .referenceStream = {
        0xff, 0x25, 0xb5, 0x89,  
        0x95, 0x99, 0x67, 0x07,   
        0xe5, 0x1f, 0xbd, 0xf0,  
        0x8b, 0x34, 0xd8, 0x75
    },
    .referenceStreamLength = 16,
    .referenceStreamOffset = 4096
};

/*
    Key length:    64 bits
    Key:           0x641910833222772a
    Stream offset: 0
    Stream length: 16 byte
*/
testCase testCaseC = {
    .key = {
        0x64, 0x19, 0x10, 0x83,
        0x32, 0x22, 0x77, 0x2a
    },
    .keyLength = 8,
    .referenceStream = {
        0xbb, 0xf6, 0x09, 0xde,
        0x94, 0x13, 0x17, 0x2d,   
        0x07, 0x66, 0x0c, 0xb6,
        0x80, 0x71, 0x69, 0x26
    },
    .referenceStreamLength = 16,
    .referenceStreamOffset = 0
};

#endif // RC4_PRNG_TEST_H