  Sorting Algorithm Summary
Sorting Algorithm	Time Complexity	        Space Complexity	Stable?
Bubble Sort      	    O(N^2)              O(1)                    Yes
Insertion Sort      	O(N^2)               O(1)	            Yes
Selection Sort	        O(N^2)              O(1)	            No
Heap Sort	            O(NlogN)	         O(1)           	No
Counting Sort	        O(N+K)	            O(N + K)        	Yes
Radix Sort	            O(WN + WK)	        O(N + K)        	Yes
Bucket Sort	    O(N^2) -- O(N + K) average	O(N+K)	            Yes
Note: For radix sort, WW is the maximum number of characters/numbers of each element in the array, and KK is the maximum alphabet size. For counting sort, assuming non-negative integers, KK is the maximum element in the input. For all sorting methods, NN is the size of the input array.