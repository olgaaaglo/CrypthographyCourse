from Crypto.Hash import SHA3_224, SHA3_256, SHA3_384, SHA3_512, SHAKE128, SHAKE256

def digest(digestmod, name):
    hash_object = digestmod.new(data=b'')
    print(name, "(''):")
    print(hash_object.hexdigest(), '\n')

digest(SHA3_224, 'SHA3_224')
digest(SHA3_256, 'SHA3_256')
digest(SHA3_384, 'SHA3_384')
digest(SHA3_512, 'SHA3_512')

def digestShake(digestmod, name, len, msg=b''):
    hash_object = digestmod.new(data=msg)
    print(name, "(", msg, ",", len, "):")
    print(hash_object.read(len).hex(), '\n')

digestShake(SHAKE128, 'SHAKE128', 256)
digestShake(SHAKE256, 'SHAKE256', 512)
digestShake(SHAKE128, 'SHAKE128', 256, b"The quick brown fox jumps over the lazy dog")
digestShake(SHAKE128, 'SHAKE128', 256, b"The quick brown fox jumps over the lazy dof")