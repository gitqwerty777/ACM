f = open("11236ans.txt", "r")
wf = open("11236array", "w")

for line in f:
    nums = [float(s) for s in line.split()]
    s = 0.0
    for n in nums:
        s += n
    if s <= 20.00:
        wf.write("{%.02f, %.02f, %.02f, %.02f},\n" % (nums[0], nums[1], nums[2], nums[3]) ) 
        #print "%f != %f :%f %f %f %f impossible" % (s, m, nums[0], nums[1], nums[2], nums[3])
#    else:
        
