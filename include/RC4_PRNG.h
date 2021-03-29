#ifndef RC4_PRNG_H
#define RC4_PRNG_H

/*
    Allows you to get a stream of pseudo-random bytes.
    Returns a pointer to the created stream.

    If you need to set the stream offset, use the corresponding positive argument streamHeadOffset.

    The resulting stream can be used, for example, for encryption.
    (See addition modulo 2 in stream ciphers for more details.)

    NOTE OF THIS IMPLEMENTATION:
    The classic size of the S array is used, i.e. 256 bytes.
    The maximum key size (keyLength) in this case is 256 bytes.
*/
uint8_t* getPseudoRandomBytesStream(
                                     const uint8_t* const key,              /* initializes the stream and fully determines it */
                                     const uint16_t       keyLength,        /* must be 1 <= keyLength <= 256 */
                                     const uint64_t       streamHeadOffset, /* offset relative to the beginning of the stream */
                                     const uint64_t       streamLength      /* the number of bytes in the result stream */
                                   );

/*
    Allows you to print the result obtained from the function getPseudoRandomBytesStream.
    Use the same (or less) stream length (streamLength) as when calling getPseudoRandomBytesStream.
*/
void printPseudoRandomBytesStream(
                                     const uint8_t* const stream,           /* pointer to a stream */
                                     const uint64_t       streamLength      /* the number of bytes in the stream */
                                 );

#endif // RC4_PRNG_H