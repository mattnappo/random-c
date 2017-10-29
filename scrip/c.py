import os, sys
print("\n")
if sys.argv[1] == "-a":
    src = os.listdir("../src/")
    src.remove("c")
    for obj in src:
        stripped = obj[:-4]
        os.system("g++ -o ../bin/" + stripped + " " + obj)
        print("compiled: " + stripped)
else:
    stripped = sys.argv[1][:-4]
    os.system("g++ -o ../bin/" + stripped + " " + sys.argv[1])
    print("compiled: " + stripped)
print("\n")
