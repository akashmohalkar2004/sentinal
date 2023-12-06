def selection_sort(a):
    for i in range (len(a) - 1):
        min_index = i
        for j in range (i+1, len(a)):
            if a[min_index] > a[j]:
                min_index =j
        a[i] , a[min_index] = a[min_index] , a[i] 
        
        
        print(a)
        
        
def bubble_sort(a):
    for i in range(len(a)):
        for j in range(len(a) - i -1):
            if a[j] > a[j+1]:
                
                a[j] ,a[j+1] = a[j +1] ,a[j]
        print(a)        
        
        
a = [2,45,47,44,45,21,55,78]
print(" unsorted array",a)

index = selection_sort(a)
print("sorted array( selection_sort):",a)

bubble_sort(a)

print("sorted array ( bubble_sort) :",a)

