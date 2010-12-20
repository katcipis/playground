#include <secure/xor_cipher.h>
#include <utility/malloc.h>

__BEGIN_SYS

static const char * key            = "xor cipher key e";
static const unsigned int key_size = 16; /* 16 bytes - 64 bits*/

void XOR_Cipher::xor_data(char * data, unsigned int data_size)
{
    unsigned int j = 0;
    for (unsigned int i = 0; i < data_size; i++) {
        data[i] = data[i] ^ key[j];
        j++;
        if (j == key_size) {
            /* exceding the key size, back to begin */
            j = 0;
        } 
    }
}

void XOR_Cipher::encipher(void * data, unsigned int data_size)
{
    db<XOR_Cipher>(TRC) << "XOR_Cipher encipher(" << data << " size = " << data_size << ")\n";
    xor_data(reinterpret_cast<char*>(data), data_size);
}

void XOR_Cipher::decipher(void * data, unsigned int data_size)
{
    db<XOR_Cipher>(TRC) << "XOR_Cipher decipher(" << data << " size = " << data_size << ")\n";
    xor_data(reinterpret_cast<char*>(data), data_size);
}

XOR_Cipher::XOR_Cipher()
{
    db<XOR_Cipher>(TRC) << "XOR_Cipher()\n";
}


XOR_Cipher::~XOR_Cipher()
{
    db<XOR_Cipher>(TRC) << "~XOR_Cipher()\n";
}

__END_SYS
