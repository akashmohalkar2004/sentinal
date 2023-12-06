stud_list = [ 45,412,87,85,23,79,15,24]

def linear_search(l ,key):
    for i in range (len(l)):
        if l[i] == key:
            return i
    return -1
    
index = linear_search(stud_list,45)
if index == -1:
    print(" student not present in the list(linear_list")
    
else:
    print(" student present at position ",index,"( linear_search")
    
    
def sentinel_search( l ,key):
    last = l[-1]
    l[-1] =key 
    i = 0
    
    while l[i] != key :
        i += 1
        
    if l[i] != len(l) - 1:
        return i
        
    if last == key :
        return len(l) -1
        
    return -1
    
index = sentinel_search(stud_list,15)
if index == -1:
    print(" student not present in the list(sentinel_list)")
    
else:
    print(" student present at position ",index,"( sentinel_search)")
    
        
    