from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

key = get_random_bytes(16)
cipherECB = AES.new(key, AES.MODE_ECB)
cipherCBC = AES.new(key, AES.MODE_CBC)
cipherCTR = AES.new(key, AES.MODE_CTR)

fileName = 'Tux.body'
with open(fileName, mode='rb') as file:
    fileContent = file.read()

    resECB = cipherECB.encrypt(pad(fileContent, AES.block_size))
    with open("Tux.body.ecb", "wb") as binary_file:
        binary_file.write(resECB)

    resCBC = cipherCBC.encrypt(pad(fileContent, AES.block_size))
    with open("Tux.body.cbc", "wb") as binary_file:
        binary_file.write(resCBC)

    resCTR = cipherCTR.encrypt(pad(fileContent, AES.block_size))
    with open("Tux.body.ctr", "wb") as binary_file:
        binary_file.write(resCTR)

    with open('Tux.ecb.ppm', 'wb') as outfile:
        with open('Tux.header', 'rb') as infile:
            for line in infile:
                outfile.write(line)
        with open('Tux.body.ecb', 'rb') as infile:
            for line in infile:
                outfile.write(line)

    with open('Tux.cbc.ppm', 'wb') as outfile:
        with open('Tux.header', 'rb') as infile:
            for line in infile:
                outfile.write(line)
        with open('Tux.body.cbc', 'rb') as infile:
            for line in infile:
                outfile.write(line)

    with open('Tux.ctr.ppm', 'wb') as outfile:
        with open('Tux.header', 'rb') as infile:
            for line in infile:
                outfile.write(line)
        with open('Tux.body.ctr', 'rb') as infile:
            for line in infile:
                outfile.write(line)