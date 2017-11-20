int main() {

}
self.public = []
    self.private = []
    self.p = 61 # one prime
    self.q = 53 # another prime
    self.n = (self.p)*(self.q) # the modulo
    self.totient = (self.p-1)*(self.q-1) # totient
    self.e = 2
    while True:
        if fractions.gcd(self.e, self.totient)==1: # if coprime
            break
        else:
            self.e = random.randint(2, self.totient) # continue to pick a random number in the range 1 < e < totient
    self.d = 2
    while True:
        if (self.d)*(self.e)%self.totient==1: # if modulo of de == 1
            break
        else:
            self.d = random.randint(2, self.n)
    self.public = [self.e, self.n]
    self.private = [self.d, self.n]
    files = [self.name + "/" + self.name + "_n.rsa", self.name + "/" + self.name + "_public.rsa", self.name + "/" + self.name + "_private.rsa"]
    values = [self.n, self.e, self.d]
    for x in range(len(files)):
        with open(files[x], "w") as xFile:
            xFile.write(str(values[x]))
    return True
def getPublic(self):
    return self.public
def getPrivate(self):
    return self.private
class Modifier():
def __init__(self, public, private):
    self.public = public
    self.private = private
    self.contents = ""
def encrypt(self, file):
    with open(file, "r", encoding="utf-8") as xFile:
        self.contents = xFile.read()
    open(file, "w", encoding="utf-8").close()
    with open(file, "w", encoding="utf-8") as xFile:
        for x in range(len(self.contents)):
            encr = ord(self.contents[x])**self.public[0]%self.public[1]
            xFile.write(chr(encr))
def decrypt(self, file):
    with open(file, "r", encoding="utf-8") as xFile:
        self.contents = xFile.read()
    open(file, "w", encoding="utf-8").close()
    with open(file, "w", encoding="utf-8") as xFile:
        for x in range(len(self.contents)):
            encr = ord(self.contents[x])**self.private[0]%self.private[1]
            xFile.write(chr(encr))
