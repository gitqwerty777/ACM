f = open("12442in", "w")
f.write("50000\n")
for i in range(1, 49999, 1):
    f.write("%d %d\n" % (i, i+1))
f.write("50000 1\n")
f.close()
