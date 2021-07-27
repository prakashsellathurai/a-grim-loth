def isPowerOfTwo(x):
    return (x != 0) and ((x & (x - 1)))


print(isPowerOfTwo(2))
a = 8
print(bin(a), a)
print(bin(a - 1), a - 1)
print(a & (a - 1))

print(2 & 1, 3 & 1)

# for i in range(6):
#     print(i, i& i-1)

#   bool isPowerOfTwo(int x)
#     {
#         // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
#         return (x && !(x & (x - 1)));
#     }
# int count_one (int n)
#     {
#         while( n )
#         {
#         n = n&(n-1);
#            count++;
#         }
#         return count;
# }

#   void possibleSubsets(char A[], int N)
# {
#     for(int i = 0;i < (1 << N); ++i)
#     {
#         for(int j = 0;j < N;++j)
#             if(i & (1 << j))
#                 cout << A[j] << ‘ ‘;
#         cout << endl;
# }
# }


# long largest_power(long N)
#     {
#         //changing all right side bits to 1.
#         N = N| (N>>1);
#         N = N| (N>>2);
#         N = N| (N>>4);
#         N = N| (N>>8);


#     //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by
#      2.
#                 return (N+1)>>1;

#     }
def possible_subsets(arr):
    for i in range(1 << len(arr)):
        for j in range(len(arr)):
            if i & (1 << j):
                print(arr[j], end=" ")
        print("\n")


print("possible subsets")
possible_subsets([1, 2, 3])
