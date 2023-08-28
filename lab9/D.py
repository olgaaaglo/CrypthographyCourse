from Crypto.Hash import HMAC, SHA256, SHA3_256, SHA512, SHA3_512 

def digest(digestmod, name):
  msg = b'The quick brown fox jumps over the lazy dog'
  secret = b'key'
  h = HMAC.new(secret, digestmod=digestmod)
  h.update(msg)

  mac = h.hexdigest()
  print("HMAC_", name, "('key', 'The quick brown fox jumps over the lazy dog)")
  print(h.hexdigest())

  try:
    h.hexverify(mac)
    print("The message '%s' is authentic" % msg)
  except ValueError:
    print("The message or the key is wrong")
  print("\n")

digest(SHA256, 'SHA256')
digest(SHA3_256, 'SHA3_256')
digest(SHA512, 'SHA512')
digest(SHA3_512, 'SHA3_512')