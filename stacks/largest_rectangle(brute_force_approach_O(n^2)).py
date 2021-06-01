height = [3,5,1,4]
width = []
l = len(height)

for i in range(l):
    lptr,rptr,lcount,rcount = 0,0,0,0

    if (i != 0):
        lptr = i-1

        while(lptr != -1 and height[lptr] >= height[i]):
            lcount += 1
            lptr -= 1
            
    
    if (i != l-1):
        rptr = i + 1

        while(rptr != l and height[rptr] >= height[i]):
            rcount += 1
            rptr += 1
            
    width.append(lcount+rcount+1)

print("height: " + str(height))
print("width: " + str(width))
area = [h[i]*w[i] for i in range(l)]
print("area: " + str(area))
print("largest rectangle/ max area : " + str(max(area)))

# Logic used => atleast one rectangle will be fully included in the largest rectangle 
# for explanation refer https://www.youtube.com/watch?v=vcv3REtIvEo
# brute force approach
# time complexity => O(n^2)
