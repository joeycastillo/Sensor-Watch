#!/usr/bin/env python3

# Transform TOTP credentials into the format expected by
# movement/watch/faces/complication/totp_face.c
#
# Edit the credentials list below if __name__ == '__main__':

from base64 import b32decode
from collections import namedtuple

(SHA1, SHA224, SHA256, SHA384, SHA512) = ('SHA1', 'SHA224', 'SHA256',
                                          'SHA384', 'SHA512')

Credential = namedtuple('Credential',
                        ('label', 'key', 'algorithm', 'time_step'),
                        defaults=(SHA1, 30))

def key_to_octet_array_line(key, keys):
    key_bytes = [f'0x{byte:02x},' for byte in b32decode(key)]
    keys.append(' '.join(key_bytes))
    return len(key_bytes)

def to_c_array(keys, credentials):
    print('static uint8_t keys[] = {')
    for (key, credential) in zip(keys, credentials):
        print(f'    {key} // {credential.label}')
    print('};')

def add_field(name, value):
    print(f', .{name} = {value}', end='')

def to_totpc_credentials(credentials):
    keys = []
    print(('Replace everything between `Enter your TOTP key data below`'
           ' and `END OF KEY DATA` in `movement/watch/faces/complication/totp_face.c`'
           ' by the following:\n'))
    print('#pragma GCC diagnostic ignored "-Winitializer-overrides"')
    print('const static totp_parameters_t credentials[] = {')
    for credential in credentials:
        print(f'    CREDENTIAL(.label = "{credential.label}"', end='')
        key_size = key_to_octet_array_line(credential.key, keys)
        if key_size != 20:
            add_field('key_size', key_size)
        if credential.time_step != 30:
            add_field('time_step', credential.time_step)
        if credential.algorithm != SHA1:
            add_field('algorithm', credential.algorithm)
        print('),')
    print('};\n')
    to_c_array(keys, credentials)

if __name__ == '__main__':
    # Replace these credentials by your credentials,
    # either by using their positions Credential(LABEL, KEY[, ALGORITHM][, TIME_STEP])
    # or by using the keyword arguments label, key, algorithm and time_step.
    #
    # The default key size is 20, the default algorithm is SHA1 and
    # the default time-step is 30 seconds.
    #
    # A label is made up of two characters (Which can be entered as a string.)
    # Due to the structure of the display, the first character can be
    # displayed as anything but an uppercase R.
    # The second character can be displayed as the letters A, B, C, D, E,
    # F, H, I, J, L, N, O, R, T, U and X, and the numbers 0, 1, 3, 7 and 8.
    # (See: https://www.sensorwatch.net/docs/wig/display/)
    credentials = (Credential('2F', 'JBSWY3DPEHPK3PXP'),
                   Credential('AC', 'JBSWY3DPEHPK3PXP'),
                   Credential('GL', 'OUP7FO6VOLI67IQ5SOKY3YR4BSGYPUL6'),
                   Credential('TF',
                              '7GDDVXOXY2ZHTG253TVMHPOE54KQV25DNV4QASFACXMPDKWRFOLVOT5E',
                              algorithm=SHA512),
                   Credential('EB', '2TH5QXGKY6GCS5OVRP3KHW5NNMTVQG57', time_step=40),)

    to_totpc_credentials(credentials)
