원본 : https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

## Cutting a Rod | DP-13

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


|length| 1 |  2 |  3 |  4 |  5 |  6 |  7 |  8  |
|------|---|----|---|-----|---|----|----|-----|
|price    | 1|   5|   8|   9|  10|  17|  17|  20|


구간별 단가가 다른 통나무를 가장 높은 가격으로 자르는 방법


A naive solution for this problem is to generate all configurations of different pieces and find the highest priced configuration. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.

단순한 방법으로 시작하자면 길이의 모든 조합을 찾아서 가장 높은 가격을 계산한다. 하지만 complexity 가 많이 걸림. DP 방식으로 어떻게 풀 수 있는지 알아보자

__1) Optimal Substructure:__ </br>
We can get the best price by making a cut at different positions and comparing the values obtained after a cut. We can recursively call the same function for a piece obtained after a cut.

각각 다른 위치에서 통나무를 자르고 나서 가격을 계산한뒤 최고 값을 구할 수 있다. 이를 재귀함수로 구현할 수 있다.

Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.

cutRod(n) 를 길이가 n 일 때 최고 값이라고 가정하면 점화식은 다음과 같다. 

cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1} <br>
max(i길이의 값 + cutRod(n-i-1)) : price[i] 의 값과 나머지 길이의 가격의 최대 값의 합

__2) Overlapping Subproblems__</br>
Following is simple recursive implementation of the Rod Cutting problem. The implementation simply follows the recursive structure mentioned above.

```c++
int cutRod(int price[], int n) 
{ 
   if (n <= 0) 
     return 0; 
   int max_val = 0; 
  
   // Recursively cut the rod in different pieces and compare different  
   // configurations 
   for (int i = 0; i<n; i++) 
         max_val = max(max_val, price[i] + cutRod(price, n-i-1)); 
  
   return max_val; 
} 
```

위와 같은 코드는 아래와 같이 재귀트리의 depth 가 4가 된다. 

```
cR() ---> cutRod() 

                             cR(4)
                  /        /           
                 /        /              
             cR(3)       cR(2)     cR(1)   cR(0)
            /  |         /         |
           /   |        /          |  
      cR(2) cR(1) cR(0) cR(1) cR(0) cR(0)
     /        |          |
    /         |          |   
  cR(1) cR(0) cR(0)      cR(0)
   /
 /
CR(0)
```

위의 트리를 참고하면 cR(2) 같은 경우 두번 계산되게 된다. 트리의 depth 가 깊으면 깊을수록 이런 중복된 계산이 많아질 것이다. 따라서 이렇게 계산된 값들은 미리 저장해두는 것이 좋다. 

```c++
int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = 0; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
```
val[i] 는 i 길이 일때 최대값, 길이는 1부터 시작 <br>

Time Complexity 는 O(n<sup>2</sup>)로 첫번째 방법의 worst case 보다 낫다. 

재귀함수 구현은 다음과 같음
```c++
int cutting_rod_recurv(int price[], int n, int cut)
{
    if( cut == n-1 )
    {
        return price[n-1];
    }

    return std::max( (price[cut] + price[n-1-cut-1]), cutting_rod_recurv(price, n, cut+1) );
}
```




